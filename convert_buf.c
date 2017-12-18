/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   convert_buf.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ghazette <ghazette@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/30 14:08:33 by ghazette     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/07 15:40:14 by ghazette    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdlib.h>

char		**convert_buf(char *buf)
{
	int		i;
	int		j;
	int		k;
	char	**cbuf;

	j = 0;
	i = 0;
	k = 0;
	if (!(cbuf = ft_2d_malloc(5, 5)))
		return (NULL);
	while (cbuf[i] != 0)
	{
		j = 0;
		while (buf[k] != '\n')
		{
			cbuf[i][j] = buf[k];
			j++;
			k++;
		}
		cbuf[i][j] = '\0';
		k++;
		i++;
	}
	return (cbuf);
}

static int	append_3d_array(char ****dst, char ***src, int i)
{
	int j;

	j = 0;
	if (!((*dst)[i] = ft_2d_malloc(ft_strlen((*src)[0]) + 1,
					ft_heightlen(*src) + 1)))
		return (0);
	while ((*src)[j] != 0)
	{
		ft_strcpy((*dst)[i][j], (*src)[j]);
		j++;
	}
	(*dst)[i + 1] = 0;
	return (1);
}

static int	prepend_3d_array(char ****dst, char ****src, int *i)
{
	int j;

	j = 0;
	if (!((*dst)[*i] = ft_2d_malloc(ft_strlen((*src)[*i][j]) + 1,
					ft_heightlen((*src)[*i]) + 1)))
		return (0);
	while ((*src)[*i][j] != 0)
	{
		ft_strcpy((*dst)[*i][j], (*src)[*i][j]);
		j++;
	}
	(*dst)[(*i) + 1] = 0;
	(*i)++;
	return (1);
}

char		***convert_buf_3d(char *buf, char ****oldbuf3d, int size)
{
	char	***buf3d;
	char	**cbuf;
	int		i;

	i = 0;
	if (!(cbuf = convert_buf(buf)) ||
			!(buf3d = (char***)malloc(sizeof(char**) * size)))
		return (NULL);
	if ((*oldbuf3d) != NULL)
	{
		while ((*oldbuf3d)[i] != 0)
		{
			if (!(prepend_3d_array(&buf3d, oldbuf3d, &i)))
				return (NULL);
		}
		if (!(append_3d_array(&buf3d, &cbuf, i)))
			return (NULL);
		ft_free2d(&cbuf);
		ft_free3d(oldbuf3d);
		return (buf3d);
	}
	if (!(append_3d_array(&buf3d, &cbuf, 0)))
		return (NULL);
	ft_free2d(&cbuf);
	return (buf3d);
}
