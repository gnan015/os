#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 5  // Number of philosophers

sem_t forks[N];
pthread_t philosophers[N];

// Function for each philosopher
void* philosopher(void* num) {
    int id = *(int*)num;

    while (1) {
        // Thinking
        printf("Philosopher %d is thinking\n", id);
        sleep(1);

        // Pick up left fork
        sem_wait(&forks[id]);
        printf("Philosopher %d picked up left fork\n", id);

        // Pick up right fork
        sem_wait(&forks[(id + 1) % N]);
        printf("Philosopher %d picked up right fork\n", id);

        // Eating
        printf("Philosopher %d is eating\n", id);
        sleep(2);

        // Put down right fork
        sem_post(&forks[(id + 1) % N]);
        printf("Philosopher %d put down right fork\n", id);

        // Put down left fork
        sem_post(&forks[id]);
        printf("Philosopher %d put down left fork\n", id);
    }
}

int main() {
    int i, ids[N];

    // Initialize semaphores (each fork = 1)
    for (i = 0; i < N; i++) {
        sem_init(&forks[i], 0, 1);
    }

    // Create philosopher threads
    for (i = 0; i < N; i++) {
        ids[i] = i;
        pthread_create(&philosophers[i], NULL, philosopher, &ids[i]);
    }

    // Join threads
    for (i = 0; i < N; i++) {
        pthread_join(philosophers[i], NULL);
    }

    return 0;
}