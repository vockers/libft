/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_abs.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: vockers <vockers@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 14:45:29 by vockers       #+#    #+#                 */
/*   Updated: 2023/10/03 14:52:33 by vockers       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

unsigned int	ft_uabs(int x)
{
	if (x < 0)
		return ((unsigned int)-x);
	return (x);
}
