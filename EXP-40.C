#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

void displayPermissions(const char *filename) {
    struct stat fileStat;
    
    if (stat(filename, &fileStat) == -1) {
        perror("Error getting file status");
        exit(EXIT_FAILURE);
    }

    printf("Owner permissions: ");
    printf((fileStat.st_mode & S_IRUSR) ? "r" : "-");
    printf((fileStat.st_mode & S_IWUSR) ? "w" : "-");
    printf((fileStat.st_mode & S_IXUSR) ? "x" : "-");
    printf("\n");
    
    printf("Group permissions: ");
    printf((fileStat.st_mode & S_IRGRP) ? "r" : "-");
    printf((fileStat.st_mode & S_IWGRP) ? "w" : "-");
    printf((fileStat.st_mode & S_IXGRP) ? "x" : "-");
    printf("\n");

    printf("Others permissions: ");
    printf((fileStat.st_mode & S_IROTH) ? "r" : "-");
    printf((fileStat.st_mode & S_IWOTH) ? "w" : "-");
    printf((fileStat.st_mode & S_IXOTH) ? "x" : "-");
    printf("\n");
}

int main() {
    const char *filename = "example.txt";

    if (chmod(filename, 0644) == -1) {
        perror("Error setting file permissions");
        exit(EXIT_FAILURE);
    }

    printf("File access permissions for %s:\n", filename);
    displayPermissions(filename);

    return 0;
}
