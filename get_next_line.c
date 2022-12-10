/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 00:43:42 by mfouadi           #+#    #+#             */
/*   Updated: 2022/12/10 05:56:26 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Function that returns a line read from a file descriptor */
/* Read line: correct behavior
 * NULL: there is nothing else to read, or an error
 * occurred
*/

#include "get_next_line.h"

size_t	get_len(char *p, size_t n)
{
	// size_t	i;
	// int		state;
	if (!p || n <= 0)
		return 0;
	if (p[i] == '\n' || p[i] == '\0')
		return (n);
	else
		i++;
		get_len(&p[i + 1], n - 1);
	// state = 0;
	// i = 0;
	// while (n-- && p[i] != (char)'\0')
	// {
	// 	if ((int)p[i] == '\n')
	// 		return (i);
	// 	i++;
	// }
	// if (state == 0)
	// 	return (i);
	return (0);
}

static	char	*ft_realloc(char *p, size_t line_len)
{
	char		*tmp;
	long long	text_left;
	size_t		cur_pos;

	if (!p || line_len == 0)
		return (NULL);
	text_left = BUFFER_SIZE - line_len;
	if (text_left <= 0)
		return (free(p), p = NULL, NULL);
	cur_pos = line_len;
	tmp = (char *)ft_calloc(text_left + NULL_CHAR, 1);
	if (!tmp)
		return (free(p), NULL);
	tmp[text_left] = '\0';
	while(cur_pos < BUFFER_SIZE)
	{
		ft_memcpy((void *)tmp, (void *)(&p[line_len]), text_left);
		cur_pos++;
	}
	// printf("\n tmp(realloc)---->%s\n", p);
	free(p);
	p = NULL;
	return (tmp);
}

char	*get_next_line(int fd)
{
	static	char	*p;
	char			*line;
	int				bytes;
	size_t			line_len;
	
	bytes = 0;
	line_len = 0;
	
	if (fd < 0)
		return (NULL);
	/*allocating enough for BUFFER_SIZE*/

	p = (char *)ft_calloc((BUFFER_SIZE + 1), 1);
	if (!p)
		return (NULL);
	bytes = read(fd, p, BUFFER_SIZE);
	// printf("\n p(realloc)---->%s\n", p);
	if (bytes < 0)
		return (free(p), NULL);
	if (bytes == 0)
		return NULL;
		// printf("Hey\n");

/*Reading from the fd and storing in p*/
	// printf("bytes = %d\n", bytes);
	// printf("\nthis is p---->%s\n", p);

/*Getting the len of the line to be returned*/
	line_len = get_len(p, bytes);
	// if(line_len == 0)
	// 	return (NULL);
	printf("line_len = %zu\n", line_len);

/*Allocating for line based on len*/
	if (p[line_len] == '\n')
		line_len++;
	line = (char *)ft_calloc((line_len + 1), 1);
	// if (line == NULL)
	// 	return (free(p), NULL);

/*copying *p to *line, line_len bytes*/
	ft_memcpy(line, p, line_len);
	// if (!line)
	// 	return (free(p), free(line), NULL);
	// // printf("%s", line);

/*adding \n to line*/
	if (p[line_len] == '\n')
			line[line_len] = '\n';

/*reallocating p*/
	p = ft_realloc(p, line_len);
	// if (p == NULL)
	// 	return (NULL);
	// printf("hey\n");
	// printf("\n p(realloc)---->%s\n", p);
	// printf("\n******************\n\nResult : ");
	return (line);
}

int	main()
{
	int	fd;
	// int i;

  	// static char	p[1024];

	// fd = open("ReAdFrOmMe.txt", O_RDWR | O_CREAT, 0777);
	fd = open("te.txt", O_RDONLY);
	// write(fd, "hey", 3);
	// read(fd, p, 3);
	// printf("%s\n", p);
	// read(fd, p, 3);
	// printf("%zd\n", read(fd, p, 100));
	
	// printf("%s\n", p);
	// read(fd, p, 3);
	// printf("%s\n", p);
	//**************
	// char *s;
	// while (1)
	// {
	// 	s = get_next_line(fd);
	// 	printf("%s", s);
	// 	if (!s)
	// 		break;
	// 	//sleep(1);
	// }

	// char *s;
	// while ((s = get_next_line(fd)))
	// 	{
	// 		printf("%s", s);
	// 		// sleep(1);
	// 	}

	// int	i;
	// i = 10;
	// while (i-- > 0)
	// 	printf("%s", get_next_line(fd));
	// while (read(fd, char c))
	// i = 100000000;
	// while (i > 0)
	// {
	// 	printf("%s", get_next_line(fd));
	// 	i--;
	// }
	// printf("%zu", get_len(s));
	// printf("%s", get_next_line(fd));
	// // printf("%s", ft_realloc("hellochds", 0));
	// printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));

	// printf("%s", get_next_line(fd));
	close(fd);
	return (0);
}