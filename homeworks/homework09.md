## Homework 9

### C Exercises

Modify the link below so it points to the `ex09` directory in your
student repository.

[Here is a link to the ex09 directory in my repository](https://github.com/ericasaywhat/ExercisesInC/tree/master/exercises/ex09)

### Think OS Chapter 9 reading questions

1) Why does each thread have its own stack?

A thread contains the program counter and other hardware state, adn the call stack. Within a single process, different threads in a multi-threaded process run different parts of the same code. They share the same static segment so that they can keep track of global variables that may have been changed by other threads. However, each thread has its own stack so they don't interfere with each other when they call functions. 

2) What does the gcc flag `-lpthread` do?

The `-lpthread` flag compiles the Pthread library in gcc.

3) What does the argument of `pthread_exit` do?

The argument of `pthread_exit` is the value that is passed from the thread to the thread it is goining with.

4) Normally the same thread that created a thread also waits to join it.
What happens if another thread tries to join a thread it did not create?

Nothing happens. Any thread can join any other thread. 

5) What goes wrong if several threads try to increment a shared integer at the same time?

If several threads try to increment a shared integer at the same time, there could be synchronization errors. We don't know when the threads read the integer, they could read it before or after another thread increments it. We could get a different output each time.

6) What does it mean to "lock a mutex"?

To "lock a mutex" means to barr other threads from accessing the mutex object. Therefore, if thread A locks the mutex, thread b that tries to lock the mutex will block until thread A is done executing.
