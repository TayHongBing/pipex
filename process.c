/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 22:09:52 by thong-bi          #+#    #+#             */
/*   Updated: 2023/03/08 15:16:31 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*read_cmd(char **paths, char *cmd_arg)
{
	char	*tmp;
	char	*cmd;

	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		cmd = ft_strjoin(tmp, cmd_arg);
		free (tmp);
		if (access(cmd, F_OK) == 0)
			return (cmd);
		free(cmd);
		paths++;
	}
	return (NULL);
}

void	process_one(t_pipex pipex, char *argv[], char *envp[])
{
	dup2(pipex.end[1], 1);
	close(pipex.end[0]);
	dup2(pipex.infile, 0);
	pipex.cmd_args = ft_split(argv[2], ' ');
	pipex.cmd = read_cmd(pipex.cmd_paths, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		free_process(&pipex);
		ft_printerr(ERR_CMD);
		exit(1);
	}
	execve(pipex.cmd, pipex.cmd_args, envp);
}

void	process_two(t_pipex pipex, char *argv[], char *envp[])
{
	dup2(pipex.end[0], 0);
	close(pipex.end[1]);
	dup2(pipex.outfile, 1);
	pipex.cmd_args = ft_split(argv[3], ' ');
	pipex.cmd = read_cmd(pipex.cmd_paths, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		free_process(&pipex);
		ft_printerr(ERR_CMD);
		exit(1);
	}
	execve(pipex.cmd, pipex.cmd_args, envp);
}
