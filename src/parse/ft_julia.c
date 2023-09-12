/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iestero- <iestero-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 09:21:46 by iestero-          #+#    #+#             */
/*   Updated: 2023/09/12 13:13:08 by iestero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	polinomic_ft(t_complex z, double n)
{
	unsigned long long int	coefficient;
	t_complex				t;
	int						k;

	k = 0;
	while (k <= n)
	{
		coefficient = binomialcoeff(n, k);
		t.real = coefficient * pow(z.real, n - k) * pow(z.img, k);
		t.img = 0;
		if (k % 2 == 1)
			t.img = coefficient * pow(z.real, n - k) * pow(z.img, k);
		k++;
	}
	return (t);
}

t_complex	final_sum(t_complex z, t_complex c, t_fractol *fractol)
{
	return (sum_complex(polinomic_ft(z, fractol->info_frt.power), c));
}

t_complex	polinomic_exp_ft(t_complex z, t_complex c, t_fractol *fractol)
{
	t_complex	t;

	t = polinomic_ft(z, fractol->info_frt.power);
	t.real = exp(t.real);
	t.img = exp(t.img);
	return (sum_complex(t, c));
}

t_complex	polinomic_sin_ft(t_complex z, t_complex c, t_fractol *fractol)
{
	t_complex	t;

	t = polinomic_ft(z, fractol->info_frt.power);
	t.real = sin(t.real);
	t.img = sin(t.img);
	return (sum_complex(t, c));
}

t_complex	mandelbrot(t_complex z, t_complex c, t_fractol *fractol)
{
	fractol->info_frt.name = "Mandelbrot";
	return (sum_complex(sqrt_complex(z), c));
}
