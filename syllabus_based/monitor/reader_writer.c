#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define SIZE 5

// Shared buffer and variables
int buffer[SIZE];
int count = 0;

// Monitor components
pthread_mutex_t mutex;
pthread_cond_t not_full;
pthread_cond_t not_empty;

// Monitor function: produce item
void produce(int item) {
    pthread_mutex_lock(&mutex);

    // Condition: wait if buffer is full
    while (count == SIZE) {
        pthread_cond_wait(&not_full, &mutex);
    }

    buffer[count++] = item;
    printf("Produced: %d\n", item);

    // Signal consumer
    pthread_cond_signal(&not_empty);

    pthread_mutex_unlock(&mutex);
}

// Monitor function: consume item
int consume() {
    pthread_mutex_lock(&mutex);

    // Condition: wait if buffer is empty
    while (count == 0) {
        pthread_cond_wait(&not_empty, &mutex);
    }

    int item = buffer[--count];
    printf("Consumed: %d\n", item);

    // Signal producer
    pthread_cond_signal(&not_full);

    pthread_mutex_unlock(&mutex);

    return item;
}

// Producer thread
void* producer(void* arg) {
    for (int i = 1; i <= 10; i++) {
        produce(i);
        sleep(1);
    }
    return NULL;
}

// Consumer thread
void* consumer(void* arg) {
    for (int i = 1; i <= 10; i++) {
        consume();
        sleep(2);
    }
    return NULL;
}

int main() {
    pthread_t p, c;

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&not_full, NULL);
    pthread_cond_init(&not_empty, NULL);

    pthread_create(&p, NULL, producer, NULL);
    pthread_create(&c, NULL, consumer, NULL);

    pthread_join(p, NULL);
    pthread_join(c, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&not_full);
    pthread_cond_destroy(&not_empty);

    return 0;
}