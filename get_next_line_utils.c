/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/22 13:18:14 by dreijans      #+#    #+#                 */
/*   Updated: 2023/01/09 17:36:12 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*new_str;
	size_t		strlen;

	strlen = ft_strlen((char *)s);
	if (start >= strlen)
		len = 0;
	else if (len > strlen - start)
		len = strlen - start;
	if (len == 0)
		return (NULL);
	new_str = malloc(sizeof(char) * (len + 1));
	if (new_str == NULL)
		return (NULL);
	if (strlen == 0 || len == 0)
		new_str[0] = 0;
	else
		ft_strlcpy(new_str, &s[start], len + 1);
	return (new_str);
}

/*concatenates two strings*/
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize < dst_len)
		return (dstsize + src_len);
	ft_strlcpy(dst + dst_len, src, dstsize - dst_len);
	return (dst_len + src_len);
}

// /*Allocates (with malloc(3)) and returns a new
// string, which is the result of the concatenation
// of ’s1’ and ’s2’.
// constant is just for reading but i want to edit s1*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*new_str;
	size_t		len;
	size_t		i;

	len = (ft_strlen(s1) + ft_strlen(s2)) + 1;
	new_str = (char *)malloc(sizeof (char) * len);
	if (new_str == NULL)
		return (NULL);
	while (s1[i] != '\0' && (i + 1) < len)
	{
		new_str[i] = s1[i];
		i++;
	}
	// if (i < len)
	// 	new_str[i]= '\0';

	// ft_strlcat(new_str, s2, len);
	return (new_str);
}

/*
function allocates sufficient memory 
1)for a copy of the string s1,
2)does the copy 
3)and returns a pointer to it.
*/

char	*ft_strdup(char *s1)
{
	size_t	len;
	char	*s2;
	size_t	i;

	if (s1 != NULL)
		len = ft_strlen(s1) + 1;
	s2 = malloc(len * sizeof (char));
	if (s2 == NULL)
		return (NULL);
	i = 0;
	if (s1[i] == '\0' && s2[i] == '\0')
		return (NULL);
	while (i < len)
	{
		s1[i] = s2[i];
		i++;
	}
	s2[len - 1] = '\0';
	return (s2);
}

// /* copies n bytes from memory area to dst */
// void	*ft_memcpy(void *dst, const void *src, size_t n)
// {
// 	char	*ptrd;
// 	char	*ptrs;
// 	size_t	i;

// 	i = 0;
// 	ptrd = (char *)dst;
// 	ptrs = (char *)src;
// 	if (ptrd == '\0' && ptrs == '\0')
// 		return (NULL);
// 	while (i < n)
// 	{
// 		*ptrd = *ptrs;
// 		ptrd++;
// 		ptrs++;
// 		i++;
// 	}
// 	return (dst);
// }

// /*copy and concatenate strings */
// size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
// {
// 	size_t	i;

// 	i = 0;
// 	while (src[i] != '\0' && (i + 1) < dstsize)
// 	{
// 		dst[i] = src[i];
// 		i++;
// 	}
// 	if (i < dstsize)
// 		dst[i] = '\0';
// 	return (ft_strlen(src));
// }
/*
Function name: 		get_next_line

Prototype: 			char *get_next_line(int fd);

Turn in files : 	get_next_line.c, get_next_line_utils.c,
					get_next_line.h

Parameters: fd: 	The file descriptor to read from

Return value: 		Read line: correct behavior
					NULL: there is nothing else to read, or an error
					occurred
				
External functs: 	read, malloc, free

Description: 		Write a function that returns a line read from a
					file descriptor
*/