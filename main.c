/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 17:29:18 by acarlett          #+#    #+#             */
/*   Updated: 2020/06/27 19:29:11 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>
#include "mlx.h"

#define WIN_X 1200
#define WIN_Y 800

int main()
{
	void				*mlx;
	void				*win1;
	int					a;
	int					x;
	unsigned int		dx;
	unsigned int		dy;
	unsigned int		y;
	unsigned int		y_end;
	unsigned int		x_end;
	int					x0;
	int					y0;
	int					err;
	int					derr;
	int					diry;
	int					dirx;
	int					i;
	
	a = 0xFF9900;
	x = 0;
	y = 0;
	x0 = 600;
	y0 = 0;
	i = 800;
	err = 0;
	derr = 0;
	mlx = mlx_init();
	win1 = mlx_new_window(mlx, WIN_X, WIN_Y, "Holla!");
	// while(j >= 0)
	// {	
	// 	while (i >= 0)
	// 	{
	// 		mlx_pixel_put(mlx, win1, j, i, a);
	// 		j--;
	// 		mlx_pixel_put(mlx, win1, j, i, a);
	// 		j++;
	// 		i--;
	// 	}
	// 	j-= 100;
	// 	i = 800;
	// 	a += 20;
	// }
	i = 800;
	// while(j >= 0)
	// {	
	// 	while (i >= 0)
	// 	{
	// 		mlx_pixel_put(mlx, win1, i, j, a);
	// 		j--;
	// 		mlx_pixel_put(mlx, win1, i, j, a);
	// 		j++;
	// 		i--;
	// 	}
	// 	j-= 100;
	// 	i = 800;
	// 	a += 20;
	// }
	y_end = WIN_X;
	x_end = WIN_X;
	while(i)
	{
		dx = (x_end - x0);
		dy = (y_end - x0);
		x = x0;
		y = y0;
		err = 0;
		derr = 0;
		derr = (dy + 1);
		diry = y_end - y0;
		diry = (diry > 0 ? 1 : -1);
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
		i--;
		y_end -= 10;
	}
	i = 1200;
	x_end = WIN_X;
	y_end = WIN_Y;
	while(i)
	{
		dx = (x_end - x0);
		dy = (y_end - y0);
		x = x0;
		y = y0;
		err = 0;
		derr = 0;
		derr = (dx + 1);
		dirx = x_end - x0;
		if ((x_end - x0) > 0)
		{
			dirx = 1;
		}
		if ((x_end  - x0) < 0)
		{
			dirx = -1;
		}
		while (y != 1000)
		{
			mlx_pixel_put(mlx, win1, x, y, a);
			err += derr;
			if (err >= (dy + 1))
			{
				x += dirx;
				err -= (dy + 1);
			}
			y++;
		}
		i--;
		x_end -= 10;
	}
	mlx_loop(mlx);
}