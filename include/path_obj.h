#ifndef PATH_OBJ_H
#define PATH_OBJ_H

struct individPath {
    char *path;
    int size; //size does not include null terminator

};

struct pathObject {
    struct individPath *paths;
    int size;
};



#endif
