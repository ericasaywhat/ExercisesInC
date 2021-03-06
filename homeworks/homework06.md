## Homework 6

### C Exercises

Modify the link below so it points to the `ex06` directory in your
student repository.

[Here is a link to the ex06 directory in my repository](https://github.com/ericasaywhat/ExercisesInC/tree/master/exercises/ex06)

### Think OS Chapter 6 reading questions

**Memory management**

1) Which memory management functions would you expect to take constant time?
Which ones take time proportional to the size of the allocated chunk?

Of the 4 functions for dynamic memory allocation, I would expect `malloc` and `free` to take constant time.
`calloc` and `realloc` would take time proportional to the size of the allocated chunk.

2) For each of the following memory errors, give an example of something that might go wrong:

a) Reading from unallocated memory.

The system might detect the error and stop the program yielding a segmentation fault, but usually the program will just read whatever value is stored at that particular location and yield a result that is hard to understand.

b) Writing to unallocated memory.

After the value is written, it might only be accessed some other time when you don't need it and cause problems that would be hard to diagnose.

c) Reading from a freed chunk.

Reading from a freed chunk should be the same as reading from unallocated memory in which the system might detect the error or will just read the value that is stored at that location and yield a result that is hard to understand.

d) Writing to a freed chunk.

Writing to a freed chunk should be the same as writing to unallocated memory in that it might be accessed some other time when you don't need it and that would cause problems that would be hard to diagnose. 

e) Failing to free a chunk that is no longer needed.

This will yield a memory leak which in small programs are ok since it will exit shortly anyway. In larger programs, however, the system might run out of physical memory and an error in calling `malloc` somewhere down the line.

3) Run

```
    ps aux --sort rss
```

to see a list of processes sorted by RSS, which is "resident set size", the amount of physical 
memory a process has.  Which processes are using the most memory?

Google Chrome are using most memory along with Spotify and Firefox.

4) What's wrong with allocating a large number of small chunks?  What can you do to mitigate the problem?

Allocating a large number of small chunks will take up a lot of overhead since boundary tags and free list pointers take a lot of space. We can mitigate the problem by allocating them in arrays.

If you want to know more about how malloc works, read 
[Doug Lea's paper about dlmalloc](http://gee.cs.oswego.edu/dl/html/malloc.html)
