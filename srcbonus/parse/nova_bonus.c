/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nova_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iestero- <iestero-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 07:41:48 by iestero-          #+#    #+#             */
/*   Updated: 2023/10/16 10:54:28 by iestero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	encontrar_raices(int n, t_fractol *fractal)
{
	int			k;
	double		theta;
	t_complex	raiz;

	k = 0;
	while (k < n)
	{
		theta = (2.0 * M_PI * k) / n;
		raiz.real = cos(theta);
		raiz.img = sin(theta);
		fractal->nova.roots[k] = raiz;
		k++;
	}
}

void	init_nova(t_fractol *fractol)
{
	fractol->nova.roots = (t_complex *) malloc(sizeof(t_complex)
			* fractol->info_frt.power);
	if (fractol->nova.roots == NULL)
	{
		perror("init_nova");
		exit(EXIT_FAILURE);
	}
	encontrar_raices(fractol->info_frt.power, fractol);
}

t_complex	nova_ft(t_complex z, t_fractol *fractol)
{
	t_complex	result;
	t_complex	result2;
	t_complex	new_z;

	new_z = power_complex(z, fractol->info_frt.power);
	new_z.real -= 1.0;
	result2 = power_complex(z, fractol->info_frt.power - 1);
	result2.img *= fractol->info_frt.power;
	result2.real *= fractol->info_frt.power;
	result = divide_complex(new_z, result2);
	result2.real = z.real - result.real;
	result2.img = z.img - result.img;
	return (result2);
}
