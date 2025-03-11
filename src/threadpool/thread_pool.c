#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 4
#define NUM_TASKS 8

pthread_mutex_t queue_lock;
pthread_cond_t queue_cond;

int task_queue[NUM_TASKS];
int task_count = 0;
int current_task = 0;

void *worker(void *arg) {
    while (1) {
        pthread_mutex_lock(&queue_lock);

        while (task_count == 0) {
            pthread_cond_wait(&queue_cond, &queue_lock);
        }

        int task = task_queue[current_task++];
        task_count--;

        pthread_mutex_unlock(&queue_lock);

        printf("Thread %ld exécute la tâche %d\n", pthread_self(), task);
        sleep(1);
    }
    return NULL;
}

void add_task(int task) {
    pthread_mutex_lock(&queue_lock);
    task_queue[task_count++] = task;
    pthread_cond_signal(&queue_cond);
    pthread_mutex_unlock(&queue_lock);
}

int main() {
    pthread_t threads[NUM_THREADS];
    pthread_mutex_init(&queue_lock, NULL);
    pthread_cond_init(&queue_cond, NULL);

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, worker, NULL);
    }

    for (int i = 0; i < NUM_TASKS; i++) {
        add_task(i);
        sleep(1);
    }

    sleep(5);
    printf("Fin du programme\n");

    return 0;
}
