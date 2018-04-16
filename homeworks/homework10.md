## Homework 10

### C Exercises

Modify the link below so it points to the `ex12` directory in your
student repository.  That's right, Homework 10 is to do Exercise 12.

[Here is a link to the ex12 directory in my repository](https://github.com/ericasaywhat/ExercisesInC/tree/master/exercises/ex12)

### Think OS Chapter 10 reading questions

1) What does it mean to say that a data structure is thread safe?

To say that a data structure is thread safe is to say that multiple threads can access the data structure and the result will not be unexpected. A problem that can occur is when two threads read the same value from a data structure and perform the same actions on that value. In this case, the data structure is not very thread safe.

2) In the circular buffer implementation of a queue, why is the maximum number of elements in the queue `n-1`,
if `n` is the size of the array?

Because this is a circular buffer, the maximum number of elemenets in the queue must be `n-1` so that it does not wrap around such that `next_in == next_out`. If incrementing `next_in` lands on `next_out`, we would have to stop otherwirse we would think that the queue is empty. 

3) If there is no mutex to protect the queue, give an example of a sequence of steps that could leave
the queue in an inconsistent state.

If there is no mutex to protect the queue, different threads could access the values of the queue at the same time and leave the queue in an inconsistent state. For example, a thread meaning to put a value into the queue would read `next_in` and increment `next_out`, but before it could increment `next_out` a thread that needs to get a value from the queue would read `next_out`.

4) When a thread calls `cond_wait`, why does it have to unlock the mutex before blocking?

When a thread calls `cond_wait`, it has to unlock the mutex before blocking so that another thread would be able to access the queue and add items so that the queue would not always be empty.

5) When a thread returns from `cond_wait`, what do we know is definitely true?  What do we think is probably true?

When a thread returns from `cond_wait`, we know that the mutex is locked and that the condition is probably true.

6) What happens if you signal a condition variable when there are no waiting threads?

If you signal a condition variable when there are no waiting threads, the signal has no effect.

7) Do you have to lock the mutex to signal a condition variable?

No, you do not have to lock the mutex to signal a condition variable. You have to unlock the mutex before you can `cond_signal`

8) Does the condition have to be true when you signal a condition variable?

Yes the condition has to be true when you signal a condition variable. If there is an intercepted signal and the condition suddenly is not true, it will probably cause an error.



