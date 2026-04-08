#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define N 5

// States
#define THINKING 0
#define HUNGRY   1
#define EATING   2

int state[N];

// Monitor components
pthread_mutex_t mutex;
pthread_cond_t cond[N];

// Left and Right macros
#define LEFT(i)  (i + N - 1) % N
#define RIGHT(i) (i + 1) % N

// Test if philosopher can eat
void test(int i) {
    if (state[i] == HUNGRY &&
        state[LEFT(i)] != EATING &&
        state[RIGHT(i)] != EATING) {

        state[i] = EATING;
        printf("Philosopher %d starts EATING\n", i);

        pthread_cond_signal(&cond[i]);
    }
}

// Monitor function: take forks
void take_forks(int i) {
    pthread_mutex_lock(&mutex);

    state[i] = HUNGRY;
    printf("Philosopher %d is HUNGRY\n", i);

    test(i);

    // If not able to eat, wait
    while (state[i] != EATING) {
        pthread_cond_wait(&cond[i], &mutex);
    }

    pthread_mutex_unlock(&mutex);
}

// Monitor function: put forks
void put_forks(int i) {
    pthread_mutex_lock(&mutex);

    state[i] = THINKING;
    printf("Philosopher %d is THINKING\n", i);

    // Check neighbors
    test(LEFT(i));
    test(RIGHT(i));

    pthread_mutex_unlock(&mutex);
}

// Philosopher thread
void* philosopher(void* arg) {
    int i = *(int*)arg;

    while (1) {
        printf("Philosopher %d is THINKING\n", i);
        sleep(1);

        take_forks(i);

        sleep(1); // Eating

        put_forks(i);
    }
}

int main() {
    pthread_t thread[N];
    int id[N];

    pthread_mutex_init(&mutex, NULL);

    for (int i = 0; i < N; i++) {
        pthread_cond_init(&cond[i], NULL);
        state[i] = THINKING;
        id[i] = i;
    }

    for (int i = 0; i < N; i++) {
        pthread_create(&thread[i], NULL, philosopher, &id[i]);
    }

    for (int i = 0; i < N; i++) {
        pthread_join(thread[i], NULL);
    }

    return 0;
}