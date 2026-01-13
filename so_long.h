/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-- <erocha--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:44:56 by erocha--          #+#    #+#             */
/*   Updated: 2026/01/13 18:49:44 by erocha--         ###   ########.fr       */
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
	int 	value;
	t_map	map;
}			t_data;

void	parsing(t_map *data);