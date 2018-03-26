## Homework 7

### C Exercises

Modify the link below so it points to the `ex07` directory in your
student repository.

[Here is a link to the ex07 directory in my repository](https://github.com/ericasaywhat/ExercisesInC/tree/master/exercises/ex07)

### Think OS Chapter 7 reading questions

### Caching

1) What happens if a program writes a new value into the program counter?

If a program writes a new value into the program counter, the flow of execution will jump to another location in the program wrote into the program counter.

2) What is the fundamental problem caches are meant to solve?

The fundamental problem that caches are meant to solve is the speed limiting factor that memory presents in current computers. It takes 10ns to transfer data to and from memory, so the CPU would complete instructions 20 times slower than what is theoretically possible.

3) If cache access time is 1 ns and memory access time is 10 ns, what is the average
access time of a program with hit rate 50%?  How about 90%?

With a hit rate of 50%, the average access time would be .5(1) + .5(10), or 5.5 ns. With a hit rate of 90%, the average access time would be 1.9 ns.

4) The book gives several examples of programming language features, like loops, that tend 
to improve locality in the access pattern of instructions and/or data.  Can you think of other examples?  
Or counter-examples that might decrease locality?

A method has high temporal locality if it is called repeatedly in a short period of time, so recursion would improve locality. In reading files, generating outputs, and writing the outputs into files, for more temporal locality, we could read all the inputs and generate all the outputs before writing all the outputs to a file rather than reading, generating and writing each one.

5)  If you refactor a program to improve locality, would you say the program is "cache aware"?  Why not?

A program that is cache aware uses memory more efficiently and is designed to minimize the movement to data on memory cache to avoid cache misses. If you refactor the program to improve locality, the program still doesn't know anything about the hardware, so while it can infer size of the cache and the block size, it isn't tailored to the specific hardware characteristics and can't be called cache-aware.

6) See if you can estimate the cost of a memory cache by comparing the prices of two similar CPUs with 
different cache sizes.

According to the reading, a DRAM is 1000 times faster than the SSD and 10 times more expensive. With that proportion, a cache and a DRAM should have about the same price per GiB, $11/GiB. Since the cache has 2 MiB, I would estimate the cost of the memory cache to be about 2 cents.

7) Why are cache policies generally more complex at the bottom of the memory hierarchy?

Cache policies are a lot more simple at the top of the hierarchy because they have to be fast and are implemented in the hardware. At the bottom of the hierarchy data has to be explicitly moved between disk adn tape. It takes more time to make decisions and a well-designed policy makes a big difference.

8) Can you think of a strategy operating systems could use to avoid thrashing or recover when it occurs?

According to the reading operating systems could avoid thrashing by detecting an increase in paging and blocking or killing processes until the system is responsive again. 

