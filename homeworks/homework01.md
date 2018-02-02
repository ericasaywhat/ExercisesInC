## Homework 1

### C Exercises

[Here is a link to the ex01 directory in my repository](https://github.com/ericasaywhat/ExercisesInC/tree/master/exercises/ex01)


### Think OS Chapter 1 reading questions

For each of the reading questions below, write answers in the form of
a clear, concise, complete sentence or two.

1) Give an example of a feature common in interpreted languages that is rare in compiled languages.

In interpreted languages, variable names are stored in memory while teh program runs and are accessible by the program.

2) Name two advantages of static typing over dynamic typing.
	>1) We know what type we return by looking at the code.
 	>2) The compiler can check whether the arguments have the right type and if the return value is used correctly.

3) Give an example of a static semantic error.

Static semantic errors could happen when variables and values don't have the right type.

4) What are two reasons you might want to turn off code optimization?
	>1) Optimizations can cause certain subtle bugs to appear or disappear.
	>2) Using higher level optimizations takes a longer time to compile.

5) When you run `gcc` with `-S`, why might the results look different on different computers?

GCC generates code for the machine the program is running on, so the assembly code `-S` generates will look different on different computers.

6) If you spell a variable name wrong, or if you spell a function name wrong, the error messages
you get might look very different.  Why?

When you spell a variable name wrong, you get an error message from the compiler because the misspelled variable doesn't exist. When you spell a function name wrong, the error message comes from the linker if the function comes from a library.

7) What is a segmentation fault?

 A segmentation fault occurs if you try to read or write an incorrect location in memory.
