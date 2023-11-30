#include <stdio.h>
#include <stdlib.h>
#define MAX_BLOCKS 10
#define BLOCK_SIZE 256
void initializeFile(char file[], int size);
void readRecord(char file[], int indexBlock[], int recordNumber);
int main() {
    char file[MAX_BLOCKS][BLOCK_SIZE];
    int indexBlock[MAX_BLOCKS]; 
    initializeFile((char *)file, MAX_BLOCKS);
    for (int i = 0; i < MAX_BLOCKS; ++i) {
        indexBlock[i] = i;     }
    for (int i = 0; i < MAX_BLOCKS; ++i) {
        printf("Reading Record %d:\n", i + 1);
        readRecord((char *)file, indexBlock, i);
    }
    return 0;
}
void initializeFile(char file[], int size) {
    for (int i = 0; i < size; ++i) {
        sprintf(file + i * BLOCK_SIZE, "This is block %d.", i + 1);
    }
}
void readRecord(char file[], int indexBlock[], int recordNumber) {
    int blockIndex = indexBlock[recordNumber];
    if (blockIndex < 0 || blockIndex >= MAX_BLOCKS) {
        printf("Invalid block index.\n");
        return;
    }
    printf("%s\n", file + blockIndex * BLOCK_SIZE);
}
