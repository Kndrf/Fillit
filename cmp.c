/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cmp.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ghazette <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/30 13:52:57 by ghazette     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/30 13:54:41 by ghazette    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int		cmp0(char **data, int x, int y, char c)
{
	if (data[y + 1] != 0 && data[y + 2] != 0 && data[y][x + 1] != '\0')
	{
		if (data[y][x] == c && data[y + 1][x + 1] == c &&
				data[y + 2][x + 1] == c && data[y][x + 1] == c)
			return (0);
	}
	return (-1);
}

int		cmp1(char **data, int x, int y, char c)
{
	if (data[y + 1] != 0 && data[y + 2] != 0 && data[y][x + 1] != '\0')
	{
		if (data[y][x] == c && data[y + 1][x] == c &&
				data[y + 2][x] == c && data[y][x + 1] == c)
			return (1);
	}
	return (-1);
}

int		cmp2(char **data, int x, int y, char c)
{
	if (data[y + 1] != 0 && data[y + 2] != 0 && x != 0)
	{
		if (data[y][x] == c && data[y + 1][x] == c &&
				data[y + 2][x] == c && data[y + 2][x - 1] == c)
			return (2);
	}
	return (-1);
}

int		cmp3(char **data, int x, int y, char c)
{
	if (data[y][x + 1] != '\0' && data[y + 1] != 0 && data[y + 2] != 0)
	{
		if (data[y][x] == c && data[y + 1][x] == c &&
				data[y + 2][x] == c && data[y + 2][x + 1] == c)
			return (3);
	}
	return (-1);
}

int		cmp4(char **data, int x, int y, char c)
{
	if (data[y + 1] != 0 && x >= 2)
	{
		if (data[y][x] == c && data[y + 1][x] == c &&
				data[y + 1][x - 1] == c && data[y + 1][x - 2] == c)
			return (4);
	}
	return (-1);
}
