/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:50:05 by thong-bi          #+#    #+#             */
/*   Updated: 2023/02/21 15:50:05 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/wait.h>
# include <string.h>

# define ERR_INFILE "Invalid infile.\n"
# define ERR_OUTFILE "Invalid outfile.\n"
# define ERR_INPUT "Invalid number of input.\n"
# define ERR_PIPE "Pipe error.\n"
# define ERR_CMD "Command not found.\n"

typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	int		end[2];
	int		infile;
	int		outfile;
	char*	paths;
	char**	cmd_paths;
	char**	cmd_args;
	char*	cmd;
}t_pipex;



