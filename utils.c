/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enzorolinux <enzorolinux@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 17:17:03 by enzorolinux       #+#    #+#             */
/*   Updated: 2026/01/15 17:32:08 by enzorolinux      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_exit(t_data *data)
{
	int	i;
	
	mlx_clear_window(data->mlx_ptr, (data->win_ptr));
	i = 0;
	while (i != (data->map.height))
		free(data->map.grid[i++]);
	free(data->map.grid);
	exit (0);
}