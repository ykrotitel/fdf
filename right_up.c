/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 15:46:06 by acarlett          #+#    #+#             */
/*   Updated: 2020/06/29 15:46:13 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rainbow.h"

int     right_up(t_help *p, void *mlx, void *win1)
{
	p->a =     0x00CCFF;
    p->dx = ABS((p->x_end - p->x0));
	p->dy = ABS((p->y_end - p->y0));
	p->x0 = ABS(p->x0);
	p->y0 = ABS(p->y0);
	p->err = 0;
	p->derr = 0;
	p->derr = (p->dy + 1);
	p->diry = p->y_end - p->y0;
	p->diry = (p->diry > 0 ? 1 : -1);
	while (p->x0 != 1200)
	{
		mlx_pixel_put(mlx, win1, p->x0, p->y0, p->a);
		p->err += p->derr;
		if (p->err >= (p->dx + 1))
		{
			p->y0 += p->diry;
			p->err -= (p->dx + 1);
		}
		p->x0++;
	}
    return (0);
}