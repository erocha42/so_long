/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-- <erocha--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:43:53 by erocha--          #+#    #+#             */
/*   Updated: 2026/01/13 19:07:02 by erocha--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	char_check(char c, t_map *map)
{
	int	i;

	i = 0;
	if (c == 'e')
		(*map).e_count++;
	else if (c == 'p')
		(*map).p_count++;
	else if (c == 'c')
		(*map).c_count++;
	if ((*map).c_count < 1 || (*map).p_count != 1 || (*map).e_count != 1)
		return (0);
	i++;
	return (1);
}

static int	set_map_size(int file, t_map *map)
{
	char	*line;
	int		i;
	int		j;
	
	line = get_next_line(file);
	(*map).width = ft_strlen(line);
	i = 0;
	j = 0;
	while (line[0] != '\0')
	{
		j = 0;
		while (line[j])
		{
			if (!char_check(line[j], map))
				return (0);
			j++;
		}
		line = get_next_line(file);
		if (j > (*map).width)
			return (0);
		i++;
	}
	(*map).height = i;
	return (1);
}

void	parsing(t_map *map)
{
	t_map	map;
	int		fd;
	int		i;
    
	fd = open("map.ber", O_RDONLY);
	set_map_size(fd, map);
	(*map).grid = malloc((*map).height * sizeof(char*));
	(*map).grid[0] = get_next_line(fd);
	i = 0;
	while ((*map).height != i)
	{
		(*map).grid[i] = malloc((*map).width * sizeof(char));
		(*map).grid[i] = get_next_line(fd);
		i++;
	}
}
