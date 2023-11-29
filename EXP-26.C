#include <stdio.h>
#include <stdlib.h>

void createFile(const char *fileName);
void writeFile(const char *fileName, const char *content);
void readFile(const char *fileName);
void appendFile(const char *fileName, const char *content);
void deleteFile(const char *fileName);

int main() {
    const char *fileName = "example_file.txt";
    createFile(fileName);
    const char *content = "Hello, File Management!";
    writeFile(fileName, content);
    printf("Content read from the file:\n");
    readFile(fileName);
    const char *additionalContent = "\nAppending more content.";
    appendFile(fileName, additionalContent);
    printf("\nContent read from the file after appending:\n");
    readFile(fileName);
    deleteFile(fileName);
    return 0;
}
void createFile(const char *fileName) {
    FILE *file = fopen(fileName, "w");
    if (file == NULL) {
        perror("Error creating file");
        exit(EXIT_FAILURE);
    }
    fclose(file);
    printf("File '%s' created successfully.\n", fileName);
}
void writeFile(const char *fileName, const char *content) {
    FILE *file = fopen(fileName, "w");
    if (file == NULL) {
        perror("Error opening file for writing");
        exit(EXIT_FAILURE);
    }
    fprintf(file, "%s", content);
    fclose(file);
    printf("Content written to file '%s' successfully.\n", fileName);
}
void readFile(const char *fileName) {
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        perror("Error opening file for reading");
        exit(EXIT_FAILURE);
    }
    char buffer[100];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }
    fclose(file);
}
void appendFile(const char *fileName, const char *content) {
    FILE *file = fopen(fileName, "a");
    if (file == NULL) {
        perror("Error opening file for appending");
        exit(EXIT_FAILURE);
    }
    fprintf(file, "%s", content);
    fclose(file);
    printf("Content appended to file '%s' successfully.\n", fileName);
}
void deleteFile(const char *fileName) {
    if (remove(fileName) != 0) {
        perror("Error deleting file");
        exit(EXIT_FAILURE);
    }
    printf("File '%s' deleted successfully.\n", fileName);
}
