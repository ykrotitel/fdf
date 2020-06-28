/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 17:29:18 by acarlett          #+#    #+#             */
/*   Updated: 2020/06/28 19:31:12 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rainbow.h"

#define WIN_X 1200
#define WIN_Y 1200
#define ABS(x) (x < 0 ? -x : x)

int main()
{
	void				*mlx;
	void				*win1;
	int					a;
	int					x;
	int					dx;
	int					dy;
	int					y;
	int					y_end;
	int					x_end;
	int					x0;
	int					y0;
	int					err;
	int					derr;
	int					diry;
	int					dirx;
	int					i;
	
	mlx =	mlx_init();
	win1 =	mlx_new_window(mlx, WIN_X, WIN_Y, "Holla!");
	a =		0x00CCFF;
	
	
	
	
	x0 =	600;
	y0 =	600;
	x_end =	WIN_X;
	y_end =	WIN_Y;
	i =		800;
	err =	0;
	derr =	0;
	while(i && y_end >= 600)
	{
		right_down(x0, y0, x_end, y_end, mlx, win1);
		// dx = ABS((x_end - x0));
		// dy = ABS((y_end - y0));
		// x = ABS(x0);
		// y = ABS(y0)
		// ;
		// err = 0;
		// derr = 0;
		// derr = (dy + 1);
		// diry = y_end - y0;
		// diry = (diry > 0 ? 1 : -1);
		// while (x != 1200)
		// {
		// 	mlx_pixel_put(mlx, win1, x, y, a);
		// 	err += derr;
		// 	if (err >= (dx + 1))
		// 	{
		// 		y += diry;
		// 		err -= (dx + 1);
		// 	}
		// 	x++;
		// }
		i--;
		y_end -= 10;
	}






// 	i =		1200;
// 	x0 =	600;
// 	y0 =	600;
// 	x_end = WIN_X;
// 	y_end = WIN_Y;
// 	while(i)
// 	{
// 		dx = ABS((x_end - x0));
// 		dy = ABS((y_end - y0));
// 		x = ABS(x0);
// 		y = ABS(y0);
// 		err = 0;
// 		derr = 0;
// 		derr = (dx + 1);
// 		dirx = ((x_end - x0) > 0 ? 1 : -1);
// 		while (y != 1300)
// 		{
// 			mlx_pixel_put(mlx, win1, x, y, a);
// 			err += derr;
// 			if (err >= (dy + 1))
// 			{
// 				x += dirx;
// 				err -= (dy + 1);
// 			}
// 			y++;
// 		}
// 		i--;
// 		x_end -= 10;
// 	}








// 	i = 800;
// 	x0 = 600;
// 	y0 = 600;
// 	x_end = 0;
// 	y_end = 600;
// 	while(i)
// 	{
// 		dx = ABS((x0 - x_end));
// 		dy = ABS((y0 - y_end));
// 		x = ABS(x0);
// 		y = ABS(y0);
// 		err = 0;
// 		derr = 0;
// 		derr = (dy + 1);
// 		diry = y_end - y0;
// 		diry = (diry > 0 ? 1 : -1);
// 		while (x != 0)
// 		{
// 			mlx_pixel_put(mlx, win1, x, y, a);
// 			err += derr;
// 			if (err >= (dx + 1))
// 			{
// 				y += diry;
// 				err -= (dx + 1);
// 			}
// 			x--;
// 		}
// 		i--;
// 		y_end += 10;
// 	}
	
	
	







	
	
	
// 	x0 =	600;
// 	y0 =	600;
// 	x_end =	WIN_X;
// 	y_end =	0;
// 	i =		800;
// 	err =	0;
// 	derr =	0;
// 	while(i && y_end <= 600)
// 	{
// 		dx = ABS((x_end - x0));
// 		dy = ABS((y_end - y0));
// 		x = ABS(x0);
// 		y = ABS(y0)
// 		;
// 		err = 0;
// 		derr = 0;
// 		derr = (dy + 1);
// 		diry = y_end - y0;
// 		diry = (diry > 0 ? 1 : -1);
// 		while (x != 1200)
// 		{
// 			mlx_pixel_put(mlx, win1, x, y, a);
// 			err += derr;
// 			if (err >= (dx + 1))
// 			{
// 				y += diry;
// 				err -= (dx + 1);
// 			}
// 			x++;
// 		}
// 		i--;
// 		y_end += 10;
// 	}





// 	i = 1200;
// 	x0 = 600;
// 	y0 = 600;
// 	x_end = WIN_X;
// 	y_end = 10;
// 	while(i)
// 	{
// 		dx = ABS((x_end - x0));
// 		dy = ABS((y_end - y0));
// 		x = ABS(x0);
// 		y = ABS(y0);
// 		err = 0;
// 		derr = 0;
// 		derr = (dx + 1);
// 		dirx = ((x_end - x0) > 0 ? 1 : -1);
// 		while (y >= 0)
// 		{
// 			mlx_pixel_put(mlx, win1, x, y, a);
// 			err += derr;
// 			if (err >= (dy + 1))
// 			{
// 				x += dirx;
// 				err -= (dy + 1);
// 			}
// 			y--;
// 		}
// 		i--;
// 		x_end -= 10;
// 	}




	
// 	i = 800;
// 	x0 = 600;
// 	y0 = 600;
// 	x_end = 0;
// 	y_end = 0;
// 	while(i)
// 	{
// 		dx = ABS((x0 - x_end));
// 		dy = ABS((y0 - y_end));
// 		x = ABS(x0);
// 		y = ABS(y0);
// 		err = 0;
// 		derr = 0;
// 		derr = (dy + 1);
// 		diry = y0 - y_end;
// 		diry = (diry > 0 ? 1 : -1);
// 		while (x != 0)
// 		{
// 			mlx_pixel_put(mlx, win1, x, y, a);
// 			err += derr;
// 			if (err >= (dx + 1))
// 			{
// 				y += diry;
// 				err -= (dx + 1);
// 			}
// 			x--;
// 		}
// 		i--;
// 		y_end += 10;
// 	}
	mlx_loop(mlx);
}