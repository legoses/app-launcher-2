#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <path_obj.h>

//get number of directories in user path
int get_path_len(char *path) {
    int i = 0;
    int len = 0;
    
    while(path[i] != '\0') {
        if(path[i] == ':') {
            len++; 
        }
        i++;
    }

    return len;
}


struct individPath *alloc_path(int i, int pathStart, char *path) {
    struct individPath *p = (struct individPath*)malloc(sizeof(struct individPath*));
    p->size = i - pathStart;
    p->path = (char*)malloc(sizeof(char)*(p->size+1)); //allocate size of path +1 for null terminator

    memcpy(p->path, &path[pathStart], p->size);
    p->path[p->size+1] = '\0'; //add null terminator
    printf("Malloc test\n");
    return p;
}


struct pathObject* gen_path_object(char *path) {
    //char **paths;
    struct pathObject *paths = (struct pathObject*)malloc(sizeof(struct pathObject*));
    paths->size =  get_path_len(path);
    paths->paths = (struct individPath**)malloc(sizeof(struct individPath**) * paths->size); //allocate memory for number of found paths

    int curPath = 0;

    int i = 0; //loop location
    int pathStart = 0; //start of current path

    printf("Path size: %i\n", paths->size);

    //loop loop through path
    while(path[i] != '\0') {
        if((path[i] == ':') || (path[i] == ' ')) { //match seperator in bash and fish
            paths->paths[curPath] = alloc_path(i, pathStart, path); //allocate memory for indivudal paths
            printf("Post Malloc test\n");
            printf("%i\n", paths->paths[curPath]->size);
            pathStart = i+1;
            curPath++;
        } 
        i++;
    }

    return paths;
}


int main() {
    char *path = getenv("PATH");
    //char **parsedPaths = parse_path(path);
    struct pathObject *paths = gen_path_object(path);

    //printf("%s\n", paths->size);

    return 0;
}
