/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscariot <lscariot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 12:56:46 by lscariot          #+#    #+#             */
/*   Updated: 2016/06/01 16:01:02 by lscariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_map(t_gen *gen)
{
	int	x;
	int	y;

	y = 0;
	while (y < gen->y)
	{
		x = 0;
		while (x < gen->x)
		{
			if ((x + 1) < gen->x)
				ft_draw_line(gen, gen->map[y][x], gen->map[y][x + 1]);
			if (y  + 1 < gen->y)
				ft_draw_line(gen, gen->map[y][x], gen->map[y + 1][x]);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(gen->mlx, gen->win, gen->img->img, 0, 0);
}

void	ft_show_map(t_gen *gen)
{
	gen->img = (t_img *)malloc(sizeof(t_img));
	gen->img->img = mlx_new_image(gen->mlx, WIN_X, WIN_Y);
	gen->img->data = mlx_get_data_addr(gen->img->img, &gen->img->bits,
		&gen->img->size_line, &gen->img->endian);
	ft_draw_map(gen);
}