/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 20:51:15 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/27 12:51:35 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_btree_count(t_btree *root)
{
	if (!root)
		return (0);
	return (ft_btree_count(root->left) + ft_btree_count(root->right) + 1);
}
