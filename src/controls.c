/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:23:51 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/03/28 16:31:32 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	close_window_esc(int keycode, t_fdf *fdf)
{
	if (keycode == ESC)
		close_fdf(fdf);
	return (0);
}

int	close_window_x(t_fdf *fdf)
{
	close_fdf(fdf);
	return (0);
}
