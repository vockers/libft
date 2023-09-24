#include "libft.h"

void	*memset(void *s, int c, size_t n)
{
	unsigned char *str;

	str = (unsigned char *)s;
	while (n)
	{
		*str++ = c;
		n--;
	}
	return s;
}