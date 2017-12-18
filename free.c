/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ghazette <ghazette@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/30 14:08:40 by ghazette     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/07 17:36:37 by ghazette    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft/libft.h"
#include "includes/fillit.h"
#include <stdlib.h>

void	free_t_shape(t_shape **list)
{
	t_shape *free_list;
	t_shape *tmp;

	free_list = *list;
	if (free_list)
	{
		while (free_list)
		{
			tmp = free_list;
			free_list = free_list->next;
			ft_free2d(&(tmp->data));
			free(tmp);
		}
		*list = NULL;
	}
}
