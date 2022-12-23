/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 00:43:45 by mfouadi           #+#    #+#             */
/*   Updated: 2022/12/23 04:41:35 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/***
 * if read() reads NULL it doesn't return what is left
 * 
 * 
 * 
*/

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

    if (!s)
        return (NULL);
	i = 0;
	while (*s != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)(s));
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

    if (!s)
        return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*ptr1;
	size_t	s1_len;

    if (!s1)
        return (NULL);
	s1_len = ft_strlen(s1);
	ptr1 = (char *)malloc(s1_len + NULL_CHAR);
	if (ptr1 == (void *)0)
		return (ptr1);
	while (*s1 != '\0')
		*ptr1++ = *s1++;
	*ptr1 = '\0';
	return (ptr1 - s1_len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = (char *)malloc(1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	result = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!result || !s2)
		return (free(s1), NULL);
	i = -1;
	while (s1[++i])
		result[i] = s1[i];
	j = 0;
	while (s2[j])
		result[i++] = s2[j++];
	result[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	return (free(s1), result);
}

// char	*ft_strjoin(char *s1, char *s2)
// {
// 	char	*all;
// 	char	*ptr;

// 	all = malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
// 	if (!all)
// 		return (NULL);
// 	ptr = all;
// 	while (*s1)
// 		*all ++ = *s1 ++;
// 	while (*s2)
// 		*all ++ = *s2 ++;
// 	*all = '\0';
// 	free (s1);
// 	return (ptr);
// }
