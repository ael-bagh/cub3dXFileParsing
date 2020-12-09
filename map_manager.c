/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bagh <ael-bagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 11:46:48 by ael-bagh          #+#    #+#             */
/*   Updated: 2020/12/08 23:53:09 by ael-bagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void		player_init(char c, int x, int y)
{
	if (g_peeinit)
	{
		ft_putstr("Error:\nthe map has more than one player\n");
		exit(0);
	}
	else
	{
		g_tile_size = 16;
		g_player.x = (x * g_tile_size) + (g_tile_size / 2);
		g_player.y = (y * g_tile_size) + (g_tile_size / 2);
		g_peeinit = 1;
		if (c == 'N')
			g_player.rotation_angle = 270 * (M_PI / 180);
		else if (c == 'S')
			g_player.rotation_angle = 90 * (M_PI / 180);
		else if (c == 'E')
			g_player.rotation_angle = 0;
		else if (c == 'W')
			g_player.rotation_angle = M_PI;
		g_player.fov = 60 * (M_PI / 180);
		g_player.turn_direction = 0;
		g_player.walk_direction = 0;
		g_player.move_speed = 6;
		g_player.rotation_speed = 4 * (M_PI / 180);
	}
}

void		array_height(void)
{
	int i;

	i = 0;
	while (g_map_array[i])
		i++;
	g_map_height = i;
}

char		**map_manager(void)
{
	char	**map_array;
	int		i;
	int		j;

	j = 0;
	i = 0;
	map_array = (char**)malloc((g_map_height + 3) * sizeof(char*));
	while (i < g_map_height + 2)
	{
		map_array[i] = (char*)malloc((g_map_width + 3) * sizeof(char));
		i++;
	}
	map_array[i] = NULL;
	surrend_by_spaces(map_array);
	fill_map(map_array);
	map_errors(map_array);
	if (g_player.x == -1 || g_player.y == -1)
	{
		ft_putstr("Error:\nPlayer or map missing\n");
		exit(0);
	}
	return (map_array);
}

void		map_errors(char **map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (++i <= g_map_height)
	{
		while (++j <= g_map_width)
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != '2'
			&& map[i][j] != 'N' && map[i][j] != 'W' && map[i][j] != 'E'
			&& map[i][j] != 'S' && map[i][j] != ' ')
				error_redirect(0);
			else if (map[i][j] != ' ' && map[i][j] != '1')
			{
				if (map[i][j + 1] == ' ' || map[i][j - 1] == ' '
				|| map[i + 1][j] == ' ' || map[i - 1][j] == ' ')
					error_redirect(1);
				if ((map[i][j] == 'N' || map[i][j] == 'S' ||
				map[i][j] == 'E' || map[i][j] == 'W') && !g_peeinit)
					player_init(map[i][j], j - 1, i - 1);
			}
		}
		j = 0;
	}
}

void		error_redirect(int error)
{
	if (error == 0)
		ft_putstr("Error:\nmap has an unknown character\n");
	else if (error == 1)
		ft_putstr("Error:\nthe map isnt closed");
	exit(0);
}
