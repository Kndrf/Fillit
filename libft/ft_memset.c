/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memset.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ghazette <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 14:08:17 by ghazette     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 14:08:18 by ghazette    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	unsigned char *b_;

	b_ = (unsigned char *)b;
	if (n == 0)
		return (b);
	while (n--)
	{
		*b_ = (unsigned char)c;
		b_++;
	}
	return (b);
}
