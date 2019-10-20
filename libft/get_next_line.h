/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 11:20:24 by min-kim           #+#    #+#             */
/*   Updated: 2019/09/17 12:58:38 by min-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 32

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

int		get_next_line(const int fd, char **line);
t_list	*get_node(int fd, t_list **node_chain);
int		read_line_end_range(const int fd, char **content);
int		save_line(char **line, char *content, char character);

#endif
