/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltenhage <ltenhage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 15:41:26 by larstenhage       #+#    #+#             */
/*   Updated: 2022/04/13 19:26:51 by ltenhage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* this function gives the first line of the given text */
char	*ft_get_line(char *save)
{
	int		i;
	char	*s;

	i = 0;
	if (save[i] == 0)
		return (0);
	while (save[i] != '\n' && save[i] != 0)
		i++;
	s = (char *) malloc(sizeof(char) * (i + 2));
	if (!s)
		return (0);
	i = 0;
	while (save[i] != '\n' && save[i] != 0)
	{
		s[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		s[i] = save[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

/* this function subtracts the first line that is going to be written
and save the remaining lines in 'save' */
char	*ft_save(char *save)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (0);
	}
	s = (char *) ft_calloc(ft_strlen(save) - i + 1, sizeof(char));
	if (!s)
		return (0);
	i++;
	j = 0;
	while (save[i])
	{
		s[j] = save[i];
		j++;
		i++;
	}
	free(save);
	return (s);
}

/*This function reads the openend textfile via fd. The buffersize decides
how many characters/bytes are being read and saved into save. */
char	*ft_read_and_save(int fd, char *save)
{
	int		read_bytes;
	char	buf[BUFFER_SIZE + 1];

	read_bytes = 1;
	while (!ft_strchr(save, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes == -1)
			return (0);
		buf[read_bytes] = '\0';
		save = ft_strjoin(save, buf);
	}
	return (save);
}

// Retreive text, fish first and store remaining.
char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (0);
	save = ft_read_and_save(fd, save);
	if (!save)
		return (0);
	line = ft_get_line(save);
	save = ft_save(save);
	return (line);
}

// int main()
// {
// 	int fd;
// 	char *line;
// 	fd = open("tekst.txt", O_RDONLY);
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		if (!line)
// 			break;
// 		printf("%s", line);
// 		free(line);
// 	}
// 	printf("%s", line);
// 	free(line);
// 	close(fd);
// 	system("leaks a.out");
// 	return (0);
// }
