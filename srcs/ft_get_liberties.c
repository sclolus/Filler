/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_liberties.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 03:19:05 by sclolus           #+#    #+#             */
/*   Updated: 2017/06/17 03:15:51 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static uint32_t	ft_get_bottom_libertie(uint32_t x)
{
	if (!x)
		return (1);
	else
		return (((x / (sizeof(uint64_t) * 8))
				- ((x - 1) / (sizeof(uint64_t) * 8))));
}

static uint32_t	ft_get_long_liberties(t_board *board, uint32_t player_index
								, uint32_t y, uint32_t long_index)
{
	uint32_t	i;
	uint32_t	x;
	uint32_t	liberties;

	i = 0;
	x = 0;
	liberties = 0;
	(void)player_index;
#define debuf  0
# if debuf == 1
	uint32_t	test = 0;
#endif
	while (x < sizeof(uint64_t) * 8)
	{
# if debuf ==1
		test = 0;
# endif
		if (((board->player_1.map.map[board->long_nbr * y + long_index] >> (63 - x)) & 1)
			|| ((board->player_2.map.map[board->long_nbr * y + long_index] >> (63 - x)) & 1))
		{
			x++;
# if debuf == 1
				ft_putchar('.');
#endif
			continue ;
		}
# if debuf == 1
		if ((x || long_index ? (board->player_1.map.map[(board->size_longs * player_index)
												+ (y * board->long_nbr) + long_index - ft_get_bottom_libertie(x)] >> (63 - ((x - 1)))) & 1 : 0))
			test++;
# endif
		liberties += (x || long_index ? (board->player_1.map.map[(board->size_longs * player_index)
					+ (y * board->long_nbr) + long_index - ft_get_bottom_libertie(x)] >> (63 - ((x - 1)))) & 1 : 0);
# if debuf ==1
		if (x < 63 || long_index < board->long_nbr - 1 || x < 63
					? (board->player_1.map.map[(board->size_longs * player_index)
					+ y * board->long_nbr + long_index + (((x + 1) / (sizeof(uint64_t) * 8))
														  - ((x) / (sizeof(uint64_t) * 8)))] >> (63 - ((x + 1)))) & 1 : 0)
			test++;
#endif
		liberties += x < 63 || long_index < board->long_nbr - 1 || x < 63
					? (board->player_1.map.map[(board->size_longs * player_index)
					+ y * board->long_nbr + long_index + (((x + 1) / (sizeof(uint64_t) * 8))
					- ((x) / (sizeof(uint64_t) * 8)))] >> (63 - ((x + 1)))) & 1 : 0;
#if debuf == 1
		if (y > 0 ? (board->player_1.map.map[(board->size_longs * player_index)
									 + (y - 1) * board->long_nbr + long_index] >> (63 - (x))) & 1 : 0)
			test++;
#endif
		liberties += y > 0 ? (board->player_1.map.map[(board->size_longs * player_index)
											  + (y - 1) * board->long_nbr + long_index] >> (63 - (x))) & 1 : 0;
#if debuf ==1
		if (y < board->len_y - 1 ? (board->player_1.map.map[(board->size_longs * player_index)
													+ (y + 1) * board->long_nbr + long_index] >> (63 - (x))) & 1 : 0)
			test++;
#endif
		liberties += y < board->len_y - 1 ? (board->player_1.map.map[(board->size_longs * player_index)
					+ (y + 1) * board->long_nbr + long_index] >> (63 - (x))) & 1 : 0;
# if debuf ==1
		ft_putchar((unsigned char)test + '0');
# endif
		x++;
	}
	return (liberties);
}

uint32_t	ft_get_line_liberties(t_board *board, uint32_t player_index
								, uint32_t y)
{
	uint32_t	x;
	uint32_t	liberties;

	liberties = 0;
	x = 0;
	while (x < board->long_nbr)
	{
		liberties += ft_get_long_liberties(board, player_index, y, x);
		x++;
 		if (x * 64 > board->len_x)
 			break ;
	}
	return (liberties);
}

uint32_t	ft_get_liberties(t_board *board, uint32_t player_index)
{
	uint32_t	i;
	uint32_t	liberties;

	i = 0;
	liberties = 0;
	while (i < board->len_y)
	{
		liberties += ft_get_line_liberties(board, player_index, i);
# if debuf ==1
		ft_putchar('\n');
# endif
		i++;
	}
	ft_putchar('\n');
	return (liberties);
}