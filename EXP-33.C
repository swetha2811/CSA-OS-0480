#include <stdio.h>
#include <limits.h>
#define MAX_FRAMES 3
#define MAX_PAGES 10
void initializeMemory(int memory[], int size);
void displayMemory(int memory[], int size);
int pageFault(int memory[], int size, int pages[], int pageIndex, int futureReferences[]);
int main() {
    int memory[MAX_FRAMES];
    int pages[MAX_PAGES] = {0, 1, 2, 3, 4, 2, 4, 5, 6, 7};
    int futureReferences[MAX_PAGES] = {4, 1, 7, 3, 0, 6, 8, 5, 2, 9};
    int pageFaultCount = 0;
    initializeMemory(memory, MAX_FRAMES);
    printf("Page Reference Sequence: ");
    for (int i = 0; i < MAX_PAGES; ++i) {
        printf("%d ", pages[i]);
        pageFaultCount += pageFault(memory, MAX_FRAMES, pages, i, futureReferences);
        displayMemory(memory, MAX_FRAMES);
    }
    printf("\nTotal Page Faults: %d\n", pageFaultCount);
    return 0;
}
void initializeMemory(int memory[], int size) {
    for (int i = 0; i < size; ++i) {
        memory[i] = -1; 
    }
}
void displayMemory(int memory[], int size) {
    printf("Memory: ");
    for (int i = 0; i < size; ++i) {
        if (memory[i] == -1) {
            printf("[ ] ");
        } else {
            printf("[%d] ", memory[i]);
        }
    }
    printf("\n");
}
int pageFault(int memory[], int size, int pages[], int pageIndex, int futureReferences[]) {
    int pageFault = 1; 
    for (int i = 0; i < size; ++i) {
        if (memory[i] == pages[pageIndex]) {
            pageFault = 0;
			            break;
        }
    }
    if (pageFault) {
        int farthestFutureIndex = -1;
        int farthestFutureDistance = INT_MIN;
        for (int i = 0; i < size; ++i) {
            int futureIndex = -1;
            for (int j = pageIndex + 1; j < MAX_PAGES; ++j) {
                if (pages[j] == memory[i]) {
                    futureIndex = j;
                    break;
                }
            }
            if (futureIndex == -1) {
                farthestFutureIndex = i;
                break;
            } else if (futureIndex > farthestFutureDistance) {
                farthestFutureIndex = i;
                farthestFutureDistance = futureIndex;
            }
        }
        memory[farthestFutureIndex] = pages[pageIndex];
    }    return pageFault;
}
