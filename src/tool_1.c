#include "fdf.h"
#include "../libft/libft.h"
#include "../libft/get_next_line.h"

static void free_arr(char **arr)
{
    size_t  i;

    i = 0;
    while (arr[i])
    {
        free(arr[i]);
        i++;
    }
    free(arr);
}

static int  isdigit_base(char c, int base)
{
    const char  *digits = "0123456789ABCDEF";
    int         i;

    i = 0;
    while (i < base)
    {
        if (digits[i] == ft_toupper(c))
            return (i);
        i++;
    }
    return (-1);
}

static t_bool has_prefix(const char *str, int base)
{
    size_t  i;

    i = 0;
    if (base == 2 || base == 8 || base == 16)
    {
        if (str[i++] != '0')
            return (false);
        if ((base == 2) && (str[i] == 'B' || str[i] == 'b'))
            return (true);
        if ((base == 16) && (str[i] == 'X' || str[i] == 'x'))
            return (true);
        if (base == 8)
            return (true);
    }
    return (false);
}

int is_space(int c)
{
    return (c == ' ' ||
            c == '\t' ||
            c == '\n' ||
            c == '\v' ||
            c == '\f' ||
            c == '\r');
}

t_bool is_number(char *str, int base)
{
    size_t  i;
    size_t  digits;
    t_bool  result;

    i = 0;
    digits = 0;
    while (is_space(str[i]))
        i++;
    if (base != 10 && !has_prefix(&str[i], base))
        return (false);
    if ((base == 2) || (base == 16))
        i += 2;
    else if (base == 8)
        i++;
    else if ((base == 10) && (str[i] == '-' || str[i] == '+'))
        i++;
    while (isdigit_base(str[i++], base) >= 0)
        digits++;
    if (!str[i] && digits)
        true;
    else
        false;
    return (result);
}

int     atoi_base(const char *str, int base)
{
    unsigned long result;
    size_t          i;
    int             sign;

    result = 0;
    i = 0;
    sign = 1;
    while (is_space(str[i]))
        i++;
    if (base != 10 && !has_prefix(&str[i], base))
        return (false);
    if (base == 2 || base == 16)
        i += 2;
    else if (base == 8)
        i++;
    else if (base == 10 && (str[i] == '-' || str[i] == '+'))
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (isdigit_base(str[i], base) >= 0)
        result = result * base + isdigit_base(str[i++], base);
    return ((int)(result * sign));
}