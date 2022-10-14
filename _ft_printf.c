/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ft_printf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 09:57:13 by chanheki          #+#    #+#             */
/*   Updated: 2022/10/14 09:57:28 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_s(char *string)
{
	int	index;

	index = 0;
	if (!string)
		string = "(null)";
	while (string[index])
		index++;
	return (write(1, string, index));
}

int	ft_put_n(int n)
{
	long long	num;
	char		temp[10];
	int			i;
	int			ret_num;

	if (n == 0)
		return (write(1, "0", 1));
	i = 0;
	ret_num = 0;
	num = (long long)n;
	if (n < 0)
	{
		ret_num += write(1, "-", 1);
		num *= -1;
	}
	while (num)
	{
		temp[i++] = num % 10 + '0';
		num = num / 10;
	}
	ret_num += i;
	while (i--)
		write(1, &temp[i], 1);
	return (ret_num);
}

int	ft_put_x(unsigned int n, char format)
{
	int		i;
	char	*table;
	char	temp[8];

	if (!n)
		return (write(1, "0", 1));
	if (format == 'x')
		table = "0123456789abcdef";
	else
		table = "0123456789ABCDEF";
	i = 0;
	while (n > 0)
	{
		temp[i++] = table[n % 16];
		n /= 16;
	}
	while (i--)
		n += write(1, &temp[i], 1);
	return (n);
}

int	ft_put_p(unsigned int *ptr)
{
	char			*table;
	char			temp[18];
	int				i;
	unsigned long	num;

	num = (unsigned long)ptr;
	table = "0123456789abcdef";
	i = 0;
	if (!ptr)
		temp[i++] = '0';
	while (num > 0)
	{
		temp[i++] = table[num % 16];
		num /= 16;
	}
	temp[i++] = 'x';
	temp[i++] = '0';
	while (i--)
		num += write(1, &temp[i], 1);
	return (num);
}

int	ft_put_u(unsigned int num)
{
	char		temp[10];
	int			i;
	int			ret_num;

	if (num == 0)
		return (write(1, "0", 1));
	i = 0;
	ret_num = 0;
	while (num)
	{
		temp[i++] = num % 10 + '0';
		num = num / 10;
	}
	ret_num += i;
	while (i--)
		write(1, &temp[i], 1);
	return (ret_num);
}
