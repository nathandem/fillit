/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetriminos_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advardon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 15:43:27 by advardon          #+#    #+#             */
/*   Updated: 2019/01/07 13:14:26 by advardon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Check if the tetriminos file is not an emty file.
*/

void	check_empty_file(int line_nb)
{
	if (line_nb == 1)
		error_message();
}

/*
** Free the copies of the tetriminos.
*/

void	free_cpy_tet(char **cpy_tet, int line_nb)
{
	int i;

	i = line_nb;
	line_nb = 1;
	while (line_nb < i)
	{
		free(cpy_tet[line_nb]);
		line_nb++;
	}
}

/*
** Check if the the first and last terminos are 4 lines long.
*/

void	check_nb_line(char **cpy_tet, int line_nb)
{
	if (line_nb < 5)
		error_message();
	if (line_nb > 5 && cpy_tet[line_nb - 5][0] != '\0')
		error_message();
}

/*
** Check different parameters once the tetriminos file is read.
*/

void	check_eof(char **cpy_tet, int line_nb, int ret)
{
	if (ret == -1)
		error_message();
	check_empty_file(line_nb);
	check_nb_line(cpy_tet, line_nb);
	check_nb_hash(line_nb, ret, cpy_tet);
	check_no_nl_eof(line_nb, ret, cpy_tet);
	check_nb_tet((line_nb - 1), ret);
}
