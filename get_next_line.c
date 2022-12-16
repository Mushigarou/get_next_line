/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 00:43:42 by mfouadi           #+#    #+#             */
/*   Updated: 2022/12/16 05:58:19 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Function that returns a line read from a file descriptor */
/* Read line: correct behavior
 * NULL: there is nothing else to read, or an error
 * occurred
*/

#include "get_next_line.h"

static	char	*ft_realloc(char *p)
{
	if (!p)
		return (NULL);
	else if(*p == '\n')
		return (++p);
	else if (*p == '\0')
		{
			*p = '\0';
			return (p);
		}
	else
	// printf("p IN = %s\n", p);
		while (*p != '\n' && p != '\0')
			p = p + 1;
	// printf("p OUT = %s\n", p);
	return (p);
}

char	*find_line(char *p)
{
	char	*line;
	size_t	i;

	if (!p)
		return (NULL);
	i = 0;
	if ((i = ft_strchr(p, '\n')) >= 0)
	{
		line = (char *)ft_calloc(i + NULL_CHAR + 1, 1);
		if (!line)
			return (NULL);
		line = (char *)ft_memcpy(line, p, i);
		line[i++] = '\n';
		line[i] = '\0';
		return (line);
	}
	if (*p == '\0')
		*p = '\0';
	return (p);
}

char	*read_fd(char *p, int fd)
{
	char			*tmp;
	int				bytes;

	bytes = 0;

	while (1)
	{
		tmp = (char *)ft_calloc(BUFFER_SIZE + 1, 1);
		if (!tmp)
			return (NULL);
		bytes = read(fd, tmp, BUFFER_SIZE);
		if (bytes < 0)
			return (free(tmp), free(p), NULL);
		else if (bytes == 0)
			return (free(tmp), p);
		p  = ft_strjoin(p, tmp);
		//  printf("p = %s\n", p);
		if (ft_strchr(tmp, '\n') >= 0)
			return (free(tmp), p);
		free(tmp);
		tmp = NULL;
		// printf("p = %s", p);
		// printf("%d\n", bytes);
		// printf("%s\n", tmp);
	}
	// printf("tmp 2 = %s\n", tmp);
	return (p);
}
char *get_next_line(int fd)
{
	static	char	*p;
	char			*line;

	if (BUFFER_SIZE < 0 || read(fd, 0, 0) < 0 || fd < 0)
		return (NULL);
	p = read_fd(p, fd);
	// printf("p = %s\n", p);
	if (!p)
		return (NULL);
	line = find_line(p);

	p = ft_realloc(p);
	if (*p == '\0')
		line = NULL;
	// printf("line = %s\n", line);
	return (line);
}

// PROBLEMS : 
//	1 - if no newline is found, it returns nothing
// 2 - Timeout with while()
// 3 - even if it's called many times it returns only the first line

int main()
{
	int	fd = 0;

	fd = open("get_next_line_utils.c", O_RDONLY);

	char *s;
	while((s = get_next_line(fd)))
		{
			printf("%s", s);
			// sleep(1);
		}
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s\n\n", get_next_line(fd));
	// static char *s;
	// printf("%s", read_fd(s, fd));
	// printf("%s", read_fd(s, fd));

	// printf("%s", read_fd(s, fd));


}

// char	*test(char *p)
// {
// 	p++;
// 	return (p);
// }

// int	main()
// {
// 	// static	char	*s = "hello";

// 	// while (*s)
// 	// 	{
// 	// 		printf("%s\n", test(s));
// 	// 		s++;
// 	// 	}
	
	
// }