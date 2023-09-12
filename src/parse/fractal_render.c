/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iestero- <iestero-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 10:44:53 by iestero-          #+#    #+#             */
/*   Updated: 2023/09/12 13:00:45 by iestero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
 * @brief 
 * 
 * @param z 
 * @param c 
 * @param fractal 
 */
static void	choose_fractal(t_complex *z, t_complex *c, t_fractol *fractal)
{	
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		c->real = fractal->info_frt.z.real;
		c->img = fractal->info_frt.z.img;
	}
	else
	{
		c->real = z->real;
		c->img = z->img;
	}
}

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

	num_segments = num_colors - 1;
	segment_index = (int)(t * num_segments);
	segment_t = (t * num_segments) - segment_index;
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

	z.real = map(x, -2, +2, WIDTH) * fractal->zoom;
	z.img = map(y, +1.3, -1.3, HEIGHT) * fractal->zoom;
	choose_fractal(&z, &c, fractal);
	i = -1;
	while (++i < fractal->cmplx_precision)
	{
		z = fractal->info_frt.ft(z, c, fractal);
		if (hypot(z.real, z.img) >= fractal->escape_value)
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
int	fractol_render(t_fractol *fractal)
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
	return (0);
}
