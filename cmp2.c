/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cmp2.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ghazette <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/30 13:53:19 by ghazette     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/30 13:53:20 by ghazette    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int		cmp10(char **data, int x, int y, char c)
{
	if (data[y + 1] != 0 && data[y + 2] != 0 && x != 0)
	{
		if (data[y][x] == c && data[y + 1][x] == c &&
		data[y + 1][x - 1] == c && data[y + 2][x - 1] == c)
			return (10);
	}
	return (-1);
}

int		cmp11(char **data, int x, int y, char c)
{
	if (data[y + 1] != 0 && data[y + 2] != 0 && data[y][x + 1] != '\0')
	{
		if (data[y][x] == c && data[y + 1][x] == c &&
		data[y + 1][x + 1] == c && data[y + 2][x + 1] == c)
			return (11);
	}
	return (-1);
}

int		cmp12(char **data, int x, int y, char c)
{
	if (data[y + 1] != 0 && data[y][x + 1] != '\0' && x != 0)
	{
		if (data[y][x] == c && data[y + 1][x + 1] == c &&
		data[y + 1][x - 1] == c && data[y + 1][x] == c)
			return (12);
	}
	return (-1);
}

int		cmp13(char **data, int x, int y, char c)
{
	if (data[y + 1] != 0 && data[y][x + 1] != '\0' && data[y][x + 2] != '\0')
	{
		if (data[y][x] == c && data[y + 1][x + 1] == c &&
		data[y][x + 1] == c && data[y][x + 2] == c)
			return (13);
	}
	return (-1);
}

int		cmp14(char **data, int x, int y, char c)
{
	if (data[y + 1] != 0 && data[y + 2] != 0 && x != 0)
	{
		if (data[y][x] == c && data[y + 1][x] == c &&
		data[y + 2][x] == c && data[y + 1][x - 1] == c)
			return (14);
	}
	return (-1);
}
