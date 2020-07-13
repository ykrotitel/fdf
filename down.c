/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   down.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 13:56:14 by acarlett          #+#    #+#             */
/*   Updated: 2020/07/13 20:23:58 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rainbow.h"

int		down(t_help *p, void *mlx, void *win1, int color)
{
	params_down(p, color);
	while (p->y0 != p->y_end)
	{
		if (p->x0 >= WIN_X || p->y0 >= WIN_Y || p->x0 < 0 || p->y0 < 0)
		{
			p->y0++;
			p->x0 = (p->x0 >= WIN_X ? WIN_X : 0);
		}
		else
		{
			p->data[p->y0 * WIN_X + p->x0] = p->a;
			p->err += p->derr;
			if (p->err >= (p->dy + 1))
			{
				p->x0 += p->dirx;
				p->err -= (p->dy + 1);
			}
			p->y0++;
		}
	}
	return (0);
}