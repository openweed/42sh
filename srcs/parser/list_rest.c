/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_rest.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 17:23:13 by bwerewol          #+#    #+#             */
/*   Updated: 2019/01/30 20:20:02 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**        LIST
**       /    \
** AND_OR      LIST_REST(type:separator)
**            /    \
**      AND_OR      LIST_REST(type:separator)
**                 /    \
**                0      0
*/

#include "parser.h"

t_astree	*list_rest(void)
{
	t_astree	*root;

	if (!(root = separator_op()))
		return (0);
	if (!(root->left = and_or()))
		return (root);
	/* XXX - Need norm type */
	root->type = 0;
	root->right = list_rest();
	return (root);
}