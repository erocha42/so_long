/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enzorolinux <enzorolinux@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 14:54:03 by enzorolinux       #+#    #+#             */
/*   Updated: 2026/01/18 17:29:37 by enzorolinux      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void move_player(t_data *data, int new_x, int new_y)
{
	if (data->map.grid[new_y][new_x] == '0' || data->map.grid[new_y][new_x] == 'C'
		|| data->map.grid[new_y][new_x] == 'E')
	{
		if (data->map.grid[new_y][new_x] == 'C')
			data->map.c_count--;
		if (data->map.grid[new_y][new_x] == 'E' && data->map.c_count == 0)
			clean_exit(data);
		if (data->map.grid[data->map.p_y][data->map.p_x] != 'E')
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor_img, data->map.p_x * 32, data->map.p_y * 32);
			data->map.grid[data->map.p_y][data->map.p_x] = '0';
		}
		else
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->exit_img, data->map.p_x * 32, data->map.p_y * 32);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player_img, new_x * 32, new_y * 32);
		data->map.p_x = new_x;
		data->map.p_y = new_y;
	}
}

static int key_handling(int keycode, t_data *data)
{
	if (keycode == 65307)
		clean_exit(data);
	else if (keycode == 119)
		move_player(data, data->map.p_x, data->map.p_y - 1);
	else if (keycode == 115)
		move_player(data, data->map.p_x, data->map.p_y + 1);
	else if (keycode == 97)
		move_player(data, data->map.p_x - 1, data->map.p_y);
	else if (keycode == 100)
		move_player(data, data->map.p_x + 1, data->map.p_y);
	return (1);
}

void	events_handling(t_data *data)
{
	mlx_hook(data->win_ptr, 17, 0, clean_exit, data);
	mlx_hook(data->win_ptr, 12, (1L << 15), render, data);
	mlx_hook(data->win_ptr, 2, (1L << 0), key_handling, data);
}