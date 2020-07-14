/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 20:47:55 by acarlett          #+#    #+#             */
/*   Updated: 2020/07/14 18:47:57 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rainbow.h"

int		vertical_lines(t_cord *s, t_help *p, int **mas)
{
	s->tx0 = (p->startx - WIN_X / 2);
	s->b_ty0 = (float)mas[p->jj][p->ii] * sin(p->a_x);
	s->ty0 = (float)(p->starty - WIN_Y / 2) * cos(p->a_x) + s->b_ty0;
	s->b_ty0 = (float)mas[p->jj][p->ii] * cos(p->a_x);
	s->tz0 = s->b_ty0 - (float)(p->starty - WIN_Y / 2) * sin(p->a_x);
	s->tx1 = (p->startx - WIN_X / 2) + p->d;
	s->b_ty0 = (float)mas[p->jj][p->ii + 1] * sin(p->a_x);
	s->ty1 = (float)(p->starty - WIN_Y / 2) * cos(p->a_x) + s->b_ty0;
	s->b_ty0 = (float)mas[p->jj][p->ii + 1] * cos(p->a_x);
	s->tz1 = s->b_ty0 - (float)(p->starty - WIN_Y / 2) * sin(p->a_x);
	s->t_tx0 = s->tx0 * cos(p->a_y) + s->tz0 * sin(p->a_y);
	s->t_ty0 = s->ty0;
	s->t_tz0 = s->tz0 * cos(p->a_y) - s->tx0 * sin(p->a_y);
	s->t_tx1 = s->tx1 * cos(p->a_y) + s->tz1 * sin(p->a_y);
	s->t_ty1 = s->ty1;
	s->t_tz1 = s->tz1 * cos(p->a_y) - s->tx1 * sin(p->a_y);
	p->x0 = (s->t_tx0 * cos(p->a_z) - s->t_ty0 * sin(p->a_z));
	p->y0 = (s->t_ty0 * cos(p->a_z) + s->t_tx0 * sin(p->a_z));
	p->x_end = (s->t_tx1 * cos(p->a_z) - s->t_ty1 * sin(p->a_z));
	p->y_end = (s->t_ty1 * cos(p->a_z) + s->t_tx1 * sin(p->a_z));
	s->t_tz0 += p->into;
	s->t_tz1 += p->into;
	return (0);
}

int		horizontal_lines(t_cord *s, t_help *p, int **mas)
{
	s->tx0 = (p->startx - WIN_X / 2);
	s->b_ty0 = (float)mas[p->ii][p->jj] * sin(p->a_x);
	s->ty0 = (float)(p->starty - WIN_Y / 2) * cos(p->a_x) + s->b_ty0;
	s->b_ty0 = (float)mas[p->ii][p->jj] * cos(p->a_x);
	s->tz0 = s->b_ty0 - (float)(p->starty - WIN_Y / 2) * sin(p->a_x);
	s->tx1 = (p->startx - WIN_X / 2);
	s->b_ty0 = (float)mas[p->ii + 1][p->jj] * sin(p->a_x);
	s->ty1 = (float)((p->starty - WIN_Y / 2) + p->d) * cos(p->a_x) + s->b_ty0;
	s->b_ty0 = (float)mas[p->ii + 1][p->jj] * cos(p->a_x);
	s->tz1 = s->b_ty0 - (float)((p->starty + p->d) - WIN_Y / 2) * sin(p->a_x);
	s->t_tx0 = s->tx0 * cos(p->a_y) + s->tz0 * sin(p->a_y);
	s->t_ty0 = s->ty0;
	s->t_tz0 = s->tz0 * cos(p->a_y) - s->tx0 * sin(p->a_y);
	s->t_tx1 = s->tx1 * cos(p->a_y) + s->tz1 * sin(p->a_y);
	s->t_ty1 = s->ty1;
	s->t_tz1 = s->tz1 * cos(p->a_y) - s->tx1 * sin(p->a_y);
	p->x0 = (s->t_tx0 * cos(p->a_z) - s->t_ty0 * sin(p->a_z));
	p->y0 = (s->t_ty0 * cos(p->a_z) + s->t_tx0 * sin(p->a_z));
	p->x_end = (s->t_tx1 * cos(p->a_z) - s->t_ty1 * sin(p->a_z));
	p->y_end = (s->t_ty1 * cos(p->a_z) + s->t_tx1 * sin(p->a_z));
	s->t_tz0 += p->into;
	s->t_tz1 += p->into;
	return (0);
}

int		lines_first_if(t_help *p, t_cord *s)
{
	s->per0 = p->persp / (p->persp - s->t_tz0);
	s->per1 = p->persp / (p->persp - s->t_tz1);
	p->x0 = (float)p->x0 * s->per0 + (WIN_X / 2);
	p->y0 = (float)p->y0 * s->per0 + (WIN_Y / 2);
	p->x_end = (float)p->x_end * s->per1 + (WIN_X / 2);
	p->y_end = (float)p->y_end * s->per1 + (WIN_Y / 2);
	return (0);
}

int		lines_first_else(t_help *p)
{
	p->x0 = (float)p->x0 + (WIN_X / 2);
	p->y0 = (float)p->y0 + (WIN_Y / 2);
	p->x_end = (float)p->x_end + (WIN_X / 2);
	p->y_end = (float)p->y_end + (WIN_Y / 2);
	return (0);
}

int		lines_second_if(t_help *p)
{
	p->buff = p->x_end;
	p->x_end = p->x0;
	p->x0 = p->buff;
	p->buff = p->y_end;
	p->y_end = p->y0;
	p->y0 = p->buff;
	return (0);
}
