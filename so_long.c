/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-- <erocha--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 09:09:00 by erocha--          #+#    #+#             */
/*   Updated: 2026/01/13 18:59:17 by erocha--         ###   ########.fr       */
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
    (*data).value = 0;
    (*data).map.width = 0;
    (*data).map.height = 0;
    (*data).map.c_count = 0;
    (*data).map.e_count = 0;
    (*data).map.p_count = 0;
}

int	main(void)
{
	t_data	data;
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		return (1);
	win_ptr = mlx_new_window(mlx_ptr, 800, 600, "So_long - Test Linux");
	if (win_ptr == NULL)
	{
		free(mlx_ptr);
		return (1);
	}
	data_init(&data);
	parsing(&data.map);
	mlx_hook(win_ptr, 17, 0, stop, &data);
	mlx_loop(mlx_ptr);
	return (0);
}
