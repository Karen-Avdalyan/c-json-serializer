#include "main.h"

int key_length(char *tmp)
{
    int i = 0;
    int len = 0;

    while (tmp[i] != '"')
        i++;
    i++;
    len++;
    while (tmp[i] != '"')
    {
        len++;
        i++;
    }
    return len;
}

int value_length(char *tmp, int i)
{
    int len = 0;

    while (tmp[i] != '"')
        i++;
    i++;
    len++;
    while (tmp[i] != '"')
    {
        len++;
        i++;
    }
    return len;
}

char **get_key_value(char *tmp)
{
    int i = 0;
    int j = 0;
    int saver = 0;
    char **key_value_pairs;
    char *key;
    char *value;

    key_value_pairs = malloc(sizeof(char *) * 3);
    // get key
    key = malloc(key_length(tmp) * sizeof(char));
    while (tmp[i] != '"')
        i++;
    while (j <= key_length(tmp))
    {
        key[j] = tmp[i];
        i++;
        j++;
    }
    // get value
    i++;
    saver = i;
    j = 0;
    while (tmp[i] != '"')
        i++;
    if (i > (int)strlen(tmp))
    {
        i = saver;
        j = 0;
        // seems there are boolian or number
        while (tmp[i])
            i++;
        value = malloc((i - saver + 1) * sizeof(char));
        i = saver;
        while (tmp[i] && tmp[i] != '\n')
        {
            value[j] = tmp[i];
            i++;
            j++;
        }
        key_value_pairs[2] = "TRUE";
    }
    else
    {
        value = malloc(value_length(tmp, i) * sizeof(char) + 1);
        while (j <= value_length(tmp, i))
        {
            value[j] = tmp[i];
            i++;
            j++;
        }
        key_value_pairs[2] = NULL;
    }
    key_value_pairs[0] = key;
    key_value_pairs[1] = value;
    return key_value_pairs;
}

void json_to_dict_stream(char *file_path, char *key_json, char *res_bin)
{
    int fd;            // input file descriptor
    int result_fd;     // bin file where need to save result
    int key_result_fd; // json file where need to save keys dictionary
    int number = 0;
    char *tmp;             // stream tmp , will read line by line (check get_next_line_h -> buffer size value)
    char **key_value_pair; // each time will read here key and value e.g. {"key", "value"}
    int stream_flag = 0;

    // open all files that needs
    fd = open(file_path, O_RDONLY);
    result_fd = open(res_bin, O_RDWR | O_CREAT | O_TRUNC, 0777);
    key_result_fd = open(key_json, O_RDWR | O_CREAT | O_TRUNC, 0777);
    // error handling
    if (fd < 0 || result_fd < 0)
    {
        printf("Wrong file names, or not enough permissions!\n");
        exit(2);
    }
    // write dict in file (just start part)
    write(result_fd, "{", 1);     // in binar file
    write(key_result_fd, "{", 1); // in json file
    tmp = get_next_line(fd);      /// read first line
    // start read with streams
    while (tmp)
    {
        if (stream_flag && tmp[0] != '}')
        {
            write(key_result_fd, ",", 1);
            stream_flag = 0;
        }
        if (tmp[0] == '{' || tmp[0] == '}')
        {
            free(tmp);
            tmp = get_next_line(fd);
            continue;
        }
        // get key and value in array
        key_value_pair = get_key_value(tmp);
        write2bin(result_fd, key_value_pair, number);      // write in binary file
        write2json(key_result_fd, key_value_pair, number); // write in json file
        free(tmp);
        tmp = get_next_line(fd); // get next stream
        if (tmp)
            stream_flag = 1;
        number++;
    }
    write(result_fd, "}", 1);
    write(key_result_fd, "}", 1);
}
