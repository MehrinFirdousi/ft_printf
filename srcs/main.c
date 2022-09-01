#include "../include/ft_printf.h"
#include <stdlib.h>
#include <limits.h>

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
	char *ptr = "sdfdsf";
	len1 = ft_printf(" %p %p ", 0, 0);
	len2 = printf(" %p %p ", 0, 0);
	printf("%d, %d\n", len1, len2);
	printf("\nlen = %d", len2);
}