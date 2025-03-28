/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:23:51 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/03/27 20:54:53 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	close_window_ESC(int keycode, t_fdf *fdf)
{
	if (keycode == ESC)
		close_fdf(fdf);
	return (0);
}

int	close_window_X(t_fdf *fdf)
{
	close_fdf(fdf);
	return (0);
}

