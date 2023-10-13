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

static void	putunbr_base_recursive(
	unsigned int n,
	char *base,
	unsigned int radix,
	int fd
)
{
	char	c;

	c = base[n % radix];
	n /= radix;
	if (n != 0)
		putunbr_base_recursive(n, base, radix, fd);
	write(fd, &c, 1);
}

void	ft_putunbr_base_fd(unsigned int n, char *base, int fd)
{
	unsigned int	radix;

	radix = get_radix(base);
	if (radix <= 1)
		return ;
	putunbr_base_recursive(n, base, radix, fd);
}

// #include <stdio.h>
// #include <limits.h>

// int	main(void)
// {
// 	ft_putunbr_base_fd(0, "0123456789abcdef", 1);
// 	write(1, "\n", 1);
// 	printf("%x\n\n", 0);

// 	ft_putunbr_base_fd(4, "0123456789abcdef", 1);
// 	write(1, "\n", 1);
// 	printf("%x\n\n", 4);

// 	ft_putunbr_base_fd(25, "0123456789abcdef", 1);
// 	write(1, "\n", 1);
// 	printf("%x\n\n", 25);

// 	ft_putunbr_base_fd(50, "0123456789abcdef", 1);
// 	write(1, "\n", 1);
// 	printf("%x\n\n", 50);

// 	ft_putunbr_base_fd(358, "0123456789abcdef", 1);
// 	write(1, "\n", 1);
// 	printf("%x\n\n", 358);

// 	ft_putunbr_base_fd(1242564, "0123456789abcdef", 1);
// 	write(1, "\n", 1);
// 	printf("%x\n\n", 1242564);

// 	ft_putunbr_base_fd(INT_MAX, "0123456789abcdef", 1);
// 	write(1, "\n", 1);
// 	printf("%x\n\n", INT_MAX);

// 	return (0);
// }