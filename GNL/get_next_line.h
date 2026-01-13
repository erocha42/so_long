/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-- <erocha--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:47:43 by erocha--          #+#    #+#             */
/*   Updated: 2026/01/06 19:10:38 by erocha--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

char		*get_next_line(int fd);
t_list		*get_last(t_list *lst);
int			new_line(t_list *stash);
void		create_line(char **line, t_list *stash);
int			ftt_strlen(const char *str);
void		free_stash(t_list *stash);

#endif
