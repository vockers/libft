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

static int	ft_putptr_fd_recursive(uintptr_t ptr, char *hex, int fd)
{
	char	c;
	int		len;

	len = 0;
	c = hex[ptr % 16];
	ptr /= 16;
	if (ptr != 0)
		len = ft_putptr_fd_recursive(ptr, hex, fd);
	write(fd, &c, 1);
	return (len + 1);
}

int	ft_putptr_fd(void *ptr, int fd)
{
	char	hex[17];

	if (ptr == NULL)
	{
		write(fd, "(nil)", 5);
		return (5);
	}
	ft_strcpy(hex, "0123456789abcdef");
	write(fd, "0x", 2);
	return (ft_putptr_fd_recursive((uintptr_t)ptr, hex, fd) + 2);
}

// #include <stdio.h>

// int	main(void)
// {
// 	// int i = 42;
// 	int j = ft_putptr_fd(NULL, 1);
// 	printf("\t%d\n", j);
// 	printf("%p\t%d\n", NULL, j);
// 	return (0);
// }