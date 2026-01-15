/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enzorolinux <enzorolinux@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 18:00:51 by enzorolinux       #+#    #+#             */
/*   Updated: 2026/01/15 20:10:06 by enzorolinux      ###   ########.fr       */
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
		data->map.p_count++;
	else if (grid[i][j] != '0' && grid[i][j] != '1')
		clean_exit(data);
}

int	filename_checker(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 4 || ft_strncmp(&filename[len - 4], ".ber", 4))
		return (0);
	return (1);
}
