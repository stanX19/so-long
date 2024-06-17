/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_bfs_target_tile.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:46:28 by shatan            #+#    #+#             */
/*   Updated: 2024/06/17 18:48:35 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static inline bool	invalid_cord(t_map *map, t_vec2 cord, int blocking)
{
	return (cord.x >= map->grid_size.x || cord.y >= map->grid_size.y
		|| cord.x < 0 || cord.y < 0 || map->grid[cord.y][cord.x] & blocking);
}

static void	propagate(t_map_bfs_args args, t_vec2 *queue, t_vec2 curr,
		int *rear)
{
	const t_vec2	d[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
	t_vec2			next;
	int				i;

	args.map->grid[curr.y][curr.x] |= TILE_VISITED;
	i = 0;
	while (i < 4 && *rear < args.depth)
	{
		next = vec2_add(curr, d[i]);
		if (!invalid_cord(args.map, next, args.blocking | TILE_VISITED))
			queue[(*rear)++] = next;
		i++;
	}
}

static t_vec2	process_queue(t_map_bfs_args args, t_vec2 *queue, int *front,
		int *rear)
{
	t_vec2			curr;

	while (*front < *rear)
	{
		curr = queue[(*front)++];
		if (invalid_cord(args.map, curr, args.blocking | TILE_VISITED))
			continue ;
		if (args.map->grid[curr.y][curr.x] & args.target)
		{
			return (curr);
		}
		propagate(args, queue, curr, rear);
	}
	return ((t_vec2){args.depth, args.depth});
}

// 1 + 2 * args.depth * (args.depth + 1);
// is formula of
// 1 + 4 * (1 + 2 + 3 + ... + n)
t_vec2	ft_map_bfs_target_tile(t_map_bfs_args args, t_vec2 start)
{
	t_vec2	*queue;
	int		front;
	int		rear;
	t_vec2	target_loc;

	args.depth = 1 + 2 * args.depth * (args.depth + 1);
	queue = (t_vec2 *)ft_calloc(sizeof(t_vec2), args.depth * 2);
	if (!queue)
		return ((t_vec2){args.depth, args.depth});
	front = 1;
	rear = 1;
	queue[0] = start;
	propagate(args, queue, start, &rear);
	target_loc = process_queue(args, queue, &front, &rear);
	front = -1;
	while (++front < rear)
		args.map->grid[queue[front].y][queue[front].x] &= ~TILE_VISITED;
	free(queue);
	return (vec2_sub(target_loc, start));
}
