/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putunbr_base_fd.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: vockers <vockers@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 14:43:48 by vockers       #+#    #+#                 */
/*   Updated: 2023/10/03 16:20:59 by vockers       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	unsigned int	get_radix(char *base)
{
	unsigned int	radix;

	radix = 0;
	while (base[radix])
		radix++;
	return (radix);
}

static int	putunbr_base_recursive(
	unsigned int n,
	char *base,
	unsigned int radix,
	int fd
)
{
	char	c;
	int		len;

	len = 0;
	c = base[n % radix];
	n /= radix;
	if (n != 0)
		len = putunbr_base_recursive(n, base, radix, fd);
	write(fd, &c, 1);
	return (len + 1);
}

int	ft_putunbr_base_fd(unsigned int n, char *base, int fd)
{
	unsigned int	radix;

	radix = get_radix(base);
	if (radix <= 1)
		return (0);
	return (putunbr_base_recursive(n, base, radix, fd));
}

// #include <stdio.h>
// #include <limits.h>

// int	main(void)
// {
// 	printf ("\t%d\n", ft_putunbr_base_fd(255, "01", 1));
// 	printf("\n");

// 	printf ("\t%d\n", ft_putunbr_base_fd(0, "0123456789abcdef", 1));
// 	printf("\n");
// 	printf("%x\n\n", 0);

// 	printf ("\t%d\n", ft_putunbr_base_fd(4, "0123456789abcdef", 1));
// 	printf("\n");
// 	printf("%x\n\n", 4);

// 	printf ("\t%d\n", ft_putunbr_base_fd(25, "0123456789abcdef", 1));
// 	printf("\n");
// 	printf("%x\n\n", 25);

// 	printf ("\t%d\n", ft_putunbr_base_fd(50, "0123456789abcdef", 1));
// 	printf("\n");
// 	printf("%x\n\n", 50);

// 	printf ("\t%d\n", ft_putunbr_base_fd(358, "0123456789abcdef", 1));
// 	printf("\n");
// 	printf("%x\n\n", 358);

// 	printf ("\t%d\n", ft_putunbr_base_fd(1242564, "0123456789abcdef", 1));
// 	printf("\n");
// 	printf("%x\n\n", 1242564);

// 	printf ("\t%d\n", ft_putunbr_base_fd(INT_MAX, "0123456789abcdef", 1));
// 	printf("\n");
// 	printf("%x\n\n", INT_MAX);

// 	return (0);
// }