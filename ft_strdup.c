/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:20:23 by jchu              #+#    #+#             */
/*   Updated: 2023/03/07 01:10:52 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strdup(const char *s1)
{
	int		idx;
	char	*buffer;
	int		len;

	len = ft_strlen(s1);
	buffer = (char *)malloc(sizeof(char) * (len + 1));
	if (!buffer)
		return (NULL);
	idx = 0;
	while (s1[idx])
	{
		buffer[idx] = s1[idx];
		idx++;
	}
	buffer[idx] = '\0';
	return (buffer);
}
