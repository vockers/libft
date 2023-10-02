/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vockers <vockers@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 14:42:28 by vockers       #+#    #+#                 */
/*   Updated: 2023/10/02 15:01:11 by vockers       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	i;
	int	j;

	i = 0;
	while (big[i])
	{
		j = 0;
		while (big[i] == little[j])
		{
			if (j == len)
				return ((char *)(big + i));
			j++;
		}
		i++;
	}
	return ((char *)big);
}
