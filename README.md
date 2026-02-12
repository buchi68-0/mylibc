# mylibc - reproduction of the C standard library, according the EPITECH's coding style
<img
  src="https://www.c-language.org/logo.svg"
  alt="C logo"
  width=100px
  height=100px
/>

> [!TIP]
> This project is only aviable on Linux, and maybe on MacOS

## Quick start

### 1. Clone the repository

```bash
git clone https://github.com/buchi68-0/mylibc.git
cd mylibc
```

### 2. Build the project

```bash
make
```

### 3. use the library

Compile any executable binary, using -lmylibc. You probably need the -L option with the path of this repository.  

## Advanced start

This help will allow you to use the library as a part of an existing project.  

### 1. Clone the repository
same as before  

```bash
git clone https://github.com/buchi68-0/mylibc.git
cd mylibc
```

### 2. Copy the library

```bash
cp mylibc [Project_Path]/lib/mylibc
```
or  
```bash
cp mylibc [Project_Path]/mylibc
```

### 3. Compile recursively

you can do this by hand, or put this in a Makefile  
```bash
make -C lib/mylibc
```
or  
```bash
make -C mylibc
```
depending on where you copied the mylibc directory  

### 4. Copy header files
If you want to put all headers into a common directory, like includes/ <br>
you can automate the copy of the files by adding this after the recursive compilation: <br>
```bash
cp (lib/)mylibc/includes/mylibc.h includes/
```
> [!CAUTION]
> Please do not copy private headers. They often contains some typedefs and structs that I can't put directly in source files because of the coding style limitation. These could cause compatibility issues with other headers

## Unit testing

You can run unit tests for mylibc at any time. They certify the project's rigor.  

You can also run them recursively, if you want to unit test your *whole* project while unit testing

## Contributing to the project

You can create a new issue to report a bug

You can also maybe make a pull request, although it **must** be according to coding style and **must** come with it's own tests  

in case of a successfull pull request, you will be put in the contributors page and your name will be mentionned in the file you helped in  

in case of an issue, you'll be thanked in the thanked section, followed by the number of issued you helped me fix

## Full pull request rules

### 1. Content of the pull request

The pull request may **not in _any_ case** contain full features, like a reproduction of a libc func.  

This project is, on the first place, a way for me to understand deeply the glibc  

You can:  
- submit a fix for a already developed func, which is very well apreciated  
- give an optimization for one.  
- develop a sub function that uses already existing functions to improve quality of life  

In the case of an optimization, please send the least code, and more of like pseudo-code, because I then have to think more into the core of your idea and develop it  

If you develop your own subfunction, please think first about the improvement it would give. If it's not that much, let people make this function themselves (this a standard library, not somewhere to put everything you can think about)  

> [!NOTE]
> malloc will NOT be redone, so yeah, you'll have to use it, and handle NULL

### 2. coding style

Here's a basic policy of coding style if you want to implement changes:

- no asm keyword, and no inline attribute (=> instantly refused)
- put correct function names (for sub funcs mainly, because main funcs will have the name of the libc funcs)
- function can make at most 20 lines, each line must be at most 80 characters long
- maximum 10 funcs per file, and only 5 non-static per file
- lines must be ended in UNIX-style (no \r, it's horrible to edit)
- no trailing spaces at the end of a line
- file headers (will add myself, if needed)
- no #pragma once (for .h files)
- a maximum of 2 depth for conditionnal blocs[^1]

### 3. testing policy

if you devellop a subfunction, you must include a full test file and get the maximum coverage you get.  

The function will be tested by me, and It's possible I go up to a LD_PRELOAD[^2] to test protection  

The coverage must be at minimum 70%. Best would be 100% (there will be some files to allow to test a programm with redirected malloc)

[^1]: conditionnal blocks are : for, while, if and switch. if then else is considered one of depth, but every "else if" are considered as +1 depth. If needed, use sub functions. switch are not recommended, since they use a lot of line, prefer using a for loop with an array of checks, which would be for/if
[^2]: redirection of system funcs to test how error values are being handled (like malloc returning NULL)  
