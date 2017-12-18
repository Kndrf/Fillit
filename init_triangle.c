/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init_triangle.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ghazette <ghazette@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/27 18:30:12 by ghazette     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/07 15:40:42 by ghazette    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft/libft.h"

static void		init_triangle2(char ***tri, int shape)
{
	if (shape == 12)
	{
		ft_strcpy((*tri)[0], ".#.");
		ft_strcpy((*tri)[1], "###");
	}
	else if (shape == 13)
	{
		ft_strcpy((*tri)[0], "###");
		ft_strcpy((*tri)[1], ".#.");
	}
	if (shape == 14)
	{
		ft_strcpy((*tri)[0], ".#");
		ft_strcpy((*tri)[1], "##");
		ft_strcpy((*tri)[2], ".#");
	}
	else if (shape == 15)
	{
		ft_strcpy((*tri)[0], "#.");
		ft_strcpy((*tri)[1], "##");
		ft_strcpy((*tri)[2], "#.");
	}
}

char			**init_triangle(int shape)
{
	char **tri;

	tri = NULL;
	if (shape == 12 || shape == 13)
		if (!(tri = ft_2d_malloc(4, 3)))
			return (NULL);
	if (shape == 14 || shape == 15)
		if (!(tri = ft_2d_malloc(3, 4)))
			return (NULL);
	init_triangle2(&tri, shape);
	return (tri);
}
