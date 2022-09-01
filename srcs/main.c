#include "../include/ft_printf.h"
#include <stdlib.h>
#include <limits.h>

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	int len1 = 0;
	int len2 = 0;

	int x = 1234;
	char *ptr = "sdfdsf";
	len1 = ft_printf("%s", 0);
	len2 = printf("%s", 0);
	printf("%d, %d\n", len1, len2);
	printf("\nlen = %d", len2);
}