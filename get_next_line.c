/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 00:43:42 by mfouadi           #+#    #+#             */
/*   Updated: 2022/12/28 06:21:54 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Function that returns a line read from a file descriptor */
/* Read line: correct behavior
 * NULL: there is nothing else to read, or an error
 * occurred
*/

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 100000
#endif // BUFFER_SIZE

/*removing the line that was returned for the static var*/

char	*free_line(char	*p)
{
	size_t	i;
	size_t	len;
	char	*rest;
	char	*tmp;

	if (!p)
		return (NULL);
	tmp = ft_strchr(p, '\n');
	if (!tmp)
		return (NULL);
	len = ft_strlen(++tmp);
	if (len == 0)
		return (free(p), NULL);
	rest = (char *)malloc(len + 1);
	if (!rest)
		return (free(p), NULL);
	i = 0;
	while (len-- > 0)
	{
		rest[i] = tmp[i];
		i++;
	}
	rest[i] = 0;
	free(p);
	return (rest);
}

/*retriving the line to be returned*/

char	*_line_(char *p)
{
	size_t	i;
	long	len;
	char	*line;

	line = ft_strchr(p, '\n');
	if (!line)
		return (p);
	len = line - p;
	line = (char *)malloc(len + 2);
	if (!line)
		return (free(p), NULL);
	i = 0;
	while (p[i] && len-- > 0)
	{
		line[i] = p[i];
		i++;
	}
	line[i++] = '\n';
	line[i] = 0;
	return (line);
}

/*Read from fd untill encountring '\n' or EOF*/

void read_fd(char **p, int fd)
{
	char	*tmp;
	char	*temp;
	int		bytes;

	bytes = 1;
	tmp = (char *)malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (free(*p), *p = NULL ,(void)0);
	while (bytes)
	{
		bytes = read(fd, tmp, BUFFER_SIZE);
		if (bytes == 0)
			break ;
		if (bytes < 0)
			return (free(tmp), *p = NULL ,(void)0);
		tmp[bytes] = 0;
		temp = *p;
		*p = ft_strjoin(*p, tmp);
		if (!*p)
			return (free(tmp),free(*p), *p = NULL ,(void)0);
		free(temp);
		if (ft_strchr(*p, '\n'))
			return (free(tmp), tmp = NULL, (void)NULL) ;
		temp = NULL;
	}
	free(tmp);
	tmp = NULL;
}

char	*get_next_line(int fd)
{
	static char	*p;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	char *tmp;
	tmp = p;
	read_fd(&p, fd);
	if (!p)
		return (NULL);
	line = _line_(p);
	if (!line)
		return (NULL);
	if (!p)
		return free(tmp), NULL;
	p = free_line(p);
	return (line);
}
// #define M
#ifdef M
int main(void)
{
	int fd = open("file" , O_RDONLY);
	char *s = get_next_line(fd);
	printf("line| %s", s);
	free(s);
	s= get_next_line(fd);
	printf("line| %s", s);
	free(s);
	s= get_next_line(fd);
	free(s);
	s= get_next_line(fd);
	free(s);
	s= get_next_line(fd);
	free(s);
	s= get_next_line(fd);
	free(s);
	s= get_next_line(fd);
	free(s);
	s= get_next_line(fd);
	free(s);
	s= get_next_line(fd);
	free(s);
	return 0;
}
#endif