/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_get_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:41:02 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/19 14:14:47 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libhash.h"

/*
** Returns length of table
*/

size_t		hash_get_len(t_hash *hash)
{
	if (!hash)
		return ((size_t)HSH_ERR);
	return (hash->filled);
}