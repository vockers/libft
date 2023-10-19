/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_utoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: vockers <vockers@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 14:45:01 by vockers       #+#    #+#                 */
/*   Updated: 2023/10/03 15:39:24 by vockers       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_utoa(unsigned int n)
{
	char		*a;
	static int	index = 0;
	static int	len = 1;

	index = 0;
	if (n / 10 != 0)
	{
		len++;
		a = ft_utoa(n / 10);
		if (!a)
			return (NULL);
		a[index++] = n % 10 + '0';
	}
	else
	{
		a = (char *)malloc(sizeof(char) * len + 1);
		if (!a)
			return (NULL);
		a[index++] = n % 10 + '0';
		a[len] = '\0';
		len = 1;
	}
	return (a);
}

// #include <stdio.h>
// #include <limits.h>

// int	main(void)
// {
// 	printf("%s\n", ft_utoa(0));
// 	printf("%s\n", ft_utoa(5));
// 	printf("%s\n", ft_utoa(25));
// 	printf("%s\n", ft_utoa(234));
// 	printf("%s\n", ft_utoa(INT_MAX));
// }