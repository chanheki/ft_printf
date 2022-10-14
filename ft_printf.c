/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 09:57:19 by chanheki          #+#    #+#             */
/*   Updated: 2022/10/14 10:04:08 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_format(const char *sentense, va_list ap)
{
	int	return_length;

	return_length = 0;
	if (*sentense == 'c')
		return_length += ft_put_c((char)(va_arg(ap, int)));
	else if (*sentense == 's')
		return_length += ft_put_s((char *)(va_arg(ap, char *)));
	else if (*sentense == 'p')
		return_length += ft_put_p((va_arg(ap, unsigned int *)));
	else if (*sentense == 'd' || *sentense == 'i')
		return_length += ft_put_n((int)(va_arg(ap, int)));
	else if (*sentense == 'u')
		return_length += ft_put_u((unsigned int)(va_arg(ap, int)));
	else if (*sentense == 'x' || *sentense == 'X')
		return_length += ft_put_x((unsigned int)(va_arg(ap, int)), *sentense);
	else if (*sentense == '%')
		return_length += ft_put_c('%');
	return (return_length);
}

int	ft_printf(const char *sentense, ...)
{
	va_list	ap;
	int		return_length;

	return_length = 0;
	va_start(ap, sentense);
	while (*sentense)
	{
		if (*sentense == '%')
		{
			sentense++;
			return_length += ft_check_format(sentense, ap);
		}
		else
		{
			return_length += ft_put_c(*sentense);
		}
		sentense++;
	}
	va_end(ap);
	return (return_length);
}

int	ft_put_c(char c)
{
	return (write(1, &c, 1));
}
