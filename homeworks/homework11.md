## Homework 11

### C Exercises

Modify the link below so it points to the `ex11` directory in your
student repository.

[Here is a link to the ex11 directory in my repository](https://github.com/YOUR_GITHUB_USERNAME_HERE/ExercisesInC/tree/master/exercises/ex11)

### Think OS Chapter 11 reading questions

1) Why is it a bad idea to pass a `sem_t` as a parameter?

It's a bad idea to pass a `sem_t` as a parameter because it behaves like a structure. Since copying a semaphore can yield unexpected results, you want to pass it by pointer.

2) When you use a Semaphore as a mutex, what should its initial value be?

When you use a Semaphore as a mutex, its initial value should be 1 to indicate that the mutex is unlocked so that a thread can pass the semaphore without blocking.

3) Can you think of another use for a Semaphore where you might use a different initial value?

You would want the initial value of a Semaphore to be 0 if you wanted to use the semaphore to be used as a conditional variable.

4) In my solution to the producers-consumers problem using Semaphores,
what does it mean if the value of `queue->spaces` is `3` at some point in time?

If the value of `queue->spaces` is `3` at some point in time means that the queue has 3 empty spaces in the queue. 

5) What does it mean if `queue->space` is `-3`?

If the value of `queue->spaces` is `-3`, we know that the queue is full and that there are three too many elements that attempted to be pushed into the queue.

6) Why doesn't `queue_pop` have to use `queue_empty` to check whether the queue is empty?

`queue_pop` doesn't have to use `queue_empty` to check whether the queue is empty because the semaphore keeps track of the items in the queue and blocks consumers if the queue is empty.

7) Any problem that can be solved with Semaphores can also be solved with mutexes and condition variables.
How can you prove that that's true?

Semaphores are like integers that can be initialized to any value but can only be incremented or decremented, and its value can't be read. When a thread decrements the semaphore and the result is negative, the thread blocks and can't continue until another thread increments the semaphore, like a condition variable. A semaphore is also like a mutex in which a thread locks and unlocks allowing only one thread at a time.

8) What is Property 3?  Hint: see *The Little Book of Semaphores*, 
[Section 4.3](http://greenteapress.com/semaphores/LittleBookOfSemaphores.pdf). 

Property 3 is that if there are threads waiting on a semaphore when a thread executes `signal`, then one of the waiting threads has to be woken.




