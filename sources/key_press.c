/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 19:53:48 by acarlett          #+#    #+#             */
/*   Updated: 2020/07/14 18:48:07 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rainbow.h"

int		key_press_2(int key, t_help *p)
{
	if (key == 24 && p->persp > 100)
		p->persp -= 100;
	else if (key == 27)
		p->persp += 100;
	else if (key == 116)
		p->into += 20;
	else if (key == 121)
		p->into -= 20;
	else if (key == 35)
		p->per = !(p->per);
	key_press_3(key, p);
	return (0);
}

int		key_press_3(int key, t_help *p)
{
	if (key == 43)
	{
		p->a_x = -0.523599;
		p->a_y = -0.523599;
		p->a_z = 0.523599;
	}
	else if (key == 47)
	{
		p->a_x = 0.0;
		p->a_y = 0.0;
		p->a_z = 0.0;
	}
	blackground(p);
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
		p->a_z += 0.1;
	else if (key == 123)
		p->a_z -= 0.1;
	else if (key == 126)
		p->a_x -= 0.1;
	else if (key == 125)
		p->a_x += 0.1;
	else if (key == 19)
		make_increase(p, p->coord);
	else if (key == 20)
		make_unincrease(p, p->coord);
	else if (key == 30)
		p->a_y += 0.1;
	else if (key == 33)
		p->a_y -= 0.1;
	key_press_2(key, p);
	return (0);
}

int		blackground(t_help *p)
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
		make_line(p, 0x303030);
		j++;
	}
	return (0);
}
