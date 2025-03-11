#include <stdio.h>
#include <pthread.h>

void *print_message(void *message) {
    printf("%s\n", (char *)message);
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    
    char *message1 = "Thread 1 : Bonjour!";
    char *message2 = "Thread 2 : Comment ça va?";

    pthread_create(&thread1, NULL, print_message, (void *)message1);
    pthread_create(&thread2, NULL, print_message, (void *)message2);
    
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}
