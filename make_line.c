/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 15:54:02 by acarlett          #+#    #+#             */
/*   Updated: 2020/06/29 19:00:10 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "rainbow.h"

 int		make_line(t_help *p, void *mlx, void *win1)
 {
	p->dx = p->x0 - p->x_end;
	p->dx = ABS(p->dx);
	p->dy = p->y0 - p->y_end;
	p->dy = ABS(p->dy);
	printf ("dx = %d    dy = %d\n", p->dx, p->dy);
	if ((p->x0 >= p->x_end) && (p->dx >= p->dy))
	{
		left(p, mlx, win1);
		write (1, "left\n", 5);
	}
	else if((p->x_end >= p->x0) && (p->dx >= p->dy))
	{
			right(p, mlx, win1);
		write (1, "right\n", 6);
	}
	else if(p->y_end <= p->y0 && (p->dy >= p->dx))
	{
		up(p, mlx, win1);
		write (1, "up\n", 3);
	}
	else if (p->y_end >= p->y0 && p->dy >= p->dx)
	{
		down(p, mlx, win1);
		write (1, "down\n", 5);
	}
	return (0);
 }