#include "so_long.h"

int main()
{
    int fd = open("maps.ber", O_RDONLY);
    if (fd < 0)
        return(perror("Error opening file"), 1);
    int rows = count_line(fd);
    if (rows == 0)
        return (close(fd), write(1, "this file is empty", 18), 0);
    close(fd);
    fd = open("maps.ber", O_RDONLY);
    if (fd < 0)
        return (perror("Error reopening file"),1);
    char **map = full_map(fd, rows);
    close(fd);
    
    if (validate_map(map, rows)) 
        printf("The map is valid.\n");
    else
        return (printf("The map is invalid.\n"), ft_free(map, rows), 1);
    void *mlx = mlx_init();
    if (mlx == NULL)
        return (perror("Error initializing MLX"), ft_free(map, rows), 1);
    void *mlx_win = mlx_new_window(mlx, calcule_columes(map, rows) * 64, rows * 64, "so_long");
    void *img;
    int img_w, img_h;
    img = mlx_xpm_file_to_image(mlx, "wall.xmp", &img_w, &img_h);
    if (img == NULL) {
        perror("Error loading image");
        mlx_destroy_window(mlx, mlx_win);
        ft_free(map, rows);
        return 1;
    }
    int y, x = 0;
    while (x < rows)
    {
        y = 0;
        while (y < calcule_columes(map, rows))
        {
            if (map[x][y] == '1')
                mlx_put_image_to_window(mlx, mlx_win, img, y * 64, x * 64);
            y++;
        }
        x++;
    }

    mlx_loop(mlx);
    ft_free(map, rows);
    return 0;
}

// int main()
// {
//     int fd = open("maps.ber" , O_RDONLY);
//     char **map;
//     int rows = count_line(fd);
//     if (rows == 0)
//         return (write(1, "this file is emty", 18), 0);
//     map = full_map(fd, rows);
//      if (validate_map(map, rows))
//         printf("The map is valid.\n");
//      else 
//         printf("The map is invalid.\n");
//     void	*mlx;
// 	void	*mlx_win;
// 	void	*img;
// 	int     img_w;
// 	int	    img_h;
//     int x = 0;
// 	int y;
//     mlx = mlx_init();
    
// 	mlx_win = mlx_new_window(mlx, calcule_columes(map, rows) * 64,  rows * 64, "so_long");
// 	img = mlx_xpm_file_to_image(mlx, "wall.xmp", &img_w, &img_h);
// 	while (map[x][y])
// 	{
// 		y = 0;
// 		while (map[x][y])
// 		{
// 			if (map[x][y] == '1')
// 				mlx_put_image_to_window(mlx, mlx_win, img, y * 64, x * 64);
// 			y++;
// 		}
// 		x++;
// 	}
// 	mlx_loop(mlx);
//     ft_free(map, rows);
// }

// int main()
// {
// 	int fd;
// 	// char *line;
// 	// char *arr[100];
// 	// int i;

// 	// i = 0;
// 	fd = open("maps.ber", O_RDONLY);
// 	if (valid_map(fd))
// 		printf("the map is valid ;)\n");
// 	else 
// 		printf("the map is invalid! ;(\n");
// 	// if (fd == -1)
// 	// {
// 	// 	write(1, "Error opening file", 19);
// 	// 	return 0;
// 	// }
// 	// while ((line = get_next_line(fd)))
// 	// {
// 	// 	arr[i] = line;
// 	// 	printf("%s", arr[i]);
// 	// 	i++;
// 	// }
// 	void	*mlx;
// 	void	*mlx_win;
// 	void	*img;
// 	int	img_w;
// 	int	img_h;
// 	char *map[] = {
// 		"11111",
// 		"10001",
// 		"10001",
// 		"10001",
// 		"11111"
// 	};

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 5 * 64, 5 * 64, "Hello world!");
// 	img = mlx_xpm_file_to_image(mlx, "wall.xmp", &img_w, &img_h);
// 	int i = 0;
// 	int j;
// 	while (i < 5)
// 	{
// 		j = 0;
// 		while (j < 5)
// 		{
// 			if (map[i][j] == '1')
// 				mlx_put_image_to_window(mlx, mlx_win, img, i * 64, j * 64 );
// 			j++;
// 		}
// 		i++;
// 	}
// 	mlx_loop(mlx);

// 	return (0);
// }