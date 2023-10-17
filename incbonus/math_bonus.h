/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iestero- <iestero-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:06:21 by iestero-          #+#    #+#             */
/*   Updated: 2023/10/16 11:01:05 by iestero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_BONUS_H
# define MATH_BONUS_H

# include "structs_bonus.h"

t_complex				mandelbrot(t_complex z, t_complex c,
							t_fractol *fractol);

t_complex				final_sum(t_complex z, t_complex c, t_fractol *fractol);

t_complex				polinomic_exp_ft(t_complex z, t_complex c,
							t_fractol *fractol);

t_complex				polinomic_sin_ft(t_complex z, t_complex c,
							t_fractol *fractol);

t_complex				polinomic_sqrt_sinh_ft(t_complex z, t_complex c,
							t_fractol *fractol);

t_complex				power_complex(t_complex num, int n);

t_complex				divide_complex(t_complex a, t_complex b);

t_complex				sum_complex(t_complex num1, t_complex num2);

t_complex				nova_ft(t_complex z, t_fractol *fractol);

double					ft_atod(char *s);

double					map(double unscaled_num, double new_min,
							double new_max, double old_max);


int						ft_strcmp(char *s1, char *s2);

#endif