/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ut_ret.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tony </var/mail/tony>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 14:04:38 by tony              #+#    #+#             */
/*   Updated: 2019/02/17 17:21:58 by tony             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libut.h"

int		ut_ret(int ut_errno)
{
	g_uterrno = ut_errno;
	return (ut_errno);
}
