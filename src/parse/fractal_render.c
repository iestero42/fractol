/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iestero- <iestero-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 10:44:53 by iestero-          #+#    #+#             */
/*   Updated: 2023/09/07 11:59:14 by iestero-         ###   ########.fr       */
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
static int	interpolation( double t, unsigned int colors[], int num_colors)
{
	int		num_segments;
	int		segment_index;
	double	segment_t;

	if (num_colors < 2)
		return (colors[0]);
	num_segments = num_colors - 1;
	segment_index = (int)(t * num_segments);
	segment_t = (t * num_segments) - segment_index;
	if (segment_index < 0)
		segment_index = 0;
	else if (segment_index >= num_segments)
	{
		segment_index = num_segments - 1;
		segment_t = 1.0;
	}
	return (create_trgb(0,
			(int)((1 - segment_t) * get_r(colors[segment_index])
			+ segment_t * get_r(colors[segment_index + 1])),
		(int)((1 - segment_t) * get_g(colors[segment_index])
		+ segment_t * get_g(colors[segment_index + 1])),
			(int)((1 - segment_t) * get_b(colors[segment_index])
			+ segment_t * get_b(colors[segment_index + 1]))));
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
	c.real = map(x, create_interval(-2, +2), create_interval(150, WIDTH));
	c.img = map(y, create_interval(+2, -2), create_interval(150, HEIGHT));
	i = -1;
	while (++i < fractal->cmplx_precision)
	{
		z = sum_complex(sqrt_complex(z), c);
		if (hypot(z.real, z.img) > fractal->escape_value)
		{
			color = interpolation((double) i / fractal->color_quality,
					fractal->colors.array_color, fractal->colors.num_colors);
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
