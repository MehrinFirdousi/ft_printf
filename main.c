#include "ft_printf.h"
#include <stdlib.h>

void test(char *str, ...)
{
	va_list list;
	va_start(list, str);
	unsigned int arg;
	arg = va_arg(list, unsigned int);
	printf("%u\n", arg);
	//printf("num = %s\n", arg);
}

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	int len1 = 0;
	int len2 = 0;

	int x = 1234;
	char *ptr = 0;
	len1 = ft_printf("%s\n", "e");
	//len2 = printf("%p\n", ptr);
	printf("%d, %d\n", len1, len2);
}