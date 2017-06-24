/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 23:56:00 by sclolus           #+#    #+#             */
/*   Updated: 2017/06/24 04:40:43 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	main(void)
{
	static t_board	board;
	static t_piece	piece;

	if (!(ft_init_champion(&board)))
		return (EXIT_FAILURE);
	while (1)
	{
		if (!ft_get_board_stats(&board))
		{
			ft_error(1, (char*[]){"EXITED"}, 0);
			return (EXIT_FAILURE);
		}
		if (!(ft_get_piece_stats(&piece)))
		{
			ft_error(1, (char*[]){"-EXITED"}, 0);
			return (EXIT_FAILURE);
		}
		ft_solve(&board, &piece);
		ft_cleanup_map(&board, &piece);
	}
}
