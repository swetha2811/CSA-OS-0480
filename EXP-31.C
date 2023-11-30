#include <stdio.h>
#define MAX_FRAMES 3
#define MAX_PAGES 10
void initializeMemory(int memory[], int size);
void displayMemory(int memory[], int size);
int pageFault(int memory[], int size, int page);
int main() {
    int memory[MAX_FRAMES];
    int pages[MAX_PAGES] = {0, 1, 2, 3, 4, 2, 4, 5, 6, 7};
    int pageFaultCount = 0;
    initializeMemory(memory, MAX_FRAMES);
    printf("Page Reference Sequence: ");
    for (int i = 0; i < MAX_PAGES; ++i) {
        printf("%d ", pages[i]);
        pageFaultCount += pageFault(memory, MAX_FRAMES, pages[i]);
        displayMemory(memory, MAX_FRAMES);
    }
    printf("\nTotal Page Faults: %d\n", pageFaultCount);
    return 0;
}
void initializeMemory(int memory[], int size) {
    for (int i = 0; i < size; ++i) {
        memory[i] = -1;     }
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
int pageFault(int memory[], int size, int page) {
    int pageFault = 1;
	    for (int i = 0; i < size; ++i) {
        if (memory[i] == page) {
            pageFault = 0;
    break;
        }
    }
    if (pageFault) {
        int oldestPageIndex = 0;
        for (int i = 1; i < size; ++i) {
            if (memory[i] < memory[oldestPageIndex]) {
                oldestPageIndex = i;
            }
        }
        memory[oldestPageIndex] = page;
    }
    return pageFault;
}
