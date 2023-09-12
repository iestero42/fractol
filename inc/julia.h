/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iestero- <iestero-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:01:25 by iestero-          #+#    #+#             */
/*   Updated: 2023/09/12 10:07:13 by iestero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JULIA_H
# define JULIA_H

# include "fractol.h"

/**
 * @brief 
 * 
 */
typedef struct s_julia
{
	struct s_complex	z;
	char				*name;
	struct s_complex	(*ft)(struct s_complex, struct s_complex,
			struct s_fractol *);
	double				power;
}	t_julia;

#endif