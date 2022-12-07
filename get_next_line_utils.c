/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 00:43:45 by mfouadi           #+#    #+#             */
/*   Updated: 2022/12/07 05:40:04 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	if (!dst || !src)
		return (NULL);
	while (n--)
		*(char *)dst++ = *(char *)src++;
	return (dst);
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