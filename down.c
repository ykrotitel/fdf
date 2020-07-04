/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   down.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 13:56:14 by acarlett          #+#    #+#             */
/*   Updated: 2020/07/04 16:49:15 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rainbow.h"

int		down(t_help *p, void *mlx, void *win1, int color)
{
	p->a =     color;
	p->dx = ABS((p->x_end - p->x0));
	p->dy = ABS((p->y_end - p->y0));
	p->x0 = ABS(p->x0);
	p->y0 = ABS(p->y0);
	p->err = 0;
	p->derr = 0;
	p->derr = (p->dx + 1);
	p->dirx = ((p->x_end - p->x0) > 0 ? 1 : -1);
	while (p->y0 != p->y_end)
	{
		mlx_pixel_put(mlx, win1, p->x0, p->y0, p->a);
		p->err += p->derr;
		if (p->err >= (p->dy + 1))
		{
			p->x0 += p->dirx;
			p->err -= (p->dy + 1);
		}
		p->y0++;
	}
	return (0);
}