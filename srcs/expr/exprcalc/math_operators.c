/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_operators.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 18:07:50 by nkertzma          #+#    #+#             */
/*   Updated: 2019/01/23 11:17:40 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calc.h"

intmax_t	op_sub(intmax_t operator, t_astree *node)
{
	intmax_t	tmp;

	tmp = operator - calc(node->left);
	if (node->right)
		return (g_operators[node->right->type - OPSHIFT](tmp, node->right));
	return (tmp);
}

intmax_t	op_add(intmax_t operator, t_astree *node)
{
	intmax_t	tmp;

	tmp = operator + calc(node->left);
	if (node->right)
		return (g_operators[node->right->type - OPSHIFT](tmp, node->right));
	return (tmp);
}
