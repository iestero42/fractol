/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iestero- <iestero-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:09:38 by iestero-          #+#    #+#             */
/*   Updated: 2023/09/29 09:22:07 by iestero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_BONUS_H
# define EVENTS_BONUS_H

# define ESCAPE 53
# define PLUS 69
# define MINUS 78
# define MOUSE_FWD 05
# define MOUSE_BCW 04
# define MOUSE_L 1
# define MOUSE_R 2
# define ARROW_U 126
# define ARROW_D 125
# define ARROW_L 123
# define ARROW_R 124

# define KEYPRESS		02
# define BUTTONPRESS	04
# define BUTTONRELEASE	05
# define DESTROYNOTIFY	17
# define RESIZE			15
# define MOTIONNOTIFY	06

# include "structs_bonus.h"

int			julia_track(int x, int y, t_fractol *fractal);

int			mouse__release_handler(int button, int x, int y,
				t_fractol *fractol);

int			key_handler(int key, t_fractol *fractol);

int			mouse_handler(int button, int x, int y, t_fractol *fractol);

int			close_handler(t_fractol *fractol);

#endif