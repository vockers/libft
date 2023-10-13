/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_utoa_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: vockers <vockers@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 14:45:01 by vockers       #+#    #+#                 */
/*   Updated: 2023/10/03 15:39:24 by vockers       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static	unsigned int	get_radix(char *base)
{
	unsigned int	radix;

	radix = 0;
	while (base[radix])
		radix++;
	return (radix);
}

static char	*utoa_base_radix(unsigned int n, char *base, int radix)
{
	char		*a;
	static int	index = 0;
	static int	len = 1;

	index = 0;
	if (n / radix != 0)
	{
		len++;
		a = utoa_base_radix(n / radix, base, radix);
		if (!a)
			return (NULL);
		a[index++] = base[n % radix];
	}
	else
	{
		a = (char *)malloc(sizeof(char) * (len + 1));
		if (!a)
			return (NULL);
		a[index++] = base[n % radix];
		a[len] = '\0';
		len = 1;
	}
	return (a);
}

char	*ft_utoa_base(unsigned int n, char *base)
{
	int		radix;

	radix = get_radix(base);
	if (radix <= 1)
		return (NULL);
	return (utoa_base_radix(n, base, radix));
}

// #include <limits.h>

// int	main(void)
// {
// 	printf("%s\n%x\n\n", ft_utoa_base(0, "0123456789abcdef"), 0);
// 	printf("%s\n%x\n\n", ft_utoa_base(5, "0123456789abcdef"), 5);
// 	printf("%s\n%x\n\n", ft_utoa_base(25, "0123456789abcdef"), 25);
// 	printf("%s\n%x\n\n", ft_utoa_base(234, "0123456789abcdef"), 234);
// 	printf("%s\n%x\n\n", ft_utoa_base(62321, "0123456789abcdef"), 62321);
// 	printf("%s\n%x\n\n", ft_utoa_base(UINT_MAX, "0123456789abcdef"), UINT_MAX);
// }