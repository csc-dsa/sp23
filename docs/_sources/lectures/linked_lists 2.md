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

<style>
  .red {color:red}
  .blue {color:#7cc7f9}
  .dblue {color:#011636}
  .green {color:green}
  .orange {color:orangered}
  .purple {color:purple}
  .brown {color:brown}
  iframe {width: 100%; height: 800px}
</style>

# Linked Lists

```` {div} full-width
``` {image} https://i1.faceprep.in/Companies-1/types-of-linked-list.png
```
````

## Background

`````````` {div} full-width
````` {card}

```` {admonition} 🐍 Timing Sample
:class: tip

```python
import time

n =- 100000

start  = time.time()
array = []
for i in range(n):
  array.append('s')
print(time.time() - start)

start  = time.time()
array = []
for i in range(n):
  array = array + ['s']
print(time.time() - start)
```

````

```` {admonition} How are lists implemented in CPython

CPython’s lists are really variable-length arrays, not Lisp-style linked lists. The implementation uses a contiguous array of references to other objects, and keeps a pointer to this array and the array’s length in a list head structure.

This makes indexing a list $a[i]$ an operation whose cost is independent of the size of the list or the value of the index.

When items are appended or inserted, the array of references is resized. Some cleverness is applied to improve the performance of appending items repeatedly; when the array must be grown, some extra space is allocated so the next few times don’t require an actual resize.

<i><b>CPython</b> is the reference implementation of the Python programming language</i>
````

`````
``````````

## Some STL Containers

### Sequence Containers

`````````` {div} full-width
````` {card}

**Sequence containers maintain the ordering of inserted elements that you specify.** 


```` {admonition} Array

...has some of the strengths of `vector`, but the length isn't as flexible. For more information, see array Class.

``` {code-block} cpp
:lineno-start: 1
:emphasize-lines:

#include <string>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <array>

int main()
{
  // construction uses aggregate initialization
  std::array<int, 3> a1{ {1, 2, 3} }; // double-braces required in C++11 prior to
  // the CWG 1270 revision (not needed in C++11 after the revision and in C++14 and beyond)
  std::array<int, 3> a2 = {1, 2, 3};  // double braces never required after =

  std::array<std::string, 2> a3 = { std::string("a"), "b" };
  // container operations are supported
  std::sort(a1.begin(), a1.end());
  std::reverse_copy(a2.begin(), a2.end(), std::ostream_iterator<int>(std::cout, " "));

  std::cout << '\n';
  // ranged for loop is supported
  for(const auto& s: a3)
      std::cout << s << ' ';
  // deduction guide for array creation (since C++17)
  [[maybe_unused]] std::array a4{3.0, 1.0, 4.0};  // -> std::array<double, 3>
}
```

[link: cppreference](https://en.cppreference.com/w/cpp/container/array)
````

```` {admonition} Vector

...behaves like an array, but can automatically grow as required. It is random access and contiguously stored, and length is highly flexible. For these reasons and more, vector is the preferred sequence container for most applications. When in doubt as to what kind of sequence container to use, start by using a vector!

``` {code-block} cpp
:lineno-start: 1
:emphasize-lines:

#include <iostream>
#include <vector>

int main()
{
  // Create a vector containing integers
  std::vector<int> v = { 7, 5, 16, 8 };

  // Add two more integers to vector
  v.push_back(25);
  v.push_back(13);

  // Print out the vector
  std::cout << "v = { ";
  for (int n : v) {
      std::cout << n << ", ";
  }
  std::cout << "}; \n";

}
```

[link: cppreference](https://en.cppreference.com/w/cpp/container/vector)
````

```` {admonition} forward-list

...is a singly linked list—the forward-access version of list.

``` {code-block} cpp
:lineno-start: 1
:emphasize-lines:

#include <forward_list>  
#include <iostream>

int main() {

  std::forward_list<int> numbers;
  std::cout << "Initially, numbers.empty(): " << numbers.empty() << '\n';  
  numbers.push_front(42);
  numbers.push_front(13317);
  std::cout << "After adding elements, numbers.empty(): " << numbers.empty() << '\n';

}
```

[link: cppreference](https://en.cppreference.com/w/cpp/container/forward_list)
````

```` {admonition} list

...is a doubly linked list that enables bidirectional access, fast insertions, and fast deletions anywhere in the container, but you can't randomly access an element in the container.

``` {code-block} cpp
:lineno-start: 1
:emphasize-lines:

#include <algorithm>
#include <iostream>
#include <list>

int main()
{
  // Create a list containing integers
  std::list<int> l = { 7, 5, 16, 8 };

  // Add an integer to the front of the list
  l.push_front(25);
  l.push_back(13);

  // Insert an integer before 16 by searching
  auto it = std::find(l.begin(), l.end(), 16);
  if (it != l.end())
      l.insert(it, 42);

  // Print out the list
  std::cout << "l = { ";
  for (int n : l)
      std::cout << n << ", ";
  std::cout << "};\n";

}
```

[link: cppreference](https://en.cppreference.com/w/cpp/container/list)
````

[https://learn.microsoft.com/en-us/cpp/standard-library/stl-containers?view=msvc-170](https://learn.microsoft.com/en-us/cpp/standard-library/stl-containers?view=msvc-170)

`````
``````````

## Linked Lists

### Arrays

`````````` {div} full-width
````` {card}

```` {card}
Think about making **insertions** and **deletions** efficiently...

What is the computational cost of inserting or deleting 1 element?

- **rear?**
- <b class="red">front?</b>
- <b class="red">middle?</b>

ptr
$\Downarrow$

``` {figure} imgs/07_s12.png
```

````

`````
``````````

### Linked Lists

`````````` {div} full-width
```` {card}
``` {card}
Collections of sequential elements stored at <b class="orange">non-contiguous</b> locations in memory

Elements are stored in <b class="green">nodes</b>

Nodes are connected by <b class="green">links</b>

- every node keeps a pointer to the next node

Can **grow** and **shrink** dynamically

Allow for fast insertions/deletions
```
````
``````````

## Singly Linked List

`````````` {div} full-width
````` {card}
```` {card}

``` {figure} https://media.geeksforgeeks.org/wp-content/uploads/20220816144425/LLdrawio.png
```

``` {note}
Node Left: **data**  
Node Right: **memory location of next element in LL**
```
````
`````
``````````

### Pseudo-implementation

`````````` {div} full-width
`````` {card}

````` {grid}

```` {grid-item-card}

```cpp
int main() {
  List mylist;  
  mylist.insert_end(10);  
  mylist.insert_end(20);  
  mylist.insert_end(30);
}
```

````

```` {grid-item-card}

``` {figure} imgs/07_s14.png
```

````

`````

``````
``````````

### Operations on Linked Lists

`````````` {div} full-width
```` {card}

``` {card} Linked lists are just *_collections_* of sequential data

can <b class="blue">insert</b> 1 or more elements  
    - <span class="green">_front, end, by index, by value (sorted lists)_</span>  

can <b class="blue">delete</b> 1 or more elements  
    - <span class="green">_front, end, by index, by value_</span>  

can <b class="blue">search</b> for a specific element  

can <b class="blue">get</b> an element at a given index  

can <b class="blue">traverse</b> the list  
    - <span class="green">visit all nodes and perform an operation (e.g. print or destroy)</span>
```

````
``````````

### Implementing a Singly Linked List


`````````` {div} full-width

````` {card} Linked lists in C++

```` {admonition} Prerequisites
:class: warning

``` {card} C++ Classes
```

``` {card} Pointers
- `NULL` pointers
```

``` {card} Dynamic Memory Allocation
- `new`
- `delete`
```

``` {card} Pointers and Classes
- dot notation (`.`)
- arrow notation (`->`)
```

````

`````
``````````

### Creating a Linked List

`````````` {div} full-width
`````` {card}

````` {grid}

```` {grid-item-card} 

class `Node`

``` {code-block} cpp
:lineno-start: 1
:emphasize-lines:

class Node
{
    private:
        int data;
        Node *next;
        // private data/methods
        // ...

    public:
        Node (int d);
        ~Node();

        Friend class List;
};
```

````

```` {grid-item-card} 

class `List`

``` {code-block} cpp
:lineno-start: 1
:emphasize-lines:

class List
{
  private:
    Node *head;
    Node *tail;
    // private data/methods
    // ...

  public:
    List();
    ~List();
    // public methods
    // ...
};
```

````

[https://www.geeksforgeeks.org/what-is-linked-list/](https://www.geeksforgeeks.org/what-is-linked-list/)

`````

``````
``````````

### `insert`

`````````` {div} full-width
`````` {card}

````` {admonition} Append: insert at end

```` {card}

``` {figure} https://media.geeksforgeeks.org/wp-content/cdn-uploads/gq/2013/03/Linkedlist_insert_last.png
```

``` {code-block} cpp
:lineno-start: 1
:emphasize-lines:

// Given a reference (pointer to pointer) to 
// the head of a list and an int, appends a 
// new node at the end
void insertTail(Node** head_ref, int new_data)
{
  Node* new_node = new Node();
  Node *last = *head_ref;
  new_node->data = new_data;
  new_node->next = NULL;
  if (*head_ref == NULL) {
    *head_ref = new_node;
    return;
  }
  while (last->next != NULL) {
    last = last->next;
  }
  last->next = new_node;
  return;
}
```

[https://www.geeksforgeeks.org/linked-list-set-2-inserting-a-node/](https://www.geeksforgeeks.org/linked-list-set-2-inserting-a-node/)

````

`````

````` {admonition} Prepend: insert at front

```` {card}

``` {figure} https://media.geeksforgeeks.org/wp-content/cdn-uploads/gq/2013/03/Linkedlist_insert_at_start.png
```

``` {code-block} cpp
:lineno-start: 1
:emphasize-lines:

void insertHead(Node** head_ref, int new_data)
{
  Node* new_node = new Node();
  new_node->data = new_data;
  new_node->next = (*head_ref);
  (*head_ref) = new_node;
}
```

[https://www.geeksforgeeks.org/linked-list-set-2-inserting-a-node/](https://www.geeksforgeeks.org/linked-list-set-2-inserting-a-node/)

````

````` 

````` {admonition} by index

```` {card}

``` {figure} https://media.geeksforgeeks.org/wp-content/cdn-uploads/gq/2013/03/Linkedlist_insert_middle.png
```

``` {code-block} cpp
:lineno-start: 1
:emphasize-lines:

int insertAtIdx(Node* head, int index, int new_data) {
    Node* current = head;
    Node* prev_node;
    
    int count = 0;
    while (current != NULL) {
      if (count == index) {
        Node* new_node = new Node();
        new_node->data = new_data;
        new_node->next = prev_node->next;
        prev_node->next = new_node;
        return (current->data);
      }
      count++;
      prev_node = current;
      current = current->next;
    }
    assert(0);
}
```

[https://www.geeksforgeeks.org/linked-list-set-2-inserting-a-node/](https://www.geeksforgeeks.org/linked-list-set-2-inserting-a-node/)

````

`````

``````
``````````

### `delete`

`````````` {div} full-width
````` {card}

```` {admonition} Delete: at front

``` {figure} https://iq.opengenus.org/content/images/2018/08/delete_first_ll.jpg
```

``` {code-block} cpp
:lineno-start: 1
:emphasize-lines:

void deleteHead(Node** head_ref)
{

  // Store head node
  Node* temp = *head_ref;
  Node* prev = NULL;

  // If head node itself holds
  // the key to be deleted
  if (temp != NULL) {

  // Changed head
    *head_ref = temp->next;

  // free old head
    delete temp;
    return;
  }
}
```

[https://www.geeksforgeeks.org/linked-list-set-3-deleting-node/?ref=lbp](https://www.geeksforgeeks.org/linked-list-set-3-deleting-node/?ref=lbp)

````

```` {admonition} Delete: at end

``` {figure} https://static.javatpoint.com/ds/images/deleting-a-node-from-the-last.png
```

``` {code-block} cpp
:lineno-start: 1
:emphasize-lines:

void deleteTail(Node** head){
  Node* prev = NULL;
  Node* temp = *head;
  while(temp->next!=NULL){
    prev = temp;
    temp = temp->next;
  }
  delete temp;
  prev->next = NULL;
  return;
}
```

[https://www.tutorialspoint.com/delete-a-tail-node-from-the-given-singly-linked-list-using-cplusplus](https://www.tutorialspoint.com/delete-a-tail-node-from-the-given-singly-linked-list-using-cplusplus)

````

```` {admontion} Delete: at value

``` {figure} https://media.geeksforgeeks.org/wp-content/cdn-uploads/gq/2014/05/Linkedlist_deletion.png
```

``` {code-block} cpp
:lineno-start: 1
:emphasize-lines:

void deleteNode(Node** head_ref, int key)
{

  Node* temp = *head_ref;
  Node* prev = NULL;

  if (temp != NULL && temp->data == key) {
    *head_ref = temp->next;
    delete temp;
    return;
  }
  else {
    while (temp != NULL && temp->data != key) {
      prev = temp;
      temp = temp->next;
    }
    if (temp == NULL)
      return;
    prev->next = temp->next;
    delete temp;
  }
}
```

[https://www.geeksforgeeks.org/linked-list-set-3-deleting-node/](https://www.geeksforgeeks.org/linked-list-set-3-deleting-node/)

````

```` {admonition} Delete: at index

``` {figure} https://media.geeksforgeeks.org/wp-content/cdn-uploads/gq/2014/05/Linkedlist_deletion.png
```

``` {code-block} cpp
:lineno-start: 1
:emphasize-lines:

void deleteByPos(Node** head_ref, int position)
{
    if (*head_ref == NULL)
        return;
    Node* temp = *head_ref;
    if (position == 0) {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    for (int i = 0; temp != NULL && i 
               < position - 2; i++)
        temp = temp->next;
    if (temp == NULL || temp->next == NULL)
        return;
    Node* next = temp->next->next;
    free(temp->next); // Free memory
    temp->next = next;
}
```

[https://www.geeksforgeeks.org/delete-a-linked-list-node-at-a-given-position/](https://www.geeksforgeeks.org/delete-a-linked-list-node-at-a-given-position/)

````

`````
``````````

### `get`

`````````` {div} full-width
````` {card}

```` {admonition} get

``` {code-block} cpp
:lineno-start: 1
:emphasize-lines:

int getNth(Node* head, int index)
{
  Node* current = head;

  int count = 0;
  while (current != NULL) {
    if (count == index)
      return (current->data);
    count++;
    current = current->next;
  }

  assert(0);
}
```

[https://www.geeksforgeeks.org/write-a-function-to-get-nth-node-in-a-linked-list/](https://www.geeksforgeeks.org/write-a-function-to-get-nth-node-in-a-linked-list/)

````

`````
``````````

### `search`

`````````` {div} full-width
````` {card}

```` {admonition} search

``` {code-block} cpp
:lineno-start: 1
:emphasize-lines:

bool search(Node* head, int x)
{
  Node* current = head; // Initialize current
  while (current != NULL) {
    if (current->data == x)
      return true;
    current = current->next;
  }
  return false;
}
```

[https://www.geeksforgeeks.org/search-an-element-in-a-linked-list-iterative-and-recursive/](https://www.geeksforgeeks.org/search-an-element-in-a-linked-list-iterative-and-recursive/)

````

`````
``````````

### `destroy`

`````````` {div} full-width
````` {card}

```` {admonition} destroy

``` {code-block} cpp
:lineno-start: 1
:emphasize-lines:

void destroyList(Node** head_ref)
{

  Node* current = *head_ref;
  Node* next = NULL;

  while (current != NULL)
  {
    next = current->next;
    free(current);
    current = next;
  }

  *head_ref = NULL;
}
```

[https://www.geeksforgeeks.org/write-a-function-to-delete-a-linked-list/](https://www.geeksforgeeks.org/write-a-function-to-delete-a-linked-list/)

````

`````
``````````

### `traverse`

`````````` {div} full-width
````` {card}

```` {admonition} traverse

``` {code-block} cpp
:lineno-start: 1
:emphasize-lines:

void printList(Node* node)
{
  while (node != NULL)
  {
    cout << node->data << "->";
    node = node->next;
  }
  cout << "NULL" << endl;
}
```

[https://www.geeksforgeeks.org/what-is-linked-list/?ref=lbp](https://www.geeksforgeeks.org/what-is-linked-list/?ref=lbp)

````

`````
``````````

## Circular Singly Linked List

`````````` {div} full-width
````` {card}

```` {admonition} Creating Nodes

``` {figure} https://media.geeksforgeeks.org/wp-content/uploads/20220817185024/CircularSinglyLinkedList.png
```

``` {code-block} cpp
:lineno-start: 1
:emphasize-lines:

// Initialize the Nodes.
Node one = new Node(3);         // head
Node two = new Node(5);
Node three = new Node(9);       // tail

// Connect nodes
one.next = two;
two.next = three;
three.next = one;
```

[https://www.geeksforgeeks.org/circular-linked-list/?ref=lbp](https://www.geeksforgeeks.org/circular-linked-list/?ref=lbp)

````

`````
``````````

## Doubly Linked List

`````````` {div} full-width
````` {card}

```` {admonition} Creating Nodes

``` {figure} https://media.geeksforgeeks.org/wp-content/cdn-uploads/gq/2014/03/DLL1.png
```

``` {code-block} cpp
:lineno-start: 1
:emphasize-lines:

// Node of a doubly linked list
class Node {
public:
    int data;

    // Pointer to next node in DLL
    Node* next;

    // Pointer to previous node in DLL
    Node* prev;
};
```

[https://www.geeksforgeeks.org/doubly-linked-list/?ref=lbp](https://www.geeksforgeeks.org/doubly-linked-list/?ref=lbp)

````

`````
``````````

## Circular Doubly Linked List

`````````` {div} full-width
````` {card}

```` {admonition} Creating Nodes

``` {figure} https://media.geeksforgeeks.org/wp-content/uploads/20220830114920/doubly.jpg
```

[https://www.geeksforgeeks.org/doubly-circular-linked-list-set-1-introduction-and-insertion/](https://www.geeksforgeeks.org/doubly-circular-linked-list-set-1-introduction-and-insertion/)

````

`````
``````````
