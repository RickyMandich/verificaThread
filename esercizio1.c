#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Dichiarazione delle variabili di sincronizzazione
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond_ping = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond_pong = PTHREAD_COND_INITIALIZER;

int turn = 0;  // 0 per PING, 1 per PONG

void* print_ping(void* arg) {
    printf("PING\n");
    return NULL;
}

void* print_pong(void* arg) {
    printf("PONG\n");
    return NULL;
}

int main() {
    pthread_t pid1, pid2;

    int n;
    printf("inserisci il numero di volte in cui devo stampare PING e Pong\n");
    scanf("%d", &n);
    printf("stamperò PING PONG per %d volte\n", n);

    //faccio un ciclo sulla stampa di ping e pong
    for(int i=0;i<n;i++){
        // Crea i due thread
        pthread_create(&pid1, NULL, print_ping, NULL);
        pthread_create(&pid2, NULL, print_pong, NULL);

        // Attende che i thread terminino
        pthread_join(pid1, NULL);
        pthread_join(pid2, NULL);
    }
    return 0;
}
