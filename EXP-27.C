#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
void listFiles(const char *directory);
int main(int argc, char *argv[]) {
    const char *directory;
    if (argc > 1) {
        directory = argv[1];
    } else {
        directory = ".";
    }
    listFiles(directory);
    return 0;
}
void listFiles(const char *directory) {
    DIR *dir = opendir(directory);
    if (dir == NULL) {
        perror("Error opening directory");
        exit(EXIT_FAILURE);
    }
    printf("Files in directory '%s':\n", directory);
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }
    closedir(dir);
}
