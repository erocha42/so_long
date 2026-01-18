/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enzorolinux <enzorolinux@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:44:56 by erocha--          #+#    #+#             */
/*   Updated: 2026/01/18 15:18:32 by enzorolinux      ###   ########.fr       */
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
	int		p_x;
	int		p_y;
	int		e_count;
	int		c_count;
}			t_map;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*wall_img;
	void	*floor_img;
	void	*coin_img;
	void	*player_img;
	void	*exit_img;
	char	*filepath;
	t_map	map;
}			t_data;

void	parsing(t_data *data);
int		clean_exit(t_data *data);
void	chars_checker(t_data *data, char **grid, int i, int j);
int		filepath_checker(char *filepath);
int		valid_walls(t_data *data);
int     render(t_data *data);
int     valid_char(char c);
void	events_handling(t_data *data);