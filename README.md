# sorting-via-linked-list
This program receives arguments supplied by the user and sorts them using a linked list.

### Overview

This project consists of several components that provide functionalities related to strings, sorting, and linked lists. Below are the main components:

    linked_list.c
        This component provides the implementation of a doubly linked list data structure.

    node.c
        This component provides the basic structure of a node in linked list.

    lowercase.c
        This component contains a program that takes a list of strings as command-line arguments, converts them to lowercase, and prints the modified strings.

    mystring.c
        This component provides utility functions for string manipulation.

    sortargs.c
        This component demonstrates how to use the linked list to sort command-line arguments alphabetically. 

### Usage

This program is designed to work in a Linux environment. To build, run the commands:

    cd <repository's directory> 
    make

To run the program, use the following command:

Lowercase.c:

    ./lowercase arg1 Arg2 ArG3

This will output:

    Raw arguments    :  "arg1", "arg2", "arg3"

Sortargs.c:

    ./sortargs arg3 arg1 ArG2

This will output:

    ["arg3"]
    ["arg1", "arg3"]
    ["arg1", "arg2", "arg3"]


### Author:

Aleksandra Dubrovina

### Contact

For inquiries or feedback, please contact aleks.dubrovina@gmail.com.
