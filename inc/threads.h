/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:24:39 by shurtado          #+#    #+#             */
/*   Updated: 2024/12/19 17:27:51 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREADS_H
# define THREADS_H

# include <pthread.h>
# include <stdint.h>
# include "miniRT.h"

# define NUM_THREADS 6

typedef struct s_thread_data
{
	int			thread_id;
	t_ray		**rays;
	t_data		*scene;
	uint32_t	**image;
}	t_thread_data;

void	render_with_threads(t_data *scene, t_ray **rays, uint32_t **image);
void	*process_rows(void *arg);

#endif
