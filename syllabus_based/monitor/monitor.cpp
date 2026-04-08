#include <iostream>
#include <pthread.h>
#include <unistd.h>

using namespace std;

#define SIZE 5

class Monitor {
private:
    int buffer[SIZE];
    int count;

    pthread_mutex_t mutex;
    pthread_cond_t not_full;
    pthread_cond_t not_empty;

public:
    // Constructor
    Monitor() {
        count = 0;
        pthread_mutex_init(&mutex, NULL);
        pthread_cond_init(&not_full, NULL);
        pthread_cond_init(&not_empty, NULL);
    }

    // Producer function
    void produce(int item) {
        pthread_mutex_lock(&mutex);

        while (count == SIZE) {
            pthread_cond_wait(&not_full, &mutex);
        }

        buffer[count] = item;
        cout << "Produced: " << item << endl;
        count++;

        pthread_cond_signal(&not_empty);
        pthread_mutex_unlock(&mutex);
    }

    // Consumer function
    int consume() {
        pthread_mutex_lock(&mutex);

        while (count == 0) {
            pthread_cond_wait(&not_empty, &mutex);
        }

        int item = buffer[count - 1];
        cout << "Consumed: " << item << endl;
        count--;

        pthread_cond_signal(&not_full);
        pthread_mutex_unlock(&mutex);

        return item;
    }

    // Destructor
    ~Monitor() {
        pthread_mutex_destroy(&mutex);
        pthread_cond_destroy(&not_full);
        pthread_cond_destroy(&not_empty);
    }
};

Monitor m; // shared monitor

// Thread functions (still C-style)
void* producer(void* arg) {
    for (int i = 1; i <= 10; i++) {
        m.produce(i);
        sleep(1);
    }
    return NULL;
}

void* consumer(void* arg) {
    for (int i = 1; i <= 10; i++) {
        m.consume();
        sleep(2);
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    pthread_create(&t1, NULL, producer, NULL);
    pthread_create(&t2, NULL, consumer, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}