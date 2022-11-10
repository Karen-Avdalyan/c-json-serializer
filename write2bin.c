#include "main.h"

void    write2bin(int fd, char **key_value_pair, int key_num)
{
    char *value = key_value_pair[1];
    
    // value
    write(fd, ft_itoa(key_num), strlen(value) - 1);
    write(fd, ":", 1);
    write(fd, value, strlen(value));
}

void    write2json(int fd, char **key_value_pair, int key_num)
{
    char *key = key_value_pair[0];
    
    // value
    write(fd, "\"", 1);
    write(fd, ft_itoa(key_num), 1);
    write(fd, "\"", 1);
    write(fd, ":", 1);
    write(fd, key, strlen(key));
}
