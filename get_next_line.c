/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 00:43:42 by mfouadi           #+#    #+#             */
/*   Updated: 2022/12/07 06:30:30 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Function that returns a line read from a file descriptor */
/* Read line: correct behavior
 * NULL: there is nothing else to read, or an error
 * occurred
*/

#include "get_next_line.h"
// # define BUFFER_SIZE 42

char	*get_next_line(int fd)
{
	int	buff;
	char	*p;
	static long	len;
	int	bytes;
	int i = 0;
	
	bytes = 0;
	i = 0;
	len = BUFFER_SIZE;
	if (BUFFER_SIZE <= 0)
		return (NULL);
	p = (char *)malloc(10000);
	if (p == NULL)
		return (free(p), NULL);
	// read(fd, p, BUFFER_SIZE);
	while ((bytes = read(fd, &buff, 1)) != 0 && len > 0)
	{
		p[i++] = (char)buff;
		// printf("%ld", len);
		if (buff != '\n')
		{
			// p[i++] = '\n';
			return (p);
		}
		// else
		// printf("in");
		// else
		// 	{
		// 		p[i] = '\0';
		// 		return NULL;
		// 	}
		// printf("this is bytes ->%zu<-\n", len);
		// printf("%zu\n", len);
		len--;
	}
	
	if (bytes < 0)
		return (free(p), "bytes < 0");
	else if (bytes == 0)
	{	
		// p = NULL;
		return (NULL);
	}
	if (buff == EOF)
	{
		// p[i] = '\0';
		return (free(p), "buff = EOF");
	}
	if ((char)buff == '\n')
		p[i] = '\n';
	
	if (len == BUFFER_SIZE - 1)
		len = 0;
	// if (buff < 0)
	// 	return (NULL);
	// p = (char *)malloc(i + 1);
	// p[i] = '\0';
	// if (read(fd, 0, 1) == 0)
	// 	return (NULL);
	// p[++i] = '\n';
	// p[i] = '\0';
	// printf("hey");
	return (p);
}

int	main()
{
	int	fd;
	int i;
	char *s;

	i = 10;
  	// static char	p[1024];

	// fd = open("ReAdFrOmMe.txt", O_RDWR | O_CREAT, 0777);
	fd = open("get_next_line_utils.c", O_RDONLY);
	// write(fd, "hey", 3);
	// read(fd, p, 3);
	// printf("%s\n", p);
	// read(fd, p, 3);
	// printf("%s\n", p);
	// read(fd, p, 3);
	// printf("%s\n", p);
	// read(fd, p, 3);
	// printf("%s\n", p);

	while ((s = get_next_line(fd)) != NULL)
		printf("%s", s);
	// while (i-- > 0)
	// 	printf("%s", get_next_line(fd));
	// while (read(fd, char c))
	// i = 100;
	// while (i > 0)
	// {
	// 	printf("%s", get_next_line(fd));
	// 	i--;
	// }
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	close(fd);
}
