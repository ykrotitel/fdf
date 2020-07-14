/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 21:18:54 by vabraham          #+#    #+#             */
/*   Updated: 2020/07/14 18:50:25 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rainbow.h"

static int		error(char **f)
{
	free(*f);
	return (-1);
}

static int		check_error(char **s, int fd, char **tmp, int n)
{
	if (!(s[fd] = ft_strdup(*tmp + n)))
		return (error(tmp));
	free(*tmp);
	return (1);
}

static int		new(char **s, char **a, int fd, int col)
{
	int		i;
	char	*tmp;
	char	c;

	c = '\n';
	if (!col)
		c = '\0';
	i = 0;
	while (s[fd][i] != c)
		i++;
	if (!(*a = (char *)malloc(sizeof(char) * (i + 1))))
		return (-1);
	ft_strncpy(*a, s[fd], (size_t)i);
	(*a)[i] = '\0';
	if (!(tmp = ft_strdup(ft_strchr(s[fd], c))))
		return (error(&s[fd]));
	free(s[fd]);
	if (*tmp)
		return (check_error(s, fd, &tmp, 1));
	return (check_error(s, fd, &tmp, 0));
}

static int		ret(char **s, char **a, int fd, int col)
{
	if (col == -1)
		return (-1);
	else if (col == 0 && (!s[fd] || !s[fd][0]))
		return (0);
	return (new(s, a, fd, col));
}

int				get_next_line(const int fd, char **a)
{
	char		buf[BUFF_SIZE + 1];
	int			col;
	char		*tmp;
	static char	*s[10240];

	col = -2;
	if (fd < 0 || fd > 10239 || BUFF_SIZE < 1 || BUFF_SIZE > 2147483647)
		return (-1);
	if (!s[fd])
		if (!(s[fd] = ft_strnew(1)))
			return (-1);
	if (!ft_strchr(s[fd], '\n'))
	{
		while ((col = read(fd, buf, BUFF_SIZE)) > 0)
		{
			buf[col] = '\0';
			if (!(tmp = ft_strjoin(s[fd], buf)))
				return (error(&s[fd]));
			free(s[fd]);
			s[fd] = tmp;
			if (ft_strchr(buf, '\n'))
				break ;
		}
	}
	return (ret(s, a, fd, col));
}
