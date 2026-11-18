/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-- <erocha--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 10:16:13 by erocha--          #+#    #+#             */
/*   Updated: 2025/11/04 16:53:57 by erocha--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	print_param(char type, va_list args)
{
	int	result;

	result = 0;
	if (type == 'c')
		result = print_c(va_arg(args, int));
	if (type == 's')
		result = print_s(va_arg(args, char *));
	if (type == 'p')
		result = print_p((unsigned long long)va_arg(args, void *));
	if (type == 'd' || type == 'i')
		result = print_d(va_arg(args, int));
	if (type == 'u')
		result = print_u(va_arg(args, unsigned int));
	if (type == 'x')
		result = print_x((unsigned int)va_arg(args, int));
	if (type == 'X')
		result = print_x_upp(va_arg(args, unsigned int));
	if (type == '%')
		result = print_c('%');
	return (result);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	if (!format)
		return (-1);
	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += print_param(format[i + 1], args);
			i++;
		}
		else
		{
			write(1, &format[i], 1);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}
