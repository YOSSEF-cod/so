#ifndef SO_LONG_H
#define SO_LONG_H

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <mlx.h>
#include <fcntl.h>

#define WALL '1'
#define EMPTY '0'
#define START 'P'
#define EXIT 'E'

typedef struct s_data
{
    void *imag_wall;
    void *imag_plyer;
    void *imag_exit;
    void *mlx;
    int img_w;
    int img_h;
} t_data;

typedef struct s_map
{
    int fd;
    int rows;
    char **map;
} t_map;

int count_line(int fd);
int is_rectangular(char **map, int length);

int calcule_columes(char **map, int rows);

int is_rectangular(char **map, int length_line);
int check_bounderies(char **map, int length_line, int cols);
int check_valid_characters(char **map, int length_line,int cols);
int check_if_one_player_exit(char **map, int length, int rows);
int validate_map(char **map, int rows);
int count_line(int fd);
char **full_map(int fd, int rows);
void ft_free(char **map, int lingth);
#endif
