#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define BUFFER_SIZE 5

int buffer = 0;
pthread_mutex_t lock;
pthread_cond_t cond;

void *producer(void *arg) {
    for (int i = 0; i < BUFFER_SIZE; i++) {
        pthread_mutex_lock(&lock);
        
        buffer++;  
        printf("Producteur : Produit %d\n", buffer);
        
        pthread_cond_signal(&cond);  // Signal au consommateur
        pthread_mutex_unlock(&lock);
        sleep(1);  // Simule un délai
    }
    return NULL;
}

void *consumer(void *arg) {
    for (int i = 0; i < BUFFER_SIZE; i++) {
        pthread_mutex_lock(&lock);
        
        while (buffer == 0) {  // Attend que le buffer soit rempli
            pthread_cond_wait(&cond, &lock);
        }
        
        printf("Consommateur : Consomme %d\n", buffer);
        buffer--;
        
        pthread_mutex_unlock(&lock);
        sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t prod, cons;
    pthread_mutex_init(&lock, NULL);
    pthread_cond_init(&cond, NULL);

    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&cons, NULL, consumer, NULL);

    pthread_join(prod, NULL);
    pthread_join(cons, NULL);

    pthread_mutex_destroy(&lock);
    pthread_cond_destroy(&cond);

    printf("Fin du programme\n");
    return 0;
}
