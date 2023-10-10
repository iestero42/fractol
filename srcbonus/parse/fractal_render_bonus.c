/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_render_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iestero- <iestero-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 10:44:53 by iestero-          #+#    #+#             */
/*   Updated: 2023/10/10 11:27:04 by iestero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

/**
 * @brief 
 * 
 * @param fractal 
 */
void	fractal_render_img(t_fractol *fractal)
{
	int		width;
	int		height;
	t_data	win;

	win.img = mlx_xpm_file_to_image(fractal->mlx, "./images/controls_bonus.xpm",
			&width, &height);
	win.addr = mlx_get_data_addr(win.img,
			&win.bits_per_pixel,
			&win.line_length, &win.endian);
	mlx_put_image_to_window(fractal->mlx, fractal->win_prnt, win.img,
		1300, 0);
	mlx_destroy_image(fractal->mlx, win.img);
}

/**
 * @brief 
 * 
 * @param z 
 * @param c 
 * @param fractal 
 */
void	choose_fractal(t_complex *z, t_complex *c, t_fractol *fractal)
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
int	interpolation(double t, t_fractol *fractal)
{
	int	raw_color;

	raw_color = create_trgb(0,
			(int)(9 * (1 - t) * t * t * t * fractal->colors.r),
			(int)(15 * (1 - t) * t * t * fractal->colors.g),
			(int)(8.5 * (1 - t) * t * fractal->colors.b));
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

	z.real = (map(x, -2, +2, WIDTH_FRACTAL)
			* fractal->zoom) + fractal->info_frt.shift_x;
	z.img = (map(y, +2, -2, HEIGHT_FRACTAL)
			* fractal->zoom) + fractal->info_frt.shift_y;
	choose_fractal(&z, &c, fractal);
	i = -1;
	while (++i < fractal->cmplx_precision)
	{
		z = fractal->info_frt.ft(z, c, fractal);
		if (hypot(z.real, z.img) >= fractal->escape_value)
		{
			color = interpolation((double) i / fractal->cmplx_precision,
					fractal);
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
	while (++y < HEIGHT_FRACTAL)
	{
		x = -1;
		while (++x < WIDTH_FRACTAL)
		{
			handle_pixel(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx, fractal->mlx_win,
		fractal->img_data.img, 0, 0);
	return (0);
}
