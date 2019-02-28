/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configurate_of_exptention.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 19:38:01 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/02/26 19:16:03 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "extention.h"

char	*use_an_alternate_value(char *str)
{
	char	*tmp;
	int		i;
	char	*res;

	i = 0;
	while (str[i + 1] != ':')
		i++;
	tmp = ft_strndup(str, i + 1);
	res = get_content_of_var(&tmp[2]);
	free(tmp);
	if (!res)
		return (ft_strdup(""));
	tmp = (ft_strndup(&str[i + 3], ft_strlen(&str[i + 3]) - 1));
	return (tmp);
}

char	*get_len_of_value(char *str)
{
	char	*tmp;
	char	*res;

	tmp = ft_strndup(str, ft_strlen(str) - 1);
	res = get_content_of_var(&tmp[3]);
	free(tmp);
	if (!res)
		return (ft_itoa(0));
	return (ft_itoa(ft_strlen(res)));
}

char	*remove_smallest_suffix_pattern(char *str)
{
	char	*tmp;
	char	*pattern;
	int		i;
	char	*res;
	char	*to_check;

	i = 0;
	while (str[i] != '%')
		i++;
	tmp = ft_strndup(str, i);
	res = get_content_of_var(&tmp[2]);
	if (!res)
		return (ft_strdup(""));
	pattern = ft_strndup(&str[i + 1], ft_strlen(&str[i + 3]) + 1);
	to_check = get_last_n_symbols(res, ft_strlen(pattern), 0);
	if (pattern && pattern[0] && !ft_strcmp(pattern, to_check))
		return (ft_strndup(res, ft_strlen(res) - ft_strlen(pattern)));
	return (ft_strdup(res));
}

char	*remove_smallest_prefix_pattern(char *str)
{
	char	*tmp;
	char	*pattern;
	int		i;
	char	*res;

	i = 0;
	while (str[i] != '#')
		i++;
	tmp = ft_strndup(str, i);
	res = get_content_of_var(&tmp[2]);
	if (!res)
		return (ft_strdup(""));
	pattern = ft_strndup(&str[i + 1], ft_strlen(&str[i + 3]) + 1);
	if (pattern && pattern[0] && !ft_strncmp(res, pattern, ft_strlen(pattern)))
		return (ft_strdup(&res[ft_strlen(pattern)]));
	return (ft_strdup(res));
}

char	*get_ex_tilda(char *str)
{
	int				i;
	char			*tmp;
	struct passwd	*user;

	if (!str[1] || str[1] == ' ' || str[1] == '/')
		return (ft_strdup(sgetenv("HOME")));
	i = 1;
	while (str[i] && str[i] != '/' && str[i] != ' ')
		i++;
	tmp = ft_strndup(str, i);
	if (!(user = getpwnam(&tmp[1])))
		return (tmp);
	free(tmp);
	tmp = ft_strdup(user->pw_dir);
	return (tmp);
}

char	*get_content_of_expression(char *str)
{
	char	*res;

	str = erase_repetitions_recursion(str);
	if (str[0] == '~')
		res = get_ex_tilda(str);
	else if (str[1] != '(' && str[1] != '[' && str[1] != '{')
		res = classic_get_env(&str[1]);
	else if (ft_strstr(str, ":-"))
		res = use_a_default_value(str);
	else if (ft_strstr(str, ":="))
		res = assign_a_default_value(str);
	else if (ft_strstr(str, ":?"))
		res = display_error_if_null_or_unset(str);
	else if (ft_strstr(str, ":+"))
		res = use_an_alternate_value(str);
	else if (str[2] == '#')
		res = get_len_of_value(str);
	else if (ft_strstr(str, "%%"))
		res = ft_strdup("<obosralsya(%%>");
	else if (ft_strstr(str, "%"))
		res = remove_smallest_suffix_pattern(str);
	else if (ft_strstr(str, "##"))
		res = ft_strdup("<obosralsya(##>");
	else if (ft_strstr(str, "#"))
		res = remove_smallest_prefix_pattern(str);
	else
		res = ft_strdup("something wrong in get_content_of_expression");
	free(str);
	return (res);
}