#include "get_next_line.h"

int is_rectangular(char **map, int length_line)
{
    int rows = 0;
    int columns;
    int check = -1;
    while (rows < length_line)
    {
        columns = 0;
        while (map[rows][columns])
            columns++; 
        if (check == -1)
            check = columns;
        if (check != columns)
            return 0;
        rows++;
    }
    return 1;
}
int check_bounderies(char **map, int length_line, int cols)
{
    int x = 0;
    int y = 0;
    while (y < length_line)
    {
        if (map[0][y] != '1' || map[length_line -1][y] != '1')
            return 0;
        y++;
    }
    while (x < length_line)
    {
        if (map[x][0] != '1' || map[x][cols - 1] != '1')
            return 0;
        x++;
    }
    return 1;
}
int check_valid_characters(char **map, int length_line,int cols)
{
    int x = 0;
    int y;
    while (x < length_line)
    {
        y = 0;
        while (y < cols)
        {
            if (map[x][y] != '1' && map[x][y] != '0' && map[x][y] != 'E' && map[x][y] != 'P' && map[x][y] != 'C')
                return 0;
            y++;
        }
        x++;
    }
    return 1;
}
int check_if_one_player_exit(char **map, int length, int rows)
{
    int has_palyer = 0;
    int hase_exit = 0;
    int x = 0;
    int y;
    while (x < length)
    {
        y = 0;
        while (y < rows)
        {
            if (map[x][y] == 'P')
                has_palyer++;
            else if (map[x][y] == 'E')
                hase_exit++;
                y++;
        }
        x++;
    }
    return (has_palyer == 1 && hase_exit == 1);
}


int validate_map(char **map, int rows)
{
    int cols = 0;
    while (map[0][cols] != '\0')
        cols++;
    if (!is_rectangular(map, rows))
        return (write(1, "Error: The map is not rectangular.\n", 36), 0);
    if (!check_bounderies(map , rows, cols))
        return (write(1, "Error: The map is not enclosed by walls.\n", 42), 0);
    if (!check_valid_characters(map, rows, cols))
        return (write(1, "Error: The map contains invalid characters.\n", 45), 0);
    if (!check_if_one_player_exit(map, rows, cols))
        return (perror("Error: The map must contain at least one start ('P') and one exit ('E').\n"), 0);
    return (1);
}

int count_line(int fd)
{
    int count_line = 0;
    char *line;
    while ((line = get_next_line(fd)))
    {
        count_line++;
        free(line);
    }
    return count_line;
}

char **full_map(int fd, int rows)
{
    char **result;
    char *line;
    int i = 0;
    fd = open("maps.ber", O_RDONLY);
    if (fd == -1)
        return NULL;
    result = malloc((rows + 1) * sizeof(char*));
    while ((line = get_next_line(fd)))
    {
        result[i] = line;
        i++;
    }
    result[i] = NULL;
    return result;
}
void ft_free(char **map, int lingth)
{
    int i = 0;
    while (i < lingth)
        free(map[i++]);
    free(map);
}
void print_map(char **map, int length)// deliet 
{
    int i = 0;
    while (i < length)
    {
        printf("\n%s", map[i]);
        i++;
    }
}
int calcule_columes(char **map, int rows)
{
    int columes;

    columes = 0;
    while (map[0][columes])
        columes++;
    return columes;
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
//     printf("columes =  %d", calcule_columes(map, rows));
//     ft_free(map, rows);
// }
