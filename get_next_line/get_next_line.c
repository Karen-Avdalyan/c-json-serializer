#include "get_next_line.h"
#include <string.h>
#include <fcntl.h>

char *my_while(int fd, long readsize, char *sline)
{
	char buff[BUFFER_SIZE + 1];

	while (1)
	{
		readsize = read(fd, buff, BUFFER_SIZE);
		buff[readsize] = '\0';
		if (readsize == -1)
			return (0);
		if (!sline)
			sline = ft_strdup(buff);
		else
			sline = ft_strjoin(sline, buff);
		if (ft_strchr(buff, '\n') || readsize == 0)
			break;
	}
	return (sline);
}

char *get_next_line(int fd)
{
	long index;
	long readsize;
	static char *sline;
	char *line;
	char *tmp;

	readsize = 1;
	if (readsize == 0)
		return (NULL);
	sline = my_while(fd, readsize, sline);
	index = ft_strlen(sline) - ft_strlen(ft_strchr(sline, '\n')) + 1;
	line = ft_substr(sline, 0, index);
	tmp = sline;
	sline = ft_substr(sline, index, ft_strlen(sline));
	free(tmp);
	return (line);
}