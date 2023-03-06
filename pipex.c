/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:05:47 by thong-bi          #+#    #+#             */
/*   Updated: 2023/03/06 18:46:05 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*check_path(char *envp[])
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp +5);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	pipex;

	if (argc != 5)
		return (ft_printstr(ERR_INPUT));
	pipex.infile = open(argv[1], O_RDONLY);
	if (pipex.infile < 0)
		p_error(ERR_INFILE);
	pipex.outfile = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (pipex.outfile < 0)
		p_error(ERR_OUTFILE);
	if(pipe(pipex.end) < 0)
		p_error(ERR_PIPE);
	pipex.paths = check_path(envp);
	pipex.cmd_paths = ft_split(pipex.paths, ':');
	pipex.pid1 = fork();
	if (pipex.pid1 == 0)
		process_one(pipex, argv, envp);
	pipex.pid2 = fork();
	if (pipex.pid2 == 0)
		process_two(pipex, argv, envp);
	close(pipex.end[0]);
	close(pipex.end[1]);
	waitpid(pipex.pid1, NULL, 0);
	wiatpid(pipex.pid2, NULL, 0);
	free_parent(&pipex);
	return (0);
}
