/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 13:34:48 by nde-maes          #+#    #+#             */
/*   Updated: 2019/01/07 11:22:48 by nde-maes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Unlike several linked list helper function, this one requires that the
** pointer to the head of the list (t_tet **head) must be created earlier.
** Yet, this one handles the case of the fist node and the others.
*/

void			free_lst(t_tet **head)
{
	t_tet			*node;
	t_tet			*next_node;

	node = *head;
	while (node)
	{
		next_node = node->next;
		free_sqr(node->piece);
		free(node);
		node = next_node;
	}
}

void			create_node_to_end(t_tet **head, char **piece)
{
	t_tet			*new_node;
	t_tet			*node;

	if (!(new_node = (t_tet*)malloc(sizeof(t_tet) * 1)))
		error_message();
	new_node->piece = copy_tet_with_dim(piece, 4);
	new_node->letter = '.';
	new_node->next = NULL;
	if (!*head)
	{
		*head = new_node;
		return ;
	}
	node = *head;
	while (node->next)
		node = node->next;
	node->next = new_node;
}
