#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Dichiarazione del mutex
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int contatore = 0;  // Variabile condivisa

void* incrementa_contatore(void* arg) {
    while (contatore<100) {
        // Blocca il mutex prima di accedere alla variabile condivisa
        pthread_mutex_lock(&mutex);

        // Incrementa la variabile condivisa
        if(contatore != 100){
            contatore++;
            printf("Thread %s ha incrementato il contatore a %d\n", (char*)arg, contatore);
        }
        
        // Sblocca il mutex dopo aver aggiornato la variabile condivisa
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main() {
    pthread_t threadA, threadB;

    // Crea i due thread
    pthread_create(&threadA, NULL, incrementa_contatore, "A");
    pthread_create(&threadB, NULL, incrementa_contatore, "B");

    // Attende che i thread terminino
    pthread_join(threadA, NULL);
    pthread_join(threadB, NULL);

    // Distrugge il mutex
    pthread_mutex_destroy(&mutex);

    return 0;
}
