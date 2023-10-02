#include "../../includes/cub3D.h"

void print_single_ray(t_ray *rays, t_mlx *mlx, double x, double y)
{
	double	deltax;
	double	deltay;
	int		pixels;

	printf("\n\ndirX: %f  dirY: %f\n", rays->ray_dir_x, rays->ray_dir_y);
	printf("deltaX: %f  deltaY: %f\n", rays->delta_dis_x, rays->delta_dis_y);
	printf("sideX: %f  sideY: %f\n", rays->side_dist_x, rays->side_dist_y);
	printf("stepX: %d  stepY: %d\n", rays->step_x, rays->step_y);
	printf("distance: %f\n", rays->per_wall_dist);

	deltax = (rays->ray_dir_x - x);
	deltay = (rays->ray_dir_y - y);

	printf("deltaX: %f  deltaY: %f\n", deltax, deltay);
	pixels = sqrt((deltax * deltax) + (deltay * deltay));
	while (pixels)
	{
		mlx_pixel_put(mlx->mlx, mlx->win, x, y, 0x000000FF);
		x += rays->ray_dir_x;
		y += rays->ray_dir_y;
		--pixels;
	}
}

t_ray *skip_rays(t_ray *rays, int n)
{
	int i;

	i = -1;
	if (!rays->next)
		return (NULL);
	while (++i < n)
	{
		if (!rays->next)
			break;
		rays = rays->next;
	}
	return (rays);
}

void print_rays(t_mlx *mlx, t_ray *rays, t_player *player)
{
	int n_rays;
	int i;
	double x;
	double y;
	t_ray *head;

	i = -1;
	head = rays;
	n_rays = ((SCREEN_WIDTH / FOV) / 100) * 2;
	x = player->x * SQUARE_SIZE;
	y = player->y * SQUARE_SIZE;
	printf("playerX: %f  playerY: %f\n", x, y);
	while (++i < n_rays)
	{
		if (!rays)
			break;
		print_single_ray(rays, mlx, x, y);
		rays = skip_rays(rays, n_rays);
	}
	rays = head;
}

void ft_draw(t_ray *ray, t_mlx *mlx, int i)
{
	int line_height;
	int draw_start;
	int draw_end;

	(void)ray;
	line_height = (int)SCREEN_HEIGHT / ray->per_wall_dist;
	draw_start = (line_height * -1) / 2 + SCREEN_HEIGHT / 2;
	draw_end = line_height / 2 + SCREEN_HEIGHT / 2;
	if(draw_start < 0)
		draw_start = 0;
	if(draw_end >= SCREEN_HEIGHT)
		draw_end = SCREEN_HEIGHT - 1;
	while(draw_start <= draw_end)
	{
		my_mlx_pixel_put(&mlx->map, i, draw_start, 0X0008000);
		draw_start++;
	}
}