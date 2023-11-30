#include <stdio.h>
#include <pthread.h>
void *printMessage(void *arg) {
    char *message = (char *)arg;
    printf("%s\n", message);
    pthread_exit(NULL);
}
int main() {
    pthread_t tid; 
	    char *message = "Hello, Thread!";
    if (pthread_create(&tid, NULL, printMessage, (void *)message) != 0) {
        fprintf(stderr, "Error creating thread\n");
        return 1;
    }
    pthread_join(tid, NULL);

    return 0;
}
