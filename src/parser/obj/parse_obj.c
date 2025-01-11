/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:02:22 by erigonza          #+#    #+#             */
/*   Updated: 2025/01/11 16:34:14 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	create_obj_normi(t_obj *obj, char **tmp, char **tmp2)
{
	obj->material.emision = -1;
	if (obj->type == SP)
	{
		obj->size = ft_atof(*tmp, 0);
		*tmp2 = ft_substr(*tmp, sum_parse(*tmp, 0, 0), ft_strlen(*tmp));
	}
	else if (obj->type == CY || obj->type == CO || obj->type == CU)
	{
		obj->size = ft_atof(*tmp2, 0);
		obj->cube_size.x = obj->size;
		obj->i = sum_parse(*tmp2, 0, 0);
		obj->height = ft_atof(*tmp2, obj->i);
		obj->cube_size.y = obj->height;
		obj->i = sum_parse(*tmp2, obj->i, 0);
		free(*tmp);
		*tmp = ft_substr(*tmp2, obj->i, ft_strlen(*tmp2));
	}
	if (obj->type == CU)
	{
		obj->cube_size.z = ft_atof(*tmp, 0);
		free(*tmp2);
		obj->i = skip_double(*tmp, 0, 0, 0);
		*tmp2 = ft_substr(*tmp, obj->i, ft_strlen(*tmp));
	}
}

t_obj	*create_obj(char *str, int type)
{
	char	*tmp;
	char	*tmp2;
	char	*target;
	t_obj	*obj;

	obj = new_obj();
	obj->type = type;
	tmp = doubles_parse(obj, str, 2, 0);
	if (obj->type != SP)
		tmp2 = doubles_parse(obj, tmp, 0, 1);
	create_obj_normi(obj, &tmp, &tmp2);
	if (obj->type != CY && obj->type != CO)
		target = tmp2;
	else
		target = tmp;
	obj->rgb = colors_parse(target, 0);
	obj->material.texture = NULL;
	extra_functionalities(obj, target);
	if (tmp2)
		free(tmp2);
	return (free(tmp), obj);
}
