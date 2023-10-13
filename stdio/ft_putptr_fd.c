/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putptr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: vockers <vockers@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 14:43:48 by vockers       #+#    #+#                 */
/*   Updated: 2023/10/03 16:20:59 by vockers       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putptr_fd_recursive(uintptr_t ptr, char *hex, int fd)
{
	char	c;

	c = hex[ptr % 16];
	ptr /= 16;
	if (ptr != 0)
		ft_putptr_fd_recursive(ptr, hex, fd);
	write(fd, &c, 1);
}

void	ft_putptr_fd(void *ptr, int fd)
{
	char	hex[17];

	ft_strcpy(hex, "0123456789abcdef");
	write(fd, "0x", 2);
	ft_putptr_fd_recursive((uintptr_t)ptr, hex, fd);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int i = 42;
// 	ft_putptr_fd(&i, 1);
// 	write(1, "\n", 1);
// 	printf("%p\n", &i);
// 	return (0);
// }