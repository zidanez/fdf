/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaemoni <gdaemoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 22:13:21 by gdaemoni          #+#    #+#             */
/*   Updated: 2019/06/18 20:27:05 by gdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_hed.h"
#include "../include/quaternion.h"
#include "../minilibx/mlx.h"

int			main(int argc, char **argv)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_main	*mlx_win_ptr;

	if (argc == 2)
		ft_putstr(argv[1]);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, WIN_W, WIN_H, "FDF");
	mlx_win_ptr = init_ptr(mlx_ptr, win_ptr, argv[1]);
	draw(mlx_win_ptr);
	mlx_hook(win_ptr, 17, 1L << 17, close_win, (void *)0);
	mlx_hook(win_ptr, 4, 1L << 17, mouse_press, &mlx_win_ptr);
	mlx_hook(win_ptr, 5, 1L << 17, mouse_release, &mlx_win_ptr);
	mlx_hook(win_ptr, 6, 1L << 17, mouse_move, &mlx_win_ptr);
	mlx_hook(win_ptr, 2, 1L << 17, deal_key, &mlx_win_ptr);
	mlx_loop(mlx_ptr);
	return (0);
}
