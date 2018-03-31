## Homework 8

### C Exercises

Modify the link below so it points to the `ex07` directory in your
student repository.

[Here is a link to the ex08 directory in my repository](https://github.com/YOUR_GITHUB_USERNAME_HERE/ExercisesInC/tree/master/exercises/ex08)

### Think OS Chapter 8 reading questions

**Multitasking**

1) What is the kernel's most basic task?

The kernel's most basic task is to handle interrupts.

2) When an interrupt occurs, what part of the hardware state is saved by hardware?

When an interrupt occurs, the program counter is saved by the hardware.

3) What is the difference between an interrupt and a context switch?

For an interrupt, the hardware saves the program counter and jumps to the interrupt handler. The interrupt handler stores the program counter, status register, and contents in data registers it plans to use. The interrupt handler then handles the interrupt and restores the contents of the saved registers and restores the program counter.
For a context switch, the kernel saves all the registers and switches to a new process. It might clear the data stored in the MMU and have to load data into the cache, so a context switch is slower than an interrupt.

4) Give an example of an event that might cause a process to move from the blocked to the ready state.

An example of an event that might cause a process to move from the blocked state to the ready state might be network communication or a disk read.

5) Why might a scheduler want to give higher priority to an I/O bound process?
I/O bound processes are processes that read data from a network or a disk. I/O bound processes are likely to run for a short time and then wait for. While waiting for inputs, the processor can work carry out CPU bound processes. I/O bound processes is the pie crust that needs chilling and the CPU bound are the filling.

6) When I make French toast, I usually make a batch of 12 slices.  But my griddle only has room for 8 slices. 
Each piece of toast has to cook for 5 minutes on each side.  How can I schedule 12 slices onto 8 "cores"
to minimize the elapsed time to cook all 12 slices?  (Note: this question is not hypothetical; 
this is really how I make French toast.)

We want to cook six at a time. If we fill up all 8 spots, the first batch of 8 would be hard to flip and second batch of 4 would have a lot of empty space. If we were master French toast flippers, we could cook a first batch of 4 and a second batch of 8 so that when we are done cooking we will have 8 warm ones and 4 cooler ones rather than 4 warm ones and 8 cooler ones.

