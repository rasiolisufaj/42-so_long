/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raisufaj <raisufaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:04:38 by raisufaj          #+#    #+#             */
/*   Updated: 2025/05/16 19:28:32 by raisufaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define LEFT_ARROW 65361
# define RIGHT_ARROW 65363
# define UP_ARROW 65362
# define DOWN_ARROW 65364
# define ESC_KEY 65307

# include "../libft/libft.h"
# include "../minilbx/mlx.h"
# include <X11/X.h>
# include <X11/cursorfont.h>
# include <X11/keysym.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

/* Free Image Struct */
typedef enum e_items {
  img_player,
  img_player_sick,
  img_wall,
  img_ground,
  img_col,
  img_exit_open,
  img_exit_closed,
}		t_items;

/* Struct for images */
typedef struct s_img {
  void *player;
  void *player_sick;
  void *wall;
  void *ground;
  void *col;
  void *exit_open;
  void *exit_closed;
  char *path_player;
  char *path_player_sick;
  char *path_wall;
  char *path_ground;
  char *path_col;
  char *path_exit_open;
  char *path_exit_closed;
  int *width;
  int *height;
}		t_img;

/* Struct for coords */
typedef struct s_coords {
  int x;
  int y;
  int cur_x;
  int cur_y;
  int new_x;
  int new_y;
  int x_player;
  int y_player;
  int x_exit;
  int y_exit;
}		t_coords;

/* Struct for map */
typedef struct s_map {
  char **map;
  char **map_dup;
  unsigned int map_x;
  unsigned int map_y;
  bool exit_status;
}		t_map;

/* Struct for counts and indexes */
typedef struct s_count {
  int moves;
  int score;
  int player;
  int exit;
  int col;
  int col_back;
}		t_count;

/* Struct for MLX */
typedef struct s_data {
  void *mlx;
  void *win;
  char *arguments;
  int x;
  t_coords coords;
  t_count count;
  t_img img;
  t_map map;
}		t_data;

/* CHECK ERRORS.C */
void	ft_check_mlx(t_data *data);
void	ft_check_mlx_win(t_data *data);

/* CHECK_MAPS_2.C */
void	ft_map_status(t_data *data);
void	ft_check_map_name(t_data *data);
void	ft_check_flood_fill(t_data *data);
bool	ft_is_map_ber(char *str, char *to_compare);

/* CHECK_MAPS.C */
void	ft_check_map_format(t_data *data);
void	ft_check_rectangular(t_data *data);
void	ft_check_lines(t_data *data, int n);
void	ft_check_columns(t_data *data, int n);
bool	ft_check_map_contents(t_data *data);

/* EXIT.C */
void	ft_close_game(t_data *data);
void	ft_game_success(t_data *data);
int		cross_close(t_data *data);

/* FLOOD_FILL.C */
void	ft_init_map_dup(t_data *data);
bool	ft_flood_fill(t_data *data, int x, int y);
bool	ft_flood_fill_move(t_data *data, int x, int y);
bool	ft_player_allowed_move(t_data *data, int x, int y);

/* FREE.C */
void	ft_destroy(t_data *data);
void	ft_free_map(t_data *data);
void	ft_free_map_both(t_data *data);
void	ft_remove_normal(t_data *data);
void	ft_remove_images(t_data *data, t_items items);

/* IMAGES.C */
void	ft_get_images(t_data *data);
void	ft_check_images(t_data *data);
void	ft_check_images_2(t_data *data, t_items items);
void	ft_check_and_destroy(t_data *data, t_items items);
void	ft_put_image(t_data *data, void *img, int x, int y);

/* MAPS.C */
void	ft_read_maps(t_data *data);
void	ft_put_images_exit(t_data *data, int x, int y);
void	ft_put_images_player(t_data *data, int x, int y);
int		ft_put_images_to_map(t_data *data);

/* MOVEMENT.C */
int		ft_key_press(int keycode, t_data *data);
void	ft_open_exit(t_data *data);
void	ft_move(t_data *data, int new_x, int new_y);

/* TEXT.C */
void	ft_put_score(t_data *data);
void	ft_check_col(t_data *data);

#endif