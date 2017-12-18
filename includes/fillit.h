/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ghazette <ghazette@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 17:06:18 by ghazette     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/07 16:32:32 by ghazette    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

typedef struct		s_shape
{
	int				x;
	int				y;
	int				letter;
	int				(*ptr)(char **, int, int, char);
	char			**data;
	struct s_shape	*next;
}					t_shape;

typedef struct		s_vec2d
{
	int				x;
	int				y;
}					t_vec2d;

t_shape				*get_tetri(char *fp);
char				**convert_buf(char *buf);
int					isvalid_grid(char *buf, int ret);
char				**init_triangle(int shape);
char				**init_stairs(int shape);
char				**init_square(void);
char				**init_line(int shape);
char				**init_l(int shape);
t_shape				*gen_list(void);
void				free_t_shape(t_shape **list);
char				***convert_buf_3d(char *cbuf, char ****oldbuf3d, int size);
char				**solve(t_shape **list);
int					fill_map(t_shape *shape, char ***map, int x, int y);
int					point_number(char **data);
int					ft_sqrt_ceil(int n);
int					list_size(t_shape **list);
t_vec2d				*get_first_diese(char **cbuf, char c);
void				push_letters(t_shape **tetri);

int					cmp0(char **data, int x, int y, char c);
int					cmp1(char **data, int x, int y, char c);
int					cmp2(char **data, int x, int y, char c);
int					cmp3(char **data, int x, int y, char c);
int					cmp4(char **data, int x, int y, char c);
int					cmp5(char **data, int x, int y, char c);
int					cmp6(char **data, int x, int y, char c);
int					cmp7(char **data, int x, int y, char c);
int					cmp8(char **data, int x, int y, char c);
int					cmp9(char **data, int x, int y, char c);
int					cmp10(char **data, int x, int y, char c);
int					cmp11(char **data, int x, int y, char c);
int					cmp12(char **data, int x, int y, char c);
int					cmp13(char **data, int x, int y, char c);
int					cmp14(char **data, int x, int y, char c);
int					cmp15(char **data, int x, int y, char c);
int					cmp16(char **data, int x, int y, char c);
int					cmp17(char **data, int x, int y, char c);
int					cmp18(char **data, int x, int y, char c);

#endif
