## Homework 3

### C Exercises

Modify the link below so it points to the `ex02.5` directory in your
student repository.

[Here is a link to the ex02.5 directory in my repository](https://github.com/ericasaywhat/ExercisesInC/tree/master/exercises/ex02.5)

### Think OS Chapter 3 reading questions

### Virtual memory

1) The Georgian alphabet has 33 letters.  How many bit are needed to specify a letter?

If the Georgian alphabet has 33 letters, but five bits can only specify up to 32 unique values, then we would need 6 bits to specify a letter in the Georgian alphabet.

2) In the UTF-16 character encoding, the binary representation of a character can take up to 32 bits.  
Ignoring the details of the encoding scheme, how many different characters can be represented?

If one character can take up to 32 bits, then 2<sup>32</sup> (about 4 billion) unique characters can be represented.

3) What is the difference between "memory" and "storage" as defined in *Think OS*?

As defined in *Think OS*, "memory" is used to refer to the random access memory (RAM) while "storage" is used to refer to hard disk drive (HDD) or solid state drive (SSD).

4) What is the difference between a GiB and a GB?  What is the percentage difference in their sizes?

A GiB is a gibibyte that is 2<sup>30</sup> bytes, and a GB is a gigabyte which is 10<sup>9</sup> bytes. A GiB is 7.37% bigger than a GB.

5) How does the virtual memory system help isolate processes from each other?

The virtual memory system helps isolate processes from each other since the hardware translates virtual memory to physical memory per process, the same virtual address from two different processes map to different locations in physical memory.

6) Why do you think the stack and the heap are usually located at opposite ends of the address space?

The stack and heap are usually located at opposite ends of the address space since the stack grows down and the heap grows up. This way, there is the most room for both the stack and heap to grow without running into each other.

7) What Python data structure would you use to represent a sparse array?

I would use a dictionary to represent a sparse array or a 2D array or a lists of lists.

8) What is a context switch?

A context switch is when an operating system interrupts a running process, saves its state, and then runs another process. 
