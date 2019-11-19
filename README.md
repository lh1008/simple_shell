# 0x16. C - Simple Shell

The main objective of this project is to write a simple UNIX command interpreter shell. The shell is a _command line interpreter **software**_ used to communicate with the operating system services. The actual simple shell you will find in this repository is meant to be runned in a UNIX-like operating systems or Ubuntu 14.04 LTS, which was the one we used to build it.  

## Introduction

The command line interpreter shell in this proyect is known as the CLI shell. Due to the text-only nature of the CLI shell, the shell takes alphanumeric characters to form a set of instructions/data for the operating system. The shell parses the input given and executes the command if the command exists in you local machine. Some examples of commands lines commands; cd, mkdir, ls, mv, cat, less, etc.  

Commands are built-in or external instructions given to the machine to do something such as running a program or executing an action inside the operating system like copying a file to a different directory or changing a files name. The shell is the program that reads the commands typed as input in the machine and then executes/runs them. A shell script is a program allowing the user to execute any commbination of commands.  

Shell scripts contain system calls. System calls are basically assembly language instructions to communicate directly with the kernel. When a system call is executed/called you pass from user mode to kernel mode or priviledged mode. In priviledged mode you have direct access to the kernel. Systems calls are usually made when a process in user mode requires access to a resource or a machine service. A process is simply the name for a program that´s beeing executed. UNIX-like operating systems uses processes to determine the actions taken inside the machine.  

Types of system calls:  

- Process Control: `fork()`, `exit()`, `wait()`, etc.
- File Management: `open()`, `read()`, `write()`, `close()`, etc.
- Device Management: `read()`, `write()`, `ioctl()`, etc.
- Information Maintainance: `getpid()`, `alarm()`, `sleep()`, etc.
- Communication: `pipe()`, `shmget()`, `mmap()`, etc.

Now you have a general idea of what a shell does, it´s time to get started. 

### Getting Started

In the repository you will find instructions and a copy of the files you will need to use to set up the _Simple Shell_ in your local machine for development and testing purposes.

### Prerequisites

> UNIX-like operating system or Ubuntu 14.04 LTS.
> `gcc`latest version. Recommended version 4.8.4

### Installing

Fork the repository to your local github profile. Git clone to your local machine:

> git clone https://github.com/JamesPagani/simple_shell.git
> git clone https://github.com/lh1008/simple_shell.git

### Running Tests

### Contributing

If you would like to contribute to the project please submit a pull request (PR).

### Version

Simple Shell v0.1.0

### Authors

- **Jaime Andrés Gálvez Villamarin** <1167@holbertonschool.com>
- **Luis Alejandro Herrera Bolaños** <1209@holbertonschool.com>

### License

[GNU General Public License](https://www.gnu.org/licenses/gpl-3.0.html)

### Acknowledgements

This project is an inspiration of Holberton School.
