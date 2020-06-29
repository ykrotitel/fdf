/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_sun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 19:00:41 by acarlett          #+#    #+#             */
/*   Updated: 2020/06/29 19:01:22 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rainbow.h"

void		make_sun()
{
	p.x_end =	WIN_X;
	p.y_end =	WIN_Y;
	i =		800;
	while(i)
	{
		p.x0 =	600;
		p.y0 =	600;
		right(&p, mlx, win1);
		i--;
		p.y_end -= 10;
	}


	i =	1200;
	p.x_end = WIN_X;
	p.y_end = WIN_Y;
	while(i)
	{
		p.x0 =	600;
		p.y0 =	600;
		down(&p, mlx, win1);
		i--;
		p.x_end -= 10;
	}

	i = 120;
	p.x_end = 0;
	p.y_end = WIN_Y;
	while(i)
	{
		p.x0 = 600;
		p.y0 = 600;
		left(&p, mlx, win1);
		i--;
		p.y_end -= 10;
	}
	
	i = 1200;
	p.x_end = WIN_X;
	p.y_end = 10;
	while(i)
	{
		p.x0 = 600;
		p.y0 = 600;
		up(&p, mlx, win1);
		i--;
		p.x_end -= 10;
	}
}