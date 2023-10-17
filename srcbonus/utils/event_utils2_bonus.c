/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_utils2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iestero- <iestero-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 10:45:50 by iestero-          #+#    #+#             */
/*   Updated: 2023/10/17 10:18:06 by iestero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

/**
 * @brief 
 * 
 * @param x 
 * @param y 
 * @param fractal 
 */
int	handle_pixel_nova_scr(int x, int y, t_fractol *fractal)
{
	t_complex		z;
	unsigned int	i;
	int				j;

	z.real = (map(x, -2, +2, WIDTH / 1.5)
			* fractal->zoom) + fractal->info_frt.shift_x;
	z.img = (map(y, +1.3, -1.3, HEIGHT / 1.5)
			* fractal->zoom) + fractal->info_frt.shift_y;
	i = -1;
	while (++i < fractal->cmplx_precision)
	{
		z = nova_ft(z, fractal);
		j = -1;
		while (++j < 3)
		{
			fractal->nova.diff.real = z.real - fractal->nova.roots[j].real;
			fractal->nova.diff.img = z.img - fractal->nova.roots[j].img;
			if (fabs(fractal->nova.diff.real) < 0.00001
				&& fabs(fractal->nova.diff.img) < 0.00001)
				return (interpolation((double) i / 100, fractal));
		}
	}
	return (BLACK);
}

void	reset(t_fractol *fractol)
{
	fractol->zoom = 1;
	fractol->info_frt.shift_x = 0.0;
	fractol->info_frt.shift_y = 0.0;
}
