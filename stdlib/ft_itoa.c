/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: vockers <vockers@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 14:45:01 by vockers       #+#    #+#                 */
/*   Updated: 2023/10/03 15:39:24 by vockers       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*itoa_recursive(unsigned int n, int index, int *len)
{
	char	*a;
	char	d;

	d = n % 10 + '0';
	n /= 10;
	if (n != 0)
	{
		a = itoa_recursive(n, index + 1, len);
		if (!a)
			return (NULL);
		a[(*len)++] = d;
	}
	else
	{
		a = (char *)malloc(sizeof(char) * (index + 2));
		if (!a)
			return (NULL);
		a[(*len)++] = d;
		a[index + 1] = '\0';
	}
	return (a);
}

char	*ft_itoa(int n)
{
	char	*a;
	int		len;

	len = 0;
	if (n < 0)
	{
		len++;
		a = itoa_recursive((unsigned int)-n, 1, &len);
		if (!a)
			return (NULL);
		a[0] = '-';
	}
	else
		a = itoa_recursive((unsigned int)n, 0, &len);
	return (a);
}

// #include <stdio.h>
// #include <limits.h>

// int	main(void)
// {
// 	printf("%s\n", ft_itoa(0));
// 	printf("%s\n", ft_itoa(5));
// 	printf("%s\n", ft_itoa(25));
// 	printf("%s\n", ft_itoa(234));
// 	printf("%s\n\n", ft_itoa(INT_MAX));

// 	printf("%s\n", ft_itoa(-0));
// 	printf("%s\n", ft_itoa(-5));
// 	printf("%s\n", ft_itoa(-25));
// 	printf("%s\n", ft_itoa(-234));
// 	printf("%s\n", ft_itoa(INT_MIN));
// }