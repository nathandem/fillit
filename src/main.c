/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 11:24:35 by nde-maes          #+#    #+#             */
/*   Updated: 2019/01/07 13:04:27 by nde-maes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				main(int argc, char **argv)
{
	t_tet			*head_lst;
	int				res_starting_dim;
	int				fd;

	if (argc != 2)
		ft_putstr("usage: fillit source_file\n");
	else
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			error_message();
		parse_input(fd, &head_lst);
		res_starting_dim = normalize_lst(&head_lst);
		resolve(&head_lst, res_starting_dim);
	}
	return (0);
}
