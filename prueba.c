/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuesta- <acuesta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 10:06:02 by acuesta-          #+#    #+#             */
/*   Updated: 2023/07/03 13:46:00 by acuesta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prueba.h"
#include "get_next_line.h"

char	**load_map(char *filename, t_game *game)
{
	int		fd;
	char	*line;
	int		y;
	int		x;

	game->coin_count = 2;
	y = 0;
	x = 13;
	fd = open (filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		exit(1);
	}
	game->gridcopy = (char**) malloc(sizeof(char *) * x);
	game->grid = (char**) malloc(sizeof(char *) * x);
	while ((line = get_next_line(fd)) != NULL)
	{
		game->grid[y] = line;
		game->gridcopy[y] = line;
		y++;
	}
	game->map_height = y;
	game->map_width = ft_strlen (game->grid[0]) - 1;
	game->map_width = ft_strlen (game->gridcopy[0]) - 1;

    close (fd);
	return (game->grid);
}



void	flood(char **gridcopy, int y, int x, int map_height, int map_width) //esta busca las posiciones para la inundacion
{
	if(gridcopy[y][x] == 'P' || gridcopy[y][x] == '0' || gridcopy[y][x] == 'C' || gridcopy[y][x] == 'E')
	{
		if (gridcopy[y][x] == 'E')
		{
			gridcopy[y][x] = 'e';
		
		}
		else
	 gridcopy[y][x] = 'V';

	flood(gridcopy, y - 1, x, map_height, map_width); // Arriba
	flood(gridcopy, y + 1, x, map_height, map_width); // Abajo
	flood(gridcopy, y, x - 1, map_height, map_width); // Izquierda
	flood(gridcopy, y, x + 1, map_height, map_width); // Derecha
	}
	return;
}


void check_map2(t_game *game)
{
	int map_width = game->map_width;
	int map_height = game->map_height;
	int start_x = -1;
	int start_y = -1;
	int y = 0;

	while (y < map_height && start_x == -1) {
		int x = 0;
		
		while (x < map_width && start_x == -1) {
			if (game->gridcopy[y][x] == 'P') {
				start_x = x;
				start_y = y;
			}
			x++;
		}
		y++;
	}

	if (start_x != -1) {
		flood(game->gridcopy, start_y, start_x, map_height, map_width);
		printf("Mapa actualizado\n");
		draw_map(*game);
		printf("¡Inundación completada!\n");
	}
	else if ('P' == 'P' && 'P' != '0' && 'P' != 'C' && 'P' != 'E')
	{
		printf("No se encontró la posición de inicio 'P' en el mapa.\n");
		exit(1);

	}
}




t_player	position(t_player player, t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			player.y = y;
			player.x = x;
			if (game->grid[y][x] == 'P')
			{
				player.y = y;
				player.x = x;
				return (player);
			}
			x++;
		}
		y++;
	}
	return (player);
}



int my_key_hook(int key_code, t_game *game)
{
	t_player	player = {0,0};
	player = position(player, game);

	printf("Player position: (%d, %d)\n", player.x, player.y);
	printf("monedas: %d\n", game->coin_count);
	if (key_code == 13)
		walls(game, &player, player.y - 1, player.x);
	else if (key_code == 2)
		walls(game, &player, player.y, player.x + 1);
	else if (key_code == 0)
		walls(game, &player, player.y, player.x - 1);
	else if (key_code == 1)
		walls(game, &player, player.y + 1, player.x);
	if (game->coin_count != 0 && game->grid[player.y][player.x] == 'E')
		game->grid[player.y][player.x] = '1';
	else if (game->coin_count == 0 && game->grid[player.y][player.x] == 'E')
		printf("¡Felicidades, has ganado!\n");
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	draw_map(*game);
	return (0);
}

int main(int argc, char **argv) //
{
	t_game	game;

	 if(argc != 2)
	 {
	 	printf("Error\n");
	 	exit(1);
	 }
	game.mlx_ptr = mlx_init();
	
	game.grid = load_map(argv[1] ,&game); // argv[1]
	game.win_ptr = mlx_new_window(game.mlx_ptr, game.map_width * CELL_SIZE, game.map_height * CELL_SIZE, "Map");
	check_map2(&game);
	draw_map(game); // Mostrar el mapa inicialmente
	mlx_hook(game.win_ptr, 2, 1L << 0, my_key_hook, &game);
	mlx_hook(game.win_ptr, 17, 1L << 0, my_key_hook, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
