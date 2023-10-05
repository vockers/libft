/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vockers <vockers@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 14:43:02 by vockers       #+#    #+#                 */
/*   Updated: 2023/10/03 16:32:59 by vockers       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	int	i;

	i = 0;
	while (i < (int)size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	if (i < (int)size)
		dst[i] = '\0';
	return (ft_strlen(src));
}
