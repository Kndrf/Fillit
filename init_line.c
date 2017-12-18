/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init_line.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ghazette <ghazette@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/27 18:28:08 by ghazette     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/07 15:40:26 by ghazette    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft/libft.h"

char			**init_line(int shape)
{
	char	**line;
	int		i;

	i = 3;
	if (shape < 16 || shape > 17)
		return (NULL);
	if (shape == 16)
	{
		if (!(line = ft_2d_malloc(5, 2)))
			return (NULL);
		ft_strcpy(line[0], "####");
	}
	if (shape == 17)
	{
		if (!(line = ft_2d_malloc(2, 5)))
			return (NULL);
		while (i >= 0)
		{
			ft_strcpy(line[i], "#");
			i--;
		}
	}
	return (line);
}
