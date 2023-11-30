#include <stdio.h>
#include <stdlib.h>
int calculateSeekTime(int sequence[], int size, int initialPosition);
int main() {
    int requestSequence[] = {98, 183, 37, 122, 14, 124, 65, 67};
    int sequenceSize = sizeof(requestSequence) / sizeof(requestSequence[0]);
    int initialPosition = 53;
    int totalSeekTime = calculateSeekTime(requestSequence, sequenceSize, initialPosition);
    printf("Total Seek Time: %d\n", totalSeekTime);
    return 0;
}
int calculateSeekTime(int sequence[], int size, int initialPosition) {
    int totalSeekTime = 0;
    int currentPosition = initialPosition;
    for (int i = 0; i < size; ++i) {
        int seekDistance = abs(currentPosition - sequence[i]);
        totalSeekTime += seekDistance;
        currentPosition = sequence[i];
        printf("Move from %d to %d, Seek Time = %d\n", initialPosition, sequence[i], seekDistance);
    }

    return totalSeekTime;
}
