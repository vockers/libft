/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vockers <vockers@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 14:42:15 by vockers       #+#    #+#                 */
/*   Updated: 2023/10/03 16:33:21 by vockers       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	int		i;

	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	i = 0;
	while (s[start + i] && i < (int)len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[len] = '\0';
	return (sub);
}

// int main()
// {
// 	char *str = "hello, world!";
// 	printf("%s\n", ft_substr(str, 5, 5));
// 	return 0;
// }