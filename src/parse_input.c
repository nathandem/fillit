/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 11:23:52 by nde-maes          #+#    #+#             */
/*   Updated: 2019/01/07 13:14:31 by advardon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Chek if there is there is at least one tetriminos, and no more than 26.
** For 26 tetriminos, the maximum line should be (26 * 5) - 1 = 129.
*/

void	check_nb_tet(int line_nb, int ret)
{
	if (ret == 0 && line_nb < 4)
		error_message();
	if (ret == 0 && line_nb > 129)
		error_message();
}

/*
** Check if there is no other character than '\n' between each tetriminos.
*/

void	check_space_tet(char *line)
{
	if (line[0] != '\0')
		error_message();
}

/*
** Check if there no '\n' at the end of the file.
*/

void	check_no_nl_eof(int j, int ret, char **check_tet)
{
	if (ret == 0 && check_tet[j - 1][0] == '\0')
		error_message();
}

/*
** Place each tetriminos in a node of a chained list.
*/

void	set_piece_in_lst(t_tet **head_lst, char **cpy_tet, int line_nb)
{
	char	*piece[4];
	int		i;

	i = 0;
	line_nb = line_nb - 4;
	while (i < 4)
	{
		piece[i] = cpy_tet[line_nb];
		i++;
		line_nb++;
	}
	create_node_to_end(head_lst, piece);
}

/*
** Read each line of the file. Use a modulo of 5 to differentiate
** lines of tetriminos and space between tetriminos.
*/

void	parse_input(int fd, t_tet **head_lst)
{
	char	*cpy_tet[130];
	char	*line;
	int		line_nb;
	int		ret;

	line_nb = 1;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		cpy_tet[line_nb] = ft_strdup(line);
		if (line_nb % 5 != 0)
			check_shape(line);
		else if (line_nb % 5 == 0)
		{
			check_space_tet(line);
			set_piece_in_lst(head_lst, cpy_tet, line_nb);
			check_nb_hash(line_nb, ret, cpy_tet);
		}
		line_nb++;
		free(line);
	}
	check_eof(cpy_tet, line_nb, ret);
	set_piece_in_lst(head_lst, cpy_tet, line_nb);
	free(line);
	free_cpy_tet(cpy_tet, line_nb);
}
