// execute with gcc basics.c -lpthread -o basics && ./basics

#include <pthread.h>
#include <stdio.h>

void* task(void* arg) {
    int* num = (int*)arg;
    printf("Thread %d is running.\n", *num);
    return NULL;
}

int main() {
    pthread_t threads[2];
    int args[2] = {1, 2};

    // Fork: Create threads
    pthread_create(&threads[0], NULL, task, &args[0]);
    pthread_create(&threads[1], NULL, task, &args[1]);

    // Join: Wait for threads to finish
    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);

    printf("All threads are done.\n");
    return 0;
}
