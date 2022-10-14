/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 09:57:22 by chanheki          #+#    #+#             */
/*   Updated: 2022/10/14 09:57:27 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *string, ...);
int	ft_put_c(char c);
int	ft_put_s(char *s);
int	ft_put_n(int n);
int	ft_put_x(unsigned int n, char format);
int	ft_put_p(unsigned int *ptr);
int	ft_put_u(unsigned int num);

#endif
