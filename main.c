/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 17:29:18 by acarlett          #+#    #+#             */
/*   Updated: 2020/07/13 16:37:46 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rainbow.h"

int		error()
{
	write(1, "\n\n      SORRY, MAN :c      \n\n", 30);
	return (0);
}

float		alpha_x = 0.0;
float		alpha_y = 0.0;
float		alpha_z = 0.0;
float		le_perspective = 600.0;
float 		kof = 2.5;

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
		make_line(p, mlx, win1, 0x303030);
		j++;
	}
	return (0);
}

int		key_press(int key, void *l)
{
	t_help	*p;

	p = (t_help *)l;
	p->key = key;
	printf ("key == %d\n", key);
	if (key == 53)
		exit(0);
	else if (key == 124)
	{
		alpha_z += 0.1;
		blackground(p->mlx, p->win1, p);
		make_sharp(p, p->coord, p->n, p->i);
	}
	else if (key == 123)
	{
		alpha_z -= 0.1;
		blackground(p->mlx, p->win1, p);
		make_sharp(p, p->coord, p->n, p->i);
	}
	else if (key == 125)
	{
		alpha_x -= 0.1;
		blackground(p->mlx, p->win1, p);
		make_sharp(p, p->coord, p->n, p->i);
	}
	else if (key == 126)
	{
		alpha_x += 0.1;
		blackground(p->mlx, p->win1, p);
		make_sharp(p, p->coord, p->n, p->i);
	}
	else if (key == 19)
	{
		make_increase(p, p->coord, key);
		blackground(p->mlx, p->win1, p);
		make_sharp(p, p->coord, p->n, p->i);
	}
	else if (key == 20)
	{
		make_unincrease(p, p->coord, key);
		blackground(p->mlx, p->win1, p);
		make_sharp(p, p->coord, p->n, p->i);
	}
	else if (key == 33)
	{
		alpha_y += 0.1;
		blackground(p->mlx, p->win1, p);
		make_sharp(p, p->coord, p->n, p->i);
	}
	else if (key == 30)
	{
		alpha_y -= 0.1;
		blackground(p->mlx, p->win1, p);
		make_sharp(p, p->coord, p->n, p->i);
	}
	mlx_put_image_to_window(p->mlx, p->win1, p->img, 0, 0);
	return 0;
}

int		make_increase(t_help *p, int **mas, int key)
{
	int ii;
	int jj;

	ii = 0;
	jj = 0;
	while (ii <= p->i)
	{
		while (jj <= p->n)
		{
			mas[ii][jj] *= 2;
			jj++;
		}
		jj = 0;
		ii++;
	}
	return (0);
}

int		make_unincrease(t_help *p, int **mas, int key)
{
	int ii;
	int jj;

	ii = 0;
	jj = 0;
	while (ii <= p->i)
	{
		while (jj <= p->n)
		{
			mas[ii][jj] /= 2;
			jj++;
		}
		jj = 0;
		ii++;
	}
	return (0);
}


int		spin_x(t_help *p, int m, int n, int d, int **mas)
{
	int		ii;
	int		jj;
	int		startx;
	int 	starty;

	ii = 0;
	jj = 0;
	startx = n;
	starty = m;
	p->a = 0x800000;
	while (jj <= p->i)
	{
		while (ii < p->j)
		{
			float tx0 = (startx - WIN_X / 2);
			float ty0 = (float)(starty - WIN_Y / 2) * cos(alpha_x) + (float)mas[jj][ii] * sin(alpha_x);
			float tz0 = (float)mas[jj][ii] * cos(alpha_x) - (float)(starty - WIN_Y / 2) * sin(alpha_x);
			float tx1 = (startx - WIN_X / 2) + p->d;
			float ty1 = (float)(starty - WIN_Y / 2) * cos(alpha_x) + (float)mas[jj][ii + 1] * sin(alpha_x);
			float tz1 = (float)mas[jj][ii + 1] * cos(alpha_x) - (float)(starty - WIN_Y / 2) * sin(alpha_x);

			float t_tx0 = tx0 * cos(alpha_y) + tz0 * sin(alpha_y);
			float t_ty0 = ty0;
			float t_tz0 = tz0 * cos(alpha_y) - tx0 * sin(alpha_y);
			float t_tx1 = tx1 * cos(alpha_y) + tz1 * sin(alpha_y);
			float t_ty1 = ty1;
			float t_tz1 = tz1 * cos(alpha_y) - tx1 * sin(alpha_y); 

			p->x0 = (t_tx0 * cos(alpha_z) - t_ty0 * sin(alpha_z));
			p->y0 = (t_ty0 * cos(alpha_z) + t_tx0 * sin(alpha_z));
			p->x_end = (t_tx1 * cos(alpha_z) - t_ty1 * sin(alpha_z));
			p->y_end = (t_ty1 * cos(alpha_z) + t_tx1 * sin(alpha_z));

			float per0 = le_perspective / (le_perspective - t_tz0);
			float per1 = le_perspective / (le_perspective - t_tz1);
			
			p->x0 = (float)p->x0 * per0 + (WIN_X / 2);
			p->y0 = (float)p->y0 * per0 + (WIN_X / 2);
			p->x_end = (float)p->x_end * per1 + (WIN_X / 2);
			p->y_end = (float)p->y_end * per1 + (WIN_X / 2);

			if (p->x0 < 0 || p->y0 < 0 || p->x0 > WIN_X || p->y0 > WIN_Y)
			{
				p->buff = p->x_end;
				p->x_end = p->x0;
				p->x0 = p->buff;
				p->buff = p->y_end;
				p->y_end = p->y0;
				p->y0 = p->buff;
			}
			if (t_tz0 * kof < le_perspective && t_tz1 * kof < le_perspective)
				make_line(p, p->mlx, p->win1, p->a);
			startx += d;
			ii++;
		}	
		p->a = p->a + (float)((d / 3));
		startx = n;
		starty += d;
		ii = 0;
		jj++;
	}
	ii = 0;
	jj = 0;
	startx = n;
	starty = m;
	p->a = 0x800000;
	while (jj <= p->j)
	{
		while (ii < p->i)
		{
			float tx0 = (startx - WIN_X / 2);
			float ty0 = (float)(starty - WIN_Y / 2) * cos(alpha_x) + (float)mas[ii][jj] * sin(alpha_x);			
			float tz0 = (float)mas[ii][jj] * cos(alpha_x) - (float)(starty - WIN_Y / 2) * sin(alpha_x);
			float tx1 = (startx - WIN_X / 2);
			float ty1 = (float)((starty - WIN_Y / 2) + p->d) * cos(alpha_x) + (float)mas[ii + 1][jj] * sin(alpha_x);
			float tz1 = (float)mas[ii + 1][jj] * cos(alpha_x) - (float)((starty + p->d) - WIN_Y / 2) * sin(alpha_x);

			float t_tx0 = tx0 * cos(alpha_y) + tz0 * sin(alpha_y);
			float t_ty0 = ty0;
			float t_tz0 = tz0 * cos(alpha_y) - tx0 * sin(alpha_y);
			float t_tx1 = tx1 * cos(alpha_y) + tz1 * sin(alpha_y);
			float t_ty1 = ty1;
			float t_tz1 = tz1 * cos(alpha_y) - tx1 * sin(alpha_y);

			p->x0 = (t_tx0 * cos(alpha_z) - t_ty0 * sin(alpha_z));
			p->y0 = (t_ty0 * cos(alpha_z) + t_tx0 * sin(alpha_z));
			p->x_end = (t_tx1 * cos(alpha_z) - t_ty1 * sin(alpha_z));
			p->y_end = (t_ty1 * cos(alpha_z) + t_tx1 * sin(alpha_z));

			float perr0 = le_perspective / (le_perspective - t_tz0);
			float perr1 = le_perspective / (le_perspective - t_tz1);

			p->x0 = (float)p->x0 * perr0+ (WIN_X / 2);
			p->y0 = (float)p->y0 * perr0 + (WIN_X / 2);
			p->x_end = (float)p->x_end * perr1 + (WIN_X / 2);
			p->y_end = (float)p->y_end * perr1 + (WIN_X / 2);
			
			if (p->x0 < 0 || p->y0 < 0 || p->x0 > WIN_X || p->y0 > WIN_Y)
			{
				p->buff = p->x_end;
				p->x_end = p->x0;
				p->x0 = p->buff;
				p->buff = p->y_end;
				p->y_end = p->y0;
				p->y0 = p->buff;
			}
			if (t_tz0 * kof < le_perspective && t_tz1 * kof < le_perspective)
				make_line(p, p->mlx, p->win1, p->a);
			starty += d;
			ii++;
		}
		p->a = p->a + (float)((d / 3));
		starty = m;
		startx += d;
		ii = 0;
		jj++;
	}
	return (0);
}

int		spin_z(t_help *p, int m, int n, int d)
{
	int		ii;
	int		jj;
	int		startx;
	int 	starty;

	ii = p->i;
	jj = p->j;
	startx = n;
	starty = m;
	while (ii >= 0)
	{
		while (jj > 0)
		{
			p->x0 = ((startx - (WIN_X / 2)) * cos(alpha_z) - (starty - (WIN_Y / 2)) * sin(alpha_z) + (WIN_X / 2));
			p->y0 = ((starty - (WIN_Y / 2)) * cos(alpha_z) + (startx - (WIN_X / 2)) * sin(alpha_z) + (WIN_X / 2));
			p->x_end = (((startx - (WIN_X / 2)) + d) * cos(alpha_z) - (starty - (WIN_Y / 2)) * sin(alpha_z)) + (WIN_X / 2);
			p->y_end = ((starty - (WIN_Y / 2)) * cos(alpha_z) + ((startx - (WIN_X / 2)) + d) * sin(alpha_z)) + (WIN_X / 2);
			if (p->x0 < 0 || p->y0 < 0 || p->x0 > WIN_X || p->y0 > WIN_Y)
			{
				p->buff = p->x_end;
				p->x_end = p->x0;
				p->x0 = p->buff;
				p->buff = p->y_end;
				p->y_end = p->y0;
				p->y0 = p->buff;
			}
			make_line(p, p->mlx, p->win1, p->a);
			startx += d;
			jj--;
		}	
		p->a = p->a + (d / 2);
		startx = n;
		starty += d;
		jj = p->j;
		ii--;
	}
	startx = p->start_x;
	starty = p->start_y;
	starty = m;
	startx =n;
	p->a = 0x00CC11;
	ii = p->i;	
	jj = p->j;
	while (jj >= 0)
	{
		while (ii > 0)
		{
			p->x0 = ((startx - (WIN_X / 2)) * cos(alpha_z) - (starty - (WIN_Y / 2)) * sin(alpha_z)) + (WIN_X / 2);
			p->y0 = ((starty - (WIN_Y / 2)) * cos(alpha_z) + (startx - (WIN_X / 2)) * sin(alpha_z)) + (WIN_X / 2);
			p->x_end = ((startx - (WIN_X / 2)) * cos(alpha_z) - ((starty - (WIN_Y / 2)) + d) * sin(alpha_z)) + (WIN_X / 2);
			p->y_end = (((starty - (WIN_Y / 2)) + d) * cos(alpha_z) + (startx - (WIN_X / 2)) * sin(alpha_z)) + (WIN_X / 2);
			if (p->x0 < 0 || p->y0 < 0 || p->x0 > WIN_X || p->y0 > WIN_Y)
			{
				p->buff = p->x_end;
				p->x_end = p->x0;
				p->x0 = p->buff;
				p->buff = p->y_end;
				p->y_end = p->y0;
				p->y0 = p->buff;
			}
			make_line(p, p->mlx, p->win1, p->a);
			starty += d;
			ii--;
		}
		p->a = p->a + (d / 2);
		starty = m;
		startx += d;
		ii = p->i;
		jj--;
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
	p->a = 0x800000;
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
		spin_x(p, m, n, d, mas);
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
	char				*buff;
	int					j;
	int					m;
	
	p = malloc(sizeof(t_help));
	p->mlx = mlx_init();
	p->win1 = mlx_new_window(p->mlx, WIN_X, WIN_Y, "Holla!");
	p->img = mlx_new_image(p->mlx, WIN_X, WIN_Y);
	p->data = (int *)mlx_get_data_addr(p->img, &(p->q1), &(p->q2), &(p->q3));
	write (1, "RT\n", 3);
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
	p->n = m - 1;
	p->m = m - 0;
	close(fd);
	fd = open(argv[1], O_RDONLY);
	line = malloc(sizeof(char *) * i);
	mas = malloc(sizeof(int *) * i);
	while(get_next_line(fd, &(line[j])) > 0)
	{
		mas[j] = malloc(sizeof(int) * m);
		j++;
	}
	p->j = j - 1;
	j = 0;
	m = 0;
	while (j <= p->j)
	{
		buff = line[j];
		while (m != p->m)
		{
			while (*buff == ' ')
				buff++;
			mas[j][m] = ft_atoi(buff);
			while (*buff != ' ')
				buff++;
			m++;
		}
		m = 0;
		j++;
	}
	p->coord = mas;
	p->i = i - 1;
	mlx_hook(p->win1, 2, 0, key_press, (void *)p);
	make_sharp(p, mas, p->n, p->i);
	mlx_put_image_to_window(p->mlx, p->win1, p->img, 0, 0);
	mlx_loop(p->mlx);
	return (0);
}