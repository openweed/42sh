/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 17:50:26 by bwerewol          #+#    #+#             */
/*   Updated: 2018/11/21 18:04:07 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_is_uppercase(char *s)
{
	if (!s)
		return (0);
	while (*s)
		if (!ft_isupper(*s++))
			return (0);
	return (1);
}