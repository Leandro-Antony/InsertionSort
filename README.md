# 1. Introduction

In this class assignment your task is to implement the **sorted insert**
algorithm in the [sorted_insert.cpp](src/sorted_insert.cpp) source file, more
specifically inside the `insert_in_sorted()` function.

This project already has a `main()` (client code) that tries to insert several
integer values into an array using the `insert_in_sorted()` function you will code.
Of course, at the beginning the code provided will not work because the function is empty.

# 2. Compiling the project with `cmake`

To compile the project you need to run the following command in the root folder of the project

```
$ cmake -S . -B build
```
where,
* `-S` indicates where to look for the _source tree_, which in this case is the root folder of the project (dot).
* `-B` indicates which folder the executable and `cmake` cache files will be generated and written to.

As you already know, this command will generate a `Makefile` inside the folder
`build`. If everything worked correctly in the previous step, you may run this
command to compile the project.

```
$ cmake --build build
```
or you may `cd` into the `build` folder and compile with the `make` command, like so:

```
$ cd build
$ make
```

# 3. Compiling the project without `cmake` (manual compilation)

If you don't have `cmake` installed/available or just don't want to use it, just type in the following command at the root folder of the project:

```
$ mkdir -p build
$ g++ -Wall -std=c++17 src/sorted_insert.cpp -o build/si
```

# 4. Running

Regardless of the method you've chosen to compile your project, just type in

```
$ ./build/si
```
from the root folder.

If you are already inside the `build` folder just run
```
$ ./si
```
# 5. Expected Outcome

If everything works fine, your program should produce an outcome like this

```
$ ./build/si
>>> Data source
    Array: [ 8 2 1 10 3 5 7 6 4 9 ]
>>> Destination array
    Array: [ 0 0 0 0 0 0 0 0 0 0 ]

>>> Inserting 8
    Array: [ 8 ]

>>> Inserting 2
    Array: [ 2 8 ]

>>> Inserting 1
    Array: [ 1 2 8 ]

>>> Inserting 10
    Array: [ 1 2 8 10 ]

>>> Inserting 3
    Array: [ 1 2 3 8 10 ]

>>> Inserting 5
    Array: [ 1 2 3 5 8 10 ]

>>> Inserting 7
    Array: [ 1 2 3 5 7 8 10 ]

>>> Inserting 6
    Array: [ 1 2 3 5 6 7 8 10 ]

>>> Inserting 4
    Array: [ 1 2 3 4 5 6 7 8 10 ]

>>> Inserting 9
    Array: [ 1 2 3 4 5 6 7 8 9 10 ]

>>> Normal ending...
```


--------
&copy; DIMAp/UFRN 2023.
