/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuesta- <acuesta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 10:07:11 by acuesta-          #+#    #+#             */
/*   Updated: 2023/07/03 11:53:54 by acuesta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"
# include "libft/libft.h"
# include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
# include <stdlib.h>
#define CELL_SIZE 32


typedef struct s_player{
int x;
int y;
} t_player;

typedef struct s_img{
void *img_ptr;
int width;
int height;
void *img1;
void *img2;
void *img3;
void *img4;
} t_img;

typedef struct s_game{
	void *mlx_ptr;
    void *win_ptr; 
    char **grid;
	char **gridcopy;
	int map_width;
	int map_height;
	int coin_count;
	t_player player;
	t_img img;
}t_game;


void flood(char **gridcopy, int y, int x, int map_height, int map_width);
void check_map2(t_game *game);
void coin_count(t_game *game, int y, int x);
void walls(t_game *game, t_player *player, int new_y, int new_x);
t_player	position(t_player player, t_game *game);
int	my_key_hook(int key_code, t_game *game);
char	**load_map(char *filename, t_game *game);
void	draw_map(t_game game);