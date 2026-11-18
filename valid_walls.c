/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-- <erocha--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 11:15:37 by erocha--          #+#    #+#             */
/*   Updated: 2026/01/23 12:53:08 by erocha--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**map_cpy(t_data *data)
{
	int		i;
	int		j;
	char	**gridcpy;

	gridcpy = malloc(data->map.height * sizeof(char *));
	if (!gridcpy)
		clean_exit(data, 3);
	i = 0;
	while (i < data->map.height)
	{
		j = 0;
		gridcpy[i] = malloc(data->map.width * sizeof(char));
		if (!gridcpy[i])
			clean_exit(data, 3);
		while (j < data->map.width)
		{
			gridcpy[i][j] = data->map.grid[i][j];
			j++;
		}
		i++;
	}
	return (gridcpy);
}

static void	flood_fill(char **grid, int y, int x)
{
	if (grid[y - 1][x] != '1' && grid[y - 1][x] != 'X' && grid[y - 1][x] != 'P')
	{
		grid[y - 1][x] = 'X';
		flood_fill(grid, y - 1, x);
	}
	if (grid[y][x + 1] != '1' && grid[y][x + 1] != 'X' && grid[y][x + 1] != 'P')
	{
		grid[y][x + 1] = 'X';
		flood_fill(grid, y, x + 1);
	}
	if (grid[y + 1][x] != '1' && grid[y + 1][x] != 'X' && grid[y + 1][x] != 'P')
	{
		grid[y + 1][x] = 'X';
		flood_fill(grid, y + 1, x);
	}
	if (grid[y][x - 1] != '1' && grid[y][x - 1] != 'X' && grid[y][x - 1] != 'P')
	{
		grid[y][x - 1] = 'X';
		flood_fill(grid, y, x - 1);
	}
	return ;
}

static void	free_grid(char **grid, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

void	valid_walls(t_data *data)
{
	int		i;
	int		j;
	char	**grid;

	grid = map_cpy(data);
	flood_fill(grid, data->map.p_y, data->map.p_x);
	i = 0;
	while (i < data->map.height)
	{
		j = 0;
		while (j < data->map.width)
		{
			if (grid[i][j] == 'C' || grid[i][j] == 'E')
			{
				free_grid(grid, data->map.height);
				clean_exit(data, 2);
			}
			j++;
		}
		i++;
	}
	free_grid(grid, data->map.height);
}
