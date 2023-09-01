/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iestero- <iestero-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 10:44:53 by iestero-          #+#    #+#             */
/*   Updated: 2023/09/01 12:40:11 by iestero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
 * @brief 
 * 
 * @param x 
 * @param y 
 * @param fractal 
 */
static void	handle_pixel(int x, int y, t_fractol *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	z.real = 0.0;
	z.img = 0.0;
	c.real = map(x, create_interval(-2, +2), create_interval(0, WIDTH));
	c.img = map(y, create_interval(+2, -2), create_interval(0, HEIGHT));
	i = -1;
	while (++i < fractal->iterations)
	{
		z = sum_complex(sqrt_complex(z), c);
		if (hypot(z.real, z.img) > fractal->escape_value)
		{
			color = map(i, create_interval(BLACK, WHITE),
					create_interval(0, fractal->iterations));
			my_mlx_pixel_put(fractal->img_data, x, y, color);
			return ;
		}
		my_mlx_pixel_put(fractal->img_data, x, y, color);
	}
	my_mlx_pixel_put(fractal->img_data, x, y, PSYCHEDELIC_PURPLE);
}

/**
 * @brief 
 * 
 * @param fractal 
 */
void	fractol_render(t_fractol *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			handle_pixel(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx, fractal->mlx_win,
		fractal->img_data, 0, 0);
}
