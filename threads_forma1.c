#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "commonthreads.h"
#include "mycommon.h"
#include <pthread.h>
#include <time.h>


volatile int counter = 0;
int loops;
puerta door;

clock_t start, end;

double cpu_time_used;
 
void *worker(void *arg) {
    int i;
cerrar_puerta(door);
start = clock();

    for (i = 0; i < loops; i++) {
         
        counter++;
      
    

    }
abrir_puerta(door);

end = clock();
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
	fprintf(stderr, "usage: threads <loops>\n");
	exit(1);
    }


    crear_puerta(door);
    loops = atoi(argv[1]);
    pthread_t p1, p2;
    printf("Initial value : %d\n", counter);
    Pthread_create(&p1, NULL, worker, NULL);
    Pthread_create(&p2, NULL, worker, NULL);
    Pthread_join(p1, NULL);
    Pthread_join(p2, NULL);
    destruir_puerta(door);
    printf("Final value   : %d\n", counter);

double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
printf ("fff : %f\n", cpu_time_used);
    return 0;

}
