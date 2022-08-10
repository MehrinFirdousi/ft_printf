/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfirdous <mfirdous@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 09:57:05 by mfirdous          #+#    #+#             */
/*   Updated: 2022/08/09 09:57:05 by mfirdous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_var(char format, va_list ap)
{
	if (format == 'c')
		return (print_char(va_arg(ap, int)));
	if (format == 's')
		return (print_str(va_arg(ap, void*)));
	if (format == 'p')
	{
		write(1, "0x", 2);
		return (ft_putnbr_base(va_arg(ap, long long int), "0123456789abcdef") + 2);
	}
	if (format == 'd' || format == 'i')
		return (ft_putnbr_base(va_arg(ap, int), "0123456789"));
	if (format == 'u')
		return (ft_putnbr_base(va_arg(ap, unsigned int), "0123456789"));
	if (format == 'x')
		return (ft_putnbr_base(va_arg(ap, unsigned int), "0123456789abcdef"));
	if (format == 'X')
		return (ft_putnbr_base(va_arg(ap, unsigned int), "0123456789ABCDEF"));
	if (format == '%')
		return (print_char('%'));
	return (0);
}


int	ft_printf(const char *s, ...)
{
	int		i;
	char	format;
	int		len;
	va_list ap;

	i = -1;
	len = 0;
	va_start(ap, s);
	while (s[++i])
	{
		if (s[i] == '%')
		{
			format = s[++i];
			len += print_var(format, ap);
		}
		else
		{
			write(1, &s[i], 1);
			len++;
		}
	}
	va_end(ap);
	return (len);
}