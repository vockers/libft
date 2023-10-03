/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vockers <vockers@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 14:43:11 by vockers       #+#    #+#                 */
/*   Updated: 2023/10/02 21:29:11 by vockers       ########   odam.nl         */
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
	{
		dst++;
		size--;
	}
	i = 0;
	while (i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	if (i < size)
		dst[i] = '\0';
	return (d_len + s_len);
}
