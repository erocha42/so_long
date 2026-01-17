/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enzorolinux <enzorolinux@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 17:26:05 by enzorolinux       #+#    #+#             */
/*   Updated: 2026/01/17 21:29:16 by enzorolinux      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	render(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			if (data->map.grid[y][x] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->wall_img, x * 32, y * 32);
			else if (data->map.grid[y][x] == '0')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor_img, x * 32, y * 32);
			else if (data->map.grid[y][x] == 'P')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player_img, x * 32, y * 32);
			else if (data->map.grid[y][x] == 'C')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->coin_img, x * 32, y * 32);
			else if (data->map.grid[y][x] == 'E')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->exit_img, x * 32, y * 32);
			x++;
		}
		y++;
	}
	return (0);
}