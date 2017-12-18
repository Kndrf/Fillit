/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init_square.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ghazette <ghazette@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/27 18:27:39 by ghazette     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/07 15:40:31 by ghazette    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft/libft.h"

char			**init_square(void)
{
	char **square;

	square = ft_2d_malloc(3, 3);
	if (!square)
		return (NULL);
	ft_strcpy(square[0], "##");
	ft_strcpy(square[1], "##");
	return (square);
}
