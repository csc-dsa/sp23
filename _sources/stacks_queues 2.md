---
jupytext:
  cell_metadata_filter: -all
  formats: md:myst
  text_representation:
    extension: .md
    format_name: myst
    format_version: 0.13
    jupytext_version: 1.11.5
kernelspec:
  display_name: Python 3
  language: python
  name: python3
---

# Stacks and Queues

{sub-ref}`today` | {sub-ref}`wordcount-words` words | {sub-ref}`wordcount-minutes` min read

<hr>

## Overview

Stacks and queues are the simplest of structures to work with. The two are very similar in nature and can often be used interchangeably, pending use case. Where they deviate is in access to the items held within. Stacks allow for items to be entered and retrieved from only one end of the structure called the `tail`. [Think a stack of pancakes...you can only remove the top one easily, without 'damaging' the ones beneath.] Queues, however, are able to work with data from both the `head` and the `tail`. [Think a line at the grocery store...you enter a line (queue) from one end (`tail`) and exit from the other end (`head`)].

## Stacks

_LIFO: Last in, First out..._

![](https://cdn.programiz.com/cdn/farfuture/SeMlTJWTrNJNYBgzQihno5hlAOh5TSF6lygYj3DFNY8/mtime:1651491298/sites/tutorial2program/files/cpp-stack.png)

Stacks live by this rule. As we consider the mechanics of a stack we realize as we add more and more items to our stack two things are inevitable: 1) to keep the stack upright, we must never access any item below the `top` item. The top being the item at the very end of the `tail`, 2) If we try to remove items from beneath the `top`, the process will more than likely corrupt items above and below the item attempting to be retrieved.

````{admonition} Syntax
```{code-block} c++
---
caption: https://www.programiz.com/cpp-programming/stack
emphasize-lines: 2,6,9,12
lineno-start: 1
---
// Include stack header file
#include <stack>

// create a stack of strings
// type == data type
stack<type> st;
    
// create a stack of integers
stack<int> integer_stack;

// create a stack of strings
stack<string> string_stack;
````

### Stack Methods

Various built-in methods already exist within the Stack class...

| Operation | Description |
| :--: | --:
| `push()` | adds an element into the stack |
| `pop()` |cremoves an element from the stack |
| `top()` | returns the element at the top of the stack |
| `size()` | returns the number of elements in the stack |
| `empty()` | returns true if the stack is empty |

### Stack Examples

The following exemplify different applications of the methods above to receive a desired output...

:::{admonition} General use
`````{tabbed} STL Stack
````{code-block} c++
---
caption: |  
    _Create a stack, add values, and retreive `tail` value_  
    https://www.programiz.com/cpp-programming/stack
emphasize-lines: 2,8
lineno-start: 1
---
#include <iostream>
#include <stack>
using namespace std;

int main() 
{
    // create a stack of strings
    stack<string> languages;
    
    // add element to the Stack
    languages.push("Java");
    languages.push("Python");
    languages.push("C++");
    
    // print top element
    cout << languages.top();

    return 0;
}
````  

````{toggle}
```{code-block}
---
caption: _Output_
---
C++
```
````
`````

`````{tabbed} Add element
````{code-block} c++
---
caption: |  
    _Add Element Into the Stack_  
    https://www.programiz.com/cpp-programming/stack
emphasize-lines: 11-12
lineno-start: 1
---
#include <iostream>
#include <stack>
using namespace std;

int main() {

  // create a stack of strings
  stack<string> colors;

  // push elements into the stack
  colors.push("Red");
  colors.push("Orange");
  
  cout << "Stack: ";

  // print elements of stack
   while(!colors.empty()) {
    cout << colors.top() << ", ";
    colors.pop();
  }
 
  return 0;
}
````  

````{toggle}
```{code-block}
---
caption: _Output_
---
Stack: Orange, Red, 
```
````
`````

`````{tabbed} Remove element
````{code-block} c++
---
caption: |  
    _Add Element Into the Stack_  
    https://www.programiz.com/cpp-programming/stack
emphasize-lines: 23,38
lineno-start: 1
---
#include <iostream>
#include <stack>
using namespace std;

