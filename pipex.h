/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:50:05 by thong-bi          #+#    #+#             */
/*   Updated: 2023/03/07 01:13:51 by thong-bi         ###   ########.fr       */
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
	char	*paths;
	char	**cmd_paths;
	char	**cmd_args;
	char	*cmd;
}t_pipex;

void	process_one(t_pipex pipex, char *argv[], char *envp[]);
void	process_two(t_pipex pipex, char *argv[], char *envp[]);
void	p_error(char *err);
int		ft_printerr(char *err);
void	free_parent(t_pipex pipex);
void	free_process(t_pipex pipex);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *src);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
