/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-- <erocha--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:01:49 by erocha--          #+#    #+#             */
/*   Updated: 2025/11/04 16:31:10 by erocha--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_p(unsigned long long var)
{
	int	len_var;

	if (var == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	put_hex(var, "0123456789abcdef");
	len_var = 2;
	while (var > 0)
	{
		var = var / 16;
		len_var++;
	}
	return (len_var);
}
