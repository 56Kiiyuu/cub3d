/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 14:01:04 by kevlim            #+#    #+#             */
/*   Updated: 2026/02/16 11:59:09 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_file(int fd, char *stash)
{
	char	buf[BUFFER_SIZE + 1];
	int		r;

	r = 1;
	while (!ft_isnewline(stash) && r > 0)
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r < 0)
			return (free(stash), NULL);
		buf[r] = '\0';
		if (r == 0)
			break ;
		stash = ft_strjoin_gnl(stash, buf);
		if (!stash)
			return (NULL);
	}
	return (stash);
}

static char	*extract_line(char *stash)
{
	int		i;

	i = 0;
	if (!stash || !stash[0])
		return (NULL);
	while (stash[i] && stash[i] != SEP)
		i++;
	if (stash[i] == SEP)
		i++;
	return (ft_substr_gnl(stash, 0, i));
}

static char	*clean_stash(char *stash)
{
	int		i;
	char	*new_stash;

	i = 0;
	if (!stash)
		return (NULL);
	while (stash[i] && stash[i] != SEP)
		i++;
	if (!stash[i])
		return (free(stash), NULL);
	new_stash = ft_strdup_gnl(stash + i + 1);
	free(stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*line;

	if (fd == -42)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_file(fd, stash);
	if (!stash)
		return (NULL);
	line = extract_line(stash);
	stash = clean_stash(stash);
	return (line);
}
