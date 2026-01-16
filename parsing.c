/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-- <erocha--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:43:53 by erocha--          #+#    #+#             */
/*   Updated: 2026/01/16 15:20:09 by erocha--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void sanitize_grid(t_data *data)
{
    int i;
	int j;

	i = 0;
    while (i < data->map.height)
    {
		j = 0;
        while (data->map.grid[i][j])
        {
			if (data->map.grid[i][j] == '\n')
			{
				data->map.grid[i][j] = '\0';
				break;
			}
			j++;
		}
        i++;
    }
}

static int border_map_checker(t_map map)
{
	int i;

	i = 0;
	while (map.grid[0][i])
	{
		if (map.grid[0][i] != '1' || i > map.width)
			return (0);
		i++;
	}
	i = 0;
	while (map.grid[map.height - 1][i])
	{
		if (map.grid[map.height - 1][i] != '1' || i > map.width)
			return (0);
		i++;
	}
	i = 0;
	while (map.height - 1 != i)
	{
		if (map.grid[i][0] != '1' || map.grid[i][map.width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	map_checker(t_data *data, char **grid)
{
	int i;
	int j;

	i = 0;
	while (i < data->map.height)
	{
		j = 0;
		while (grid[i][j])
		{
			chars_checker(data, grid, i, j);
			j++;
		}
		if (j != data->map.width)
			return (0);
		i++;
	}
	if (data->map.e_count != 1 || data->map.c_count < 1 || data->map.p_count != 1)
		return (0);
	return (1);
}

static void	set_map_size(t_data *data)
{
	char	*line;
	int		file;
	
	file = open(data->filename, O_RDONLY);
		if (file < 0)
    		clean_exit(data);
	line = get_next_line(file);
	if (!line)
		clean_exit(data);
	data->map.width = ft_strlen(line) - 1;
	while (line)
	{
		free(line);
		data->map.height++;
		line = get_next_line(file);
	}
	close(file);
}

void	parsing(t_data *data)
{
	int		fd;
	int		i;
	char	*temp;

	set_map_size(data);
	fd = open(data->filename, O_RDONLY);
	data->map.grid = malloc((data->map.height) * sizeof(char*));
	if (!data->map.grid)
	{
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		close (fd);
		exit (0);
	}
	i = 0;
	while (data->map.height != i)
	{
		data->map.grid[i] = get_next_line(fd);
		i++;
	}
	temp = get_next_line(fd);
	free(temp);
	close(fd);
	sanitize_grid(data);
	if (!map_checker(data, data->map.grid) || !border_map_checker(data->map)
		|| !valid_walls(data))
		clean_exit(data);
}
