/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft_bits.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vockers <vockers@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/19 18:59:29 by vockers       #+#    #+#                 */
/*   Updated: 2023/10/19 18:59:29 by vockers       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_BITS_H
# define LIBFT_BITS_H

# include <stdint.h>

uint16_t	ft_bswap16(uint16_t x);
uint32_t	ft_bswap32(uint32_t x);
uint64_t	ft_bswap64(uint64_t x);

#endif