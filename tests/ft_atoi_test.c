#include "libft.h"

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define ANSI_COLOR_RED		"\x1b[31m"
#define ANSI_COLOR_GREEN	"\x1b[32m"
#define ANSI_COLOR_YELLOW	"\x1b[33m"
#define ANSI_COLOR_BLUE		"\x1b[34m"
#define ANSI_COLOR_MAGENTA	"\x1b[35m"
#define ANSI_COLOR_CYAN		"\x1b[36m"
#define ANSI_COLOR_WHITE	"\x1b[0m"

void	test(const char *arg)
{
	int		ft_res	= ft_atoi(arg);
	int		std_res	= atoi(arg);
	
	if (ft_res != std_res)
		printf(ANSI_COLOR_RED "KO" ANSI_COLOR_WHITE ":\t%d\n\t%d", ft_res, std_res);	
	else
		printf(ANSI_COLOR_GREEN "OK" ANSI_COLOR_WHITE "\n");
}

int	main()
{
	/*  1 */ test("1");
	/*  2 */ test("a1");
	/*  3 */ test("--1");
	/*  4 */ test("++1");
	/*  5 */ test("+1");
	/*  6 */ test("-1");
	/*  7 */ test("0");
	/*  8 */ test("+42test");
	/*  9 */ test("+101");
	/* 10 */ test("2147483647");
	/* 11 */ test("-2147483648");
	/* 12 */ test("-+42");
	/* 13 */ test("+-42");
	/* 14 */ test("+");
	/* 15 */ test("-");
	return 0;
}