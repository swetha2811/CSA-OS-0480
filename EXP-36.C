#include <stdio.h>
#include <stdlib.h>
#define MAX_BLOCKS 10
#define BLOCK_SIZE 256
struct Block {
    char data[BLOCK_SIZE];
    struct Block* next;
};
void initializeFile(struct Block* file[], int size);
void readRecord(struct Block* file[], int recordNumber);
int main() {
    struct Block* file[MAX_BLOCKS]; 
    initializeFile(file, MAX_BLOCKS);
    for (int i = 0; i < MAX_BLOCKS; ++i) {
        printf("Reading Record %d:\n", i + 1);
        readRecord(file, i);
    }
    return 0;
}
void initializeFile(struct Block* file[], int size) {
    for (int i = 0; i < size; ++i) {
        file[i] = (struct Block*)malloc(sizeof(struct Block));
        file[i]->next = NULL;
        sprintf(file[i]->data, "This is block %d.", i + 1);
        if (i < size - 1) {
            file[i]->next = (struct Block*)malloc(sizeof(struct Block));
        }
    }
}
void readRecord(struct Block* file[], int recordNumber) {
    struct Block* currentBlock = file[recordNumber];
    if (currentBlock == NULL) {
        printf("Invalid block index.\n");
        return;
    }
    printf("%s\n", currentBlock->data);
    currentBlock = currentBlock->next;
}
