/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_CHILDREN 10

/* Print an error message and exit.
*/
void perror_exit(char *s)
{
    perror(s);
    exit(-1);
}

/* Call malloc and exit if it fails.
*/
void *check_malloc(int size)
{
    void *p = malloc(size);
    if (p == NULL) {
        perror_exit("malloc failed");
    }
    return p;
}

/* Structure that contains variables shared between threads.
*/
typedef struct {
    int counter;
} Shared;

/* Allocate the shared structure.
*/
Shared *make_shared()
{
    Shared *shared = check_malloc(sizeof(Shared));
    shared->counter = 0;
    return shared;
}

/* Create a child thread.
*/
pthread_t make_thread(void *(*entry)(void *), Shared *shared)
{
    int ret;
    pthread_t thread;

    ret = pthread_create(&thread, NULL, entry, (void *) shared);
    if (ret != 0) {
        perror_exit("pthread_create failed");
    }
    return thread;
}

/* Wait for a child thread.
*/
void join_thread(pthread_t thread)
{
    int ret = pthread_join(thread, NULL);
    if (ret == -1) {
        perror_exit("pthread_join failed");
    }
}

/* Code run by the child threads.
*/
void child_code(Shared *shared)
{
    printf("counter = %d\n", shared->counter);
    shared->counter++;
}

/* Entry point for the child threads.
*/
void *entry(void *arg)
{
    Shared *shared = (Shared *) arg;
    child_code(shared);
    pthread_exit(NULL);
}

int main()
{
    int i;
    pthread_t child[NUM_CHILDREN];

    Shared *shared = make_shared();

    for (i=0; i<NUM_CHILDREN; i++) {
        child[i] = make_thread(entry, shared);
    }

    for (i=0; i<NUM_CHILDREN; i++) {
        join_thread(child[i]);
    }

    printf("Final value of counter is %d\n", shared->counter);
    return 0;
}


/* Comments from Erica:
   -printing counter in children doesn't increment because the threads read at certain time
    and then print the value.
   -They run concurrently and read the counter separately, but this is fixed when we join them again.
   -The final counter is correct.

   Fortunately, for me, all the threads happen in order, but sometimes they don't. If we print 0, 0, 0, 0, 4
   for "counter= "

   Since this is relatively simple code, it's not surprising this all works. Increasing the number of children
   will eventually have us run into a synchronization error where the final number is not what it should be
   because a thread reads and write the same value that another thread has.

   The first four threads read 0 and print that before incrementing and writing, the last thread reads after
   the last write happens, and then prints 4, increments, and writes 5.
*/