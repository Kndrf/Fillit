/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_free3d.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ghazette <ghazette@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/05 20:20:30 by ghazette     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/07 17:35:55 by ghazette    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_free3d(char ****str)
{
	int i;

	i = 0;
	if ((*str))
	{
		while ((*str)[i] != 0)
		{
			ft_free2d(&((*str)[i]));
			i++;
		}
		free((*str)[i]);
		free(*str);
		*str = NULL;
	}
}
