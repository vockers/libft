#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		dst[i] = src[i];	
		i++;
	}
	if (i < size)
		dst[i] = '\0';
	return (ft_strlen(src));
}