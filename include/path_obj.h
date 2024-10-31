#ifndef PATH_OBJ_H
#define PATH_OBJ_H

struct individPath {
    char *path; //probably needs to be changed to char **path so path instances do not get deleted once function is deconstructed
    int size; //size does not include null terminator

};

struct pathObject {
    struct individPath **paths;
    int size;
};



#endif
