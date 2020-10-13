#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define min(a, b) ((a) < (b) ? (a) : (b))

/*
    schelet pentru exercitiul 5
*/

int* arr;
int n_elems;
int n_threads;

void *add_function(void *arg) {
    long id = (long)arg;
    int start = id * (double)n_elems / n_threads;
    int end = min((id + 1) * (double)n_elems / n_threads, n_elems);
    for(int i = start; i < end; ++i) {
        arr[i] += 100;
    }
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        perror("Specificati dimensiunea array-ului\n");
        exit(-1);
    }

    n_elems = atoi(argv[1]);

    arr = malloc(n_elems * sizeof(int));
    for (int i = 0; i < n_elems; i++) {
        arr[i] = i;
    }

    for (int i = 0; i < n_elems; i++) {
        printf("%d", arr[i]);
        if (i != n_elems - 1) {
            printf(" ");
        } else {
            printf("\n");
        }
    }

    // TODO: aceasta operatie va fi paralelizata
  	// for (int i = 0; i < array_size; i++) {
    //     arr[i] += 100;
    // }
    
    // crearea thread-urilor
    n_threads = sysconf(_SC_NPROCESSORS_CONF);
    long id;
    int r;
    pthread_t threads[n_threads];
    void *status;

    for (id = 0; id < n_threads; id++) {
		r = pthread_create(&threads[id], NULL, add_function, (void *)id);

		if (r) {
	  		printf("Eroare la crearea thread-ului %ld\n", id);
	  		exit(-1);
		}
  	}

  	for (id = 0; id < n_threads; id++) {
		r = pthread_join(threads[id], &status);

		if (r) {
	  		printf("Eroare la asteptarea thread-ului %ld\n", id);
	  		exit(-1);
		}
  	}

    //printarea de final
    for (int i = 0; i < n_elems; i++) {
        printf("%d", arr[i]);
        if (i != n_elems - 1) {
            printf(" ");
        } else {
            printf("\n");
        }
    }
}
