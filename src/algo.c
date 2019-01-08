/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 14:27:30 by nde-maes          #+#    #+#             */
/*   Updated: 2019/01/07 13:13:43 by nde-maes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Check whether or not tetriminos can fit in the resulting square.
*/

int				tet_can_fit_on_res(char **res, char **current_tet)
{
	int				line;
	int				col;

	line = -1;
	while (res[++line])
	{
		col = -1;
		while (res[line][++col])
			if (current_tet[line][col] != '.' && res[line][col] != '.')
				return (0);
	}
	return (1);
}

/*
** Place the non-dot symbols (i.e. the tetriminos letter in our case)
** on the resulting square.
*/

void			place_tet_on_res(char **res, char **current_tet)
{
	int				line;
	int				col;

	line = -1;
	while (res[++line])
	{
		col = -1;
		while (res[line][++col])
			if (current_tet[line][col] != '.')
				res[line][col] = current_tet[line][col];
	}
}

/*
** This function is part of `resolve_rec`, it is reponsible for checking if
** tetriminos can move on their grids and move them if possible.
** To be honest, there's no real reason for having extracted this chunck from
** the rest of `resolve_rec` besides the harsh linter of the school, which
** limit the length of function to 25 lines max.
*/

static int		handle_move_tet(char **current_tet)
{
	int				dir;

	dir = tetriminos_can_move(current_tet);
	if (dir == 1)
		move_tet_right(current_tet);
	else if (dir == 2)
		move_tet_down_left(current_tet);
	else
	{
		free_sqr(current_tet);
		return (1);
	}
	return (0);
}

/*
** This function recursively places tetriminos in a grid and print the result
** when it is done. It's a backtracking style brute force.
** It's the core of the algo.
**
** Here's an attempt to describe with a short text how it works:
** Check if the tetriminos can fit on the resulting grid. If yes, place it and
** call the function again with the next tetriminos (these pieces are stored a
** linked list, with one tetriminos per node). If not possible, check whether
** the tetriminos can move on its own grid. If it can move on the right, shift
** it one block in this direction. If the tetriminos already touch the right
** side of its grid, and if it can move downwards (i.e. if it doesn't touch the
** botton side of its grid), shift it one block downwards and align it on the
** left side of the grid. If both options are impossible, return (so that we
** can resume the execution of the function on the stack under it).
** It the first tetriminos is moved several times to the point that it can't
** fit in the resulting square anymore, we exit from the first call of the
** `resolve_rec` and resume the execution of the `resolve` function, which will
** enlarge the dimension of the resulting grid of one and call anew
** `resolve_rec`.
** At some point, when all the tetriminos of the linked list are placed, the
** function will print its resulting grid on the standard output, free the
** dynamically allocated resource used by the program, and exit.
**
** If it's not clear yet, I recommend you read code below and work out a few
** examples with a pen and paper. It's still the best way.
**
** Note: `resolve_rec` copies the tetriminos to avoid spoiling the ones it
** reads from the linked list, which are well positionned on the top left
** corner, so that the tetriminos are at the same place even after several
** calls.
*/

static void		resolve_rec(char **res, int dim, t_tet *tet, t_tet **tet_head)
{
	char			**current_tet;

	current_tet = copy_tet_with_dim(tet->piece, dim);
	while (1)
	{
		if (tet_can_fit_on_res(res, current_tet))
		{
			place_tet_on_res(res, current_tet);
			if (!(tet->next))
			{
				print_sqr(res);
				free_sqr(res);
				free_sqr(current_tet);
				free_lst(tet_head);
				exit(0);
			}
			resolve_rec(res, dim, tet->next, tet_head);
			delete_tet_on_res(res, tet->letter);
		}
		if (handle_move_tet(current_tet))
			return ;
	}
}

/*
** Entry point of the algo.
** A empty resulting square is created here, it is then passed to the recursive
** `resolve_rec` function which will fill it. At first the resulting square has
** a dimension of 2 because that's the smallest size possible it can have. If
** `resolve_rec` exits, a new resulting square with a dimension of 3 is created
** and passed to `resolve_rec`. So on till `resolve_rec` prints the most
** optimized square with all the tetriminos in it.
*/

void			resolve(t_tet **tet_head, int res_starting_dim)
{
	char			**res;
	int				dim;

	dim = res_starting_dim - 1;
	while (++dim)
	{
		if (dim > res_starting_dim)
			free_sqr(res);
		res = create_empty_sqr(dim);
		resolve_rec(res, dim, *tet_head, tet_head);
	}
}
