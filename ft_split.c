/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: vockers <vockers@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 14:43:42 by vockers       #+#    #+#                 */
/*   Updated: 2023/10/02 17:11:03 by vockers       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	ft_count_words(char const *s, char c)
{
	int	count;
	int	new_word;

	count = 0;
	new_word = 1;
	while (*s)
	{
		if (*s == c)
		{
			if (!new_word)
				count++;
			new_word = 1;
		}
		else
			new_word = 0;
		s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**new;
	char	*start;
	int		i;
	int		count;
	int		new_word;

	i = 0;
	count = ft_count_words(s, c);
	new_word = 1;
	new = (char **)malloc(sizeof(char *) * (count + 1));
	while (*s)
	{
		s++;
	}
	new[count] = NULL;
	return (new);
}
