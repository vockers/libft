/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vockers <vockers@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 14:43:11 by vockers       #+#    #+#                 */
/*   Updated: 2023/10/03 16:32:45 by vockers       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int	i;
	int	d_len;
	int	s_len;

	s_len = ft_strlen(src);
	d_len = ft_strlen(dst);
	while (*dst)
		dst++;
	i = d_len;
	while (i < (int)size - 1)
	{
		*dst++ = *src++;
		i++;
	}
	if (i < (int)size)
		*dst = '\0';
	return (d_len + s_len);
}

// int main()
// {
// 	char dst[20] = "hello, ";
// 	char *src = "worldooooooooooooooooooo";
// 	ft_strlcat(dst, dst, 10);
// 	printf("%s\n", dst);

// 	char dst2[20] = "hello, ";
// 	strlcat(dst2, dst2, 10);

// 	printf("%s\n", dst2);
// 	return 0;
// }