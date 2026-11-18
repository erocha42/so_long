/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-- <erocha--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:04:11 by erocha--          #+#    #+#             */
/*   Updated: 2025/11/04 17:47:37 by erocha--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_putnbr_u(unsigned int nb)
{
	if (nb <= 9)
	{
		nb = nb + 48;
		write(1, &nb, 1);
	}
	else
	{
		ft_putnbr_u(nb / 10);
		ft_putnbr_u(nb % 10);
	}
}

int	print_u(unsigned int var)
{
	int		len_var;

	len_var = 0;
	ft_putnbr_u(var);
	if (var == 0)
		return (1);
	while (var > 0)
	{
		var = var / 10;
		len_var++;
	}
	return (len_var);
}
