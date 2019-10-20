/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 11:15:02 by min-kim           #+#    #+#             */
/*   Updated: 2019/09/17 13:00:53 by min-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			get_next_line(const int fd, char **line)
{
	char			buffer[BUFF_SIZE + 1];
	static t_list	*node_chain;
	t_list			*node;
	int				read_result;
	char			*temp;

	if (fd < 0 || !line || (read(fd, buffer, 0)) < 0
			|| (!(node = get_node(fd, &node_chain))))
		return (-1);
	temp = node->content;
	read_result = read_line_end_range(fd, &temp);
	node->content = temp;
	if (!read_result && !*temp)
		return (0);
	read_result = save_line(line, node->content, '\n');
	temp = node->content;
	if (temp[read_result] != '\0')
	{
		node->content = ft_strdup(&(node->content)[read_result + 1]);
		free(temp);
	}
	else
		temp[0] = '\0';
	return (1);
}

t_list		*get_node(int fd, t_list **node_chain)
{
	t_list	*node;

	if (!node_chain)
		return (NULL);
	node = *node_chain;
	while (node != NULL)
	{
		if ((int)(node->content_size) == fd)
			return (node);
		node = node->next;
	}
	node = ft_lstnew("", fd);
	ft_lstadd(node_chain, node);
	return (node);
}

int			read_line_end_range(const int fd, char **content)
{
	char	buffer[BUFF_SIZE + 1];
	int		bytes_read;
	char	*temp;

	while ((bytes_read = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[bytes_read] = '\0';
		temp = *content;
		if (!(*content = ft_strjoin(*content, buffer)))
			return (-1);
		free(temp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (bytes_read);
}

int			save_line(char **line, char *content, char character)
{
	int		index;
	char	*temp;

	index = 0;
	temp = *line;
	while (content[index] != '\0' && content[index] != character)
		index++;
	if (!(*line = ft_strndup(content, index)))
		return (0);
	return (index);
}
