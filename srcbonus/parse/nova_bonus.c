/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nova_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iestero- <iestero-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 07:41:48 by iestero-          #+#    #+#             */
/*   Updated: 2023/10/12 12:10:00 by iestero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static void	create_complex(t_complex *x, double real, double imag)
{
	x->real = real;
	x->img = imag;
}

static void	colors_selected(t_fractol *fractol)
{
	fractol->nova.colors[0] = LAVA_RED;
	fractol->nova.colors[1] = BLUE;
	fractol->nova.colors[2] = BLACK;
}

void	init_nova(t_fractol *fractol)
{
	colors_selected(fractol);
	create_complex(&fractol->nova.roots[0], 1, 0);
	create_complex(&fractol->nova.roots[1], -0.5, sqrt(3) / 2);
	create_complex(&fractol->nova.roots[2], -0.5, -sqrt(3) / 2);
}

t_complex	nova_ft(t_complex z, t_complex c, t_fractol *fractol)
{
	t_complex	result;
	t_complex	result2;
	t_complex	new_z;
	t_complex	f;

	create_complex(&f, -1, 0);
	new_z = sum_complex(power_complex(z, fractol->info_frt.power), f);
	result2 = power_complex(z, 2);
	result2.img *= 3;
	result2.real *= 3;
	result = divide_complex(new_z, result2);
	result2.real = z.real - result.real;
	result2.img = z.img - result.img;
	result = sum_complex(result2, c);
	return (result);
}
