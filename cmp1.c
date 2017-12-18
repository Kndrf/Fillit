/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cmp1.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ghazette <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/30 13:53:06 by ghazette     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/30 13:55:32 by ghazette    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int		cmp5(char **data, int x, int y, char c)
{
	if (data[y][x + 1] != '\0' && data[y][x + 2] != '\0' && data[y + 1] != 0)
	{
		if (data[y][x] == c && data[y][x + 1] == c &&
				data[y][x + 2] == c && data[y + 1][x + 2] == c)
			return (5);
	}
	return (-1);
}

int		cmp6(char **data, int x, int y, char c)
{
	if (data[y][x + 1] != '\0' && data[y][x + 2] != '\0' && data[y + 1] != 0)
	{
		if (data[y][x] == c && data[y + 1][x] == c &&
				data[y + 1][x + 1] == c && data[y + 1][x + 2] == c)
			return (6);
	}
	return (-1);
}

int		cmp7(char **data, int x, int y, char c)
{
	if (data[y][x + 1] != '\0' && data[y][x + 2] != '\0' && data[y + 1] != 0)
	{
		if (data[y][x] == c && data[y][x + 1] == c &&
				data[y][x + 2] == c && data[y + 1][x] == c)
			return (7);
	}
	return (-1);
}

int		cmp8(char **data, int x, int y, char c)
{
	if (data[y + 1] != 0 && data[y][x + 1] != '\0' && x != 0)
	{
		if (data[y][x] == c && data[y][x + 1] == c &&
				data[y + 1][x] == c && data[y + 1][x - 1] == c)
			return (8);
	}
	return (-1);
}

int		cmp9(char **data, int x, int y, char c)
{
	if (data[y + 1] != 0 && data[y][x + 1] != '\0' && data[y][x + 2] != '\0')
	{
		if (data[y][x] == c && data[y][x + 1] == c &&
				data[y + 1][x + 1] == c && data[y + 1][x + 2] == c)
			return (9);
	}
	return (-1);
}
