/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bagh <ael-bagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 17:17:29 by ael-bagh          #+#    #+#             */
/*   Updated: 2020/12/09 17:56:16 by ael-bagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <ctype.h>
# include <fcntl.h>
# include <string.h>
# include <math.h>
# include <mlx.h>
# define BUFFER_SIZE 10000

int				g_tile_size;
int				g_width;
int				g_height;
char			*g_no;
char			*g_so;
char			*g_we;
char			*g_ea;
char			*g_s;
char			*g_map;
char			**g_map_array;
int				g_fr;
int				g_fg;
int				g_fb;
int				g_cr;
int				g_cg;
int				g_cb;
int				g_map_started;
int				g_map_width;
int				g_map_height;
int				g_peeinit;
int				get_next_line(int fd, char **line);
void			texture_error(int error);
void			free_this_shit(char *str, char **s);
char			*ft_strjoin(char *s1, char *s2);
int				ft_strlen(char *s);
size_t			ft_strlcpy(char *dst, char *src, size_t size);
char			*ft_substr(char *s, unsigned int start, size_t len);
char			*ft_strdup(char *s1);
char			*has_nl(char *str);
int				pre_work(int fd, char **rest, char **line);
char			**ft_split(char *str, char c);
int				c_w(char *str, char c);
void			get_re(char *line);
void			get_no(char *line);
void			get_we(char *line);
void			get_ea(char *line);
void			get_so(char *line);
void			get_s(char *line);
void			get_f(char *line);
void			get_c(char *line);
void			routing(char *line);
void			ft_putchar(char c);
void			ft_putstr(char *str);
void			ft_print_words_tables(char **tab);
char			**freethenipples(char **s);
int				s_p(char *s, char c);
int				len_str(char *s, int i, char c);
int				ft_isdigit(int c);
int				array_is_rgb(char **colors);
int				str_is_digits(char *c);
void			global_init(void);
int				all_params(void);
void			readmap(char *line);
void			manage_map(void);
void			longuest_line(void);
void			array_height(void);
char			**map_manager(void);
void			map_errors(char **map);
int				only_ones(char *s);
int				begins_by_one(char *s);
char			*ft_strjoi(char *s1, char *s2);
int				begins_by_nl(char **maptab);
void			mapcheck(char **maptab);
void			wrong_file(char *file, int type);
int				wrong_resolution(int width, int height);
void			get_resolution(int width, int height);
void			check_crgb(char **colors, int cc, int cw);
void			check_frgb(char **colors, int cc, int cw);
void			get_crgb(int r, int g, int b);
void			get_frgb(int r, int g, int b);
void			error_redirect(int error);
void			fill_map(char **map);
void			surrend_by_spaces(char **map);

typedef struct	s_player {
	float		x;
	float		y;
	int			fov;
	int			turn_direction;
	int			walk_direction;
	float		rotation_angle;
	int			move_speed;
	float		rotation_speed;
}				t_player;

t_player g_player;

typedef struct	s_vars {
	void		*mlx;
	void		*win;
}				t_vars;

t_vars			g_vars;

typedef struct	s_rays {
	float		ray_angle;
	float		wall_hitx;
	float		wall_hity;
	float		distance;
	int			was_hit_vertical;
	int			is_ray_facing_up;
	int			is_ray_facing_down;
	int			is_ray_facing_left;
	int			is_ray_facing_right;
	int			wall_hit_content;
}				t_rays[2561];

t_rays			g_rays;

typedef struct	s_data {
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

t_data			g_image;

void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			draw_cube(int x, int y);
void			norm_it(char **meh);
void			draw_map(void);
void			cast_ray(int l, float angle);
void			cast_rays(void);
int				has_wall(int x, int y);
double			normalangle(double rayangle);
void			render(void);
int				key_press(int keycode);
int				key_release(int keycode);
int				move(void);
#endif
