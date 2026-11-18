/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-- <erocha--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:02:58 by erocha--          #+#    #+#             */
/*   Updated: 2025/11/04 17:42:43 by erocha--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_d(int var)
{
	int		len_var;

	len_var = 0;
	ft_putnbr_fd(var, 1);
	if (var == (-2147483648))
		return (11);
	if (var < 1)
	{
		len_var++;
		var = var * -1;
	}
	while (var > 0)
	{
		var = var / 10;
		len_var++;
	}
	return (len_var);
}
