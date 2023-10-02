/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: vockers <vockers@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 14:44:34 by vockers       #+#    #+#                 */
/*   Updated: 2023/10/02 17:04:08 by vockers       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

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
