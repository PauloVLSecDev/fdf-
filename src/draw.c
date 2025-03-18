/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 19:58:20 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/03/18 15:30:56 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	draw_pixel(t_img *img, int x, int y)
{
	char *dest;

	dest = img->addr + (y * img->line_length + x * (img->bit_per_pixel / 8));
	return ;
}

