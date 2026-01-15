/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enzorolinux <enzorolinux@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:44:56 by erocha--          #+#    #+#             */
/*   Updated: 2026/01/15 20:11:27 by enzorolinux      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "stdlib.h"
#include "fcntl.h"
#include "GNL/get_next_line.h"
#include "libft/libft.h"

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		p_count;
	int		e_count;
	int		c_count;
}			t_map;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	*filename;
	t_map	map;
}			t_data;

void	parsing(t_data *data);
void	clean_exit(t_data *data);
void	chars_checker(t_data *data, char **grid, int i, int j);
int	filename_checker(char *filename);