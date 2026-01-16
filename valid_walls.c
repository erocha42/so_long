/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-- <erocha--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 11:15:37 by erocha--          #+#    #+#             */
/*   Updated: 2026/01/16 15:21:48 by erocha--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**map_cpy(t_data *data)
{
	int		i;
	int		j;
	char	**gridcpy;
	
	gridcpy = malloc(data->map.height * sizeof(char*));
	i = 0;
	while (i < data->map.height)
	{
		j = 0;
		gridcpy[i] = malloc(data->map.width * sizeof(char));
		while (j < data->map.width)
		{
			gridcpy[i][j] = data->map.grid[i][j];
			j++;
		}
		i++;
	}
	return (gridcpy);
}

static void	flood_fill(char **grid, int x, int y)
{
	if (grid[x-1][y] != '1' && grid[x-1][y] != 'X' && grid[x-1][y] != 'P')
	{
		grid[x-1][y] = 'X';
		flood_fill(grid, x-1, y);
	}
	if (grid[x][y+1] != '1' && grid[x][y+1] != 'X' && grid[x][y+1] != 'P')
	{
		grid[x][y+1] = 'X';
		flood_fill(grid, x, y+1);
	}
	if (grid[x+1][y] != '1' && grid[x+1][y] != 'X' && grid[x+1][y] != 'P')
	{
		grid[x+1][y] = 'X';
		flood_fill(grid, x+1, y);
	}
	if (grid[x][y-1] != '1' && grid[x][y-1] != 'X' && grid[x][y-1] != 'P')
	{
		grid[x][y-1] = 'X';
		flood_fill(grid, x, y-1);
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

int	valid_walls(t_data *data)
{
	int		i;
	int		j;
	char	**grid;

	grid = map_cpy(data);
	if (!grid)
		clean_exit(data);
	flood_fill(grid, data->map.p_x, data->map.p_y);
	i = 0;
	while (i < data->map.height)
	{
		j = 0;
		while (j < data->map.width)
		{
			if (grid[i][j] == 'C' || grid[i][j] == 'E')
			{
				free_grid(grid, data->map.height);
				return (0);
			}
			j++;
		}
		i++;
	}
	free_grid(grid, data->map.height);
	return (1);
}
