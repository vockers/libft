#include "libft.h"

#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;

	while (lst)
	{
		new_lst = (t_list *)malloc(sizeof(t_list));	
		if (!new_lst)
			return (NULL);
		new_lst->content = lst->content;
		f(new_lst->content);
		lst = lst->next;
	}
	return (new_lst);
}