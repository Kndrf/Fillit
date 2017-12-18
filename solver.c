/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   solver.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ghazette <ghazette@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/30 20:59:09 by ghazette     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/08 16:58:25 by robihaap    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft/libft.h"
#include "includes/fillit.h"

static char		**newmap(t_shape **list, int increment)
{
	int		size;
	char	**map;
	t_shape	*shape;

	shape = *list;
	size = ft_sqrt_ceil(list_size(&shape) * 4);
	if (size)
	{
		if ((map = ft_2d_malloc(size + 1 + increment, size + 1 + increment)))
			ft_str2dcpy(map, '.', size + increment);
		return (map);
	}
	return (NULL);
}

static void		del_tetri(char ***map, int letter, int x, int y)
{
	int count;

	count = 0;
	while ((*map)[y] != 0)
	{
		x = 0;
		while ((*map)[y][x])
		{
			if ((*map)[y][x] == letter)
			{
				count++;
				(*map)[y][x] = '.';
			}
			if (count == 4)
				break ;
			x++;
		}
		y++;
	}
}

static int		check(char **map, t_shape **tetri)
{
	int x;
	int y;

	y = 0;
	if (!map)
		return (0);
	while (map[y] != 0)
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '.')
				if (fill_map(*tetri, &map, x, y))
				{
					if ((*tetri)->next == NULL)
						return (1);
					if ((check(map, &(*tetri)->next)))
						return (1);
					del_tetri(&map, (*tetri)->letter, x, y);
				}
			x++;
		}
		y++;
	}
	return (0);
}

char			**solve(t_shape **list)
{
	char	**map;
	t_shape	*shape;
	int		increment;

	shape = *list;
	increment = 0;
	map = NULL;
	while ((check(map, &shape)) == 0)
	{
		if (map)
			ft_free2d(&map);
		map = newmap(&shape, increment);
		if (!map)
			return (NULL);
		increment++;
	}
	return (map);
}

int				fill_map(t_shape *tetri, char ***map, int x, int y)
{
	int i;
	int j;
	int xprev;

	i = 0;
	if ((tetri->ptr(*map, x, y, '.')) != -1)
	{
		xprev = x - point_number(tetri->data);
		while (tetri->data[i] != 0)
		{
			x = xprev;
			j = 0;
			while (tetri->data[i][j])
			{
				if ((*map)[y][x] == '.' && tetri->data[i][j] == '#')
					(*map)[y][x] = tetri->letter;
				j++;
				x++;
			}
			y++;
			i++;
		}
		return (1);
	}
	return (0);
}
