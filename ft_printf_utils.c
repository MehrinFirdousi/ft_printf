#include "ft_printf.h"

int print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int print_str(void *str)
{
	int		len;

	len = ft_strlen(str);
	write(1, str, len);
	return (len);
}

int	ft_putnbr_base(long long int num, char *base)
{
	char			s_num[16];
	long long int	radix;
	int				num_len;
	int				i;

	i = 0;
	num_len = 1;
	radix = ft_strlen(base);
	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
		num_len++;
	}
	while (num > radix - 1)
	{
		s_num[i++] = base[num % radix];
		num /= radix;
		num_len++;
	}
	s_num[i++] = base[num];
	while (i)
		write(1, &s_num[--i], 1);
	return (num_len);
}

// int	ft_print_memory(void *mem)
// {
// 	long long int a = (long long int)mem;
// 	ft_putnbr_base(a, "0123456789abcdef");
// }