/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iestero- <iestero-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 09:26:39 by iestero-          #+#    #+#             */
/*   Updated: 2023/09/18 10:21:51 by iestero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_complex	log_complex(t_complex z)
{
	t_complex	result;

	result.real = log(hypot(z.real, z.img));
	result.img = atan2(z.img, z.real);
	return (result);
}

t_complex	z2_over_ln_z_ft(t_complex z, t_complex c, t_fractol *fractol)
{
	t_complex	t;
	t_complex	y;

	t = power_complex(z, fractol->info_frt.power);
	t = sum_complex(z, t);
	y = log_complex(z);
	t = divide_complex(t, y);
	return (sum_complex(t, c));
}

