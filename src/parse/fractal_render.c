/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iestero- <iestero-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 10:44:53 by iestero-          #+#    #+#             */
/*   Updated: 2023/09/06 13:25:34 by iestero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
 * @brief
 * 
 * @param i 
 * @param iterations 
 * @return int 
 */
static int	interpolation(double t, int color1, int color2)
{
	int		r_interp;
	int		g_interp;
	int		b_interp;

	r_interp = (int)(get_r(color1) * (1 - t) + get_r(color2) * t);
	g_interp = (int)(get_g(color1) * (1 - t) + get_g(color2) * t);
	b_interp = (int)(get_b(color1) * (1 - t) + get_b(color2) * t);
	return (create_trgb(0, r_interp, g_interp, b_interp));
}

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
	c.real = map(x, create_interval(-2, +2), create_interval(30, WIDTH));
	c.img = map(y, create_interval(+2, -2), create_interval(30, HEIGHT));
	color = BLACK;
	i = -1;
	while (++i < fractal->iterations)
	{
		z = sum_complex(sqrt_complex(z), c);
		if (hypot(z.real, z.img) > fractal->escape_value)
		{
			color = interpolation((double) i / fractal->iterations,
					fractal->iterations, BLACK, RED);
			my_mlx_pixel_put(&fractal->img_data, x, y, color);
			return ;
		}
	}
	my_mlx_pixel_put(&fractal->img_data, x, y, BLACK);
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
		fractal->img_data.img, 0, 0);
}
