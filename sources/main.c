/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 17:29:18 by acarlett          #+#    #+#             */
/*   Updated: 2020/07/22 17:16:08 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rainbow.h"

int		make_sharp(t_help *p, int **mas, int j, int i)
{
	int	m;
	int	n;
	int	d;

	p->i = i;
	p->j = j;
	d = (MIN(WIN_X, WIN_Y) - 400) / MAX(i, j);
	d = (d ? d : 1);
	if (MAX(i, j) == j)
	{
		p->start_y = 200;
		p->start_x = (WIN_Y / 2) - (p->j * d) / 2;
	}
	else if (MAX(i, j) == i)
	{
		p->start_y = (WIN_X / 2) - (p->i * d) / 2;
		p->start_x = 200;
	}
	m = p->start_x;
	n = p->start_y;
	p->d = d;
	spin(p, m, n, mas);
	return (0);
}

int		main(int argc, char **argv)
{
	t_help	*p;

	p = malloc(sizeof(t_help));
	p->mlx = mlx_init();
	if (argc > 2)
		return (ft_error(4));
	p->win1 = mlx_new_window(p->mlx, WIN_X, WIN_Y, "FDF");
	p->img = mlx_new_image(p->mlx, WIN_X, WIN_Y);
	p->data = (int *)mlx_get_data_addr(p->img, &(p->q1), &(p->q2), &(p->q3));
	p->i = 0;
	p->j = 0;
	p->m = 0;
	p->mm = 0;
	main_second(p, argv);
	return (0);
}

int		continue1(t_help *p, char **argv)
{
	int		j;

	p->n = p->m - 1;
	p->per = 0;
	close(p->fd);
	j = 0;
	p->fd = open(argv[1], O_RDONLY);
	p->line = malloc(sizeof(char *) * p->i);
	p->mas = malloc(sizeof(int *) * p->i);
	while (get_next_line(p->fd, &(p->line[p->j])) > 0)
	{
		p->mas[p->j] = malloc(sizeof(int) * p->m);
		p->j++;
	}
	p->j = p->j - 1;
	p->mm = 0;
	continue2(j, p);
	return (0);
}

int		continue2(int j, t_help *p)
{
	char *buff;

	while (j <= p->j)
	{
		buff = p->line[j];
		while (p->mm != p->m)
		{
			while (*buff == ' ')
				(buff)++;
			p->mas[j][p->mm] = (ft_atoi(buff) * 3);
			while (*buff != ' ')
				buff++;
			p->mm++;
		}
		free(p->line[j]);
		p->mm = 0;
		j++;
	}
	p->coord = p->mas;
	p->i = p->i - 1;
	p->i = (p->i ? p->i : 1);
	continue3(p);
	return (0);
}

int		continue3(t_help *p)
{
	if (p->i == 1 && p->m == 1)
	{
		p->a = 0x303030;
		blackground(p);
		p->data[(int)(((float)WIN_Y / 2.0) *
		WIN_X + ((float)WIN_X / 2.0))] = 0xff0000;
		mlx_put_image_to_window(p->mlx, p->win1, p->img, 0, 0);
		mlx_hook(p->win1, 2, 0, key_press, (void *)p);
		mlx_loop(p->mlx);
		return (0);
	}
	else
		p->col = 100 / (MAX(p->i, p->m) / 2);
	p->a_x = 0.0;
	p->a_y = 0.0;
	p->a_z = 0.0;
	p->persp = 1000.0;
	p->koef = 1.03;
	p->into = 1;
	mlx_hook(p->win1, 2, 0, key_press, (void *)p);
	blackground(p);
	make_sharp(p, p->mas, p->n, p->i);
	mlx_put_image_to_window(p->mlx, p->win1, p->img, 0, 0);
	mlx_loop(p->mlx);
	return (0);
}
