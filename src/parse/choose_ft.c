/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_ft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iestero- <iestero-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:56:58 by iestero-          #+#    #+#             */
/*   Updated: 2023/10/16 11:25:15 by iestero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
 * @brief 
 * 
 * @param fractol 
 * @return void* 
 */
void	*choose_ft(t_fractol *fractol)
{
	void	*t;

	t = NULL;
	if (!ft_strcmp(fractol->name, "mandelbrot"))
		t = mandelbrot;
	else if (!ft_strcmp(fractol->name, "julia"))
	{
		if (!ft_strcmp(fractol->info_frt.name, "polinomic"))
			t = final_sum;
		else if (!ft_strcmp(fractol->info_frt.name, "polinomic-exp"))
			t = polinomic_exp_ft;
		else if (!ft_strcmp(fractol->info_frt.name, "polinomic-sin"))
			t = polinomic_sin_ft;
		else
			mlx_error("Incorrect function");
	}
	return (t);
}
