/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 17:29:18 by acarlett          #+#    #+#             */
/*   Updated: 2020/06/29 19:24:04 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rainbow.h"


int main()
{
	void				*mlx;
	void				*win1;
	void				*img;
    // int             	a;
    // int             	x0;
    // int             	y0;
    // int             	x_end;
    // int             	y_end;
    // int             	dirx;
    // int             	diry;
    // int             	err;
    // int             	derr;
    // int             	dx;
    // int             	dy;
	t_help				p;
	int					i;
	
	mlx =	mlx_init();
	p.a =		0x00CCFF;
	win1 =	mlx_new_window(mlx, WIN_X, WIN_Y, "Holla!");
	p.x0 = 600;
	p.y0 = 700;
	p.x_end = 900;
	p.y_end = 400;
	// make_line(&p, mlx, win1);
	img = mlx_new_image(mlx, 1000, 1000);
	mlx_hook();
	mlx_put_image_to_window(mlx, win1, img, 100, 100);
	mlx_loop(mlx);
}