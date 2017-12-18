/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ghazette <ghazette@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 16:03:58 by ghazette     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/07 15:40:00 by ghazette    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft/libft.h"
#include "includes/fillit.h"
#include <stdlib.h>

static int		count_diese(char *buf, int ret)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < ret)
	{
		if (buf[i] == '#')
			count++;
		i++;
	}
	if (count == 4)
		return (1);
	return (0);
}

static int		check_shape(char **cbuf, int i, int j)
{
	int count;

	count = 0;
	if (i >= 1)
		count += (cbuf[i - 1][j] == '#') ? 1 : 0;
	if (j <= 2)
		count += (cbuf[i][j + 1] == '#') ? 1 : 0;
	if (i <= 2)
		count += (cbuf[i + 1][j] == '#') ? 1 : 0;
	if (j >= 1)
		count += (cbuf[i][j - 1] == '#') ? 1 : 0;
	return (count);
}

static int		isvalid_shape(char *buf)
{
	int		i;
	int		j;
	int		count;
	char	**cbuf;

	count = 0;
	i = 0;
	if (!(cbuf = convert_buf(buf)))
		return (0);
	while (cbuf[i] != 0)
	{
		j = 0;
		while (cbuf[i][j])
		{
			if (cbuf[i][j] == '#')
				count += check_shape(cbuf, i, j);
			j++;
		}
		i++;
	}
	i = 0;
	ft_free2d(&cbuf);
	return (count);
}

int				isvalid_grid(char *buf, int ret)
{
	int i;
	int rows;
	int cols;

	cols = 0;
	rows = 0;
	i = 0;
	while (i < ret)
	{
		if (buf[i] != '.' && buf[i] != '#' && buf[i] != '\n')
			return (0);
		if (buf[i] == '\n' && buf[i - 1] != '\n')
		{
			if (cols != 4)
				return (0);
			rows++;
			cols = -1;
		}
		cols++;
		i++;
	}
	if (rows == 4 && buf[i - 1] == '\n')
		return (count_diese(buf, ret) && (isvalid_shape(buf) >= 6));
	return (0);
}
