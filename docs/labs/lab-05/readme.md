# Lab 5 - Priority Queues!


### Background Info

Priority Queues are a special form of queue that allow for "cutting in line". This is beneficial when you want to want to enforce a FIFO (first in first out) ordering schema while also allowing more important entries to have priority.

#### Linked List

We'll be using Linked Lists as our base today. We are familiar with the Node & LinkedList classes as well as how they behave together from Lab 4.

Node objects store Data & a reference to the next Node in the list. The LinkedList maintains a pointer to the first Node in the list ("head") and contains all of the operations that can be performed on the list. LinkedLists can also contain a "tail" pointer that points to the last element in the list.

``` {image} https://lh3.googleusercontent.com/-IypOlVgxKfM/YJH5hSShQVI/AAAAAAAAATk/KfjrbvbLe_cgOz7zAW1oOAsOAwlU0rPcACLcBGAsYHQ/w1200-h630-p-k-no-nu/image.png
:align: center
```

#### Queue

As a refresher, a Queue is a Linked List with an enforced add/remove order: first-in first-out (FIFO). Elements added to the Queue (enqueued) are placed at the back, and we can only ever remove (dequeue) from the front.

``` {image} https://media.geeksforgeeks.org/wp-content/uploads/20220816162225/Queue.png
:align: center
```

  How is this different from a stack? Remember stacks function like a stack of pancakes where to eat a pancake the top one is pulled off - not the bottom pancake - not the middle one. To add more pancakes on the stack, you place them on the top.
  > If you don't eat your pancakes this way please disregard this analogy; and maybe seek help.

  Try to come up with a real world example of a queue with your group and write it as a comment on the top of your main file.

#### Priority Queue

As you may suspect, a priority queue's roots lies in the Queue data structure, which we have previously seen as a special Linked List.

``` {image} https://mulesoftonlinelearninghome.files.wordpress.com/2019/12/priority-queue-data-structure.jpg
:align: center
```

The Priority Queue has the same properties as the Queue in addition to the following:

- Every element has an associated priority
- Elements with a high priority are dequeued before an element with a lower priority
- Any elements with matching priorities are dequeued in the order they arrived

Lets compare the performance of a Queue with a Priority Queue:

|         | Queue | Enqueue |
| :-----: | :---: | :-----: |
| Enqueue | O(1)  |  O(n)   |   <----
| Dequeue | O(1)  |  O(1)   |
|  Peek   | O(1)  |  O(1)   |

They are very similar, but Enqueue jumps from a constant time operation to a linear time operation. Yikes!

**Why might this be?**

``` {admonition} Click here to reveal the answer!
:class: dropdown tip
To insert elements into a P-Queue, we must iterate over the queue until we find the proper location. Worst cast would be adding an element with the lowest priority, so we would need to traverse the entire list.
```

But fret not, there is a better way to implement a Priority Queue! But we'll learn about those next week.

### Your Task

You are given code for a working Linked List in the "lab 4 solution" folder and are tasked with modifying it to be a Queue, then a Priority Queue.

Hint: Add a `tail` pointer to your Queue in order to make the `enqueue` operation more efficient! This is not needed for PriorityQueue, however.


1. Go through **all** of the classes & functions you will need to change and write comments explaining what needs changing for both problems below.
   - Reading through the code first and modifying it second will save you lots of time and confusion! See what you are working with before totally rewriting functions that are already there.
   - **If you ask a TA for help with a function that has not been commented with proposed changes, we will not help you.**
2. Convert the Linked List code into a Queue class (you will not need every linked list member function reimplemented in the queue class!) 
   - The bulk of the work will be in ensuring you have an `enqueue` function that will push a new element to the back of the queue, a `dequeue` function that will remove an element from the front of the queue, as well as a `peek` function that returns the element at the front of the queue.
3. Copy the code for your Queue program into another project and convert it into a Priority Queue. 
   - The hint for adding the priority queue functionality is to add a priority variable to the node class. This way the queue can check each Node object's priority value for comparisons when enqueing elements.

