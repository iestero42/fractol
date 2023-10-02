/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iestero- <iestero-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 10:44:53 by iestero-          #+#    #+#             */
/*   Updated: 2023/09/29 11:50:11 by iestero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
 * @brief 
 * 
 * @param fractal 
 */
static void	fractal_render_img(t_fractol *fractal)
{
	int		width;
	int		height;
	t_data	win;

	win.img = mlx_xpm_file_to_image(fractal->mlx, "./images/controls.xpm",
			&width, &height);
	win.addr = mlx_get_data_addr(win.img,
			&win.bits_per_pixel,
			&win.line_length, &win.endian);
	mlx_put_image_to_window(fractal->mlx, fractal->mlx_win, win.img,
		1200, 0);
}

/**
 * @brief 
 * 
 * @param z 
 * @param c 
 * @param fractal 
 */
static void	choose_fractal(t_complex *z, t_complex *c, t_fractol *fractal)
{	
	if (!ft_strcmp(fractal->name, "julia"))
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
static int	interpolation( double t)
{
	int	raw_color;

	raw_color = create_trgb(0,
		(int)(9 * ( 1 - t ) * t * t * t  * 255),
		(int)(15 * ( 1 - t ) * t * t * 255),
		(int)(8.5 * ( 1 - t ) * t * 120));
	return (raw_color % 0xFFFFFF);
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

	z.real = map(x, -2, +2, WIDTH / 1.5) * fractal->zoom;
	z.img = map(y, +1.3, -1.3, HEIGHT / 1.5) * fractal->zoom;
	choose_fractal(&z, &c, fractal);
	i = -1;
	while (++i < fractal->cmplx_precision)
	{
		z = fractal->info_frt.ft(z, c, fractal);
		if (hypot(z.real, z.img) >= fractal->escape_value)
		{
			color = interpolation((double) i / fractal->cmplx_precision);
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
	while (++y < HEIGHT / 1.5)
	{
		x = -1;
		while (++x < WIDTH / 1.5)
		{
			handle_pixel(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx, fractal->mlx_win,
		fractal->img_data.img, (WIDTH - (WIDTH / 1.5)) / 20,
		(HEIGHT - (HEIGHT / 1.5)) / 2);
	fractal_render_img(fractal);
	return (0);
}
