/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 19:14:51 by acarlett          #+#    #+#             */
/*   Updated: 2020/07/12 18:57:51 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rainbow.h"

int     right(t_help *p, void *mlx, void *win1, int color)
{
	p->a =     	color;
	p->dx =    	ABS((p->x_end - p->x0));
	p->dy =    	ABS((p->y_end - p->y0));
	p->x0 =     ABS(p->x0);
	p->y0 =     ABS(p->y0);
	p->err =   	0;
	p->derr =  	0;
	p->derr =  	(p->dy + 1);
	p->diry =  	p->y_end - p->y0;
	p->diry =  	(p->diry > 0 ? 1 : -1);
	while (p->x0 != p->x_end)
	{
		if (p->x0 >= WIN_X || p->y0 >= WIN_Y || p->x0 < 0 || p->y0 < 0)
			p->x0++;
		else
		{	
		p->data[p->y0 * WIN_X + p->x0] = p->a;
		// mlx_pixel_put(mlx, win1, p->x0, p->y0, p->a);
		p->err += p->derr;
		if (p->err >= (p->dx + 1))
		{
			p->y0 += p->diry;
			p->err -= (p->dx + 1);
		}
		p->x0++;
		}
	}
	return (0);
}