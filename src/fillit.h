/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 11:56:09 by nde-maes          #+#    #+#             */
/*   Updated: 2019/01/07 14:16:23 by nde-maes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft.h"

typedef struct	s_tet
{
	char			**piece;
	char			letter;
	struct s_tet	*next;
}				t_tet;

char			**create_empty_sqr(int dim);
char			**copy_tet_with_dim(char **sqr, int dim);
void			print_sqr(char **sqr);
void			free_sqr(char **sqr);

int				tetriminos_can_move(char **tet);
int				get_left_shift(char **tet);
int				get_top_shift(char **tet);
void			move_tet_right(char **tet);
void			move_tet_down_left(char **tet);
void			move_tet_top_left(char **tet);
void			replace_tet_hash_by_letter(t_tet *node, char c);
int				normalize_lst(t_tet **head);

void			create_node_to_end(t_tet **head, char **piece);
void			free_lst(t_tet **head);

int				tet_can_fit_on_res(char **res, char **current_tet);
void			place_tet_on_res(char **res, char **current_tet);
void			delete_tet_on_res(char **res, char tet_letter);
void			resolve(t_tet **tetriminos_head, int res_starting_dim);
void			parse_input(int fd, t_tet **tmp_tet);
void			set_piece_in_lst(t_tet **tmp_tet, char **cpy_tet, int j);
void			check_shape(char *line);
void			check_nb_hash(int j, int ret, char **check_tet);
void			check_no_nl_eof(int j, int ret, char **check_tet);
void			check_space_tet(char *line);
void			check_nb_tet(int j, int ret);
void			check_adjacent_hash(char **check_tet, int j);
int				count_adj_tet(char **check_tet, int j, int i, int count_adj);
void			error_message(void);
void			check_empty_file(int line_nb);
void			free_cpy_tet(char **cpy_tet, int line_nb);
void			check_nb_line(char **cpy_tet, int line_nb);
void			check_eof(char **cpy_tet, int line_nb, int ret);

#endif
