/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: vockers <vockers@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 14:43:42 by vockers       #+#    #+#                 */
/*   Updated: 2023/10/03 16:33:47 by vockers       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	count;
	int	new_word;

	count = 0;
	new_word = 1;
	while (*s)
	{
		if (*s == c)
			new_word = 1;
		else if (new_word)
		{
			count++;
			new_word = 0;
		}
		s++;
	}
	return (count);
}

static int	ft_strclen(const char *str, char c)
{
	int	len;

	len = 0;
	while (*str != '\0' && *str != c)
	{
		len++;
		str++;
	}
	return (len);
}

static char	**ft_delete_strs(char **strs)
{
	while (*strs)
		free(*strs++);
	free(strs);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**new;
	int		new_word;

	new = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!new)
		return (NULL);
	new_word = 1;
	while (*s)
	{
		if (*s == c)
			new_word = 1;
		else if (new_word)
		{
			*new = ft_strndup(s, ft_strclen(s, c));
			if (*new)
				return (ft_delete_strs(new));
			new_word = 0;
			new++;
		}
		s++;
	}
	*new = NULL;
	return (new);
}

// int main()
// {
// 	char **strs = ft_split(" Hello,  ,  world!   ", ' ');
// 	while (*strs)
// 	{
// 		printf("%s\n", *strs);
// 		strs++;
// 	}
// }