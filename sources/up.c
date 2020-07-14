/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 14:27:28 by acarlett          #+#    #+#             */
/*   Updated: 2020/07/14 18:48:32 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rainbow.h"

int		up(t_help *p)
{
	params_up(p);
	while (p->y0 >= p->y_end)
	{
		if (p->x0 >= WIN_X || p->y0 >= WIN_Y || p->x0 < 0 || p->y0 < 0)
			p->y0--;
		else
		{
			p->data[p->y0 * WIN_X + p->x0] = p->a;
			p->err += p->derr;
			if (p->err >= (p->dy + 1))
			{
				p->x0 += p->dirx;
				p->err -= (p->dy + 1);
			}
			p->y0--;
		}
	}
	return (0);
}
