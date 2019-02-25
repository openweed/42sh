/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssetenv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 18:50:20 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/25 21:08:38 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "libshell.h"

static void		genv_realloc(void)
{
	char 	**new;
	size_t	new_size;
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	ft_putendl("YEE");
	new_size = (size_t)((float)g_env.size * (float)GENV_REALLOC / (float)100);
	new = (char **)xmalloc(sizeof(char *) * (g_env.size + new_size + 1));
	while (i <= g_env.size)
	{
		if (g_env.env[i])
		{
			new[k] = g_env.env[i];
			k++;
		}
		i++;
	}
	while (i <= new_size)
	{
		new[k] = NULL;
		k++;
		i++;
	}
	free(g_env.env);
	g_env.env = new;
}

static void		ssetgenv(char *str)
{
	if (g_env.filled >= g_env.size)
		genv_realloc();
	ft_putendl(g_env.env[g_env.filled]);
	g_env.env[g_env.filled] = str;
	g_env.filled++;
}

int		ssetenv(const char *key, const char *value)
{
	char	*str;

	if (!key)
		return (SHERR_ERR);
	str = ft_strjoin(key, "=", 0);
	if (value)
		str = ft_strjoin(str, value, 1);
	if ((hash_insert(key, value, g_hash_env) == HSH_ERR))
	{
		free(str);
		return (SHERR_ERR);
	}
	ssetgenv(str);
	return (SHERR_OK);
}
