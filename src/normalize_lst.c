/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 14:33:53 by nde-maes          #+#    #+#             */
/*   Updated: 2019/01/07 12:46:08 by nde-maes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Normalization consists of 2 things:
** - moving the tetriminos to the top left corner
** - replacing its '#' with the letter corresponding to the order of which
**   the tetriminos appeared
*/

void			replace_tet_hash_by_letter(t_tet *node, char c)
{
	int				line;
	int				col;

	line = -1;
	while (node->piece[++line])
	{
		col = -1;
		while (node->piece[line][++col])
			if (node->piece[line][col] != '.')
				node->piece[line][col] = c;
	}
}

/*
** Returns the max number of blocks in a row in a tetriminos.
** Possible values are: 4 (for a line), 3 and 2 (for a square).
*/

int				get_max_blocks_aligned(char **tet)
{
	int				counter;

	counter = -1;
	while (++counter < 4)
		if (tet[counter][3] != '.' || tet[3][counter] != '.')
			return (4);
	counter = -1;
	while (++counter < 4)
		if (tet[counter][2] != '.' || tet[2][counter] != '.')
			return (3);
	return (2);
}

int				normalize_lst(t_tet **head)
{
	t_tet			*node;
	int				counter;
	char			letter;
	int				max;

	counter = 0;
	node = *head;
	max = 2;
	while (node)
	{
		letter = ++counter + 64;
		move_tet_top_left(node->piece);
		if (get_max_blocks_aligned(node->piece) > max)
			max = get_max_blocks_aligned(node->piece);
		replace_tet_hash_by_letter(node, letter);
		node->letter = letter;
		node = node->next;
	}
	return (max);
}
