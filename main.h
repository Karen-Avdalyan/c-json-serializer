#ifndef MAIN_H
# define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include "./get_next_line/get_next_line.h"


char	*ft_substr(char *s, unsigned int start, size_t len);
void    write2bin(int fd, char **key_value_pair, int key_num);
char	*ft_itoa(int number);
void    write2json(int fd, char **key_value_pair, int key_num);
void    json_to_dict_stream(char *file_path, char *key_json, char *res_bin);


#endif
