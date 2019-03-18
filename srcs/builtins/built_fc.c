#include "shell.h"
#include "builtins.h"
#include "get_next_line.h"
#include "readline.h"
#include <pwd.h>
#include "lexer.h"
#include "parser.h"
#include "execute.h"
#include "readline.h"

static void	read_history_from_disk(void **vector)
{
	int				fd;
	char			*file_name;
	struct passwd	*pw;
	int				ret;
	char			*str;

	pw = getpwuid(getuid());
	file_name = ft_strjoin(pw->pw_dir, "/", 0);
	file_name = ft_strjoin(file_name, HISTORY_FILE, 1);
	fd = open(file_name, O_CREAT | O_RDONLY | O_APPEND, 0777);
	while ((ret = get_next_line(fd, &str)))
		vector_push_back(vector, &str);
	close(fd);
	free(file_name);
}

static void	fc_history_free(void *fc_history)
{
	char	**str;
	size_t	len;
	size_t	i;

	i = 0;
	len = vector_get_len(fc_history);
	while (i < len)
	{
		str = (char **)vector_get_elem(fc_history, i);
		free(*str);
		i++;
	}
}

static int		parse_string(char *script)
{
	t_lexer		*lex;
	t_astree	*ast;
	int 		last;
	char 		*tmp;

	ft_putendl(script);
	lex = lexer(script, ft_strlen(script));
	g_tokens = lex->lexems;
	ast = inputunit();
	last = execute(ast);
	tmp = ft_itoa(last);
	ssetenv("?", tmp, ENV_RO);
	ft_strdel(&tmp);
	freeastree(ast);
	lexer_free(lex);
	return (1);
}

static int	fc_usage(void)
{
	array_add("fc usage: \n", ft_strlen("fc usage: \n"));
	array_flush();
	return (0);
}

static int	parse_flags(char **av, int *flags)
{
	int		k;
	int		i;

	i = 1;
	while (av[i] && av[i][0] == '-')
	{
		k = 1;
		while (av[i][k])
		{
			if ((av[i][k] != 'e' && av[i][k] != 'r' && av[i][k] != 'l'
			&& av[i][k] != 'n' && av[i][k] != 's')
			|| flags[0] == 1 || flags[4] == 1 || (av[i][k] == 's' && i > 1)
			|| (av[i][k] == 'e' && (flags[2] == 1 || flags[3] == 1 || flags[4] == 1)))
				return (fc_usage());
			if (av[i][k] == 'e')
				flags[0] = 1;
			else if (av[i][k] == 'r')
				flags[1] = 1;
			else if (av[i][k] == 'n')
				flags[2] = 1;
			else if (av[i][k] == 'l')
				flags[3] = 1;
			else if (av[i][k] == 's')
				flags[4] = 1;
			k++;
		}
		i++;
	}
	return (i);
}

static int	run_fc_editor(char **av, int i, int *flags, void **fc_history)
{
	(void)av;
	(void)i;
	(void)flags;
	(void)fc_history;
}

static int	run_fc_default(char **av, int i, int *flags, void **fc_history)
{
	(void)av;
	(void)i;
	(void)flags;
	(void)fc_history;
}

static int	run_fc_list(char **av, int i, int *flags, void **fc_history)
{
	(void)av;
	(void)i;
	(void)flags;
	(void)fc_history;
}

static int	run_fc_sub(char **av, int i, int *flags, void **fc_history)
{
	(void)av;
	(void)i;
	(void)flags;
	(void)fc_history;
}

static int	run_fc(char **av, int i, int *flags, void **fc_history)
{
	char	**str;

	str = (char **)vector_front(*fc_history);
	parse_string(*str);
	if (flags[0] == 1)
		return (run_fc_editor(av, i, flags, fc_history));
	if (flags[3] == 1)
		return (run_fc_list(av, i, flags, fc_history));
	if (flags[4] == 1)
		return (run_fc_sub(av, i, flags, fc_history));
	return (run_fc_default(av, i, flags, fc_history));
}

int			built_fc(char **av, char **env)
{
	int		flags[5];
	void	*fc_history;
	int		ret;

	env = NULL;
	ft_memset(flags, 0, sizeof(int) * 5);
	fc_history = vector_create(sizeof(void *));
	read_history_from_disk(&fc_history);
	ret = parse_flags(av, flags);
	if (ret == 0)
	{
		fc_history_free(fc_history);
		vector_free(&fc_history);
		return (SHERR_OK);
	}
	run_fc(av, ret, flags, &fc_history);
	fc_history_free(fc_history);
	vector_free(&fc_history);
}
