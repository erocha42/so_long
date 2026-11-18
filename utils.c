/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-- <erocha--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 17:17:03 by enzorolinux       #+#    #+#             */
/*   Updated: 2026/01/22 18:43:26 by erocha--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_char(char c)
{
	if (c == '1' || c == '0' || c == 'P' || c == 'C' || c == 'E')
		return (1);
	return (0);
}

static void	destroy_images(t_data *data)
{
	if (data->coin_img)
		mlx_destroy_image(data->mlx_ptr, data->coin_img);
	if (data->exit_img)
		mlx_destroy_image(data->mlx_ptr, data->exit_img);
	if (data->floor_img)
		mlx_destroy_image(data->mlx_ptr, data->floor_img);
	if (data->player_img)
		mlx_destroy_image(data->mlx_ptr, data->player_img);
	if (data->wall_img)
		mlx_destroy_image(data->mlx_ptr, data->wall_img);
}

static void	error_code_handling(int error_code)
{
	if (error_code == 1)
		write(2, "Invalid map\n", 12);
	else if (error_code == 2)
		write(2, "Invalid walls\n", 14);
	else if (error_code == 3)
		write(2, "Invalid alloc or open\n", 22);
	else if (error_code == 4)
		write(2, "Invalid sprite(s)\n", 19);
}

int	clean_exit(t_data *data, int error_code)
{
	int	i;

	if (error_code)
		error_code_handling(error_code);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	destroy_images(data);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	i = 0;
	while (i < (data->map.height))
		free(data->map.grid[i++]);
	free(data->map.grid);
	exit (0);
	return (1);
}
