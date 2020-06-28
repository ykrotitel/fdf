/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rainbow.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 19:18:09 by acarlett          #+#    #+#             */
/*   Updated: 2020/06/28 19:31:54 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>
#include <mlx.h>

#define WIN_X       1200
#define WIN_Y       1200
#define ABS(x)      (x < 0 ? -x : x)

typedef struct      s_help
{
    int             x;
    int             y;
    int             err;
    int             derr;
    int             dx;
    int             dy;
}                   t_help;

int     right_down(int x0, int y0, int x_end, int y_end, void *mlx, void *win1);