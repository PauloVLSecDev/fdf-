/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:45:03 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/02/25 18:11:32 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H 

# define WIDTH  800
# define HEIGHT  600
# define ESC 0xff1b

#include "../library/libft/libft.h"
#include "../library/minilibx-linux/mlx.h"
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <math.h>

int	close_window_ESC(int keycode, void *param);
int	close_window_X(void *param);

#endif
