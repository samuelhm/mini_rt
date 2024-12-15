/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseUtils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 14:13:09 by erigonza          #+#    #+#             */
/*   Updated: 2024/12/15 17:02:55 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	type_obj(t_data *data, char *str)
{
	static char		*bts[] = {"sp", "pl", "cy", "A", "C", "L", NULL};
	int				i;

	i = 0;
	while (bts[i] && !ft_strcmp(bts[i], str))
		i++;
	if (bts[i])
		return (i);
	return (50);
}

char	*floats_parse(t_obj *obj, char *str, int i, int flag)
{
	float	x;
	float	y;
	float	z;
	char	*tmp;

	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] && (!ft_isdigit(str[i]) && str[i] != '-'))
		exit(er("error: floats_parse: map parsing:\n", str));
	x = ft_atof(str, i);
	i = skip_float(str, i, 0, 1);
	y = ft_atof(str, i);
	i = random_sum_parse(str, i);
	z = ft_atof(str, i);
	i = sum_parse(str, i, 2, 0);
	if (flag == 0)
		obj->pos = vdefine(x, y, z);
	else if (flag == 1)
		obj->axis = vdefine(x, y, z);
	tmp = ft_substr(str, i, ft_strlen(str));
	return (tmp);
}

int	ft_atoi_parse(char *str, int i, int flag)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while (flag == 1 && str[i] && ft_isspace(str[i]))
		i++;
	if (!str)
		exit(er("error: atoi: str doesn't exist\n", NULL));
	if (str[i] == ',')
		i++;
	else if (str[i] == '-')
		sign = -sign;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!ft_isdigit(str[i]))
		exit(er("error: atoi: not a digit\n", str));
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - 48);
		i++;
	}
	res *= sign;
	return (res);
}

t_rgb	colors_parse(char *str)
{
	t_rgb	rgb;
	int		i;

	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	rgb.r = ft_atoi_parse(str, i, 1);
	i = skip_color(str, i, 0, 0);
	rgb.g = ft_atoi_parse(str, i, 0);
	i = skip_color(str, i, 0, 0);
	rgb.b = ft_atoi_parse(str, i, 0);
	return (rgb);
}
