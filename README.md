## C Assessment

1. First need to compile and get archived lib file 
```
cd assessment
make
```
2. you will get the json_parser.a file

## how to use 
1. import main.h file from assessment
2. you need to use this void json_to_dict_stream(char *file_path, char *key_json, char *res_bin)  function
3. where file_path file path to json witch need to read...
4. key_json where need to save json file {"1": "key1}...
5. and the last is where need to save .binary files
6. and compile with gcc <your file>.c <lib name>.a
7. run ./a.out 
8. you will get 2 files .jon and .bin 