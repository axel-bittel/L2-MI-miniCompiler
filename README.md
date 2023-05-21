# L2-MI-miniCompiler

## Directory structure

```
ExampleFile     : File to successfully compile 
TestErrorFile   : File to test error handling  
src             : Source code of the compiler  
include         : Header files of the compiler 
fedora          : Dockerfile to build the fedora image
```
## How to use
Compile: 
```
make        : Compile the compiler
make clean  : Clean files .o and .dot
make fclean : Clean files .o, .dot and the compiler
make re     : Clean files .o, .dot and the compiler and recompile the compiler
make test   : Compile the compiler and compile all the files in ExampleFile and TestError
```

Run:
```
./compiler <file1>.c <file2>.c...
```