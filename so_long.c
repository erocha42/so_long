/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enzorolinux <enzorolinux@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 09:09:00 by erocha--          #+#    #+#             */
/*   Updated: 2026/01/15 20:12:16 by enzorolinux      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int stop()
{
    exit(0);
    return (1);
}

static void	data_init(t_data *data)
{
	data->map.grid = NULL;
    data->map.width = 0;
    data->map.height = 0;
    data->map.c_count = 0;
    data->map.e_count = 0;
    data->map.p_count = 0;
}

int	main(int argc, char **argv)
{
	t_data	data;

	data.filename = argv[1];
	if (argc != 2 || !filename_checker(data.filename))
		return (1);
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 800, 600, "So_long - Test Linux");
	if (data.win_ptr == NULL)
		return (1);
	data_init(&data);
	parsing(&data);
	mlx_hook(data.win_ptr, 17, 0, stop, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