// function prototype for display_stack utility
void display_stack(stack<string> st);

int main() {

  // create a stack of strings
  stack<string> colors;

  // push elements into the stack
  colors.push("Red");
  colors.push("Orange");
  colors.push("Blue");
  
  cout << "Initial Stack: ";
  // print elements of stack
  display_stack(colors);
  
  // removes "Blue" as it was inserted last
  colors.pop();
  
  cout << "Final Stack: ";

  // print elements of stack
  display_stack(colors);
  
  return 0;
}

// utility function to display stack elements
void display_stack(stack<string> st) {

  while(!st.empty()) {
    cout << st.top() << ", ";
    st.pop();
  }

  cout << endl;
}
````  

````{toggle}
```{code-block}
---
caption: _Output_
---
Initial Stack: Blue, Orange, Red,  
Final Stack: Orange, Red, 
```
````
`````

`````{tabbed} Access element
````{code-block} c++
---
caption: |  
    _Add Element Into the Stack_  
    https://www.programiz.com/cpp-programming/stack
emphasize-lines: 16
lineno-start: 1
---
#include <iostream>
#include <stack>
using namespace std;

int main() {

  // create a stack of strings
  stack<string> colors;

  // push element into the stack
  colors.push("Red");
  colors.push("Orange");
  colors.push("Blue");
  
  // get top element
  string top = colors.top();

  cout << "Top Element: " << top;
  
  return 0;
}
````  

````{toggle}
```{code-block}
---
caption: _Output_
---
Top Element: Blue
```
````
`````

`````{tabbed} Get size
````{code-block} c++
---
caption: |  
    _Add Element Into the Stack_  
    https://www.programiz.com/cpp-programming/stack
emphasize-lines: 16
lineno-start: 1
---
#include <iostream>
#include <stack>
using namespace std;

int main() {

  // create a stack of int
  stack<int> prime_nums;

  // push elements into the stack
  prime_nums.push(2);
  prime_nums.push(3);
  prime_nums.push(5);
  
  // get the size of the stack
  int size = prime_nums.size();
  cout << "Size of the stack: " << size;

  return 0;
}
````  

````{toggle}
```{code-block}
---
caption: _Output_
---
Size of the stack: 3  
```
````
`````

`````{tabbed} isEmpty?
````{code-block} c++
---
caption: |  
    _Add Element Into the Stack_  
    https://www.programiz.com/cpp-programming/stack
emphasize-lines: 13,29
lineno-start: 1
---
#include <iostream>
#include <stack>
using namespace std;

int main() {

  // create a stack of double
  stack<double> nums;
  
  cout << "Is the stack empty? ";

  // check if the stack is empty  
  if (nums.empty()) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }

  cout << "Pushing elements..." << endl;

  // push element into the stack
  nums.push(2.3);
  nums.push(9.7);
 
  cout << "Is the stack empty? ";

  // check if the stack is empty  
  if (nums.empty()) {
    cout << "Yes";
  }
  else {
    cout << "No";
  }

  return 0;
}
````  

````{toggle}
```{code-block}
---
caption: _Output_
---
Is the stack empty? Yes  
Pushing elements...  
Is the stack empty? No  
```
````
`````
:::

## Queues  

_FIFO: First in, first out..._

![](https://cdn.programiz.com/cdn/farfuture/G-k2Zkakc5EEO13cfz903wGw0fx-19JtasX79G1Jbow/mtime:1640863727/sites/tutorial2program/files/cpp-queue.png)

````{admonition} Syntax
```{code-block} c++
---
caption: https://www.programiz.com/cpp-programming/stack
emphasize-lines: 2,6,9,12
lineno-start: 1
---
// Include queue header file
#include <queue>

// create a queue of strings
// type == data type
queue<type> q;
    
// create a queue of integers
queue<int> integer_queue;

// create a queue of strings
queue<string> string_queue;
```
````

### Queue Methods

Various built-in methods already exist within the queue class...

| Operation | Description |
| :--: | --:
| `push()` | adds an element into the queue |
| `pop()` | removes an element from the queue |
| `front()` | returns the first element of the queue |
| `back()` | returns the last element of the queue |
| `size()` | returns the number of elements in the queue |
| `empty()` | returns `true` if the queue is empty |

### Queue Examples

::::{admonition} General use

`````{tabbed} Insert element
````{code-block} c++
---
caption: https://www.programiz.com/cpp-programming/queue
emphasize-lines: 12-13
lineno-start: 1
---
#include <iostream>
#include <queue>

