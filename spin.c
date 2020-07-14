/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spin.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 18:41:24 by acarlett          #+#    #+#             */
/*   Updated: 2020/07/14 16:12:25 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rainbow.h"
int		spin(t_help *p, int m, int n, int **mas)
{
	t_cord	*s;

	first_parameters(p, n, m);
	s = malloc(sizeof(t_cord));
	while (p->jj <= p->i)
	{
		while (p->ii < p->j)
		{
			vertical_lines(s, p, mas);
			if (p->per)
				lines_first_if(p, s);
			else
				lines_first_else(p, s);
			if (p->x0 < 0 || p->y0 < 0 || p->x0 > WIN_X || p->y0 > WIN_Y)
				lines_second_if(p);
			if (s->t_tz0 * p->koef < p->persp && s->t_tz1 * p->koef < p->persp)
				make_line(p, p->mlx, p->win1, p->a);
			p->startx += p->d;
			p->ii++;
		}
		vertical_conditions(p, n);
	}
	// spin_second(p, s, m, n, mas);
	first_parameters(p, n, m);
	while (p->jj <= p->j)
	{
		while (p->ii < p->i)
		{
			horizontal_lines(s, p, mas);
			if (p->per)
				lines_first_if(p, s);
			else
				lines_first_else(p, s);
			if (p->x0 < 0 || p->y0 < 0 || p->x0 > WIN_X || p->y0 > WIN_Y)
				lines_second_if(p);
			if (s->t_tz0 * p->koef < p->persp && s->t_tz1 * p->koef < p->persp)
				make_line(p, p->mlx, p->win1, p->a);
			p->starty += p->d;
			p->ii++;
		}
		horizontal_conditions(p, m);
	}
	return (0);
}

int		spin_second(t_help *p, t_cord *s, int m, int n, int **mas)
{
	first_parameters(p, n, m);
	while (p->jj <= p->j)
	{
		while (p->ii < p->i)
		{
			horizontal_lines(s, p, mas /*p->coord*/);
			if (p->per)
				lines_first_if(p, s);
			else
				lines_first_else(p, s);
			if (p->x0 < 0 || p->y0 < 0 || p->x0 > WIN_X || p->y0 > WIN_Y)
				lines_second_if(p);
			if (s->t_tz0 * p->koef < p->persp && s->t_tz1 * p->koef < p->persp)
				make_line(p, p->mlx, p->win1, p->a);
			p->starty += p->d;
			p->ii++;
		}
		horizontal_conditions(p, m);
	}
	return (0);
}