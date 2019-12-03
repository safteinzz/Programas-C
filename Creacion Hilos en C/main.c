#include <pthread.h>
#include <stdio.h>
#define NUM_HILOS 5

void *PrintHola(void *threadid)
{
    long tid;
    tid = (long)threadid;
    printf("Hola Mundo este es mi hilo #%ld!\n", tid);
    pthread_exit(NULL);
}

// NO TIENE CONTROL DE TIEMPO

int main (int argc, char *argv[])
{
    pthread_t threads[NUM_HILOS];
    int rc;
    long t;
    for(t = 0; t < NUM_HILOS; t++)
    {
        printf("Estamos creando el hilo %ld\n", t);
        rc = pthread_create(&threads[t], NULL, PrintHola, (void *)t);
        if (rc)
        {
            printf("ERROR; codigo devuelto por pthread_create() is %d\n", rc);
            exit(-1);
        }
    }
/* Debemos llamar a pthread_exit() al final */
pthread_exit(NULL);
}
