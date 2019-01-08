/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos_utils_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 14:38:04 by nde-maes          #+#    #+#             */
/*   Updated: 2019/01/05 12:52:36 by nde-maes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** If no letter on the last column, tetriminos can move rightwards: return 1.
** If at least a letter on the last column but no letter on the last line,
** tetriminos can move downwards and to the left of the square: return 2.
** If stuff on the last column and on the last line, the tetriminos can't move
** anymore: return 0.
*/

int				tetriminos_can_move(char **tet)
{
	int				line;
	int				col;
	int				dim;

	line = -1;
	col = -1;
	dim = ft_strlen(tet[0]);
	while (++line < dim)
	{
		if (tet[line][dim - 1] != '.')
		{
			while (++col < dim)
				if (tet[dim - 1][col] != '.')
					return (0);
			return (2);
		}
	}
	return (1);
}

/*
** Work from right to left (necessary), top to bottom (arbitrary).
*/

void			move_tet_right(char **tet)
{
	int				line;
	int				col;
	int				dim;

	line = -1;
	dim = ft_strlen(tet[0]);
	while (++line < dim)
	{
		col = dim;
		while (--col > 0)
		{
			tet[line][col] = tet[line][col - 1];
			tet[line][col - 1] = '.';
		}
	}
}

/*
** Work from top to bottom (arbitrary), and left to right (needed).
*/

int				get_left_shift(char **tet)
{
	int				line;
	int				col;
	int				dim;

	col = -1;
	dim = ft_strlen(tet[0]);
	while (++col < dim)
	{
		line = -1;
		while (++line < dim)
			if (tet[line][col] != '.')
				return (col);
	}
	return (0);
}

/*
** Work form left to right and bottom to top (both are needed).
*/

void			move_tet_down_left(char **tet)
{
	int				line;
	int				col;
	int				left_shift;
	int				dim;

	left_shift = get_left_shift(tet);
	dim = ft_strlen(tet[0]);
	line = dim - 1;
	while (line > 0)
	{
		col = 0;
		while (col < dim - left_shift)
		{
			tet[line][col] = tet[line - 1][col + left_shift];
			tet[line - 1][col + left_shift] = '.';
			col++;
		}
		line--;
	}
}
