#include "ft_printf.h"

static int	ft_check_format(const char *sentense, va_list ap)
{
	int	returnLength;
	
	returnLength = 0;
	if (*sentense == 'c')
		returnLength += ft_put_c((char)(va_arg(ap, int)));
	else if (*sentense == 's')
		returnLength += ft_put_s((char *)(va_arg(ap, int)));
	else if (*sentense == 'p')
		returnLength += ft_put_p((unsigned int)(va_arg(ap, int)));
	else if (*sentense == 'd' || *sentense == 'i')
		returnLength += ft_put_n((int)(va_arg(ap, int)));
	else if (*sentense == 'u')
		returnLength += ft_put_u((unsigned int)(va_arg(ap, int)));
	else if (*sentense == 'x' || *sentense == 'X')
		returnLength += ft_put_x((unsigned int)(va_arg(ap, int)), sentense);
	else if (*sentense == '%')
		returnLength += ft_put_c('%');
	return (returnLength);
}

int ft_printf(const char *sentense, ...)
{
	va_list	ap;
	size_t	checkError;
	int		returnLength;
	
	returnLength = 0;
	va_start(ap, sentense);
	while (*sentense)
	{
		if (*sentense == '%') {
			sentense++;
			returnLength += ft_check_format(sentense, ap);
		} else {
			checkError = write(1, &(*sentense), 1);
			if (checkError == -1)
				return (0);
			returnLength += checkError;
		}
		sentense++;
	}
	va_end(ap);
	return (returnLength);
}

int	ft_put_c(char c)
{
	return (write(1, &c, 1));
}
