/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcasecmp.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: vockers <vockers@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/20 14:47:27 by vockers       #+#    #+#                 */
/*   Updated: 2023/11/20 14:47:27 by vockers       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcasecmp(const char *s1, const char *s2)
{
	while (*s1 || *s2)
	{
		if (ft_tolower(*s1) != ft_tolower(*s2))
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
	}
	return (0);
}
