/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rainbow.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 19:18:09 by acarlett          #+#    #+#             */
/*   Updated: 2020/07/04 20:04:13 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>
#include <mlx.h>
#include <stdlib.h>
#include <fcntl.h>
#include <math.h> 

# define WIN_X       800
# define WIN_Y       800
# define BUFF_SIZE 300000
# define ABS(x)         (x < 0 ? -x : x)
// # define MAX(x, y)      (x > y ? x : y)

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
	void			*mlx;
	void			*win1;
	void			*img;
    char            *line;
    char            **str;
    int             **coord;
    int             i;
    int             j;
    int             n;
    int             m;
    char            **split;
}                   t_help;

int     right(t_help *p, void *mlx, void *win1, int color);
int		down(t_help *p, void *mlx, void *win1, int color);
int		left(t_help *p, void *mlx, void *win1);
int		up(t_help *p, void *mlx, void *win1);
 int	make_line(t_help *p, void *mlx, void *win1, int color);
int		get_next_line(const int fd, char **a);
char	*ft_strchr(const char *str, int ch);
char	*ft_strdup(const char *str);
char	*ft_strncpy(char *dest, const char *src, size_t n);
char	*ft_strnew(size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memalloc(size_t size);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *dest, int n, size_t size);
int		ft_atoi(const char *str);
char	**ft_strsplit(char const *s, char c);
int		ft_takewith(char *s);
int		ft_howlong(int a);
int		make_sharp(t_help *p, int **mas, int j, int i);
