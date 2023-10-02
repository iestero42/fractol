/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_math.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iestero- <iestero-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:06:21 by iestero-          #+#    #+#             */
/*   Updated: 2023/09/29 08:30:57 by iestero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPLEX_MATH_H
# define COMPLEX_MATH_H

# include "structs.h"

t_complex	mandelbrot(t_complex z, t_complex c, t_fractol *fractol);

t_complex	final_sum(t_complex z, t_complex c, t_fractol *fractol);

t_complex	polinomic_exp_ft(t_complex z, t_complex c, t_fractol *fractol);

t_complex	polinomic_sin_ft(t_complex z, t_complex c, t_fractol *fractol);

t_complex	polinomic_sqrt_sinh_ft(t_complex z, t_complex c,
				t_fractol *fractol);

t_complex	power_complex(t_complex num, int n);

t_complex	divide_complex(t_complex a, t_complex b);

t_complex	sum_complex(t_complex num1, t_complex num2);

#endif