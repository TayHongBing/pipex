/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:17:21 by thong-bi          #+#    #+#             */
/*   Updated: 2023/03/08 15:09:47 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while(s[i])
		i++;
	return (i);
}

void	p_error(char *err)
{
	perror(err);
	exit (1);
}

int	ft_printerr(char *err)
{
	write(2, err, ft_strlen(err));
	return (1);
}
