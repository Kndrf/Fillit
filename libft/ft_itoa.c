/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ghazette <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 14:06:19 by ghazette     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 14:06:21 by ghazette    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	int	ft_getintsize(int n)
{
	int			i;
	long int	n2;

	n2 = (long)n;
	i = 0;
	if (n2 == 0)
		return (1);
	if (n2 < 0)
	{
		i++;
		n2 = -n2;
	}
	while (n2)
	{
		n2 /= 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	int			len;
	char		*nbr;
	long int	n2;
	int			limit;

	limit = 0;
	len = ft_getintsize(n);
	n2 = (long)n;
	if ((nbr = (char*)malloc(len + 1)) == NULL)
		return (NULL);
	if (n2 < 0)
	{
		nbr[0] = '-';
		n2 = -n2;
		limit = 1;
	}
	nbr[len] = '\0';
	len--;
	while (len >= limit)
	{
		nbr[len] = (n2 % 10) + '0';
		n2 /= 10;
		len--;
	}
	return (nbr);
}
