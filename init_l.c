/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init_l.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ghazette <ghazette@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/27 18:29:19 by ghazette     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/07 15:40:21 by ghazette    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft/libft.h"

static void		init_l2(char ***l, int shape)
{
	if (shape >= 4 && shape <= 7)
	{
		if (shape == 4)
		{
			ft_strcpy((*l)[0], "..#");
			ft_strcpy((*l)[1], "###");
		}
		else if (shape == 5)
		{
			ft_strcpy((*l)[0], "###");
			ft_strcpy((*l)[1], "..#");
		}
		else if (shape == 6)
		{
			ft_strcpy((*l)[0], "#..");
			ft_strcpy((*l)[1], "###");
		}
		else if (shape == 7)
		{
			ft_strcpy((*l)[0], "###");
			ft_strcpy((*l)[1], "#..");
		}
	}
}

static void		init_l1(char ***l, int shape)
{
	int i;
	int lmt;

	lmt = 1;
	i = 2;
	if (shape == 0 || shape == 1)
		ft_strcpy((*l)[0], "##");
	if (shape == 2 || shape == 3)
	{
		ft_strcpy((*l)[2], "##");
		i--;
		lmt = 0;
	}
	while (i >= lmt)
	{
		if (shape == 0 || shape == 2)
			ft_strcpy((*l)[i], ".#");
		if (shape == 1 || shape == 3)
			ft_strcpy((*l)[i], "#.");
		i--;
	}
}

char			**init_l(int shape)
{
	char	**l;

	if (shape >= 0 && shape <= 3)
	{
		if (!(l = ft_2d_malloc(3, 4)))
			return (NULL);
		init_l1(&l, shape);
	}
	if (shape >= 4 && shape <= 7)
	{
		if (!(l = ft_2d_malloc(4, 3)))
			return (NULL);
		init_l2(&l, shape);
	}
	return (l);
}
