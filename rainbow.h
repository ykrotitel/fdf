/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rainbow.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 19:18:09 by acarlett          #+#    #+#             */
/*   Updated: 2020/06/29 17:12:04 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>
#include <mlx.h>

#define WIN_X       1250
#define WIN_Y       1250
#define ABS(x)      (x < 0 ? -x : x)

typedef struct      s_help
{
    int             a;
    int             x0;
    int             y0;
    int             x_end;
    int             y_end;
    int             dirx;
    int             diry;
    int             err;
    int             derr;
    int             dx;
    int             dy;
}                   t_help;

int     right(t_help *p, void *mlx, void *win1);
int		down(t_help *p, void *mlx, void *win1);
int		left(t_help *p, void *mlx, void *win1);
int		up(t_help *p, void *mlx, void *win1);
int		make_line(t_help *p, void *mlx, void *win1);