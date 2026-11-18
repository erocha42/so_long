/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-- <erocha--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:15:36 by erocha--          #+#    #+#             */
/*   Updated: 2026/01/19 14:05:17 by erocha--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(char const *format, ...);
int		print_c(char var);
int		print_d(int var);
int		print_p(unsigned long long var);
int		print_s(char *var);
int		print_u(unsigned int var);
int		print_x(unsigned int var);
int		print_x_upp(unsigned int var);
void	put_hex(unsigned long long nbr, char *base);

#endif
