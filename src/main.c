/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 13:12:46 by erigonza          #+#    #+#             */
/*   Updated: 2024/12/01 20:59:45 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// make && ./miniRT 0.0 0.0 5.0 1 230 232 255 0.0 -3.0 -1.0 1
int	main(int ac, char **av)
{
	t_data			*data;
	mlx_t			*mlx;
    mlx_image_t		*img;
	int				fd;

	data = malloc(sizeof(t_data));
	if (ac != 2)
		exit(er("error: 2 args needed", NULL));
	correct_file(av[1]);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		exit(er("error: fd filed", NULL));
	parse(data, av, fd);
	print_t_data(data);
	exit(1);
	mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "miniRT", true);
	if (!mlx)
		exit (er("Failed to initialize MLX42", NULL));
	img = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
    if (!img)
		exit(er("Failed to create image\n", NULL));
    mlx_image_to_window(mlx, img, 0, 0);
	mlx_key_hook(mlx, &my_keyhook, NULL);
    mlx_loop(mlx);
    mlx_delete_image(mlx, img);
    mlx_terminate(mlx);
	exit(0);
}
