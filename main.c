/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 17:29:18 by acarlett          #+#    #+#             */
/*   Updated: 2020/07/05 12:08:11 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rainbow.h"

int		error()
{
	write(1, "\n\n      SORRY, MAN :c      \n\n", 30);
	return (0);
}

float		alpha_z = 0.0;
float		alpha_x = 0.0;

int		blackground(void *mlx, void *win1, t_help *p)
{
	int i;
	int j;

	i = 0;
	j = 0;
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
	p->key = key;
	printf("key = %d and alpha_z = %f\n", key, alpha_z);
	if (key == 53)
		exit(0);
	else if (key == 124)
	{
		alpha_z += 0.005;
		blackground(p->mlx, p->win1, p);
		make_sharp(p, p->coord, p->n, p->i);
	}
	else if (key == 123)
	{
		alpha_z -= 0.005;
		blackground(p->mlx, p->win1, p);
		make_sharp(p, p->coord, p->n, p->i);
	}
	else if (key == 125)
	{
		alpha_x -= 0.005;
		blackground(p->mlx, p->win1, p);
		make_sharp(p, p->coord, p->n, p->i);
	}
	return 0;
}

int		spin_x(t_help *p, int **mas, int j, int i)
{
	int		start_z;
	int		start_y;
	int		ii;
	int		jj;

	ii = 0;
	jj = 0;
	start_y = p->start_y;
	start_z = p->start_x;
	while (jj <= p->j)
	{
		while (ii != p->i)
		{
			p->x0 = (mas[i][j] * cos(alpha_x) - start_y * sin(alpha_x));
			p->y0 = (start_y * cos(alpha_x) + mas[i][j] * sin(alpha_x));
			p->x_end = ((mas[i][j] + p->d) * cos(alpha_x) - start_y * sin(alpha_x));
			p->y_end = (start_y * cos(alpha_x) + (mas[i][j] + p->d) * sin(alpha_x));
			make_line(p, p->mlx, p->win1, p->a);
			start_z += p->d;
			ii++;
		}
		ii = 0;
		jj++;
		start_y += p->d;
	}
	jj = 0;
	ii = 0;
	start_y = p->start_y;
	start_z = p->start_x;
	while (ii <= p->i)
	{
		while (jj != p->j)
		{
			p->x0 = (mas[i][j] * cos(alpha_x) - start_y * sin(alpha_x));
			p->y0 = (start_y * cos(alpha_x) + mas[i][j] * sin(alpha_x));
			p->x_end = (mas[i][j] * cos(alpha_x) - (start_y + p->d) * sin(alpha_x));
			p->y_end = ((start_y + p->d) * cos(alpha_x) + mas[i][j] * sin(alpha_x));
			make_line(p, p->mlx, p->win1, p->a);
			jj++;
			start_y += p->d;
		}
		jj = 0;
		ii++;
		start_z += p->d;
	}
	return (0);
}

int		spin_z(t_help *p, int m, int n, int d)
{
	int		ii;
	int		jj;

	ii = p->i;
	jj = p->j;
	while (jj >= 0)
	{
		while (ii)
		{
			p->x0 = (m * cos(alpha_z) - n * sin(alpha_z));
			p->y0 = (n * cos(alpha_z) - m * sin(alpha_z));
			p->x_end = ((m + d) * cos(alpha_z) - n * sin(alpha_z));
			p->y_end = (n * cos(alpha_z) - (m + d) * sin(alpha_z));
			make_line(p, p->mlx, p->win1, p->a);
			m += d;
			ii--;
		}
		p->a = p->a + (d / 3);
		m = p->start_x;
		n += d;
		ii = p->i;
		jj--;
	}
	m = p->start_x;
	n = p->start_y;
	ii = p->i;	
	p->a = 0x00CC11;
	jj = p->j;
	while (ii >= 0)
	{
		while (jj)
		{
			p->x0 = (m * cos(alpha_z) - n * sin(alpha_z));
			p->y0 = (n * cos(alpha_z) - m * sin(alpha_z));
			p->x_end = (m * cos(alpha_z) - (n + d) * sin(alpha_z));
			p->y_end = ((n + d) * cos(alpha_z) - m * sin(alpha_z));
			make_line(p, p->mlx, p->win1, p->a);
			n += d;
			jj--;
		}
		p->a = p->a + (d / 3);
		n = p->start_y;
		m += d;
		jj = p->j;
		ii--;
	}
	return (0);
}

int		make_sharp(t_help *p, int **mas, int j, int i)
{
	int		start_x;
	int		start_y;
	int 	m;
	int		max;
	int		n;
	int		d;

	p->i = i;
	p->a =     	0x00CC11;
	p->j = j;
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
	p->start_x = start_x;
	p->start_y = start_y;
	p->d = d;
	printf ("key === %d\n", p->key);
	if (p->key == 123 || p->key == 124)
		spin_z(p, m, n, d);
	else if (p->key == 125 || p->key == 126)
		spin_x(p, p->coord, p->n, p->i);

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
	mlx_hook(p->win1, 2, 0, key_press, (void *)p);
	mlx_loop(p->mlx);
	return (0);
}