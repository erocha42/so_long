/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-- <erocha--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 18:00:51 by enzorolinux       #+#    #+#             */
/*   Updated: 2026/01/21 13:07:00 by erocha--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	chars_checker(t_data *data, char **grid, int i, int j)
{
	if (grid[i][j] == 'E')
		data->map.e_count++;
	else if (grid[i][j] == 'C')
		data->map.c_count++;
	else if (grid[i][j] == 'P')
	{
		data->map.p_y = i;
		data->map.p_x = j;
		data->map.p_count++;
	}
	else if (grid[i][j] != '0' && grid[i][j] != '1')
		clean_exit(data, 1);
}

int	filepath_checker(char *filepath)
{
	int	len;

	len = ft_strlen(filepath);
	if (len < 4 || ft_strncmp(&filepath[len - 4], ".ber", 4))
		return (0);
	return (1);
}
