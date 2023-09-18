/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iestero- <iestero-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 09:21:46 by iestero-          #+#    #+#             */
/*   Updated: 2023/09/18 11:08:33 by iestero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	final_sum(t_complex z, t_complex c, t_fractol *fractol)
{
	return (sum_complex(power_complex(z, fractol->info_frt.power), c));
}

t_complex	polinomic_exp_ft(t_complex z, t_complex c, t_fractol *fractol)
{
	t_complex	t;
	t_complex	result;

	t = power_complex(z, fractol->info_frt.power);
	result.real = exp(t.real) * cos(t.img);
	result.img = exp(t.real) * sin(t.img);
	return (sum_complex(result, c));
}

t_complex	polinomic_sin_ft(t_complex z, t_complex c, t_fractol *fractol)
{
	t_complex	t;
	t_complex	result;

	t = power_complex(z, fractol->info_frt.power);
	result.real = sin(t.real) * cosh(t.img);
	result.img = cos(t.real) * sinh(t.img);
	return (sum_complex(result, c));
}

t_complex	mandelbrot(t_complex z, t_complex c, t_fractol *fractol)
{
	fractol->info_frt.name = "Mandelbrot";
	return (sum_complex(power_complex(z, 2), c));
}
