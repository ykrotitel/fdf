/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 20:18:48 by acarlett          #+#    #+#             */
/*   Updated: 2020/07/26 18:40:38 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rainbow.h"

t_help		*params_down(t_help *p, int color)
{
	p->a = color;
	p->dx = ABS((p->x_end - p->x0));
	p->dy = ABS((p->y_end - p->y0));
	p->x0 = ABS(p->x0);
	p->y0 = ABS(p->y0);
	p->err = 0;
	p->derr = 0;
	p->derr = (p->dx + 1);
	p->dirx = ((p->x_end - p->x0) > 0 ? 1 : -1);
	return (p);
}

t_help		*params_right(t_help *p, int color)
{
	p->a = color;
	p->dx = ABS((p->x_end - p->x0));
	p->dy = ABS((p->y_end - p->y0));
	p->x0 = ABS(p->x0);
	p->y0 = ABS(p->y0);
	p->err = 0;
	p->derr = 0;
	p->derr = (p->dy + 1);
	p->diry = p->y_end - p->y0;
	p->diry = (p->diry > 0 ? 1 : -1);
	return (p);
}

t_help		*params_left(t_help *p)
{
	p->dx = p->x_end - p->x0;
	p->dx = ABS(p->dx);
	p->dy = p->y_end - p->y0;
	p->dy = ABS(p->dy);
	p->x0 = ABS(p->x0);
	p->y0 = ABS(p->y0);
	p->err = 0;
	p->derr = 0;
	p->derr = (p->dy + 1);
	p->diry = p->y_end - p->y0;
	p->diry = (p->diry > 0 ? 1 : -1);
	return (p);
}

t_help		*params_up(t_help *p)
{
	p->dx = ABS((p->x_end - p->x0));
	p->dy = ABS((p->y_end - p->y0));
	p->x0 = ABS(p->x0);
	p->y0 = ABS(p->y0);
	p->err = 0;
	p->derr = 0;
	p->derr = (p->dx + 1);
	p->dirx = ((p->x_end - p->x0) > 0 ? 1 : -1);
	return (p);
}

int			ft_first_check_line(char **argv, int size, t_help *p)
{
	p->ii = 0;
	p->jj = 0;
	while (p->ii < size)
	{
		while (argv[p->ii][p->jj] != '\n' && argv[p->ii][p->jj] != '\0')
		{
			while (argv[p->ii][p->jj] == ' ' || argv[p->ii][p->jj] == '\t')
				p->jj++;
			if (argv[p->ii][p->jj] == '-' || argv[p->ii][p->jj] == '+')
				p->jj++;
			while (argv[p->ii][p->jj] >= '0' && argv[p->ii][p->jj] <= '9')
				p->jj++;
			if (argv[p->ii][p->jj] != ',' && argv[p->ii][p->jj] != ' ' &&
			argv[p->ii][p->jj] != '\t' && argv[p->ii][p->jj] != '\n' &&
			argv[p->ii][p->jj] != '\0')
				return (0);
			while (argv[p->ii][p->jj] != ' ' && argv[p->ii][p->jj] != '\t' &&
			argv[p->ii][p->jj] != '\n' && argv[p->ii][p->jj] != '\0')
				p->jj++;
		}
		p->jj = 0;
		p->ii++;
	}
	return (1);
}