using namespace std;

int main() {

  // create a queue of string
  queue<string> animals;

  // push elements into the queue
  animals.push("Cat");
  animals.push("Dog");
  
  cout << "Queue: ";

  // print elements of queue
  // loop until queue is empty
  while(!animals.empty()) {

    // print the element
    cout << animals.front() << ", ";

    // pop element from the queue
    animals.pop();
  }

  cout << endl;
 
  return 0;
}
````  

````{toggle}
```{code-block}
---
caption: _Output_
---
Queue: Cat, Dog,
```
````
`````

`````{tabbed} Remove element
````{code-block} c++
---
caption: https://www.programiz.com/cpp-programming/queue
emphasize-lines: 22,34
lineno-start: 1
---
#include <iostream>
#include <queue>
using namespace std;

// function prototype for display_queue utility
void display_queue(queue<string> q);

int main() {

  // create a queue of string
  queue<string> animals;

  // push element into the queue
  animals.push("Cat");
  animals.push("Dog");
  animals.push("Fox");
  
  cout << "Initial Queue: ";
  display_queue(animals);
  
  // remove element from queue
  animals.pop();
  
  cout << "Final Queue: ";
  display_queue(animals);
  
  return 0;
}

// utility function to display queue
void display_queue(queue<string> q) {
  while(!q.empty()) {
    cout << q.front() << ", ";
    q.pop();
  }

  cout << endl;
}
````  

````{toggle}
```{code-block}
---
caption: _Output_
---
Initial Queue: Cat, Dog, Fox,  
Final Queue: Dog, Fox,
```
````
`````

`````{tabbed} Access element
````{code-block} c++
---
caption: https://www.programiz.com/cpp-programming/queue
emphasize-lines: 16,20
lineno-start: 1
---
#include <iostream>
#include <queue>
using namespace std;

int main() {

  // create a queue of int
  queue<int> nums;

  // push element into the queue
  nums.push(1);
  nums.push(2);
  nums.push(3);
  
  // get the element at the front
  int front = nums.front();
  cout << "First element: " << front << endl;
  
  // get the element at the back
  int back = nums.back();
  cout << "Last element: " << back << endl;
  
  return 0;
}
````  

````{toggle}
```{code-block}
---
caption: _Output_
---
First element: 1  
Last element: 3
```
````
`````

`````{tabbed} Get size
````{code-block} c++
---
caption: https://www.programiz.com/cpp-programming/queue
emphasize-lines: 16
lineno-start: 1
---
#include <iostream>
#include <queue>
using namespace std;

int main() {

  // create a queue of string
  queue<string> languages;

  // push element into the queue
  languages.push("Python");
  languages.push("C++");
  languages.push("Java");
  
  // get the size of the queue
  int size = languages.size();
  cout << "Size of the queue: " << size;

  return 0;
}
````  

````{toggle}
```{code-block}
---
caption: _Output_
---
Size of the queue: 3
```
````
`````

`````{tabbed} isEmpty
````{code-block} c++
---
caption: https://www.programiz.com/cpp-programming/queue
emphasize-lines: 13,29
lineno-start: 1
---
#include <iostream>
#include <queue>
using namespace std;

int main() {

  // create a queue of string
  queue<string> languages;
  
  cout << "Is the queue empty? ";

  // check if the queue is empty  
  if (languages.empty()) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }

  cout << "Pushing elements..." << endl;

  // push element into the queue
  languages.push("Python");
  languages.push("C++");
 
  cout << "Is the queue empty? ";

  // check if the queue is empty  
  if (languages.empty()) {
    cout << "Yes";
  }
  else {
    cout << "No";
  }

  return 0;
}
````  

````{toggle}
```{code-block}
---
caption: _Output_
---
Is the queue empty? Yes  
Pushing elements...  
Is the queue empty? No  
```
````
`````
::::