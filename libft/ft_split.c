/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamy-and <mamy-and@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 10:48:53 by mamy-and          #+#    #+#             */
/*   Updated: 2026/01/24 10:48:55 by mamy-and         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

static size_t	ft_words_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	*ft_split_dup(char const *s, char c)
{
	size_t	len;
	size_t	i;
	char	*copy_s;

	i = 0;
	len = ft_words_len(s, c);
	copy_s = malloc(sizeof(char) * (len + 1));
	if (copy_s == NULL)
		return (NULL);
	while (len > i)
	{
		copy_s[i] = s[i];
		i++;
	}
	copy_s[i] = '\0';
	return (copy_s);
}

static char	**ft_copy_words(char **array, const char *s, char c)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			array[i] = ft_split_dup(s, c);
			if (!array[i])
			{
				while (i-- > 0)
					free (array[i]);
				free(array);
				return (NULL);
			}
			i++;
			s += ft_words_len(s, c);
		}
	}
	array[i] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	size;

	if (!s)
		return (NULL);
	size = ft_count_words(s, c);
	array = malloc (sizeof(char *) * (size + 1));
	if (array == NULL)
		return (NULL);
	array = ft_copy_words(array, s, c);
	return (array);
}
