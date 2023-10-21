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

	if (!base)
		return (0);
	radix = 0;
	while (base[radix])
		radix++;
	return (radix);
}

static int	count_digits(unsigned int num, int radix)
{
	int	count;

	if (num == 0)
		return (1);
	count = 0;
	while (num > 0)
	{
		count++;
		num /= radix;
	}
	return (count);
}

char	*ft_utoa_base(unsigned int num, char *base)
{
	char			*ret;
	int				len;
	int				radix;

	radix = get_radix(base);
	if (radix <= 1)
		return (0);
	len = count_digits(num, radix);
	ret = (char *)ft_calloc(len + 1, sizeof(char));
	if (!ret)
		return (NULL);
	ret[len] = '\0';
	if (num == 0)
		ret[0] = base[0];
	while (num > 0)
	{
		ret[--len] = base[num % radix];
		num /= radix;
	}
	return (ret);
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
// 	printf("%s\n", ft_utoa_base(254, "01"));
// }