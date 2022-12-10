/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 00:43:45 by mfouadi           #+#    #+#             */
/*   Updated: 2022/12/09 06:57:41 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/***
 * if read() reads NULL it doesn't return what is left
 * 
 * 
 * 
*/

#include "get_next_line.h"

// int	get_nextline_utils(int	fd, int in, char *s)
// {
// 	void	(*p[2])(char *);
// 	char	func[2];
// 	int		i;
	
// 	// func[] = {ft_strlen(), }
// 	i += in;
// 	// (*p[0]) = ft_strlen();
// 	(p[i])(s);
// 	return (0);
// }

// using it to look for '\n'
size_t	ft_strlen(char	*s)
{
	size_t	i = 0;

	while (*s++ != '\n')
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	tmp;

	tmp = size;
	ptr = malloc(count * size);
	if (ptr == 0)
		return (NULL);
	ft_bzero(ptr, size * count);
	return (ptr);
}

void	ft_bzero(void *s, size_t n)
{
	while (n-- > 0)
		*(char *)s++ = 0;
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*d;
	char	*s;
	size_t	i;

	d = (char *)dst;
	s = (char *)src;
	if (dst == src)
		return (dst);
	i = -1;
	while (++i < n)
		d[i] = s[i];
	return ((void *)(dst));
}


void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*p;
	size_t	len;

	if (s == NULL || n == 0)
		return ("ft_memchr failed, in ft_memchr get_next_line_utils.c");
	len = 0;
	while (n-- > 0)
	{
		if (*((unsigned char *)(s)) == (unsigned char)c)
		{
			p = (char *)malloc(len + 1);
			if (p == NULL)
				return (free(p), free((void *)s), NULL);
			p[len] = '\0';
			p = (char *)ft_memcpy(p, s, len);
			len = 0;
		}
		len++;
	}
	return (p);
}


// int main()
// {
// 	printf("1 : %s\n", (ft_memchr("hello this is a test GG", '\n', 120)));
// 	// printf("2 %s\n", (ft_memchr("hello this is a test GG", '\n', 10)));
// 	// printf("3 %s\n", (ft_memchr("hello this is a test GG", '\n', 10)));
// 	// printf("4 %s\n", (ft_memchr("hello\n this is a test GG", '\n', 10)));
// 	// printf("5 %s\n", (ft_memchr("hello\n this is a test GG", '\n', 10)));
// }