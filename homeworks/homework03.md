## Homework 3

### C Exercises

Modify the link below so it points to the `ex03` directory in your
student repository.

<<<<<<< HEAD
[Here is a link to the ex02.5 directory in my repository](https://github.com/ericasaywhat/ExercisesInC/tree/master/exercises/ex02.5)
=======
[Here is a link to the ex03 directory in my repository](https://github.com/YOUR_GITHUB_USERNAME_HERE/ExercisesInC/tree/master/exercises/ex03)
>>>>>>> af6015fd869d00aeb2fc4e2871b4df7a3ff9d2e7

### Think OS Chapter 4 reading questions

**Files and file systems**

1) What abstractions do file systems provide?  Give an example of something that is logically 
true about files systems but not true of their implementations.

<<<<<<< HEAD
If the Georgian alphabet has 33 letters, but five bits can only specify up to 32 unique values, then we would need 6 bits to specify a letter in the Georgian alphabet.

2) In the UTF-16 character encoding, the binary representation of a character can take up to 32 bits.  
Ignoring the details of the encoding scheme, how many different characters can be represented?

If one character can take up to 32 bits, then 2<sup>32</sup> (about 4 billion) unique characters can be represented.

3) What is the difference between "memory" and "storage" as defined in *Think OS*?

As defined in *Think OS*, "memory" is used to refer to the random access memory (RAM) while "storage" is used to refer to hard disk drive (HDD) or solid state drive (SSD). Things that are stored in RAM will be lost when the computer is shut down whereas, things stored on HDD and SDD are for long term storage.

4) What is the difference between a GiB and a GB?  What is the percentage difference in their sizes?

A GiB is a gibibyte that is 2<sup>30</sup> bytes, and a GB is a gigabyte which is 10<sup>9</sup> bytes. A GiB is 7.37% bigger than a GB.

5) How does the virtual memory system help isolate processes from each other?

The virtual memory system helps isolate processes from each other since the hardware translates virtual memory to physical memory per process.(The same virtual address from two different processes map to different locations in physical memory.)

6) Why do you think the stack and the heap are usually located at opposite ends of the address space?

The stack and heap are usually located at opposite ends of the address space since the stack grows down and the heap grows up. This way, there is the most room for both the stack and heap to grow without running into each other.

7) What Python data structure would you use to represent a sparse array?

I would use a Python dictionary to represent a sparse array.

8) What is a context switch?
=======
2) What information do you imagine is stored in an `OpenFileTableEntry`?

3) What are some of the ways operating systems deal with the relatively slow performance of persistent storage?

4) Suppose your program writes a file and prints a message indicating that it is done writing.  
Then a power cut crashes your computer.  After you restore power and reboot the computer, you find that the 
file you wrote is not there.  What happened?

5) Can you think of one advantage of a File Allocation Table over a UNIX inode?  Or an advantage of a inode over a FAT?

6) What is overhead?  What is fragmentation?

7) Why is the "everything is a file" principle a good idea?  Why might it be a bad idea?

If you would like to learn more about file systems, a good next step is to learn about journaling file systems.  
Start with [this Wikipedia article](https://en.wikipedia.org/wiki/Journaling_file_system), then 
[Anatomy of Linux Journaling File Systems](http://www.ibm.com/developerworks/library/l-journaling-filesystems/index.html).  
Also consider reading [this USENIX paper](https://www.usenix.org/legacy/event/usenix05/tech/general/full_papers/prabhakaran/prabhakaran.pdf).


>>>>>>> af6015fd869d00aeb2fc4e2871b4df7a3ff9d2e7

A context switch is when an operating system interrupts a running process, saves its state, and then runs another process. 
