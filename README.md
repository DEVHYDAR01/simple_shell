# 0x16. C - Simple Shell
 **By Spencer Cheng, featuring Julien Barbier**
 Project to be done in teams of 2 people (your team: DEVHYDAR01, MARWAN MAI).

# Learning Objectives
At the end of this project, you are expected to be able to explain to anyone, without the help of Google:

# General
Who designed and implemented the original Unix operating system
Who wrote the first version of the UNIX shell
Who invented the B programming language (the direct predecessor to the C programming language)
Who is Ken Thompson
How does a shell work
What is a pid and a ppid
How to manipulate the environment of the current process
What is the difference between a function and a system call
How to create processes
What are the three prototypes of main
How does the shell use the PATH to find the programs
How to execute another program with the execve system call
How to suspend the execution of a process until one of its children terminates
What is EOF / “end-of-file”?

## Overview

**Hsh** is a sh-compatible command language interpreter that executes commands read from the standard input or from a file.

### Invocation

Usage: **Hsh** 
is started with the standard input connected to the terminal. To start, compile all .c located in this repository by using this command: 
```
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
./hsh
```

**Hsh** is allowed to be invoked interactively and non-interactively. If **hsh** is invoked with standard input not connected to a terminal, it reads and executes received commands in order.

Example:
```
$ echo "echo 'alx'" | ./hsh
'alx'
$
```

When **hsh** is invoked with standard input connected to a terminal (determined by isatty(3), the interactive mode is opened. **hsh** Will be using the following prompt `^-^ `.

Example:
```
$./hsh
^-^
```

If a command line argument is invoked, **hsh** will take that first argument as a file from which to read commands.

Example:
```
$ cat text
echo 'alx'
$ ./hsh text
'alx'
$
```

### Environment

Upon invocation, **hsh** receives and copies the environment of the parent process in which it was executed. This environment is an array of *name-value* strings describing variables in the format *NAME=VALUE*. A few key environmental variables are:

# List of allowed functions and system calls
access (man 2 access)
chdir (man 2 chdir)
close (man 2 close)
closedir (man 3 closedir)
execve (man 2 execve)
exit (man 3 exit)
_exit (man 2 _exit)
fflush (man 3 fflush)
fork (man 2 fork)
free (man 3 free)
getcwd (man 3 getcwd)
getline (man 3 getline)
getpid (man 2 getpid)
isatty (man 3 isatty)
kill (man 2 kill)
malloc (man 3 malloc)
open (man 2 open)
opendir (man 3 opendir)
perror (man 3 perror)
read (man 2 read)
readdir (man 3 readdir)
signal (man 2 signal)
stat (__xstat) (man 2 stat)
lstat (__lxstat) (man 2 lstat)
fstat (__fxstat) (man 2 fstat)
strtok (man 3 strtok)
wait (man 2 wait)
waitpid (man 2 waitpid)
wait3 (man 2 wait3)
wait4 (man 2 wait4)
write (man 2 write)

#### exit
  * Usage: `exit [STATUS]`
  * Exits the shell.
  * The `STATUS` argument is the integer used to exit the shell.
  * If no argument is given, the command is interpreted as `exit 0`.

Example:
```
$ ./hsh
$ exit
```

#### env
  * Usage: `env`
  * Prints the current environment.

Example:
```
$ ./hsh
$ env
NVM_DIR=/home/vagrant/.nvm
...
```

#### setenv
  * Usage: `setenv [VARIABLE] [VALUE]`
  * Initializes a new environment variable, or modifies an existing one.
  * Upon failure, prints a message to `stderr`.

Example:
```
$ ./hsh
$ setenv NAME Alx
$ echo $NAME
Alx
```

#### unsetenv
  * Usage: `unsetenv [VARIABLE]`
  * Removes an environmental variable.
  * Upon failure, prints a message to `stderr`.

Example:
```
$ ./hsh
$ setenv NAME Alx
$ unsetenv NAME
$ echo $NAME

$
```

## Authors & Copyrights

* ALIYU AHMAD <[DEVHYDAR01](https://github.com/DEVHYDAR01)>
* MARWAN MAI <[Mf4z](emef4z@gmail.com)> ## More info.

**hsh** is a simple shell unix command interpreter that is part of the alx low level programming module at Alx Africa and is intended to emulate the basics **sh** shell. All the information given in this README is based on the **hsh** and **bash** man (1) pages.
