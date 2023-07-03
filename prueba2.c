/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuesta- <acuesta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:04:25 by acuesta-          #+#    #+#             */
/*   Updated: 2023/06/27 10:38:09 by acuesta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prueba.h"
#include "get_next_line.h"

void	draw_map(t_game game)
{

	
	int	height; 
	int	width;
	int	x;
	int	y;

	height = 32;
	width = 32;
	game.img.img1 = mlx_xpm_file_to_image (game.mlx_ptr, "aarena.xpm", &width, &height );
	game.img.img2 = mlx_xpm_file_to_image (game.mlx_ptr, "chara.xpm", &width, &height );
	game.img.img3 = mlx_xpm_file_to_image (game.mlx_ptr, "aarena.xpm", &width, &height );
	game.img.img4 = mlx_xpm_file_to_image (game.mlx_ptr, "coin.xpm", &width, &height );
	y = 0;
	while (y < game.map_height)
	{
		x = 0;
		while (x < game.map_width)
		{
			if (game.grid[y][x] == '1')
				mlx_pixel_put (game.mlx_ptr,  game.win_ptr, x * CELL_SIZE, y * CELL_SIZE, 0xFF9900);	
			else if (game.grid[y][x] == 'P')
				mlx_put_image_to_window (game.mlx_ptr, game.win_ptr, game.img.img2,  x * CELL_SIZE, y * CELL_SIZE);
			else if (game.grid[y][x] == 'E')
				mlx_pixel_put (game.mlx_ptr, game.win_ptr, x * CELL_SIZE, y * CELL_SIZE, 0xFF00FF);
			else if (game.grid[y][x] == 'C')
				mlx_put_image_to_window(game.mlx_ptr,  game.win_ptr, game.img.img4, x * CELL_SIZE, y * CELL_SIZE);
			else if (game.grid[y][x] == '0')
				mlx_put_image_to_window (game.mlx_ptr, game.win_ptr, game.img.img1,  x * CELL_SIZE, y * CELL_SIZE);
			x++;
    	}
		y++;
	}
}

void coin_count(t_game *game, int y, int x)
{
	if (game->grid[y][x] == 'C')
		game->coin_count--;

	if (game->coin_count == 0 && game->grid[y][x] == 'E')
		exit(0);
}

void walls(t_game *game, t_player *player, int y, int x)
{
	if (y >= 0 && y < game->map_height && x >= 0 && x < game->map_width && game->grid[y][x] != '1')
	{
		coin_count(game, y, x);
		game->grid[player->y][player->x] = '0';
		
		if (game->coin_count != 0 && game->grid[y][x] == 'E')
		{
			// No actualizar la posición del personaje
			game->grid[player->y][player->x] = 'P';
		}
		else
		{
			// Actualizar la posición del personaje
			game->grid[y][x] = 'P';
			player->y = y;
			player->x = x;
		}
	}
}

