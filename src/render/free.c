/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 19:02:12 by shurtado          #+#    #+#             */
/*   Updated: 2024/12/15 17:23:16 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/miniRT.h"
#include "../inc/render.h"

static void	free_rays(t_ray **rays)
{
	int	i;

	i = HG - 1;
	while (i >= 0)
	{
		free(rays[i]);
		i--;
	}
	free(rays);
}

void	free_render(t_vp *vp, t_ray **rays)
{
	free(vp);
	free_rays(rays);
}
