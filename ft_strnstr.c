/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vockers <vockers@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 14:42:28 by vockers       #+#    #+#                 */
/*   Updated: 2023/10/03 16:33:13 by vockers       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	i;
	int	j;

	i = 0;
	if (*little == '\0')
		return ((char *)big);
	while (big[i] && i < (int)len)
	{
		j = 0;
		while (big[i] == little[j] && i < (int)len)
		{
			j++;
			i++;
		}
		if (little[j] == '\0')
			return ((char *)&big[i - j]);
		i = i - j + 1;
	}
	return (NULL);
}

// int main()
// {
// 	char *haystack	= "hello, world!";
// 	char *needle	= "world";
// 	printf("%s\n", ft_strnstr(haystack, needle, 12));
// 	printf("%s\n", strnstr(haystack, needle, 12));
// 	return 0;
// }
