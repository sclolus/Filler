/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_board.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 01:15:57 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/29 21:36:46 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_free_board(t_board *board)
{
	free(board->player_1.map.map);
	free(board->player_1.player_name);
	free(board->player_2.map.map);
	free(board->player_2.player_name);
	free(board);
}
