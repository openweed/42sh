/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitlcead <sitlcead@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 14:12:10 by sitlcead          #+#    #+#             */
/*   Updated: 2019/03/08 13:23:54 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include <string.h>
#include "term.h"
#include <unistd.h>

t_history		*g_history;
int				g_mode;
int				g_search_mode;
int				g_heredoc;
int				g_vi_mode;
int				g_syntax;
struct winsize	g_w;
t_uchar			g_shortcuts[SHORTCUT_ARRAY_SIZE];

void			init_readline(void)
{
	get_term_params(&g_w);
	set_term();
	g_heredoc = 0;
	print_prompt();
	history_fill();
}

t_string		*readline(void)
{
	int			ret;
	t_string	*str;

	init_readline();
	ret = 1;
	while (ret > 0)
	{
		if (g_search_mode)
			print_search(g_history->matrix[g_history->cur]);
		else
			print_default(g_history->matrix[g_history->cur]);
		ret = check_next_symbol();
	}
	if (ret == 0)
	{
		print_end(g_history->matrix[g_history->cur]);
		str = string_init();
		if (history_save(&str))
			return (readline());
		unset_term();
		return (str);
	}
	history_del(&g_history);
	unset_term();
	return (NULL);
}
