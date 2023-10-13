#include <criterion/criterion.h>
#include <stdlib.h>

#include "libft.h"

int test_atoi(const char *arg) 
{
	return ft_atoi(arg) == atoi(arg);
}

Test(atoi_tests, test1) { cr_expect(test_atoi("1")); }

Test(atoi_tests, test2) { cr_expect(test_atoi("a1")); }

Test(atoi_tests, test3) { cr_expect(test_atoi("--1")); }

Test(atoi_tests, test4) { cr_expect(test_atoi("++1")); }

Test(atoi_tests, test5) { cr_expect(test_atoi("+1")); }

Test(atoi_tests, test6) { cr_expect(test_atoi("-1")); }

Test(atoi_tests, test7) { cr_expect(test_atoi("0")); }

Test(atoi_tests, test8) { cr_expect(test_atoi("+42test")); }

Test(atoi_tests, test9) { cr_expect(test_atoi("+101")); }

Test(atoi_tests, test10) { cr_expect(test_atoi("2147483647")); }

Test(atoi_tests, test11) { cr_expect(test_atoi("-2147483648")); }

Test(atoi_tests, test12) { cr_expect(test_atoi("-+42")); }

Test(atoi_tests, test13) { cr_expect(test_atoi("+-42")); }

Test(atoi_tests, test14) { cr_expect(test_atoi("+")); }

Test(atoi_tests, test15) { cr_expect(test_atoi("-")); }