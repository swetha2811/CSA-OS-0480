#include <stdio.h>
#include <stdlib.h>
void cScanDisk(int requestSequence[], int sequenceSize, int initialPosition);
int main() {
    int requestSequence[] = {98, 183, 37, 122, 14, 124, 65, 67};
    int sequenceSize = sizeof(requestSequence) / sizeof(requestSequence[0]);
    int initialPosition = 53;
    cScanDisk(requestSequence, sequenceSize, initialPosition);
    return 0;
}
void cScanDisk(int requestSequence[], int sequenceSize, int initialPosition) {
    int totalSeekTime = 0;
    int currentPosition = initialPosition;
    printf("Disk Head Movement: ");
    for (int i = 0; i < sequenceSize - 1; ++i) {
        for (int j = 0; j < sequenceSize - i - 1; ++j) {
            if (requestSequence[j] > requestSequence[j + 1]) {
                int temp = requestSequence[j];
                requestSequence[j] = requestSequence[j + 1];
                requestSequence[j + 1] = temp;
            }
        }
    }
    int initialIndex = 0;
    while (initialIndex < sequenceSize && requestSequence[initialIndex] < initialPosition) {
        initialIndex++;
    }
    for (int i = initialIndex; i < sequenceSize; ++i) {
        int seekDistance = abs(currentPosition - requestSequence[i]);
        totalSeekTime += seekDistance;
        currentPosition = requestSequence[i];
        printf("%d -> ", requestSequence[i]);
    }
    totalSeekTime += abs(currentPosition - 199);
    currentPosition = 199;
    printf("199 -> 0 -> ");
    for (int i = 0; i < initialIndex; ++i) {
        int seekDistance = abs(currentPosition - requestSequence[i]);
        totalSeekTime += seekDistance;
        currentPosition = requestSequence[i];
        printf("%d -> ", requestSequence[i]);
    }

    printf("End\n");

    printf("Total Seek Time: %d\n", totalSeekTime);
}
