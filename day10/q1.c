#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define N 5

int state[N];

pthread_mutex_t mutex;
pthread_cond_t cond[N];

#define THINKING 0
#define HUNGRY 1
#define EATING 2

int left(int i) {
    return (i + N - 1) % N;
}

int right(int i) {
    return (i + 1) % N;
}

void print_state(int i) {
    if(state[i] == THINKING)
        printf("Philosopher %d is THINKING\n", i);
    else if(state[i] == HUNGRY)
        printf("Philosopher %d is HUNGRY\n", i);
    else if(state[i] == EATING)
        printf("Philosopher %d is EATING\n", i);
}

void test(int i) {
    if(state[i] == HUNGRY &&
       state[left(i)] != EATING &&
       state[right(i)] != EATING) {
        state[i] = EATING;
        print_state(i);
        pthread_cond_signal(&cond[i]);
    }
}

void pickup(int i) {
    pthread_mutex_lock(&mutex);

    state[i] = HUNGRY;
    print_state(i);

    test(i);

    while(state[i] != EATING)
        pthread_cond_wait(&cond[i], &mutex);

    pthread_mutex_unlock(&mutex);
}

void putdown(int i) {
    pthread_mutex_lock(&mutex);

    state[i] = THINKING;
    print_state(i);

    test(left(i));
    test(right(i));

    pthread_mutex_unlock(&mutex);
}

void* philosopher(void* num) {
    int i = *(int*)num;

    while(1) {
        sleep(1);
        pickup(i);
        sleep(2);
        putdown(i);
    }
}

int main() {
    pthread_t thread[N];
    int id[N];

    pthread_mutex_init(&mutex, NULL);

    for(int i = 0; i < N; i++) {
        pthread_cond_init(&cond[i], NULL);
        state[i] = THINKING;
    }

    for(int i = 0; i < N; i++) {
        id[i] = i;
        pthread_create(&thread[i], NULL, philosopher, &id[i]);
    }

    for(int i = 0; i < N; i++)
        pthread_join(thread[i], NULL);

    return 0;
}