#include <stdio.h>
#define MAX_RECORDS 10
void initializeFile(char file[], int size);
void readRecord(char file[], int currentRecord);
int main() {
    char file[MAX_RECORDS][256]; 
    int currentRecord = 0;
    initializeFile((char *)file, MAX_RECORDS);
    for (int i = 0; i < MAX_RECORDS; ++i) {
        printf("Reading Record %d:\n", i + 1);
        readRecord((char *)file, i);
    }
    return 0;
}
void initializeFile(char file[], int size) {
    for (int i = 0; i < size; ++i) {
        sprintf(file + i * 256, "This is record %d.", i + 1);
    }
}
void readRecord(char file[], int currentRecord) {
    printf("%s\n", file + currentRecord * 256);
}
