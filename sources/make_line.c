/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 15:54:02 by acarlett          #+#    #+#             */
/*   Updated: 2020/07/14 18:48:15 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rainbow.h"

int		make_line(t_help *p, int color)
{
	p->dx = p->x0 - p->x_end;
	p->dx = ABS(p->dx);
	p->dy = p->y0 - p->y_end;
	p->dy = ABS(p->dy);
	if (p->x0 < 0 || p->y0 < 0)
		return (0);
	if ((p->x0 >= p->x_end) && (p->dx >= p->dy))
		left(p);
	else if ((p->x_end >= p->x0) && (p->dx >= p->dy))
		right(p, color);
	else if (p->y_end <= p->y0 && (p->dy >= p->dx))
		up(p);
	else if (p->y_end >= p->y0 && p->dy >= p->dx)
		down(p, color);
	return (0);
}
