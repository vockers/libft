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

static void	reverse_str(char *s, int len)
{
	int		start;
	int		end;
	char	tmp;

	start = 0;
	end = len - 1;
	while (start < end)
	{
		tmp = s[start];
		s[start] = s[end];
		s[end] = tmp;
		start++;
		end--;
	}
}

char	*ft_itoa(int n)
{
	char			*new;
	unsigned int	un;
	int				len;
	char			buffer[11];

	if (n < 0)
		un = (unsigned int)n * -1;
	else
		un = n;
	len = 0;
	while (un > 0)
	{
		buffer[len++] = (un % 10) + '0';
		un /= 10;
	}
	if (n < 0)
		buffer[len++] = '-';
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	reverse_str(buffer, len);
	ft_memcpy(new, buffer, len);
	new[len] = '\0';
	return (new);
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