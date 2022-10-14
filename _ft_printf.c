/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ft_printf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 09:57:13 by chanheki          #+#    #+#             */
/*   Updated: 2022/10/14 15:02:54 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_s(char *s)
{
	int	index;

	index = 0;
	if (!s)
		s = "(null)";
	while (s[index])
		index++;
	return (write(1, s, index));
}

int	ft_put_n(int n)
{
	long	num;
	char	storage[10];
	int		index;
	int		return_length;

	if (n == 0)
		return (write(1, "0", 1));
	index = 0;
	return_length = 0;
	num = (long)n;
	if (n < 0)
	{
		return_length += write(1, "-", 1);
		num *= -1;
	}
	while (num)
	{
		storage[index++] = num % 10 + '0';
		num = num / 10;
	}
	while (index--)
		return_length += write(1, &storage[index], 1);
	return (return_length);
}

int	ft_put_x(unsigned int n, char format)
{
	int		index;
	char	*table;
	char	storage[8];
	int		return_length;

	return_length = 0;
	if (!n)
		return (write(1, "0", 1));
	if (format == 'x')
		table = "0123456789abcdef";
	else
		table = "0123456789ABCDEF";
	index = 0;
	while (n > 0)
	{
		storage[index++] = table[n % 16];
		n /= 16;
	}
	while (index--)
		return_length += write(1, &storage[index], 1);
	return (return_length);
}

int	ft_put_p(unsigned int *ptr)
{
	char			*table;
	char			storage[18];
	int				index;
	unsigned long	num;
	int				return_length;

	return_length = 0;
	num = (unsigned long)ptr;
	table = "0123456789abcdef";
	index = 0;
	if (!ptr)
		storage[index++] = '0';
	while (num > 0)
	{
		storage[index++] = table[num % 16];
		num /= 16;
	}
	storage[index++] = 'x';
	storage[index++] = '0';
	while (index--)
		return_length += write(1, &storage[index], 1);
	return (return_length);
}

int	ft_put_u(unsigned int num)
{
	char		storage[10];
	int			index;
	int			return_length;

	if (num == 0)
		return (write(1, "0", 1));
	index = 0;
	return_length = 0;
	while (num)
	{
		storage[index++] = num % 10 + '0';
		num = num / 10;
	}
	while (index--)
		return_length += write(1, &storage[index], 1);
	return (return_length);
}