#### Requirements

Your program will read in the name of a file via CLA.

The first line in the file will control which constructor will be used (similar to Lab 4). Examine the constructor declarations to determine the possible cases you will need to check for.

After the first line is read, the rest of the file will contain a series of commands, 1 per line, that must be followed:

- An integer ([-99, 99])
  - Triggers an `enqueue`
- A minus sign ('-')
  - Triggers a `dequeue`
- A question mark ('?')
  - Triggers a `peek`

After each command is read and executed, print out the list **if there have been any changes**. For `peek` calls, print the value the function returns.

Here are the file contents for **text1.txt**:

```
-19 -28 -1 18 -50 -43 18 41 18 -86
-83
-25
-
-
31
-96
-97
?
-82
-
```

This is the output for **test1.txt** with the **Queue**:

```
-19 -28 -1 18 -50 -43 18 41 18 -86
-19 -28 -1 18 -50 -43 18 41 18 -86 -83
-19 -28 -1 18 -50 -43 18 41 18 -86 -83 -25
-28 -1 18 -50 -43 18 41 18 -86 -83 -25
-1 18 -50 -43 18 41 18 -86 -83 -25
-1 18 -50 -43 18 41 18 -86 -83 -25 31
-1 18 -50 -43 18 41 18 -86 -83 -25 31 -96
-1 18 -50 -43 18 41 18 -86 -83 -25 31 -96 -97
-1
-1 18 -50 -43 18 41 18 -86 -83 -25 31 -96 -97 -82
18 -50 -43 18 41 18 -86 -83 -25 31 -96 -97 -82
```

Here are the file contents for **test7.txt**:

```
0 76 -32 -73 -64 -8 38 -97 99 5
-30 2
61 3
5 3
-98 0
-57 8
-
-60 7
-
-75 2
?
```

This is the output for **PriorityQueue** with **test7.txt**

```
(0,0) (76,1) (-32,2) (-73,3) (-64,4) (-8,5) (38,6) (-97,7) (99,8) (5,9)
(0,0) (76,1) (-32,2) (-30,2) (-73,3) (-64,4) (-8,5) (38,6) (-97,7) (99,8) (5,9)
(0,0) (76,1) (-32,2) (-30,2) (-73,3) (61,3) (-64,4) (-8,5) (38,6) (-97,7) (99,8) (5,9)
(0,0) (76,1) (-32,2) (-30,2) (-73,3) (61,3) (5,3) (-64,4) (-8,5) (38,6) (-97,7) (99,8) (5,9)
(0,0) (-98,0) (76,1) (-32,2) (-30,2) (-73,3) (61,3) (5,3) (-64,4) (-8,5) (38,6) (-97,7) (99,8) (5,9)
(0,0) (-98,0) (76,1) (-32,2) (-30,2) (-73,3) (61,3) (5,3) (-64,4) (-8,5) (38,6) (-97,7) (99,8) (-57,8) (5,9)
(-98,0) (76,1) (-32,2) (-30,2) (-73,3) (61,3) (5,3) (-64,4) (-8,5) (38,6) (-97,7) (99,8) (-57,8) (5,9)
(-98,0) (76,1) (-32,2) (-30,2) (-73,3) (61,3) (5,3) (-64,4) (-8,5) (38,6) (-97,7) (-60,7) (99,8) (-57,8) (5,9)
(76,1) (-32,2) (-30,2) (-73,3) (61,3) (5,3) (-64,4) (-8,5) (38,6) (-97,7) (-60,7) (99,8) (-57,8) (5,9)
(76,1) (-32,2) (-30,2) (-75,2) (-73,3) (61,3) (5,3) (-64,4) (-8,5) (38,6) (-97,7) (-60,7) (99,8) (-57,8) (5,9)
(76,1)
```

-----

## Submission

Submit the following files to Gradescope:

- main.cpp
- queue.cpp
- node.cpp
- main_2.cpp
- priority_queue.cpp
- priority_node.cpp

**Note: You must submit all 6 files every time in order for Gradescope to run.**