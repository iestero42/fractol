/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iestero- <iestero-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 09:26:39 by iestero-          #+#    #+#             */
/*   Updated: 2023/09/12 11:28:59 by iestero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	polinomic_sqrt_sinh_ft(t_complex z, t_complex c, t_fractol *fractol)
{
	t_complex	t;

	t = polinomic_ft(z, fractol->info_frt.power);
	t.real = sinh(t.real);
	t.img = sinh(t.img);
	t = sqrt_complex(t);
	return (sum_complex(t, c));
}

t_complex	z2_over_ln_z_ft(t_complex z, t_complex c, t_fractol *fractol)
{
	t_complex	t;
	t_complex	y;

	t = polinomic_ft(z, fractol->info_frt.power);
	t = sum_complex(t, z);
	y.img = log(z.img);
	y.real = log(z.real);
	t.real = t.real / y.real;
	t.img = t.img / y.img;
	return (sum_complex(t, c));
}

