/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pids.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 16:31:01 by nkertzma          #+#    #+#             */
/*   Updated: 2019/03/01 16:31:55 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	init_pids(void)
{
	g_pids = vector_create(sizeof(pid_t));
	g_jobs = vector_create(sizeof(pid_t));
}
