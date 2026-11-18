/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-- <erocha--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 09:09:00 by erocha--          #+#    #+#             */
/*   Updated: 2026/01/23 12:58:50 by erocha--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	data_init(t_data *data)
{
	data->map.grid = NULL;
	data->map.width = 0;
	data->map.height = 0;
	data->map.c_count = 0;
	data->map.e_count = 0;
	data->map.p_count = 0;
	data->map.p_x = 0;
	data->map.p_y = 0;
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->wall_img = NULL;
	data->floor_img = NULL;
	data->coin_img = NULL;
	data->player_img = NULL;
	data->exit_img = NULL;
	data->move_counter = 0;
}

static void	load_images(t_data *data)
{
	int		img_h;
	int		img_w;

	data->wall_img = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/sprites/wall.xpm", &img_w, &img_h);
	data->floor_img = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/sprites/floor.xpm", &img_w, &img_h);
	data->coin_img = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/sprites/coin-bag.xpm", &img_w, &img_h);
	data->player_img = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/sprites/player/front.xpm", &img_w, &img_h);
	data->exit_img = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/sprites/exit-closed.xpm", &img_w, &img_h);
	if (!data->wall_img || !data->floor_img || !data->coin_img
		|| !data->player_img || !data->exit_img)
		clean_exit(data, 4);
}

int	main(int argc, char **argv)
{
	t_data	data;

	data.filepath = argv[1];
	if (argc != 2 || !filepath_checker(data.filepath))
	{
		write(2, "Argument(s) invalid\n", 20);
		return (1);
	}
	data_init(&data);
	parsing(&data);
	if (data.map.width * 32 > 1920 || data.map.height * 32 > 1080)
		clean_exit(&data, 1);
	valid_walls(&data);
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (1);
	load_images(&data);
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.map.width * 32,
			data.map.height * 32, "So_long");
	if (data.win_ptr == NULL)
		return (1);
	events_handling(&data);
	mlx_loop(data.mlx_ptr);
	clean_exit(&data, 0);
}
