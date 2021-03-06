/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 13:06:52 by narchiba          #+#    #+#             */
/*   Updated: 2019/03/08 13:07:05 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include <stdlib.h>

void	history_free(t_history *history)
{
	size_t	i;

	if (history == NULL)
		return ;
	i = 0;
	while (i < history->len)
		matrix_free(history->matrix[i++]);
	matrix_free(history->last_hst_matrix);
	free(history->matrix);
	string_free(history->buffer);
	string_free(history->event);
	line_free(g_history->search_line);
	free(history);
}
