/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-- <erocha--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:44:56 by erocha--          #+#    #+#             */
/*   Updated: 2026/01/23 12:58:21 by erocha--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "ft_printf/ft_printf.h"
#include "stdlib.h"
#include "fcntl.h"
#include "GNL/get_next_line.h"
#include "libft/libft.h"

#define ESC 65307

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
	int		move_counter;
	t_map	map;
}			t_data;

void	parsing(t_data *data);
int		clean_exit(t_data *data, int error_code);
void	chars_checker(t_data *data, char **grid, int i, int j);
int		filepath_checker(char *filepath);
void	valid_walls(t_data *data);
int		render(t_data *data);
int		valid_char(char c);
void	events_handling(t_data *data);