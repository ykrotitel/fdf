/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 17:29:18 by acarlett          #+#    #+#             */
/*   Updated: 2020/07/13 20:37:54 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rainbow.h"

int		make_sharp(t_help *p, int **mas, int j, int i)
{
	int 	m;
	int		max;
	int		n;
	int		d;

	p->i = i;
	p->j = j;
	max = MAX(i, j);
	d = (MAX(WIN_X, WIN_Y) - 200) / max;
	if (max == i)
	{
		p->start_x = 100;
		p->start_y = (((WIN_X / d) - j) / 2) * d;
	}
	else if (max == j)
	{
		p->start_x = (((WIN_X / d) - i) / 2) * d;
		p->start_y = 100;
	}
	m = p->start_x;
	n = p->start_y;
	p->d = d;
		spin_x(p, m, n, mas);
	return (0);
}

int		main(int argc, char **argv)
{
	t_help				*p;
	int					j;
	int					m;
	
	p = malloc(sizeof(t_help));
	p->mlx = mlx_init();
	p->win1 = mlx_new_window(p->mlx, WIN_X, WIN_Y, "FDF");
	p->img = mlx_new_image(p->mlx, WIN_X, WIN_Y);
	p->data = (int *)mlx_get_data_addr(p->img, &(p->q1), &(p->q2), &(p->q3));
	p->i = 0;
	p->j = 0;
	p->m = 0;
	p->fd = open(argv[1], O_RDONLY);
	while (get_next_line(p->fd, &(p->s)) > 0)
	{
		p->i++;
		p->m = ft_takewith(p->s);
		free(p->s);
	}
	p->n = p->m - 1;
	p->per = 0;
	close(p->fd);
	continue1(p, argv);
	return (0);
}

int		continue1(t_help *p, char **argv)
{
	int		j;
	char	*buff;

	j = 0;
	p->fd = open(argv[1], O_RDONLY);
	p->line = malloc(sizeof(char *) * p->i);
	p->mas = malloc(sizeof(int *) * p->i);
	while(get_next_line(p->fd, &(p->line[p->j])) > 0)
	{
		p->mas[p->j] = malloc(sizeof(int) * p->m);
		p->j++;
	}
	p->j = p->j - 1;
	p->mm = 0;
	continue2(j, p, buff);
	return (0);
}

int		continue2(int j, t_help *p, char *buff)
{
	while (j <= p->j)
	{
		buff = p->line[j];
		while (p->mm != p->m)
		{
			while (*buff == ' ')
				(buff)++;
			p->mas[j][p->mm] = ft_atoi(buff);
			while (*buff != ' ')
				buff++;
			p->mm++;
		}
		p->mm = 0;
		j++;
	}
	continue3(p);
	return(0);
}

int		continue3(t_help *p)
{
	p->coord = p->mas;
	p->i = p->i - 1;
	p->col = 100 / (MAX(p->i, p->m) / 2);
	p->alpha_x = 0.0;
	p->alpha_y = 0.0;
	p->alpha_z = 0.0;
	p->persp = 1000.0;
	p->koef = 1.05;
	p->into = 1;
	mlx_hook(p->win1, 2, 0, key_press, (void *)p);
	make_sharp(p, p->mas, p->n, p->i);
	mlx_put_image_to_window(p->mlx, p->win1, p->img, 0, 0);
	mlx_loop(p->mlx);
	return (0);
}