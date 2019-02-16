/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 12:22:14 by narchiba          #+#    #+#             */
/*   Updated: 2019/01/04 12:22:18 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void	*vector_create(size_t elem_byte_size)
{
	size_t	*arr;

	if (!(arr = (size_t *)malloc(sizeof(size_t) * 3 +
					elem_byte_size * ARR_SIZE)))
		return (NULL);
	arr[0] = elem_byte_size;
	arr[1] = ARR_SIZE;
	arr[2] = 0;
	return ((void *)arr);
}