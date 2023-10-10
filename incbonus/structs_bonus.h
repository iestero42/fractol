/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iestero- <iestero-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 08:29:25 by iestero-          #+#    #+#             */
/*   Updated: 2023/10/10 10:17:55 by iestero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCS_BONUS_H
# define STRUCS_BONUS_H

typedef struct s_colors
{
	int r;
	int g;
	int b;	
}	t_colors;

/**
 * @brief 
 * 
 */
typedef struct s_complex
{
	double	real;
	double	img;
}	t_complex;

/**
 * @brief 
 * 
 */
typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

/**
 * @brief 
 * 
 */
typedef struct s_info
{
	char		*name;
	t_complex	z;
	t_complex	(*ft)(struct s_complex, struct s_complex, void *param);
	double		power;
	double		shift_x;
	double		shift_y;
	
}	t_info;

/**
 * @brief 
 * 
 */
typedef struct s_fractol {
	char			*name;
	void			*mlx;
	void			*mlx_win;
	void			*win_prnt;
	int				cmplx_precision;
	int				button_pressed;
	int				key_pressed;
	double			zoom;
	double			escape_value;
	t_info			info_frt;
	t_data			img_data;
	t_colors		colors;
}	t_fractol;

#endif