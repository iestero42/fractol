/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iestero- <iestero-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 09:19:42 by iestero-          #+#    #+#             */
/*   Updated: 2023/09/01 12:23:16 by iestero-         ###   ########.fr       */
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

t_interval	create_interval(int min, int max)
{
	t_interval	interval;

	interval.max = max;
	interval.min = min;
	return (interval);
}

double	map(double unscaled_num, t_interval new, t_interval old)
{
	return ((new.max - new.min) * (unscaled_num - old.min)
		/ (old.max - old.min) + new.min);
}

t_complex	sum_complex(t_complex num1, t_complex num2)
{
	t_complex	result;

	result.real = num1.real + num2.real;
	result.img = num1.img + num2.img;
	return (result);
}

t_complex	sqrt_complex(t_complex num)
{
	t_complex	result;

	result.real = pow(num.real, 2) - pow(num.img, 2);
	result.img = 2 * num.real * num.img;
	return (result);
}
