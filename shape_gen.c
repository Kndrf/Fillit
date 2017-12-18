/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   shape_gen.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ghazette <ghazette@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 11:52:49 by ghazette     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/07 15:40:51 by ghazette    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft/libft.h"
#include "includes/fillit.h"
#include <stdlib.h>

static char		**gen_shape(int shape)
{
	if (shape >= 0 && shape <= 7)
		return (init_l(shape));
	if (shape >= 8 && shape <= 11)
		return (init_stairs(shape));
	if (shape >= 12 && shape <= 15)
		return (init_triangle(shape));
	if (shape == 16 || shape == 17)
		return (init_line(shape));
	if (shape == 18)
		return (init_square());
	return (NULL);
}

static int		(**cmpfunc(void))(char **, int, int, char)
{
	int (**ptr)(char **, int, int, char);

	if (!(ptr = malloc(sizeof(*ptr) * 19)))
		return (NULL);
	ptr[0] = cmp0;
	ptr[1] = cmp1;
	ptr[2] = cmp2;
	ptr[3] = cmp3;
	ptr[4] = cmp4;
	ptr[5] = cmp5;
	ptr[6] = cmp6;
	ptr[7] = cmp7;
	ptr[8] = cmp8;
	ptr[9] = cmp9;
	ptr[10] = cmp10;
	ptr[11] = cmp11;
	ptr[12] = cmp12;
	ptr[13] = cmp13;
	ptr[14] = cmp14;
	ptr[15] = cmp15;
	ptr[16] = cmp16;
	ptr[17] = cmp17;
	ptr[18] = cmp18;
	return (ptr);
}

static void		create_cmp_list(t_shape **cmp, int i,
		int (fptr) (char **, int, int, char))
{
	t_shape *tmp;

	tmp = *cmp;
	tmp->data = gen_shape(i);
	tmp->x = ft_strlen(tmp->data[0]);
	tmp->y = ft_heightlen(tmp->data);
	tmp->ptr = fptr;
	tmp->letter = 0;
}

t_shape			*gen_list(void)
{
	t_shape		*list;
	t_shape		*tmp;
	int			(**fptr)(char **, int, int, char);
	int			i;

	i = 0;
	if (!(fptr = cmpfunc()))
		return (NULL);
	if (!(list = (t_shape*)malloc(sizeof(*list))))
		return (NULL);
	tmp = list;
	while (i < 19)
	{
		create_cmp_list(&tmp, i, fptr[i]);
		if (i <= 17)
		{
			if (!(tmp->next = (t_shape*)malloc(sizeof(*list))))
				return (NULL);
			tmp = tmp->next;
		}
		i++;
	}
	free(fptr);
	tmp->next = NULL;
	return (list);
}
