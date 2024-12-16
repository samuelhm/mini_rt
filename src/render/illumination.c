/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   illumination.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:09:03 by shurtado          #+#    #+#             */
/*   Updated: 2024/12/16 13:51:42 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/miniRT.h"
#include "../inc/render.h"
#include "../lib/libvector/libvct.h"

t_rgb	apply_ambient_light(t_rgb color, t_aLight *ambient_light)
{
	t_rgb	result;

	result.r = (unsigned char)fminf(color.r * ambient_light->br, 255.0f);
	result.g = (unsigned char)fminf(color.g * ambient_light->br, 255.0f);
	result.b = (unsigned char)fminf(color.b * ambient_light->br, 255.0f);
	return (result);
}

void	difuse_light(t_rgb *color, t_ray *ray, t_sLight *slight, t_obj *obj, t_v3 dir)
{
	t_rgb	dif_color;
	float	intensity;

	intensity = fmax(dot(dir, ray->normal), 0.0f);
	if (intensity > 0.0f)
	{
		dif_color.r = (unsigned char)(slight->rgb.r * intensity * slight->br);
		dif_color.g = (unsigned char)(slight->rgb.g * intensity * slight->br);
		dif_color.b = (unsigned char)(slight->rgb.b * intensity * slight->br);
		color->r = fmin(color->r + (obj->rgb.r * dif_color.r) / 255, 255);
		color->g = fmin(color->g + (obj->rgb.g * dif_color.g) / 255, 255);
		color->b = fmin(color->b + (obj->rgb.b * dif_color.b) / 255, 255);
	}
}

bool	scene_shadow(t_data *scene, t_ray *shadow_ray, float max_dist)
{
	t_obj	*current_obj;
	float	t;

	t = INFINITY;
	current_obj = scene->obj;
	while (current_obj)
	{
		if (current_obj->type == SP && hit_sp(shadow_ray, current_obj, &t))
		{
			if (t > EPSILON && t < max_dist)
				return (true);
		}
		else if (current_obj->type == CY && hit_cy(shadow_ray, current_obj, &t))
		{
			if (t > EPSILON && t < max_dist)
				return (true);
		}
		else if (current_obj->type == PL && hit_pl(shadow_ray, current_obj, &t))
		{
			if (t > EPSILON && t < max_dist)
				return (true);
		}
		current_obj = current_obj->next;
	}
	return (false);
}

t_rgb	phong(t_data *scene, t_ray *ray, t_obj *obj)
{
	t_rgb		color;
	t_v3		shadow_origin;
	t_ray		shadow_ray;
	t_sLight	*slight;

	color = apply_ambient_light(obj->rgb, scene->aLight);
	slight = scene->sLight;
	while (slight)
	{
		shadow_origin = vadd(ray->point, vmul(1e-3, ray->normal));
		shadow_ray.origin = shadow_origin;
		shadow_ray.direction = normalize(vsub(slight->pos, ray->point));
		if (scene_shadow(scene, &shadow_ray, \
			vlength(vsub(slight->pos, ray->point))))
		{
			slight = slight->next;
			continue ;
		}
		difuse_light(&color, ray, slight, obj, shadow_ray.direction);
		slight = slight->next;
	}
	return (color);
}
