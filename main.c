/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 17:29:18 by acarlett          #+#    #+#             */
/*   Updated: 2020/07/04 20:08:45 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rainbow.h"

int		error()
{
	write(1, "\n\n      SORRY, MAN :c      \n\n", 30);
	return (0);
}

int		alpha = 32;

int		blackground(void *mlx, void *win1, t_help *p)
{
	int i;
	int j;

	i = 0;
	j = 0;
	write (1, "RT", 2);
	while (j != WIN_Y)
	{
		p->x0 = 0;
		p->y0 = j;
		p->x_end = WIN_X;
		p->y_end = j;
		make_line(p, mlx, win1, 0x000000);
		j++;
	}
	return (0);
}

int		key_press(int key, void *l)
{
	t_help	*p;

	p = (t_help *)l;
	printf("%d and alpha = %d\n", key, alpha);
	if (key == 53)
		exit(0);
	else if (key == 124)
	{
		alpha++;
		blackground(p->mlx, p->win1, p);
		make_sharp(p, p->coord, p->n, p->i);
	}
	else if (key == 123)
	{
		alpha--;
		blackground(p->mlx, p->win1, p);
		make_sharp(p, p->coord, p->n, p->i);
	}
	return 0;
}

int		make_sharp(t_help *p, int **mas, int j, int i)
{
	int		start_x;
	int		start_y;
	int 	m;
	int		ii;
	int		jj;
	int		max;
	int		n;
	int		d;

	ii = i;
	p->a =     	0x00CC11;
	jj = j;
	max = MAX(i, j);
	d = (WIN_X - 200) / max;
	if (max == i)
	{
		start_x = 100;
		start_y = (((WIN_X / d) - j) / 2) * d;
	}
	else if (max == j)
	{
		start_x = (((WIN_X / d) - i) / 2) * d;
		start_y = 100;
	}
	m = start_x;
	n = start_y;
	printf ("x = %d  y = %d  delta = %d\n alpha = %d\n", i, j, d, alpha);
	while (j >= 0)
	{
		while (i)
		{
			p->x0 = (m * cos(alpha) - n * sin(alpha));
			p->y0 = (n * cos(alpha) - m * sin(alpha));
			p->x_end = ((m + d) * cos(alpha) - n * sin(alpha));
			p->y_end = (n * cos(alpha) - (m + d) * sin(alpha));
			make_line(p, p->mlx, p->win1, p->a);
			m += d;
			i--;
		}
		p->a = p->a + (d / 3);
		m = start_x;
		n += d;
		i = ii;
		j--;
	}
	m = start_x;
	n = start_y;
	i = ii;	
	p->a = 0x00CC11;
	j = jj;
	while (i >= 0)
	{
		while (j)
		{
			p->x0 = (m * cos(alpha) - n * sin(alpha));
			p->y0 = (n * cos(alpha) - m * sin(alpha));
			p->x_end = (m * cos(alpha) - (n + d) * sin(alpha));
			p->y_end = ((n + d) * cos(alpha) - m * sin(alpha));
			make_line(p, p->mlx, p->win1, p->a);
			n += d;
			j--;
		}
		p->a = p->a + (d / 3);
		n = start_y;
		m += d;
		j = jj;
		i--;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_help				*p;
	int					fd;
	char				*s;
	char				**line;
	int					i;
	int					**mas;
	int					j;
	int					m;
	
	p = malloc(sizeof(t_help));
	p->a =     	0x00CCFF;
	i = 0;
	j = 0;
	m = 0;
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &s) > 0)
	{
		i++;
		m = ft_takewith(s);
		free(s);
	}
	close(fd);
	fd = open(argv[1], O_RDONLY);
	line = malloc(sizeof(char *) * i);
	mas = malloc(sizeof(int *) * i);
	while(get_next_line(fd, &(line[j])) > 0)
	{
		mas[j] = malloc(sizeof(int) * m);
		j++;
	}
	m = 0;
	j = 0;
	while (m != i)
	{
		while (*line[m] != '\0')
		{
			mas[m][j] = ft_atoi(line[m]);
			line[m] += (ft_howlong(mas[m][j]) + 1);
			j++;
		}
		p->n = j;
		j = 0;
		m++;
	}
	p->coord = mas;
	p->i = i;
	p->mlx = mlx_init();
	p->win1 = mlx_new_window(p->mlx, WIN_X, WIN_Y, "Holla!");
	// make_sharp(p, mas, i, p->n);
	mlx_hook(p->win1, 2, 0, key_press, (void *)p);
	mlx_loop(p->mlx);
	return (0);
}