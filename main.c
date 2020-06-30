/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 17:29:18 by acarlett          #+#    #+#             */
/*   Updated: 2020/06/30 18:40:40 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rainbow.h"

int		error()
{
	write(1, "\n\n      SORRY, MAN :c      \n\n", 30);
	return (0);
}

int		key_press(int key, void *l)
{
	t_help	*p;

	p = (t_help *)l;
	printf("%d\n", key);
	if (key == 53)
		exit(0);
		
	return 0;
}

int		main(int argc, char **argv)
{
	t_help				*p;
	int					fd;
	
	p = malloc(sizeof(t_help));
	p->mlx = mlx_init();
	p->a = 0x00CCFF;
	p->i = 0;
	p->win1 = mlx_new_window(p->mlx, WIN_X, WIN_Y, "Holla!");
	if ((fd = open(argv[1], O_RDONLY)) <= 0)
		return (error());
	while (get_next_line(fd, &(p->line)) > 0)
	{
		p->i++;
		free(p->line);
	}
	close (fd);
	p->str = malloc(sizeof(char *) * p->i);
	if ((fd = open(argv[1], O_RDONLY)) <= 0)
		return (error());
	p->i = 0;
	while (get_next_line(fd, &(p->str[p->i])) > 0)
		p->i++;
	p->i--;
	while(p->i >= 0)
	{
		printf ("%s\n", p->str[p->i]);
		p->i--;
	}
	// mlx_hook(p->win1, 2, 0, key_press, (void *)p);
	// mlx_loop(p->mlx);
	return (0);
}