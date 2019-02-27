/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 16:27:11 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/20 17:51:06 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**     CMDREDIR
**    /        \
** CMD          REDIR
**
**     CMD
*/

/*
**	RDLST - ReDirection LiST	(res)
**	RD - ReDirection			(root)(type: REDIRECTION)
**
**    RDLST
**   /     \
** RD       RDLST
**         /     \
**       RD       ...
*/

#include "execute.h"

static void		applycmdredir(t_astree *root)
{
	t_redir		*redir;
	t_astree	*redthree;

	redthree = root->right;
	while (redthree)
	{
		redir = get_redir(redthree->left);
		if (redir->type == REDIRECT)
			dup2(redir->fd[1], redir->fd[0]);
		if (redir->type == CLOSEFD)
			close(redir->fd[0]);
		redthree = redthree->right;
	}
}

int				execcmd(t_astree *root, int fd[2], int job, int isfork)
{
	int			status;
	pid_t		pid;

	if (root->type != CMDREDIR)
		return (execshellcmd(root, fd, job, isfork));
	if (!(pid = fork()))
	{
		applycmdredir(root);
		exit(execshellcmd(root->left, fd, job, isfork));
	}
	if (pid == -1)
		return (-1);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (EXIT_FAILURE);
}
