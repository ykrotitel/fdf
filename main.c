/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 17:29:18 by acarlett          #+#    #+#             */
/*   Updated: 2020/07/01 19:57:56 by acarlett         ###   ########.fr       */
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
	char				*s;
	char				**line;
	int					i;
	int					**mas;
	int					j;
	int					m;
	
	p = malloc(sizeof(t_help));
	i = 0;
	j = 0;
	m = 0;
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &s) > 0)
	{
		i++;
		m = ft_takewith(s);
		free(s);
	}
	close(fd);
	fd = open(argv[1], O_RDONLY);
	line = malloc(sizeof(char *) * i);
	mas = malloc(sizeof(int *) * i);
	while(get_next_line(fd, &(line[j])) > 0)
	{
		mas[j] = malloc(sizeof(int) * m);
		j++;
	}
	m = 0;
	j = 0;
	while (m != i)
	{
		while (*line[m] != '\0')
		{
			mas[m][j] = ft_atoi(line[m]);
			line[m] += (ft_howlong(mas[m][j]) + 1);
			j++;
		}
		j = 0;
		m++;
	}
	printf ("%d", mas[6][4]);
	// p->mlx = mlx_init();
	// p->win1 = mlx_new_window(p->mlx, WIN_X, WIN_Y, "Holla!");
	// mlx_hook(p->win1, 2, 0, key_press, (void *)p);
	// mlx_loop(p->mlx);
	return (0);
}