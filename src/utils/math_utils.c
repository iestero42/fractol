/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iestero- <iestero-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 09:19:42 by iestero-          #+#    #+#             */
/*   Updated: 2023/09/14 11:22:25 by iestero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	len_s1;
	int	len_s2;

	len_s2 = ft_strlen(s2);
	len_s1 = ft_strlen(s1);
	if (len_s1 > len_s2)
		return (ft_strncmp(s1, s2, len_s1));
	else
		return (ft_strncmp(s1, s2, len_s2));
}

double	map(double unscaled_num, double new_min, double new_max, double old_max)
{
	return ((new_max - new_min) * (unscaled_num - 0)
		/ (old_max - 0) + new_min);
}

t_complex	sum_complex(t_complex num1, t_complex num2)
{
	t_complex	result;

	result.real = num1.real + num2.real;
	result.img = num1.img + num2.img;
	return (result);
}

t_complex	power_complex(t_complex num, int n)
{
	t_complex	result;
	double		angle;
	double		magnitude;

	magnitude = sqrt(num.real * num.real + num.img * num.img);
	angle = atan2(num.img, num.real);
	magnitude = pow(magnitude, n);
	angle = angle * n;
	result.real = magnitude * cos(angle);
	result.img = magnitude * sin(angle);
	return (result);
}

t_complex	divide_complex(t_complex a, t_complex b)
{
	t_complex	result;
	double		denominator;

	denominator = b.real * b.real + b.img * b.img;
	result.real = (a.real * b.real + a.img * b.img) / denominator;
	result.img = (a.img * b.real - a.real * b.img) / denominator;
	return (result);
}
