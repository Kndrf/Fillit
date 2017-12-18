/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa_base.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ghazette <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 14:06:25 by ghazette     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 14:06:26 by ghazette    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	int	getsize(int nb, int base)
{
	int			i;
	long int	n2;

	n2 = (long)nb;
	i = 0;
	if (n2 < 0)
		n2 = -n2;
	while (n2 != 0)
	{
		n2 /= base;
		i++;
	}
	return (i);
}

char		*ft_itoa_base(int nbr, int base)
{
	char		*ret;
	int			size;
	char		tab[37];
	long int	nbr2;

	if (base == 10)
		return (ft_itoa(nbr));
	nbr2 = (long)nbr;
	if (nbr2 == 0)
		return ("0");
	ft_strcpy(tab, "0123456789abcdefghijklmnopqrstuvwxyz");
	size = getsize(nbr, base);
	nbr2 = (nbr2 < 0) ? -nbr2 : nbr2;
	if ((ret = (char*)malloc(sizeof(char) + (size + 1))) == NULL)
		return (NULL);
	ret[size] = '\0';
	size--;
	while (nbr2 > 0)
	{
		ret[size] = tab[nbr2 % base];
		nbr2 /= base;
		size--;
	}
	return (ret);
}
