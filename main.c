/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 17:29:18 by acarlett          #+#    #+#             */
/*   Updated: 2020/06/26 19:56:16 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>
#include "mlx.h"

#define WIN_X 800
#define WIN_Y 800

int main()
{
	void	*mlx;
	void	*win1;
	int		a;
	int		i;
	int		j;
	
	a = 0xFF0000;
	i = 100;
	j = 1000;
	mlx = mlx_init();
	win1 = mlx_new_window(mlx, WIN_X, WIN_Y, "Holla!");
	while(j)
	{	
		while (i)
		{
			mlx_pixel_put(mlx, win1, j, i, a);
			i--;
		}
		j--;
		i = 100;
		a+=1;
	}
	mlx_loop(mlx);
}