/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-- <erocha--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:06:32 by erocha--          #+#    #+#             */
/*   Updated: 2026/01/06 19:10:48 by erocha--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	new_line(t_list *stash)
{
	t_list	*last;
	int		i;

	i = 0;
	if (stash == NULL)
		return (0);
	last = get_last(stash);
	while (last->content[i])
	{
		if (last->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

t_list	*get_last(t_list *lst)
{
	t_list	*current;

	current = lst;
	while (current && current->next)
		current = current->next;
	return (current);
}

void	create_line(char **line, t_list *stash)
{
	int	i;
	int	len;
	int	found;

	len = 0;
	found = 0;
	while (stash && !found)
	{
		i = 0;
		while (stash->content[i] && stash->content[i] != '\n')
		{
			len++;
			i++;
		}
		if (stash->content[i] == '\n')
		{
			len++;
			found = 1;
		}
		stash = stash->next;
	}
	*line = malloc(sizeof(char) * (len + 1));
}

int	ftt_strlen(const char *str)
{
	int	len;

	len = 0;
	while (*(str++))
		len++;
	return (len);
}

void	free_stash(t_list *stash)
{
	t_list	*current;
	t_list	*next;

	current = stash;
	while (current)
	{
		free(current->content);
		next = current->next;
		free(current);
		current = next;
	}
}
