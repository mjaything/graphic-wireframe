#include "fdf.h"

int activate_mouse(int mouse_button, int x, int y, void *param)
{
    t_env   *env;

    (void)x;
    (void)y;
    env = (t_env *)param;
    if (mouse_button == MOUSE_SCROLL_UP || mouse_button == MOUSE_SCROLL_DOWN)
        zoom(mouse_button, env);
    else if (mouse_button == MOUSE_LEFT_CLICK)
        env->mouse->clicked = true;
    return (0);
}

int deactivate_mouse(int mouse_button, int x, int y, void *param)
{
    t_env   *env;

    (void)x;
    (void)y;
    (void)mouse_button;
    env = (t_env *)param;
    env->mouse->clicked = false;
    return (0);
}

int move_mouse(int x, int y, void *param)
{
    t_env *env;

    env = (t_env *)param; 
    env->mouse->old_x = env->mouse->x;
    env->mouse->old_y = env->mouse->y;
    env->mouse->x = x;
    env->mouse->y = y;
    if (env->mouse->clicked)
    {
        env->camera->beta += (x - env->mouse->old_x) * 0.002;
        env->camera->alpha += (y - env->mouse->old_y) * 0.002;
        draw(env->map, env);
    }
    return (0);
}