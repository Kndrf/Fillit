/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   solve_func.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ghazette <ghazette@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/05 20:13:17 by ghazette     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/08 16:58:36 by robihaap    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/fillit.h"
#include <stdlib.h>

int		point_number(char **data)
{
	int nbpoints;

	nbpoints = 0;
	while (data[0][nbpoints] == '.' && data[0][nbpoints])
		nbpoints++;
	return (nbpoints);
}

int		ft_sqrt_ceil(int n)
{
	int size;

	size = 2;
	while ((size * size) < n)
		size++;
	return (size);
}

int		list_size(t_shape **list)
{
	int		i;
	t_shape	*shape;

	shape = *list;
	i = 0;
	if (shape)
	{
		while (shape->next)
		{
			i++;
			shape = shape->next;
		}
	}
	return (i);
}

t_vec2d	*get_first_diese(char **cbuf, char c)
{
	t_vec2d		*coord;

	if (!(coord = (t_vec2d*)malloc(sizeof(*coord))))
		return (NULL);
	coord->y = 0;
	while (cbuf[coord->y] != 0)
	{
		coord->x = 0;
		while (cbuf[coord->y][coord->x] != '\0')
		{
			if (cbuf[coord->y][coord->x] == c)
				return (coord);
			coord->x++;
		}
		coord->y++;
	}
	return (NULL);
}

void	push_letters(t_shape **tetri)
{
	t_shape	*tmp;
	int		a;

	a = 'A';
	tmp = *tetri;
	while (tmp)
	{
		tmp->letter = a;
		a++;
		tmp = tmp->next;
	}
}
