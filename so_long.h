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
