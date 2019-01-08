/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos_utils_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 15:19:46 by nde-maes          #+#    #+#             */
/*   Updated: 2019/01/07 13:10:53 by nde-maes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				get_top_shift(char **tet)
{
	int				line;
	int				col;
	int				dim;

	line = -1;
	dim = ft_strlen(tet[0]);
	while (++line < dim)
	{
		col = -1;
		while (++col < dim)
			if (tet[line][col] != '.')
				return (line);
	}
	return (0);
}

void			move_tet_left(char **tet)
{
	int				line;
	int				col;
	int				dim;

	line = -1;
	dim = ft_strlen(tet[0]);
	while (++line < dim)
	{
		col = -1;
		while (++col < dim - 1)
		{
			tet[line][col] = tet[line][col + 1];
			tet[line][col + 1] = '.';
		}
	}
}

void			move_tet_up(char **tet)
{
	int				line;
	int				col;
	int				dim;

	line = -1;
	dim = ft_strlen(tet[0]);
	while (++line < dim - 1)
	{
		col = -1;
		while (++col < dim)
		{
			tet[line][col] = tet[line + 1][col];
			tet[line + 1][col] = '.';
		}
	}
}

void			move_tet_top_left(char **tet)
{
	int				s_left;
	int				s_top;

	s_left = get_left_shift(tet);
	s_top = get_top_shift(tet);
	while (s_left--)
		move_tet_left(tet);
	while (s_top--)
		move_tet_up(tet);
}

/*
** Remove the tetriminos `letter` from the double array `res` if instances
** of the letter can be found in it.
*/

void			delete_tet_on_res(char **res, char tet_letter)
{
	int				line;
	int				col;

	line = -1;
	while (res[++line])
	{
		col = -1;
		while (res[line][++col])
			if (res[line][col] == tet_letter)
				res[line][col] = '.';
	}
}
