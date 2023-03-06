/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 00:05:09 by thong-bi          #+#    #+#             */
/*   Updated: 2023/03/07 00:13:05 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_parent(t_pipex pipex)
{
	int	i;

	i = 0;
	close(pipex.infile);
	close(pipex.outfile);
	while (pipex.cmd_paths[i++])
		free(pipex.cmd_paths[i]);
	free(pipex.cmd_paths);
}

void	free_process(t_pipex pipex)
{
	int	i;

	i = 0;
	while (pipex.cmd_args[i++])
		free(pipex.cmd_args[i]);
	free(pipex.cmd_args);
	free(pipex.cmd);
}
