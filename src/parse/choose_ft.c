/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_ft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iestero- <iestero-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:56:58 by iestero-          #+#    #+#             */
/*   Updated: 2023/09/08 13:30:55 by iestero-         ###   ########.fr       */
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
	}
	return (t
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

t_complex	mandelbrot(t_complex z, t_complex c, t_fractol *fractol)
{
	return (sum_complex(sqrt_complex(z), c));
}

void	*choose_ft(t_complex z, t_complex c, t_fractol *fractol)
{
	void	*t;

	if (!ft_strcmp(fractol->name, "mandelbrot"))
		t = mandelbrot;
	else
	{
		if (!ft_strcmp(fractol->info_frt.ft, "polinomic"))
			t = final_sum;
		else if (!ft_strcmp(fractol->info_frt.ft, "polinomic-exp"))
			t = polinomic_exp_ft;
	}
	return (t);
}
