#include "get_next_line.h"

long ft_strlen(char *str)
{
	long i;

	if (str)
		if (!str[0])
			return (0);
	if (!str)
		return (0);
	i = 0;
	while (str && str[i] != '\0')
		i++;
	return (i);
}

char *ft_strjoin(char *s1, char *s2)
{
	char *s;
	int i;
	int j;

	s = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		s[i] = s2[j];
		i++;
		j++;
	}
	if (s1 != NULL)
		free(s1);
	s[i] = '\0';
	return (s);
}

char *ft_strchr(const char *s, int c)
{
	int i;
	char *k;
	char l;

	l = c;
	k = (char *)s;
	i = 0;
	if (!s)
		return (0);
	while (k[i] != '\0' && k[i] != l)
		i++;
	if (k[i] == l)
	{
		return (&k[i]);
	}
	return (0);
}

char *ft_substr(char *s, unsigned int start, size_t l)
{
	size_t lns;
	char *ptr;
	size_t j;

	if (!s || !*s)
		return (0);
	j = 0;
	lns = ft_strlen(s);
	if (start > lns || l == 0)
		j = 0;
	else if (lns - start + 1 > l)
		j = l;
	else
		j = lns - start;
	ptr = (char *)malloc((1 + j));
	if (!ptr)
		return (0);
	lns = 0;
	while (s[start] && lns < j)
		ptr[lns++] = s[start++];
	ptr[lns] = '\0';
	return (ptr);
}

char *ft_strdup(char *s)
{
	int i;
	char *a;

	i = ft_strlen(s);
	a = malloc((i + 1) * sizeof(char));
	i = 0;
	if (!a)
		return (NULL);
	while (s[i] != '\0')
	{
		a[i] = s[i];
		i++;
	}
	a[i] = '\0';
	return (a);
}
