#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE_LENGTH 1024
void grep(const char *pattern, FILE *file);
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <pattern> [file]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    const char *pattern = argv[1];
    FILE *file;
    if (argc == 2) {
        grep(pattern, stdin);
    } else {
        file = fopen(argv[2], "r");
        if (file == NULL) {
            perror("Error opening file");
            exit(EXIT_FAILURE);
        }
        grep(pattern, file);
        fclose(file);
    }
    return 0;
}
void grep(const char *pattern, FILE *file) {
    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file) != NULL) {
        if (strstr(line, pattern) != NULL) {
            printf("%s", line);
        }
    }
}
