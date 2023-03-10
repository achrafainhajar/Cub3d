/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_3D.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aainhaja <aainhaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 14:10:57 by mrafik            #+#    #+#             */
/*   Updated: 2023/03/03 00:06:05 by aainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_3D_H
# define CUB_3D_H

# include<stdlib.h>
# include<stdio.h>
# include<unistd.h>
# include<fcntl.h>
# include<mlx.h>
# include<string.h>
# include<math.h>

# define WIDTH 2084
# define HEIGHT 1024

typedef struct t_prasing_data
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	**floor;
	char	**ceiling;
	char	**map;
	char	direction;
}			t_prasing_data;

# define A_KEY			0
# define D_KEY			2
# define S_KEY			1
# define W_KEY			13
# define TILE_SIZE		64

typedef struct s_img {
	void	*img;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	*addr;
}t_img;

typedef struct s_player
{
	double	x;
	double	y;
	int		l;
	double	realx;
	double	nrealx;
	double	nrealy;
	long	ndist;
	double	realy;
	int		raduis;
	int		turndirection;
	int		walkdirection;
	double	rotationangle;
	double	movespeed;
	double	rotationspeed;
	double	fov_angle;
	int		ray_num;
	long	dist;
	int		d;
}t_Player;
typedef struct textures {
	void	*img;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	*addr;
	int		w;
	int		h;
}t_tex;
typedef struct s_vars {
	void		*mlx;
	int			h;
	int			width;
	int			height;
	void		*mlx_win;
	char		**map;
	t_img		img;
	int			v;
	t_tex		n;
	t_tex		w;
	t_tex		e;
	t_tex		s;
	int			f;
	int			c;
	t_Player	player;
	char		**floor;
	char		**ceiling;
	double		tempx;
	double		tempy;
	double		temp1x;
	double		temp1y;
}				t_vars;

void			cast(t_vars *vars, double rayangle);
double			normalizeangle(double angle);
double			dist(double ax, double ay, double bx, double by);
void			my_mlx_pixel_put(t_img *data, int x, int y, int color);
unsigned int	get_v_color(t_vars	*vars, int y, int x, double rayangle);
int				update(t_vars *vars);
void			init_player(t_vars *vars, t_prasing_data *data);
char			**editmap(char **map, int l);
int				ft_exit(t_vars *vars);
void			castrays(t_vars *vars);
unsigned long	creratergb(int r, int g, int b);
int				lol(t_vars *vars, double y, double x);
int				get_width(char	**map);
double			get_view(char a);
int				get_height(char **map);
void			get_pos(t_vars	*vars, t_prasing_data *data);
int				get_rgb(char	**str);
int				ft_strlen(const char *s);
int				ft_strlen2(char **str, int i);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s1);
char			*ft_substr(char const *s, int start, int len);
int				ft_atoi(const char *str);
char			*get_next_line(int fd);
char			**ft_split(char const *s, char c);
char			*ft_strjoin(char *s1, char *s2);
int				ft_isalpha(int c);
void			map_checker(char **ar, int i, t_prasing_data *data);
void			check_stranger(char **str, int x, t_prasing_data *data);
char			*ft_strrchr(const char *s, int c);
int				ft_strcmp(const char *s1, const char *s2);
void			print_error(char *str);
int				ft_isdigit(int c);
void			store_map(char **map, int *x, t_prasing_data *data);
void			ceiling_floor(char **map, int x, int i, t_prasing_data *data);
void			parsing_norm(char **map, int *x, int i, t_prasing_data *data);
void			check_all(char **map, t_prasing_data *data);
void			parsing(char *str, t_prasing_data *data);
void			parsing_befor_split(char *all);
void			print_error(char *str);
void			read_file_contents(char *filename, char **all);
void			check_all_data(t_prasing_data *data);
int				type_check(char *map);
void			check_stranger(char **str, int x, t_prasing_data *data);
void			get_direction(int t, t_prasing_data *data, char **str);
void			init(t_prasing_data *data);
int				store_data(char *str, t_prasing_data *data, int i);
int				store_helper(char *str, int i, t_prasing_data *data, char *tmp);
int				texter_type(char *map);
int				check_texter(char *str, int i);
int				search(char *str, char *ptr, int i);
int				is_color(char *str);
void			if_num_color(char **tmp);
void			if_num_helper(char **tmp, int i);
void			color_norm(char **tmp, int i, int x);
void			color_helper(char *str);
void			ft_free(char **str);
int				whitespace(char a);

#endif