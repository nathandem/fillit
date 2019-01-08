/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sqr_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 12:14:40 by nde-maes          #+#    #+#             */
/*   Updated: 2019/01/07 11:28:56 by nde-maes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Create a square of dimension `dim` and fills it with '.'.
*/

char		**create_empty_sqr(int dim)
{
	char		**sqr;
	int			line;
	int			col;

	if (!(sqr = (char**)malloc(sizeof(char*) * (dim + 1))))
		error_message();
	sqr[dim] = NULL;
	line = 0;
	while (line < dim)
	{
		if (!(sqr[line] = (char*)malloc(sizeof(char) * (dim + 1))))
			error_message();
		sqr[line][dim] = 0;
		col = 0;
		while (col < dim)
			sqr[line][col++] = '.';
		line++;
	}
	return (sqr);
}

/*
** Allocates a square of dimension `dim`, then copies the provided
** tetriminos in it (the tetriminos blocks can't be further than
** index 3).
*/

char		**copy_tet_with_dim(char **tet, int dim)
{
	char		**tet_copy;
	int			line;
	int			col;

	tet_copy = create_empty_sqr(dim);
	line = -1;
	while (tet_copy[++line] && line < 4)
	{
		col = -1;
		while (tet_copy[line][++col] && col < 4)
			tet_copy[line][col] = tet[line][col];
	}
	return (tet_copy);
}

void		print_sqr(char **sqr)
{
	int			line;

	line = 0;
	while (sqr[line])
	{
		ft_putstr(sqr[line]);
		ft_putchar(10);
		line++;
	}
}

void		free_sqr(char **sqr)
{
	int			line;

	line = 0;
	while (sqr[line])
		free(sqr[line++]);
	free(sqr);
}
