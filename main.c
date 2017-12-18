/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ghazette <ghazette@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/27 19:10:31 by ghazette     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/07 16:41:00 by ghazette    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft/libft.h"
#include "includes/fillit.h"

int		main(int argc, char **argv)
{
	t_shape	*tetri;
	int		i;
	char	**solved;

	i = 0;
	if (argc == 2)
	{
		tetri = get_tetri(argv[1]);
		if (tetri)
		{
			if ((solved = solve(&tetri)))
			{
				while (solved[i] != 0)
					ft_putendl(solved[i++]);
			}
			free_t_shape(&tetri);
		}
		else
			ft_putstr_fd("error\n", 1);
	}
	else
		ft_putstr_fd("usage: ./fillit [valid_input_file]\n", 1);
	return (0);
}
