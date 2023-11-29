#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
void demonstrate_fcntl(const char *file_path);
void demonstrate_lseek(const char *file_path);
void demonstrate_stat(const char *file_path);
void demonstrate_opendir(const char *dir_path);
int main() {
    const char *file_path = "example_file.txt";
    const char *dir_path = "."; 
    demonstrate_fcntl(file_path);
    demonstrate_lseek(file_path);
    demonstrate_stat(file_path);
    demonstrate_opendir(dir_path);
    return 0;
}
void demonstrate_fcntl(const char *file_path) {
    int fd = open(file_path, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("Error opening file for fcntl");
        exit(EXIT_FAILURE);
    }
    struct flock lock;
    lock.l_type = F_WRLCK; 
	    lock.l_start = 0;
    lock.l_whence = SEEK_SET;
    lock.l_len = 0;
	    if (fcntl(fd, F_SETLK, &lock) == -1) {
        perror("Error performing fcntl");
    } else {
        printf("File locked successfully.\n");
    }
    close(fd);
}
void demonstrate_lseek(const char *file_path) {
    int fd = open(file_path, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("Error opening file for lseek");
        exit(EXIT_FAILURE);
    }
    const char *data = "Hello, lseek!\n";
    write(fd, data, strlen(data));
    lseek(fd, 0, SEEK_SET);
    char buffer[100];
    read(fd, buffer, sizeof(buffer));
    printf("Data read using lseek:\n%s", buffer);
    close(fd);
}
void demonstrate_stat(const char *file_path) {
    struct stat file_info;
	    if (stat(file_path, &file_info) == -1) {
        perror("Error getting file information");
        exit(EXIT_FAILURE);
    }
    printf("\nFile Information (stat):\n");
    printf("File Size: %ld bytes\n", file_info.st_size);
    printf("File Permissions: %o\n", file_info.st_mode & (S_IRWXU | S_IRWXG | S_IRWXO));
    if (S_ISREG(file_info.st_mode)) {
        printf("File Type: Regular File\n");
    } else {
        printf("File Type: Unknown\n");
    }
}
void demonstrate_opendir(const char *dir_path) {
    DIR *dir = opendir(dir_path);
    if (dir == NULL) {
        perror("Error opening directory");
        exit(EXIT_FAILURE);
    }
    printf("\nDirectory Contents (opendir/readdir):\n");
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }
    closedir(dir);
}
