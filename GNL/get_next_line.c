/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-- <erocha--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 11:41:54 by erocha--          #+#    #+#             */
/*   Updated: 2026/01/06 19:11:00 by erocha--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	clean_stash(t_list **stash)
{
	t_list	*last;
	t_list	*cleaned;
	int		i;
	int		j;

	cleaned = malloc(sizeof(t_list));
	if (cleaned == NULL)
		return ;
	cleaned->next = NULL;
	last = get_last(*stash);
	i = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content && last->content[i] == '\n')
		i++;
	cleaned->content = malloc(sizeof(char)
			* ((ftt_strlen(last->content) - i) + 1));
	if (cleaned->content == NULL)
		return ;
	j = 0;
	while (last->content[i])
		cleaned->content[j++] = last->content[i++];
	cleaned->content[j] = '\0';
	free_stash(*stash);
	*stash = cleaned;
}

static void	extract_line(t_list *stash, char **line)
{
	int	i;
	int	j;
	int	found;

	if (stash == NULL)
		return ;
	create_line(line, stash);
	if (*line == NULL)
		return ;
	j = 0;
	found = 0;
	while (stash && !found)
	{
		i = 0;
		while (stash->content[i] && stash->content[i] != '\n')
			(*line)[j++] = stash->content[i++];
		if (stash->content[i] == '\n')
		{
			(*line)[j++] = '\n';
			found = 1;
		}
		stash = stash->next;
	}
	(*line)[j] = '\0';
}

static void	put_to_stash(t_list **stash, char *buf, int readed_value)
{
	t_list	*new_node;
	t_list	*last;
	int		i;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	new_node->next = NULL;
	new_node->content = malloc(sizeof(char) * (readed_value + 1));
	if (new_node->content == NULL)
		return ;
	i = 0;
	while (buf[i] && i < (readed_value))
	{
		new_node->content[i] = buf[i];
		i++;
	}
	new_node->content[i] = '\0';
	if (*stash == NULL)
	{
		*stash = new_node;
		return ;
	}
	last = get_last(*stash);
	last->next = new_node;
}

static int	read_stash(int fd, t_list **stash)
{
	char	*buf;
	int		readed_value;

	readed_value = 1;
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buf == NULL)
		return (-1);
	while (!new_line(*stash))
	{
		readed_value = read(fd, buf, BUFFER_SIZE);
		if (readed_value == -1)
		{
			free(buf);
			free_stash(*stash);
			*stash = NULL;
			return (-1);
		}
		if (readed_value == 0)
			break ;
		buf[readed_value] = '\0';
		put_to_stash(stash, buf, readed_value);
	}
	free(buf);
	return (0);
}

char	*get_next_line(int fd)
{
	static t_list	*stash;
	char			*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (read_stash(fd, &stash) == -1)
		return (NULL);
	if (stash == NULL)
		return (NULL);
	extract_line(stash, &line);
	clean_stash(&stash);
	if (line[0] == '\0')
	{
		free_stash(stash);
		stash = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}
