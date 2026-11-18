/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x_upp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-- <erocha--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:06:23 by erocha--          #+#    #+#             */
/*   Updated: 2025/11/04 17:49:29 by erocha--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_x_upp(unsigned int var)
{
	int	len_var;

	put_hex(var, "0123456789ABCDEF");
	len_var = 0;
	if (var == 0)
		return (1);
	while (var > 0)
	{
		var = var / 16;
		len_var++;
	}
	return (len_var);
}
