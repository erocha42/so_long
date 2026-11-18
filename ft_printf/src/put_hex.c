/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-- <erocha--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:58:08 by erocha--          #+#    #+#             */
/*   Updated: 2025/11/04 16:31:04 by erocha--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	put_hex(unsigned long long nbr, char	*base)
{
	if (nbr < 16)
		write(1, &base[nbr], 1);
	else
	{
		put_hex(nbr / 16, base);
		put_hex(nbr % 16, base);
	}
}
