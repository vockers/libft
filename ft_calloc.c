#include "libft.h"

#include <stddef.h>
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*new;
	size_t	mem_size;

	mem_size = nmemb * size;
	new = malloc(mem_size);
	if (!new)
		return (NULL);	
	ft_bzero(new, mem_size);
	return (new);
}