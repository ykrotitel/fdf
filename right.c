/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 19:14:51 by acarlett          #+#    #+#             */
/*   Updated: 2020/07/13 20:27:28 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rainbow.h"

int     right(t_help *p, void *mlx, void *win1, int color)
{
	params_right(p, color);
	while (p->x0 != p->x_end)
	{
		if (p->x0 >= WIN_X || p->y0 >= WIN_Y || p->x0 < 0 || p->y0 < 0)
			p->x0++;
		else
		{	
		p->data[p->y0 * WIN_X + p->x0] = p->a;
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