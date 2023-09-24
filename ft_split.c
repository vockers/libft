#include "libft.h"
#include <stdlib.h>

char	**ft_split(char const *s, char c)
{
	char	**new;
	char	*start;
	int		i;
	int		count;
	int		new_word;

	i = 0;
	count = 0;
	new_word = 1;
	while (s[i])
	{
		if (s[i] == c)
		{
			if (!new_word)
				count++;
			new_word = 1;
		}
		else
			new_word = 0;
		i++;
	}
	new = (char **)malloc(sizeof(char *) * (count + 1));
	while (*s)
	{
		s++;
	}
	new[count] = NULL;
	return (new);
}