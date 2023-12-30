# DS-ToolBox

DS-ToolBox is a C++ project that provides implementations of queue and stack data structures using different underlying data structures. It offers flexibility in choosing between a linked list-based implementation and an array-based implementation for both the queue and stack.

## Features

- `clsMyQueue`: A queue implementation using a doubly linked list as the underlying data structure.
- `clsMyQueueArr`: A queue implementation using a dynamic array as the underlying data structure.
- `clsMyStack`: A stack implementation derived from `clsMyQueue`, utilizing a linked list.
- `clsMyStackArr`: A stack implementation derived from `clsMyQueueArr`, utilizing a dynamic array.
- `clsDblLinkedList`: A doubly linked list implementation.
- `clsDynamicArray`: A dynamic array implementation.

## Usage

To use the DS-ToolBox library in your C++ project, follow these steps:

1. Clone or download the repository to your local machine.

2. Include the necessary header files in your source code:

   - #include "clsMyQueue.h"         // For linked list-based queue
   - #include "clsMyQueueArr.h"      // For array-based queue
   - #include "clsMyStack.h"         // For linked list-based stack
   - #include "clsMyStackArr.h"      // For array-based stack
   - #include "clsDblLinkedList.h"   // For doubly linked list
   - #include "clsDynamicArray.h"    // For dynamic array

3. Create objects of the desired data structures and use their member functions according to your requirements.
