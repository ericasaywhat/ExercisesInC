## Homework 3

### C Exercises

Modify the link below so it points to the `ex03` directory in your
student repository.

[Here is a link to the ex03 directory in my repository](https://github.com/ericasaywhat/ExercisesInC/tree/master/exercises/ex03)

### Think OS Chapter 4 reading questions

**Files and file systems**

1) What abstractions do file systems provide?  Give an example of something that is logically
true about files systems but not true of their implementations.

File systems provide the abstraction that a file is a sequence of bytes and that it maps from a file's name to its contents. File systems, however, is not entirely true in the implementation since files are streams of bytes and storage is made of blocks. Thus, the operating system actually has to translate the bytes-based file operations to block-based operations.

2) What information do you imagine is stored in an `OpenFileTableEntry`?

An `OpenFileTableEntry` should store whether or not the file is being read or written, as well as a pointer for where it's read up to in the file. It should possibly contain a pointer to the piece of memory where the operating system can check whether or not the next character of the file is already in memory.

3) What are some of the ways operating systems deal with the relatively slow performance of persistent storage?

Operating systems deal with the relatively slow performance of persistent storage by trying to read large blocks each time they access the disk (block transfers), loading a block that is predicted the process needs before it's been requested (prefetching), storing the data in memory to modify and write into disk later (buffering), and keeping a copy of a block in memory since a process is likely to use the same blocks so that it can handle future requests at memory speed (caching).

4) Suppose your program writes a file and prints a message indicating that it is done writing.
Then a power cut crashes your computer.  After you restore power and reboot the computer, you find that the
file you wrote is not there.  What happened?

The file that my program had just written was probably stored in a buffer to be written into disk later. The power cut probably crashed the computer before the operating system was able to write the file into disk.

5) Can you think of one advantage of a File Allocation Table over a UNIX inode?  Or an advantage of a inode over a FAT?

With a File Allocation Table, accessing data is generally faster than a UNIX inode if the data needs to be accessed through an indirect block. Indirection adds overhead to random access to large files. Inode blocks can be spread all over the disk. However, inodes allow for fast access to common small files that are located in a fixed array of direct blocks. On most systems, the 12 direct blocks in an inode is enough for a large majority of files.

6) What is overhead?  What is fragmentation?

Overhead is the data structures used by the allocator that take up space. Fragmentation is the unused space that results from blocks that are left unused or just partially used. When you allocate and free chunks of various sizes the heap becomes fragmented, and the free space is fragmented into small pieces that then wastes space and slows a program down.

7) Why is the "everything is a file" principle a good idea?  Why might it be a bad idea?

The "everything is a file" principle is a good idea since this allows us to understand how everything works and treat everything as a file. Thus, we can just use one API for everything. Using the example of the UNIX pipe, since the pipe behaves like a file open for reading or writing, we can call `fputs` and `fprintf` or `fgets` and `fscanf`, respectively. Programs can also be more versatile since a program that works with files can also work with data coming from other sources.

The "everything is a file" principle can be a bad idea when not everything is a file. Since a file is a collection of bytes there is no type information. Thus, we can only understand what is in the file if we already know what it is. For example, working with plain text is fine in that writing to a program that prints things is the same as writing to a terminal and writing to a text file, but if we had an image instead, that information printed out is useless unless we were to know that it was an image in the first place.


If you would like to learn more about file systems, a good next step is to learn about journaling file systems.
Start with [this Wikipedia article](https://en.wikipedia.org/wiki/Journaling_file_system), then
[Anatomy of Linux Journaling File Systems](http://www.ibm.com/developerworks/library/l-journaling-filesystems/index.html).
Also consider reading [this USENIX paper](https://www.usenix.org/legacy/event/usenix05/tech/general/full_papers/prabhakaran/prabhakaran.pdf).


