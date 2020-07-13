/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 19:53:48 by acarlett          #+#    #+#             */
/*   Updated: 2020/07/13 20:17:35 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rainbow.h"

int		key_press_2(int key, t_help *p)
{
	if (key == 27 && p->persp > 100)
		p->persp -= 100;
	else if (key == 24)
		p->persp += 100;
	else if (key == 116)
		p->into += 20;
	else if (key == 121)
		p->into -= 20;
	else if (key == 35)
		p->per = !(p->per);
		blackground(p->mlx, p->win1, p);
		make_sharp(p, p->coord, p->n, p->i);
	mlx_put_image_to_window(p->mlx, p->win1, p->img, 0, 0);
	return (0);
}

int		key_press(int key, void *l)
{
	t_help	*p;

	p = (t_help *)l;
	p->key = key;
	if (key == 53)
		exit(0);
	else if (key == 124)
		p->alpha_z += 0.1;
	else if (key == 123)
		p->alpha_z -= 0.1;
	else if (key == 126)
		p->alpha_x -= 0.1;
	else if (key == 125)
		p->alpha_x += 0.1;
	else if (key == 19)
		make_increase(p, p->coord, key);
	else if (key == 20)
		make_unincrease(p, p->coord, key);
	else if (key == 30)
		p->alpha_y += 0.1;
	else if (key == 33)
		p->alpha_y -= 0.1;
	key_press_2(key, p);
	return 0;
}

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