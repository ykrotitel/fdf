/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rainbow.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 16:35:50 by acarlett          #+#    #+#             */
/*   Updated: 2020/07/21 18:26:04 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAINBOW_H
# define RAINBOW_H

# include <libc.h>
# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

# define WIN_X			1000
# define WIN_Y			1000
# define BUFF_SIZE		300000
# define ABS(x)			(x < 0 ? -x : x)

typedef struct			s_cord
{
	float				tx0;
	float				ty0;
	float				b_ty0;
	float				tz0;
	float				t_tx0;
	float				t_ty0;
	float				t_tz0;
	float				tx1;
	float				ty1;
	float				tz1;
	float				t_tx1;
	float				t_ty1;
	float				t_tz1;
	float				per0;
	float				per1;
}						t_cord;

typedef struct			s_help
{
	float				a;
	int					x0;
	int					y0;
	int					x_end;
	int					y_end;
	int					dirx;
	int					diry;
	int					d;
	int					err;
	int					derr;
	int					dx;
	int					dy;
	void				*mlx;
	void				*win1;
	void				*img;
	char				**line;
	char				**str;
	char				*s;
	int					**coord;
	int					**mas;
	int					i;
	int					j;
	int					ii;
	int					jj;
	int					n;
	int					m;
	int					mm;
	int					buff;
	char				**split;
	int					start_x;
	int					start_y;
	int					startx;
	int					starty;
	int					key;
	int					*data;
	int					q1;
	int					q2;
	int					q3;
	int					per;
	float				persp;
	float				koef;
	int					col;
	int					into;
	float				a_x;
	float				a_y;
	float				a_z;
	int					fd;
}						t_help;

int						right(t_help *p, int color);
int						down(t_help *p, int color);
int						left(t_help *p);
int						up(t_help *p);
int						make_line(t_help *p, int color);
int						get_next_line(const int fd, char **a);
int						ft_atoi(const char *str);
int						ft_takewith(char *s);
int						ft_howlong(int a);
int						make_sharp(t_help *p, int **mas, int j, int i);
int						make_increase(t_help *p, int **mas);
int						make_unincrease(t_help *p, int **mas);
int						tuda(t_help *p, int **mas, int key);
int						spin(t_help *p, int m, int n, int **mas);
int						ft_error(int a);
int						key_press(int key, void *l);
int						key_press_2(int key, t_help *p);
int						blackground(t_help *p);
int						continue1(t_help *p, char **argv);
int						continue2(int j, t_help *p);
int						continue3(t_help *p);
int						vertical_lines(t_cord *s, t_help *p, int **mas);
int						horizontal_lines(t_cord *s, t_help *p, int **mas);
int						lines_first_if(t_help *p, t_cord *s);
int						lines_first_else(t_help *p);
int						lines_second_if(t_help *p);
int						vertical_conditions(t_help *p, int n);
int						horizontal_conditions(t_help *p, int m);
int						first_parameters(t_help *p, int n, int m);
int						spin_second(t_help *p, t_cord *s, int m, int n);
char					*ft_strchr(const char *str, int ch);
char					*ft_strdup(const char *str);
char					*ft_strncpy(char *dest, const char *src, size_t n);
char					*ft_strnew(size_t size);
char					*ft_strjoin(char const *s1, char const *s2);
void					*ft_memalloc(size_t size);
char					**ft_split(char *str);
size_t					ft_strlen(const char *str);
void					*ft_memset(void *dest, int n, size_t size);
char					**ft_strsplit(char const *s, char c);
t_help					*params_down(t_help *p, int color);
t_help					*params_left(t_help *p);
t_help					*params_up(t_help *p);
t_help					*params_right(t_help *p, int color);
int						key_press_3(int key, t_help *p);
int						main_second(t_help *p, char **argv);

#endif
