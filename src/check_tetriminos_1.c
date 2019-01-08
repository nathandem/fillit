/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetriminos_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advardon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 15:59:38 by advardon          #+#    #+#             */
/*   Updated: 2019/01/05 18:25:11 by advardon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Check if the hash in the tetriminos are adjacent.
** Valid tetriminos have at least 6 connections between each hash.
*/

void	check_adjacent_hash(char **check_tet, int j)
{
	int i;
	int line_tet;
	int count_adj;

	i = 0;
	line_tet = 4;
	count_adj = 0;
	while (line_tet--)
	{
		while (check_tet[j][i] != '\0')
		{
			if (check_tet[j][i] == '#')
			{
				count_adj = count_adj_tet(check_tet, j, i, count_adj);
			}
			i++;
		}
		i = 0;
		j++;
	}
	if (count_adj < 6)
		error_message();
}

/*
** Count the number of adjacent hash for each hash in one tetriminos.
*/

int		count_adj_tet(char **check_tet, int j, int i, int count_adj)
{
	if (i > 0 && check_tet[j][i - 1] == '#')
		count_adj++;
	if (i < 4 && check_tet[j][i + 1] == '#')
		count_adj++;
	if (((j - 1) % 5) != 0 && check_tet[j - 1][i] == '#')
		count_adj++;
	if (((j + 1) % 5) != 0 && check_tet[j + 1][i] == '#')
		count_adj++;
	return (count_adj);
}

/*
** Check how many hash are included in each tetriminos.
*/

void	check_nb_hash(int nb_line, int ret, char **check_tet)
{
	int			i;
	int			k;
	int			hash;

	i = -1;
	k = 0;
	hash = 0;
	if (ret == 0 || check_tet[nb_line][0] == '\0')
	{
		nb_line = nb_line - 4;
		while (k++ < 4)
		{
			while (check_tet[nb_line][++i] != '\0')
			{
				if (check_tet[nb_line][i] == '#')
					hash++;
			}
			i = -1;
			nb_line++;
		}
		if (hash != 4)
			error_message();
	}
	check_adjacent_hash(check_tet, nb_line - 4);
}

/*
** Check if each line of tetriminos is 4 characters long and
** only contains '.' or '#'.
*/

void	check_shape(char *line)
{
	int i;

	i = 0;
	i = ft_strlen(line);
	if (i != 4)
		error_message();
	i = 0;
	while (line[i])
	{
		if (line[i] != '.' && line[i] != '#')
			error_message();
		i++;
	}
}

/*
** Display error message
*/

void	error_message(void)
{
	write(1, "error\n", 6);
	exit(1);
}
