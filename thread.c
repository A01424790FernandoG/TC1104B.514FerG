#include <pthread.h>
#include <stdio.h>

void * holaMundo(void *arg){
    printf("Hola desde el hilo");
    return NULL;
}

int main(){{
    pthread_t threadId;
    pthread_create(&threadId, NULL, holaMundo,NULL);
}}