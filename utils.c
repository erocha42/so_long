/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-- <erocha--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 17:17:03 by enzorolinux       #+#    #+#             */
/*   Updated: 2026/01/16 14:05:53 by erocha--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	clean_exit(t_data *data)
{
	int	i;
	
	if (data->win_ptr)
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	i = 0;
	while (i != (data->map.height))
		free(data->map.grid[i++]);
	free(data->map.grid);
	exit (0);
	return (1);
}