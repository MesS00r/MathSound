#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <wav.h>

#ifdef _WIN32
    #include <direct.h>
    #define getcwd _getcwd

    #define PATH_SEP "\\"
    #define CWDBUF_LEN _MAX_PATH 
#else
    #include <unistd.h>

    #define PATH_SEP "/"
    #define CWDBUF_LEN 0 
#endif

int main(void) {
    char *cwd = getcwd(NULL, CWDBUF_LEN);
    if (!cwd) {
        perror("getcwd() error");
        return 1;
    }

    const char *folder    = "test";
    const char *file_name = "test.wav";

    size_t len = strlen(cwd)       +
                 strlen(PATH_SEP)  + 
                 strlen(folder)    + 
                 strlen(PATH_SEP)  + 
                 strlen(file_name) +
                 1;

    char *path = (char *)calloc(1, len);
    if (!path) {
        perror("Memory allocation error");
        free(cwd);
        return 1;
    }

    snprintf(path,
             len,
             "%s%s%s%s%s",
             cwd,
             PATH_SEP,
             folder,
             PATH_SEP,
             file_name
            );

    FILE *file = fopen(path, "wb");
    if (!file) {
        perror("File error");
        free(path);
        free(cwd);
        return 1;
    }

    wav_init(file);

    //TODO:

    fclose(file); 
    free(path);
    free(cwd);
    return 0;
}