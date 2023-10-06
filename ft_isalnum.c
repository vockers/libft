/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalnum.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vockers <vockers@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 14:45:21 by vockers       #+#    #+#                 */
/*   Updated: 2023/10/02 15:56:04 by vockers       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9')
		|| (c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z'))
		return (LIBFT_IS_ALNUM);
	return (0);
}

// #include <stdio.h>
// #include <ctype.h>

// int main()
// {
// 	printf("%d\n", ft_isalnum(68));
// 	printf("%d\n", isalnum(68));
// }