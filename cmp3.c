/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cmp3.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ghazette <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/30 13:53:26 by ghazette     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/30 13:53:27 by ghazette    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int		cmp15(char **data, int x, int y, char c)
{
	if (data[y + 1] != 0 && data[y + 2] != 0 && data[y][x + 1] != '\0')
	{
		if (data[y][x] == c && data[y + 1][x] == c &&
				data[y + 2][x] == c && data[y + 1][x + 1] == c)
			return (15);
	}
	return (-1);
}

int		cmp16(char **data, int x, int y, char c)
{
	if (data[y][x + 1] != '\0' && data[y][x + 2] != '\0' &&
			data[y][x + 3] != '\0')
	{
		if (data[y][x] == c && data[y][x + 1] == c && data[y][x + 2] == c &&
				data[y][x + 3] == c)
			return (16);
	}
	return (-1);
}

int		cmp17(char **data, int x, int y, char c)
{
	if (data[y + 1] != 0 && data[y + 2] != 0 && data[y + 3] != 0)
	{
		if (data[y][x] == c && data[y + 1][x] == c && data[y + 2][x] == c &&
				data[y + 3][x] == c)
			return (17);
	}
	return (-1);
}

int		cmp18(char **data, int x, int y, char c)
{
	if (data[y][x + 1] != '\0' && data[y + 1] != 0)
	{
		if (data[y][x] == c && data[y][x + 1] == c &&
				data[y + 1][x] == c && data[y + 1][x + 1] == c)
			return (18);
	}
	return (-1);
}
