#include "libft.h"

size_t	strlcat(char *dst, const char *src, size_t size)
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