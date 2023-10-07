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

static int	n_len(int n)
{
	int				len;
	unsigned int	un;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
	{
		un = (unsigned int)n * -1;
		len++;
	}
	else
		un = n;
	while (un > 0)
	{
		un /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*a;
	unsigned int	un;
	int				len;

	len = n_len(n);
	a = (char *)malloc(sizeof(char) * (len + 1));
	if (!a)
		return (NULL);
	if (n < 0)
		un = (unsigned int)n * -1;
	else
		un = n;
	a[len] = '\0';
	while (len > 0)
	{
		a[--len] = (un % 10) + '0';
		un /= 10;
	}
	if (n < 0)
		a[len] = '-';
	return (a);
}

// #include <stdio.h>
// #include <limits.h>

// int	main(void)
// {
// 	printf("%s\n", ft_itoa(5));
// 	printf("%s\n", ft_itoa(25));
// 	printf("%s\n", ft_itoa(234));
// 	printf("%s\n\n", ft_itoa(INT_MAX));

// 	printf("%s\n", ft_itoa(-5));
// 	printf("%s\n", ft_itoa(-25));
// 	printf("%s\n", ft_itoa(-234));
// 	printf("%s\n", ft_itoa(INT_MIN));
// }