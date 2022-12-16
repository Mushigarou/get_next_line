/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 00:43:45 by mfouadi           #+#    #+#             */
/*   Updated: 2022/12/15 06:27:55 by mfouadi          ###   ########.fr       */
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
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s++ != '\0')
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr == 0)
		return (NULL);
	ft_bzero(ptr, size * count);
	return (ptr);
}

void	ft_bzero(void *s, size_t n)
{
	while (n-- > 0)
		*(char *)s++ = '\0';
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
	while (++i < n && s[i])
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

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len_src;
	size_t	len_dst;

	len_src = ft_strlen(src);
	if ((dstsize == 0 && dst == NULL) || dstsize == 0)
		return (len_src);
	len_dst = ft_strlen(dst);
	if (dstsize < len_dst)
		return (dstsize + len_src);
	i = len_dst;
	while (*src && i++ < dstsize - 1)
		*(dst++ + len_dst) = *src++;
	*(dst + len_dst) = '\0';
	return (len_dst + len_src);
}


int	ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (-1);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	if ((char)c == '\0')
		return (i);
	return (-1);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	len;
	size_t	i;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	len = ft_strlen(s1) + ft_strlen(s2);
	new_str = (char *)ft_calloc(len + NULL_CHAR, 1);
	if (new_str == NULL)
		return (new_str);
	len = 0;
	i = 0;
	while (s1[i])
		new_str[len++] = s1[i++];
	i = 0;
	while (s2[i])
		new_str[len++] = s2[i++];
	return (new_str);
}

char	*ft_strdup(const char *s1)
{
	char	*ptr1;
	size_t	s1_len;

	s1_len = ft_strlen(s1);
	ptr1 = (char *)malloc(s1_len + NULL_CHAR);
	if (ptr1 == (void *)0)
		return (ptr1);
	while (*s1 != '\0')
		*ptr1++ = *s1++;
	*ptr1 = '\0';
	return (ptr1 - s1_len);
}


// int main()
// {
// 	// printf("1 : %s\n", (ft_memchr("hello this is a test GG", '\n', 120)));
// 	printf("%d", ft_strchr("hellof\njkhkhfkshf", '\0'));
// 	// printf("2 %s\n", (ft_memchr("hello this is a test GG", '\n', 10)));
// 	// printf("3 %s\n", (ft_memchr("hello this is a test GG", '\n', 10)));
// 	// printf("4 %s\n", (ft_memchr("hello\n this is a test GG", '\n', 10)));
// 	// printf("5 %s\n", (ft_memchr("hello\n this is a test GG", '\n', 10)));
// }