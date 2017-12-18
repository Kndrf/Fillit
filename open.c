/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   open.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ghazette <ghazette@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/30 15:49:21 by ghazette     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/07 17:39:45 by ghazette    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft/libft.h"
#include "includes/fillit.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#define BUFFSIZE 21

static int		push_to_list(t_shape **tetri, t_shape *cmp_tmp)
{
	int i;

	i = 0;
	if ((*tetri) && cmp_tmp)
	{
		(*tetri)->data = ft_2d_malloc(cmp_tmp->x + 1, cmp_tmp->y + 1);
		if (!((*tetri)->data))
			return (0);
		while (i < cmp_tmp->y)
		{
			ft_strcpy((*tetri)->data[i], cmp_tmp->data[i]);
			i++;
		}
		(*tetri)->data[i] = 0;
		(*tetri)->ptr = cmp_tmp->ptr;
		(*tetri)->x = cmp_tmp->x;
		(*tetri)->y = cmp_tmp->y;
		(*tetri)->letter = 0;
		(*tetri)->next = NULL;
		return (1);
	}
	return (0);
}

static int		check_and_push(char **buf3d, t_shape *cmp_tmp,
			t_shape **tetri_ptr, t_vec2d *coord)
{
	if ((cmp_tmp->ptr(buf3d, coord->x, coord->y, '#')) != -1)
	{
		push_to_list(&(*tetri_ptr), cmp_tmp);
		if (buf3d + 1 != 0)
			if (!((*tetri_ptr)->next = (t_shape*)malloc(sizeof(t_shape))))
				return (0);
		free(coord);
		return (1);
	}
	return (0);
}

static int		get_tetri_list(char ***buf3d, t_shape **cmp, t_shape **tetri)
{
	int			i;
	t_vec2d		*coord;
	t_shape		*cmp_tmp;
	t_shape		*tetri_ptr;

	cmp_tmp = *cmp;
	tetri_ptr = *tetri;
	i = 0;
	while (buf3d[i] != 0)
	{
		tetri_ptr = (i > 0) ? tetri_ptr->next : tetri_ptr;
		coord = get_first_diese(buf3d[i], '#');
		while (cmp_tmp)
		{
			if (check_and_push(buf3d[i], cmp_tmp, &tetri_ptr, coord))
				break ;
			cmp_tmp = cmp_tmp->next;
		}
		i++;
		cmp_tmp = *cmp;
	}
	tetri_ptr->next = NULL;
	return (1);
}

static char		***read_file(char *fp)
{
	int			fd;
	char		buf[BUFFSIZE];
	char		***buf3d;
	int			size[2];
	int			ret;

	buf3d = NULL;
	size[0] = 1;
	if ((fd = open(fp, O_RDONLY)) == -1)
		return (0);
	while ((ret = read(fd, &buf, BUFFSIZE)))
	{
		if (isvalid_grid(buf, ret) && size[0] < 27)
			buf3d = convert_buf_3d(buf, &buf3d, size[0] + 1);
		else
		{
			ft_free3d(&buf3d);
			return (NULL);
		}
		size[0]++;
		size[1] = ret;
	}
	if (size[1] != 20)
		ft_free3d(&buf3d);
	return ((size[1] == 20) ? buf3d : NULL);
}

t_shape			*get_tetri(char *fp)
{
	t_shape *cmp;
	t_shape *tetri;
	char	***buf3d;

	if (!(tetri = (t_shape*)malloc(sizeof(*tetri))))
		return (NULL);
	if (!(cmp = gen_list()))
		return (NULL);
	if (!(buf3d = read_file(fp)))
	{
		free_t_shape(&cmp);
		return (NULL);
	}
	get_tetri_list(buf3d, &cmp, &tetri);
	if (!tetri)
	{
		ft_free3d(&buf3d);
		free_t_shape(&cmp);
		return (NULL);
	}
	push_letters(&tetri);
	ft_free3d(&buf3d);
	free_t_shape(&cmp);
	return (tetri);
}
