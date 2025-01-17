/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console_labels.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 20:02:25 by shurtado          #+#    #+#             */
/*   Updated: 2025/01/17 20:10:27 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	set_cam_labels(t_data *data, t_img_btn *img_btn, int top)
{
	int			mleft;
	mlx_image_t	**labels;
	mlx_t		*mlx;

	mlx = data->mlx;
	labels = img_btn->labels;
	mleft = data->x - BG_WITH;
	write_cam_labels(data, img_btn);
	img_btn->labels[0] = put_str(mlx, "Camera", mleft + 120, top - 2);
	img_btn->labels[1] = put_str(mlx, "Pos", mleft + 155, top + 50);
	img_btn->labels[2] = put_str(mlx, img_btn->posx, mleft + 35, top + 80);
	img_btn->labels[3] = put_str(mlx, img_btn->posy, mleft + 35, top + 110);
	img_btn->labels[4] = put_str(mlx, img_btn->posz, mleft + 35, top + 140);
	img_btn->labels[5] = put_str(mlx, "Axis", mleft + 155, top + 170);
	img_btn->labels[6] = put_str(mlx, img_btn->axisx, mleft + 35, top + 200);
	img_btn->labels[7] = put_str(mlx, img_btn->axisy, mleft + 35, top + 230);
	img_btn->labels[8] = put_str(mlx, img_btn->axisz, mleft + 35, top + 260);
	img_btn->labels[9] = put_str(mlx, "FOV", mleft + 158, top + 290);
	img_btn->labels[10] = put_str(mlx, img_btn->fov, mleft + 25, top + 320);
}

void	set_alight_labels(t_data *data, t_img_btn *img_btn, int top)
{
	int			mleft;
	mlx_image_t	**labels;
	mlx_t		*mlx;

	mlx = data->mlx;
	labels = img_btn->labels;
	mleft = data->x - BG_WITH;
	write_alight_labels(data, img_btn);
	img_btn->labels[0] = put_str(mlx, "Ambient Light", mleft + 120, top - 2);
	img_btn->labels[1] = put_str(mlx, "BR", mleft + 155, top + 50);
	img_btn->labels[2] = put_str(mlx, img_btn->posx, mleft + 35, top + 80);
}
