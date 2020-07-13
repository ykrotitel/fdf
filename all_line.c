/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 20:47:55 by acarlett          #+#    #+#             */
/*   Updated: 2020/07/13 21:05:34 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rainbow.h"

int		vertical_lines(t_cord *s, t_help *p, int **mas)
{
	s->tx0 = (p->startx - WIN_X / 2);
	s->ty0 = (float)(p->starty - WIN_Y / 2) * cos(p->alpha_x) + (float)mas[p->jj][p->ii] * sin(p->alpha_x);
	s->tz0 = (float)mas[p->jj][p->ii] * cos(p->alpha_x) - (float)(p->starty - WIN_Y / 2) * sin(p->alpha_x);
	s->tx1 = (p->startx - WIN_X / 2) + p->d;
	s->ty1 = (float)(p->starty - WIN_Y / 2) * cos(p->alpha_x) + (float)mas[p->jj][p->ii + 1] * sin(p->alpha_x);
	s->tz1 = (float)mas[p->jj][p->ii + 1] * cos(p->alpha_x) - (float)(p->starty - WIN_Y / 2) * sin(p->alpha_x);
	
	s->t_tx0 = s->tx0 * cos(p->alpha_y) + s->tz0 * sin(p->alpha_y);
	s->t_ty0 = s->ty0;
	s->t_tz0 = s->tz0 * cos(p->alpha_y) - s->tx0 * sin(p->alpha_y);
	s->t_tx1 = s->tx1 * cos(p->alpha_y) + s->tz1 * sin(p->alpha_y);
	s->t_ty1 = s->ty1;
	s->t_tz1 = s->tz1 * cos(p->alpha_y) - s->tx1 * sin(p->alpha_y); 

	p->x0 = (s->t_tx0 * cos(p->alpha_z) - s->t_ty0 * sin(p->alpha_z));
	p->y0 = (s->t_ty0 * cos(p->alpha_z) + s->t_tx0 * sin(p->alpha_z));

	p->x_end = (s->t_tx1 * cos(p->alpha_z) - s->t_ty1 * sin(p->alpha_z));
	p->y_end = (s->t_ty1 * cos(p->alpha_z) + s->t_tx1 * sin(p->alpha_z));
			
	s->t_tz0 += p->into;
	s->t_tz1 += p->into;
	return(0);
}

int		horizontal_lines(t_cord *s, t_help *p, int **mas)
{
	s->tx0 = (p->startx - WIN_X / 2);
	s->ty0 = (float)(p->starty - WIN_Y / 2) * cos(p->alpha_x) + (float)mas[p->ii][p->jj] * sin(p->alpha_x);			
	s->tz0 = (float)mas[p->ii][p->jj] * cos(p->alpha_x) - (float)(p->starty - WIN_Y / 2) * sin(p->alpha_x);
	s->tx1 = (p->startx - WIN_X / 2);
	s->ty1 = (float)((p->starty - WIN_Y / 2) + p->d) * cos(p->alpha_x) + (float)mas[p->ii + 1][p->jj] * sin(p->alpha_x);
	s->tz1 = (float)mas[p->ii + 1][p->jj] * cos(p->alpha_x) - (float)((p->starty + p->d) - WIN_Y / 2) * sin(p->alpha_x);

	s->t_tx0 = s->tx0 * cos(p->alpha_y) + s->tz0 * sin(p->alpha_y);
	s->t_ty0 = s->ty0;
	s->t_tz0 = s->tz0 * cos(p->alpha_y) - s->tx0 * sin(p->alpha_y);
	s->t_tx1 = s->tx1 * cos(p->alpha_y) + s->tz1 * sin(p->alpha_y);
	s->t_ty1 = s->ty1;
	s->t_tz1 = s->tz1 * cos(p->alpha_y) - s->tx1 * sin(p->alpha_y);

	p->x0 = (s->t_tx0 * cos(p->alpha_z) - s->t_ty0 * sin(p->alpha_z));
	p->y0 = (s->t_ty0 * cos(p->alpha_z) + s->t_tx0 * sin(p->alpha_z));
	p->x_end = (s->t_tx1 * cos(p->alpha_z) - s->t_ty1 * sin(p->alpha_z));
	p->y_end = (s->t_ty1 * cos(p->alpha_z) + s->t_tx1 * sin(p->alpha_z));

	s->t_tz0 += p->into;
	s->t_tz1 += p->into;
	return (0);
}