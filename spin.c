/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spin.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 18:41:24 by acarlett          #+#    #+#             */
/*   Updated: 2020/07/13 21:04:59 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rainbow.h"
int		spin_x(t_help *p, int m, int n, int **mas)
{
	t_cord	*s;

	p->ii = 0;
	p->jj = 0;
	p->startx = n;
	p->starty = m;
	s = malloc(sizeof(t_cord));
	p->a = 0x800000;
	while (p->jj <= p->i)
	{
		while (p->ii < p->j)
		{
			vertical_lines(s, p, mas);
			if (p->per)
			{
				float per0 = p->persp / (p->persp - s->t_tz0);
				float per1 = p->persp / (p->persp - s->t_tz1);
			
				p->x0 = (float)p->x0 * per0 + (WIN_X / 2);
				p->y0 = (float)p->y0 * per0 + (WIN_Y / 2);
				p->x_end = (float)p->x_end * per1 + (WIN_X / 2);
				p->y_end = (float)p->y_end * per1 + (WIN_Y / 2);
			}
			else
			{
				p->x0 = (float)p->x0 + (WIN_X / 2);
				p->y0 = (float)p->y0 + (WIN_Y / 2);
				p->x_end = (float)p->x_end + (WIN_X / 2);
				p->y_end = (float)p->y_end + (WIN_Y / 2);
			}
			if (p->x0 < 0 || p->y0 < 0 || p->x0 > WIN_X || p->y0 > WIN_Y)
			{
				p->buff = p->x_end;
				p->x_end = p->x0;
				p->x0 = p->buff;
				p->buff = p->y_end;
				p->y_end = p->y0;
				p->y0 = p->buff;
			}
			if (s->t_tz0 * p->koef < p->persp && s->t_tz1 * p->koef < p->persp)
				make_line(p, p->mlx, p->win1, p->a);
			p->startx += p->d;
			p->ii++;
		}
		p->a = p->a + p->col;
		p->startx = n;
		p->starty += p->d;
		p->ii = 0;
		p->jj++;
	}
	p->ii = 0;
	p->jj = 0;
	p->startx = n;
	p->starty = m;
	p->a = 0x800000;
	while (p->jj <= p->j)
	{
		while (p->ii < p->i)
		{
			horizontal_lines(s, p, mas);
			if (p->per)
			{
				float per0 = p->persp / (p->persp - s->t_tz0);
				float per1 = p->persp / (p->persp - s->t_tz1);
			
				p->x0 = (float)p->x0 * per0 + (WIN_X / 2);
				p->y0 = (float)p->y0 * per0 + (WIN_Y / 2);
				p->x_end = (float)p->x_end * per1 + (WIN_X / 2);
				p->y_end = (float)p->y_end * per1 + (WIN_Y / 2);
			}
			else
			{
				p->x0 = (float)p->x0 + (WIN_X / 2);
				p->y0 = (float)p->y0 + (WIN_Y / 2);
				p->x_end = (float)p->x_end + (WIN_X / 2);
				p->y_end = (float)p->y_end + (WIN_Y / 2);
			}
			
			if (p->x0 < 0 || p->y0 < 0 || p->x0 > WIN_X || p->y0 > WIN_Y)
			{
				p->buff = p->x_end;
				p->x_end = p->x0;
				p->x0 = p->buff;
				p->buff = p->y_end;
				p->y_end = p->y0;
				p->y0 = p->buff;
			}
			if (s->t_tz0 * p->koef < p->persp && s->t_tz1 * p->koef < p->persp)
				make_line(p, p->mlx, p->win1, p->a);
			p->starty += p->d;
			p->ii++;
		}
		p->a = p->a + p->col;
		p->starty = m;
		p->startx += p->d;
		p->ii = 0;
		p->jj++;
	}
	return (0);
}