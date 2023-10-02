#include "../../includes/cub3D.h"

bool is_moving(int key_code)
{
	if (key_code == W || key_code == A || key_code == S || key_code == D)
		return (true);
	return (false);
}

bool is_rotating(int key_code)
{
	if (key_code == LEFT || key_code == RIGHT)
		return (true);
	return (false);
}
