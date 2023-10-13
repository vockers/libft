/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: vockers <vockers@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 14:43:48 by vockers       #+#    #+#                 */
/*   Updated: 2023/10/03 16:20:59 by vockers       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putunbr_fd(unsigned int n, int fd)
{
	char			c;

	c = n % 10 + '0';
	n /= 10;
	if (n != 0)
		ft_putunbr_fd(n, fd);
	write(fd, &c, 1);
}

// #include <limits.h>
// int	main(void)
// {
// 	ft_putunbr_fd(0, 1);
// 	write(1, "\n", 1);
// 	ft_putunbr_fd(4, 1);
// 	write(1, "\n", 1);
// 	ft_putunbr_fd(25, 1);
// 	write(1, "\n", 1);
// 	ft_putunbr_fd(358, 1);
// 	write(1, "\n", 1);
// 	ft_putunbr_fd(1242564, 1);
// 	write(1, "\n", 1);
// 	ft_putunbr_fd(INT_MAX, 1);
// 	write(1, "\n", 1);
// 	return (0);
// }