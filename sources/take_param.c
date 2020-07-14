/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 20:18:48 by acarlett          #+#    #+#             */
/*   Updated: 2020/07/14 18:48:28 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rainbow.h"

t_help		*params_down(t_help *p, int color)
{
	p->a = color;
	p->dx = ABS((p->x_end - p->x0));
	p->dy = ABS((p->y_end - p->y0));
	p->x0 = ABS(p->x0);
	p->y0 = ABS(p->y0);
	p->err = 0;
	p->derr = 0;
	p->derr = (p->dx + 1);
	p->dirx = ((p->x_end - p->x0) > 0 ? 1 : -1);
	return (p);
}

t_help		*params_right(t_help *p, int color)
{
	p->a = color;
	p->dx = ABS((p->x_end - p->x0));
	p->dy = ABS((p->y_end - p->y0));
	p->x0 = ABS(p->x0);
	p->y0 = ABS(p->y0);
	p->err = 0;
	p->derr = 0;
	p->derr = (p->dy + 1);
	p->diry = p->y_end - p->y0;
	p->diry = (p->diry > 0 ? 1 : -1);
	return (p);
}

t_help		*params_left(t_help *p)
{
	p->dx = p->x_end - p->x0;
	p->dx = ABS(p->dx);
	p->dy = p->y_end - p->y0;
	p->dy = ABS(p->dy);
	p->x0 = ABS(p->x0);
	p->y0 = ABS(p->y0);
	p->err = 0;
	p->derr = 0;
	p->derr = (p->dy + 1);
	p->diry = p->y_end - p->y0;
	p->diry = (p->diry > 0 ? 1 : -1);
	return (p);
}

t_help		*params_up(t_help *p)
{
	p->dx = ABS((p->x_end - p->x0));
	p->dy = ABS((p->y_end - p->y0));
	p->x0 = ABS(p->x0);
	p->y0 = ABS(p->y0);
	p->err = 0;
	p->derr = 0;
	p->derr = (p->dx + 1);
	p->dirx = ((p->x_end - p->x0) > 0 ? 1 : -1);
	return (p);
}
