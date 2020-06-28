/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right_down.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 19:14:51 by acarlett          #+#    #+#             */
/*   Updated: 2020/06/28 19:32:54 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rainbow.h"

int     right_down(int x0, int y0, int x_end, int y_end, void *mlx, void *win1)
{
	int     dx;
	int     dy;
	int     x;
	int     y;
	int     err;
	int     derr;
	int     diry;
	int     a;

	a =     0x00CCFF;
	dx =    ABS((x_end - x0));
	dy =    ABS((y_end - y0));
	x =     ABS(x0);
	y =     ABS(y0);
	err =   0;
	derr =  0;
	derr =  (dy + 1);
	diry =  y_end - y0;
	diry =  (diry > 0 ? 1 : -1);
	while (x != 1200)
	{
		mlx_pixel_put(mlx, win1, x, y, a);
		err += derr;
		if (err >= (dx + 1))
		{
			y += diry;
			err -= (dx + 1);
		}
		x++;
	}
}