/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 00:43:42 by mfouadi           #+#    #+#             */
/*   Updated: 2022/12/22 11:39:57 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Function that returns a line read from a file descriptor */
/* Read line: correct behavior
 * NULL: there is nothing else to read, or an error
 * occurred
*/

#include "get_next_line.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif // BUFFER_SIZE

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
		return (p);
	len = ft_strlen(tmp);
	if (len == 0)
		return (NULL);
	rest = (char *)malloc(len + 1);
	if (!rest)
		return (NULL); // maybe freeing p, here
	i = 0;
	while (len)
	{
		rest[i] = tmp[i];
		i++;
		len--;
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
	
	if (!p)
		return (NULL);
	line = ft_strchr(p, '\n');
	if (!line)
		return (p);
	len = line - p;
	// printf("%ld", len);
	line = (char *)malloc(len + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (p[i] && len--)
	{
		line[i] = p[i];
		i++;
	}
	// line[i++] = '\n';
	line[i] = 0;
	return (line);
}

/*Read from fd untill encountring '\n' or EOF*/
char	*read_fd(char *p, int fd)
{
	char	*tmp;
	int		bytes;

	bytes = 1;
	while (bytes > 0)
	{
		tmp = (char *)malloc(BUFFER_SIZE + 1);
		if (!tmp)
			return (NULL);
		bytes = read(fd, tmp, BUFFER_SIZE);
		if (bytes == 0)
			return (free(tmp), NULL);
		tmp[bytes] = 0;
		// printf("$ tmp == %s$", tmp);
		p = ft_strjoin(p, tmp);
		if (ft_strchr(p, '\n'))
			break;
		free(tmp);
	}
	return (p);
}

char	*get_next_line(int fd)
{
	static	char	*p;
	char			*line;

	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);	
	p = read_fd(p, fd);
	if (!p)
		return (NULL);
	line = _line_(p);
	// printf("$p == %s$", p);
	p = free_line(p);
	// printf("$p == %s$", p);
	return (line);
}

// #define M
#ifdef M

int	main()
{
	char	*s;
	int		fd;
	
	fd = open("te.txt", O_RDONLY);

	while (1)
	{
		s = get_next_line(fd);
		if (!s)
			break;
		printf("%s", s);
		sleep(1);
		free(s);
	}
	// printf("%s", (s = get_next_line(fd)));	
	// free(s);
	// printf("%s", (s = get_next_line(fd)));	
	// free(s);
	// printf("%s", (s = get_next_line(fd)));	
	// free(s);
	return (0);
}
#endif // M