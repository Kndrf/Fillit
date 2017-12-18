/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init_stairs.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ghazette <ghazette@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/27 18:28:47 by ghazette     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/07 15:40:38 by ghazette    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft/libft.h"

static void		init_stairs2(char ***stairs, int shape)
{
	if (shape == 8)
	{
		ft_strcpy((*stairs)[0], ".##");
		ft_strcpy((*stairs)[1], "##.");
	}
	else if (shape == 9)
	{
		ft_strcpy((*stairs)[0], "##.");
		ft_strcpy((*stairs)[1], ".##");
	}
	if (shape == 10)
	{
		ft_strcpy((*stairs)[0], ".#");
		ft_strcpy((*stairs)[1], "##");
		ft_strcpy((*stairs)[2], "#.");
	}
	else if (shape == 11)
	{
		ft_strcpy((*stairs)[0], "#.");
		ft_strcpy((*stairs)[1], "##");
		ft_strcpy((*stairs)[2], ".#");
	}
}

char			**init_stairs(int shape)
{
	char **stairs;

	stairs = NULL;
	if (shape == 8 || shape == 9)
		if (!(stairs = ft_2d_malloc(4, 3)))
			return (NULL);
	if (shape == 10 || shape == 11)
		if (!(stairs = ft_2d_malloc(3, 4)))
			return (NULL);
	init_stairs2(&stairs, shape);
	return (stairs);
}
