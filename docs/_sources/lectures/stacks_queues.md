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

# Stacks and Queues

`````````` {div} full-width
``` {image} https://techcrunch.com/wp-content/uploads/2014/11/stacks.jpg
:align: center
```
``````````

## Stacks

`````````` {div} full-width
``````` {card} LIFO: Last In, First Out

``` {figure} imgs/08_s02.png
```

```````
``````````

### Documentation

`````````` {div} full-width

<iframe src="https://en.cppreference.com/w/cpp/container/stack" frameborder="0"></iframe>

```` {card} Example

%``` {figure} imgs/08_s04_01.png
%```

```cpp
#include <stack>
#include <iostream>

int main() {
  std::stack<int> s;
  s.push(1);
  s.push(2);
  s.push(3);
  std::cout << s.size() << " elements on stack\n";  
  std::cout << "Top element: " << s.top() << "\n";
  std::cout << s.size() << " elements on stack\n";
  s.pop();
  std::cout << s.size() << " elements on stack\n";
  std::cout << "Top element: " << s.top() << "\n";
  return 0;
}
```

%[https://en.cppreference.com/w/cpp/container/stack](https://en.cppreference.com/w/cpp/container/stack)

%``` {figure} imgs/08_s04_02.png
%```

````
``````````

### Basic Operations

`````````` {div} full-width
```` {card}

``` {figure} https://miro.medium.com/max/814/0*pdhOeAK6wSh8ipTW.png
```

``` {dropdown} push

- inserts one element onto the stack
```

``` {dropdown} pop

- returns the element at the top of the stack (and removes it)
```

``` {dropdown} isEmpty

- not necessary, but sometimes useful
```

````
``````````

### Implementation

`````````` {div} full-width
``````` {card}

```` {admonition} Arrays

- **push** and **pop** at the end of the array (easier and efficient)
- can be <span class="blue">fixed-length</span>
- can also use a <span class="blue">dynamic array</span> (grows overtime)   
  - additional cost for dynamic arrays

``` {figure} imgs/08_s05.png
:width: 92%
```

````

```` {admonition} Stack
```cpp
class Stack {
    private:
        int *array;
        int length;
        int top_idx;

    public:
        Stack();
        ~Stack();
          
        void push(int);
        int peek();        // returns top
        void pop();        // removes top
}
```
````

```` {admonition} Stack: Array Sample

```cpp
// CPP program to illustrate
// Implementation of push() function      

#include <iostream>
#include <stack>
using namespace std;

int main()
{
    // Empty stack
    stack<int> mystack;
    mystack.push(0);
    mystack.push(1);
    mystack.push(2);
    // Printing content of stack
    while (!mystack.empty()) {
        cout << ' ' << mystack.top(); 
        mystack.pop();
    }
}
```

[https://www.geeksforgeeks.org/stack-push-and-pop-in-c-stl/?ref=rp](https://www.geeksforgeeks.org/stack-push-and-pop-in-c-stl/?ref=rp)

````

```` {admonition} Visualize: Stack Array (general premise)
:class: tip

[https://www.cs.usfca.edu/~galles/visualization/StackArray.html](https://www.cs.usfca.edu/~galles/visualization/StackArray.html)
````

````` {admonition} Visualize: Stack Array (in Memory)
:class: tip

```` {card}
:link: https://pythontutor.com/visualize.html#code=/*%20C%2B%2B%20program%20to%20implement%20basic%20stack%0Aoperations%20*/%0A%23include%20%3Cbits/stdc%2B%2B.h%3E%0A%0Ausing%20namespace%20std%3B%0A%0A%23define%20MAX%203%0A%0Aclass%20Stack%20%7B%0A%20%20%20%20int%20top%3B%0A%0Apublic%3A%0A%20%20%20%20int%20a%5BMAX%5D%3B%20//%20Maximum%20size%20of%20Stack%0A%0A%20%20%20%20Stack%28%29%20%7B%20top%20%3D%20-1%3B%20%7D%0A%20%20%20%20bool%20push%28int%20x%29%3B%0A%20%20%20%20int%20pop%28%29%3B%0A%20%20%20%20int%20peek%28%29%3B%0A%20%20%20%20bool%20isEmpty%28%29%3B%0A%7D%3B%0A%0Abool%20Stack%3A%3Apush%28int%20x%29%0A%7B%0A%20%20%20%20if%20%28top%20%3E%3D%20%28MAX%20-%201%29%29%20%7B%0A%20%20%20%20%20%20%20%20cout%20%3C%3C%20%22Stack%20Overflow%22%3B%0A%20%20%20%20%20%20%20%20return%20false%3B%0A%20%20%20%20%7D%0A%20%20%20%20else%20%7B%0A%20%20%20%20%20%20%20%20a%5B%2B%2Btop%5D%20%3D%20x%3B%0A%20%20%20%20%20%20%20%20cout%20%3C%3C%20x%20%3C%3C%20%22%20pushed%20into%20stack%5Cn%22%3B%0A%20%20%20%20%20%20%20%20return%20true%3B%0A%20%20%20%20%7D%0A%7D%0A%0Aint%20Stack%3A%3Apop%28%29%0A%7B%0A%20%20%20%20if%20%28top%20%3C%200%29%20%7B%0A%20%20%20%20%20%20%20%20cout%20%3C%3C%20%22Stack%20Underflow%22%3B%0A%20%20%20%20%20%20%20%20return%200%3B%0A%20%20%20%20%7D%0A%20%20%20%20else%20%7B%0A%20%20%20%20%20%20%20%20int%20x%20%3D%20a%5Btop--%5D%3B%0A%20%20%20%20%20%20%20%20return%20x%3B%0A%20%20%20%20%7D%0A%7D%0Aint%20Stack%3A%3Apeek%28%29%0A%7B%0A%20%20%20%20if%20%28top%20%3C%200%29%20%7B%0A%20%20%20%20%20%20%20%20cout%20%3C%3C%20%22Stack%20is%20Empty%22%3B%0A%20%20%20%20%20%20%20%20return%200%3B%0A%20%20%20%20%7D%0A%20%20%20%20else%20%7B%0A%20%20%20%20%20%20%20%20int%20x%20%3D%20a%5Btop%5D%3B%0A%20%20%20%20%20%20%20%20return%20x%3B%0A%20%20%20%20%7D%0A%7D%0A%0Abool%20Stack%3A%3AisEmpty%28%29%0A%7B%0A%20%20%20%20return%20%28top%20%3C%200%29%3B%0A%7D%0A%0A//%20Driver%20program%20to%20test%20above%20functions%0Aint%20main%28%29%0A%7B%0A%20%20%20%20class%20Stack%20s%3B%0A%20%20%20%20s.push%2810%29%3B%0A%20%20%20%20s.push%2820%29%3B%0A%20%20%20%20s.push%2830%29%3B%0A%20%20%20%20cout%20%3C%3C%20s.pop%28%29%20%3C%3C%20%22%20Popped%20from%20stack%5Cn%22%3B%0A%0A%20%20%20%20//%20//print%20top%20element%20of%20stack%20after%20popping%0A%20%20%20%20//%20cout%20%3C%3C%20%22Top%20element%20is%20%3A%20%22%20%3C%3C%20s.peek%28%29%20%3C%3C%20endl%3B%0A%0A%20%20%20%20//%20//print%20all%20elements%20in%20stack%20%3A%0A%20%20%20%20//%20cout%20%3C%3C%22Elements%20present%20in%20stack%20%3A%20%22%3B%0A%20%20%20%20//%20while%28!s.isEmpty%28%29%29%0A%20%20%20%20//%20%7B%0A%20%20%20%20//%20%20%20%20%20//%20print%20top%20element%20in%20stack%0A%20%20%20%20//%20%20%20%20%20cout%20%3C%3C%20s.peek%28%29%20%3C%3C%22%20%22%3B%0A%20%20%20%20//%20%20%20%20%20//%20remove%20top%20element%20in%20stack%0A%20%20%20%20//%20%20%20%20%20s.pop%28%29%3B%0A%20%20%20%20//%20%7D%0A%0A%20%20%20%20return%200%3B%0A%7D&cumulative=false&curInstr=0&heapPrimitives=nevernest&mode=display&origin=opt-frontend.js&py=cpp_g%2B%2B9.3.0&rawInputLstJSON=%5B%5D&textReferences=false

Click to interact...

``` {figure} img/w5_stack_array.png
:align: center
```

_Note: may need a few seconds to execute code..._

````
`````

```` {admonition} Linked Lists

- **push** and **pop** at front (could use the other end as well)

``` {figure} https://i1.faceprep.in/Companies-1/stack%20linked%20list.png
```

````

`````` {admonition} Stack: LL Sample

````` {tab-set}
```` {tab-item} Altogether
``` {code-block} cpp
class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    void push(int data) {
        Node* newNode = new Node(data);
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (top == NULL) {
            return -1; // stack is empty
        }
        int popped = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return popped;
    }

    int peek() {
        if (top == NULL) {
            return -1; // stack is empty
        }
        return top->data;
    }

    bool isEmpty() {
        return top == NULL;
    }
};
```
````
```` {tab-item} Node
``` {code-block} cpp
class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        next = NULL;
    }
};
```

````
```` {tab-item} Stack
``` {code-block} cpp
class Stack {
private:
    Node* top;

public:
    Stack() {
        top = NULL;
    }
};
```
````
```` {tab-item} push()
``` {code-block} cpp
void push(int data) {
    Node* newNode = new Node(data);
    newNode->next = top;
    top = newNode;
}
```

````
```` {tab-item} pop()
``` {code-block} cpp
int pop() {
    if (top == NULL) {
        return -1; // stack is empty
    }
    int popped = top->data;
    Node* temp = top;
    top = top->next;
    delete temp;
    return popped;
}
```
````
```` {tab-item} peek()
``` {code-block} cpp
int peek() {
    if (top == NULL) {
        return -1; // stack is empty
    }
    return top->data;
}
```
````
```` {tab-item} isEmpty()
``` {code-block} cpp 
bool isEmpty() {
    return top == NULL;
}
```
````
`````

[https://www.geeksforgeeks.org/implement-a-stack-using-singly-linked-list/](https://www.geeksforgeeks.org/implement-a-stack-using-singly-linked-list/)

``````

```` {admonition} Visualize: Stack Array (general premise)
:class: tip

<!-- <iframe src="https://www.cs.usfca.edu/~galles/visualization/StackLL.html" width="1000" height="600" frameborder="0"> -->

[https://www.cs.usfca.edu/~galles/visualization/StackLL.html](https://www.cs.usfca.edu/~galles/visualization/StackLL.html)
````

````` {admonition} Visualize: Stack LL (in Memory)
:class: tip

```` {card}
:link: https://pythontutor.com/iframe-embed.html#code=//%20C%2B%2B%20program%20for%20linked%20list%20implementation%20of%20stack%0A%23include%20%3Cbits/stdc%2B%2B.h%3E%0Ausing%20namespace%20std%3B%0A%0A//%20A%20structure%20to%20represent%20a%20stack%0Aclass%20StackNode%20%7B%0Apublic%3A%0A%20%20%20%20int%20data%3B%0A%20%20%20%20StackNode*%20next%3B%0A%7D%3B%0A%0AStackNode*%20newNode%28int%20data%29%0A%7B%0A%20%20%20%20StackNode*%20stackNode%20%3D%20new%20StackNode%28%29%3B%0A%20%20%20%20stackNode-%3Edata%20%3D%20data%3B%0A%20%20%20%20stackNode-%3Enext%20%3D%20NULL%3B%0A%20%20%20%20return%20stackNode%3B%0A%7D%0A%0Aint%20isEmpty%28StackNode*%20root%29%0A%7B%0A%20%20%20%20return%20!root%3B%0A%7D%0A%0Avoid%20push%28StackNode**%20root,%20int%20data%29%0A%7B%0A%20%20%20%20StackNode*%20stackNode%20%3D%20newNode%28data%29%3B%0A%20%20%20%20stackNode-%3Enext%20%3D%20*root%3B%0A%20%20%20%20*root%20%3D%20stackNode%3B%0A%20%20%20%20cout%20%3C%3C%20data%20%3C%3C%20%22%20pushed%20to%20stack%5Cn%22%3B%0A%7D%0A%0Aint%20pop%28StackNode**%20root%29%0A%7B%0A%20%20%20%20if%20%28isEmpty%28*root%29%29%0A%20%20%20%20%20%20%20%20return%20INT_MIN%3B%0A%20%20%20%20StackNode*%20temp%20%3D%20*root%3B%0A%20%20%20%20*root%20%3D%20%28*root%29-%3Enext%3B%0A%20%20%20%20int%20popped%20%3D%20temp-%3Edata%3B%0A%20%20%20%20delete%20temp%3B%0A%0A%20%20%20%20return%20popped%3B%0A%7D%0A%0A//%20Driver%20code%0Aint%20main%28%29%0A%7B%0A%20%20%20%20StackNode*%20root%20%3D%20NULL%3B%0A%0A%20%20%20%20push%28%26root,%2010%29%3B%0A%20%20%20%20push%28%26root,%2020%29%3B%0A%20%20%20%20push%28%26root,%2030%29%3B%0A%0A%20%20%20%20cout%20%3C%3C%20pop%28%26root%29%20%3C%3C%20%22%20popped%20from%20stack%5Cn%22%3B%0A%0A%20%20%20%20return%200%3B%0A%7D&codeDivHeight=400&codeDivWidth=350&cumulative=false&curInstr=0&heapPrimitives=nevernest&origin=opt-frontend.js&py=cpp_g%2B%2B9.3.0&rawInputLstJSON=%5B%5D&textReferences=false

Click to interact...

``` {figure} img/w5_stack_ll.png
:align: center
```

_Note: may need a few seconds to execute code..._

````
`````

```````
``````````

### Considerations

`````````` {div} full-width
```` {card}

``` {figure} https://static.platzi.com/media/user_upload/Captura%20de%20pantalla%20(55)-27856afe-5df2-45ee-afdb-59af2e1629c1.jpg
```

``` {dropdown} Underflow
error can be thrown when calling *_pop_* on an empty stack
```

``` {dropdown} Overflow
error can be thrown when calling *_push_* on a full stack  (especially in fixed-length implementations)
```

````
``````````

### Applications

`````````` {div} full-width
```` {card}
``` {card}

**Undo in software applications...**

**Stack in compilers/programming languages...**

**Parsing expressions...**

**etc...**

```
````
``````````

## Queues

`````````` {div} full-width
````` {card}
```` {admonition} FIFO: First In First Out
``` {figure} https://airpix.io/assets/images/queue-management/airport-queue.png
```
````
`````
``````````

### Basic Operations

`````````` {div} full-width
````` {card}

``` {figure} https://assets.interviewbit.com/assets/skill_interview_questions/data-structure/queue-2c61774234ac435fa7c5edb2867d269f7b22159a72c5e871a2d7c94b5f945831.png.gz
```

```` {card}

``` {figure} https://miro.medium.com/max/814/0*pdhOeAK6wSh8ipTW.png
```

``` {dropdown} enqueue
inserts one element onto the queue
```

``` {dropdown} dequeue
returns the element at the top of the queue (and removes it)
```

``` {dropdown} isEmpty
not necessary, but sometimes useful
```

`````
``````````

### Documentation

`````````` {div} full-width

``` {card}
:text-align: center
<iframe src="https://en.cppreference.com/w/cpp/container/queue" frameborder="0"></iframe>
```

```` {card}

%``` {figure} imgs/08_s12_01.png
%```

```cpp
#include <stack>
#include <iostream>

int main() {
    std::queue<int> q1;
    q1.push(5);
    std::cout << q1.size() << "\n";
    
    std::queue<int> q2(q1);
    std::cout << s.size() << "\n";
    
    std::deque<int> deq { 3, 1, 4, 1, 5 };
    std::queue<int> q3(deq);
    std::cout << q3.size() << "\n";
    return 0;
}
```

[https://en.cppreference.com/w/cpp/container/queue](https://en.cppreference.com/w/cpp/container/queue)

%``` {figure} imgs/08_s12_02.png
%```

````
``````````

### Implementation

`````````` {div} full-width
``````` {card}

```` {admonition} Arrays

- **enqueue** and **dequeue** at <u>different</u> ends of the array (easier and efficient)
- can be <span class="blue">fixed-length</span>
- can also use a <span class="blue">dynamic array</span> (grows over time)   
  - additional cost for dynamic arrays

``` {figure} imgs/08_s05.png
:width: 92%
```

````

```` {admonition} Visualize: Queue Array (general premise)
:class: tip

[https://www.cs.usfca.edu/~galles/visualization/QueueArray.html](https://www.cs.usfca.edu/~galles/visualization/QueueArray.html)
````

```` {admonition} Queue: Array Sample

```cpp
void enqueue(Queue* queue, int item)
{
  if (isFull(queue))
    return;
  queue->rear = (queue->rear + 1)
                % queue->capacity;
  queue->array[queue->rear] = item;
  queue->size = queue->size + 1;
  cout << item << " enqueued to queue\n"; 
}
```

```cpp
int dequeue(Queue* queue)
{
  if (isEmpty(queue))
    return INT_MIN;
  int item = queue->array[queue->front];  
  queue->front = (queue->front + 1)
                  % queue->capacity;
  queue->size = queue->size - 1;
  return item;
}
```

``` {figure} https://examradar.com/wp-content/uploads/2016/10/Figure-4.6.-Basic-operations-on-deque.png
```

[https://www.geeksforgeeks.org/queue-set-1introduction-and-array-implementation/](https://www.geeksforgeeks.org/queue-set-1introduction-and-array-implementation/)

````

````` {admonition} Visualize: Queue Array (in Memory)
:class: tip

```` {card} 
:link: https://pythontutor.com/iframe-embed.html#code=//%20CPP%20program%20for%20array%0A//%20implementation%20of%20queue%0A%23include%20%3Cbits/stdc%2B%2B.h%3E%0Ausing%20namespace%20std%3B%0A%0A//%20A%20structure%20to%20represent%20a%20queue%0Aclass%20Queue%20%7B%0Apublic%3A%0A%20%20%20%20int%20front,%20rear,%20size%3B%0A%20%20%20%20unsigned%20capacity%3B%0A%20%20%20%20int*%20array%3B%0A%7D%3B%0A%0A//%20function%20to%20create%20a%20queue%0A//%20of%20given%20capacity.%0A//%20It%20initializes%20size%20of%20queue%20as%200%0AQueue*%20createQueue%28unsigned%20capacity%29%0A%7B%0A%20%20%20%20Queue*%20queue%20%3D%20new%20Queue%28%29%3B%0A%20%20%20%20queue-%3Ecapacity%20%3D%20capacity%3B%0A%20%20%20%20queue-%3Efront%20%3D%20queue-%3Esize%20%3D%200%3B%0A%0A%20%20%20%20//%20This%20is%20important,%20see%20the%20enqueue%0A%20%20%20%20queue-%3Erear%20%3D%20capacity%20-%201%3B%0A%20%20%20%20queue-%3Earray%20%3D%20new%20int%5Bqueue-%3Ecapacity%5D%3B%0A%20%20%20%20return%20queue%3B%0A%7D%0A%0A//%20Queue%20is%20full%20when%20size%0A//%20becomes%20equal%20to%20the%20capacity%0Aint%20isFull%28Queue*%20queue%29%0A%7B%0A%20%20%20%20return%20%28queue-%3Esize%20%3D%3D%20queue-%3Ecapacity%29%3B%0A%7D%0A%0A//%20Queue%20is%20empty%20when%20size%20is%200%0Aint%20isEmpty%28Queue*%20queue%29%0A%7B%0A%20%20%20%20return%20%28queue-%3Esize%20%3D%3D%200%29%3B%0A%7D%0A%0A//%20Function%20to%20add%20an%20item%20to%20the%20queue.%0A//%20It%20changes%20rear%20and%20size%0Avoid%20enqueue%28Queue*%20queue,%20int%20item%29%0A%7B%0A%20%20%20%20if%20%28isFull%28queue%29%29%0A%20%20%20%20%20%20%20%20return%3B%0A%20%20%20%20queue-%3Erear%20%3D%20%28queue-%3Erear%20%2B%201%29%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%25%20queue-%3Ecapacity%3B%0A%20%20%20%20queue-%3Earray%5Bqueue-%3Erear%5D%20%3D%20item%3B%0A%20%20%20%20queue-%3Esize%20%3D%20queue-%3Esize%20%2B%201%3B%0A%20%20%20%20cout%20%3C%3C%20item%20%3C%3C%20%22%20enqueued%20to%20queue%5Cn%22%3B%0A%7D%0A%0A//%20Function%20to%20remove%20an%20item%20from%20queue.%0A//%20It%20changes%20front%20and%20size%0Aint%20dequeue%28Queue*%20queue%29%0A%7B%0A%20%20%20%20if%20%28isEmpty%28queue%29%29%0A%20%20%20%20%20%20%20%20return%20INT_MIN%3B%0A%20%20%20%20int%20item%20%3D%20queue-%3Earray%5Bqueue-%3Efront%5D%3B%0A%20%20%20%20queue-%3Efront%20%3D%20%28queue-%3Efront%20%2B%201%29%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%25%20queue-%3Ecapacity%3B%0A%20%20%20%20queue-%3Esize%20%3D%20queue-%3Esize%20-%201%3B%0A%20%20%20%20return%20item%3B%0A%7D%0A%0A//%20Function%20to%20get%20front%20of%20queue%0Aint%20front%28Queue*%20queue%29%0A%7B%0A%20%20%20%20if%20%28isEmpty%28queue%29%29%0A%20%20%20%20%20%20%20%20return%20INT_MIN%3B%0A%20%20%20%20return%20queue-%3Earray%5Bqueue-%3Efront%5D%3B%0A%7D%0A%0A//%20Function%20to%20get%20rear%20of%20queue%0Aint%20rear%28Queue*%20queue%29%0A%7B%0A%20%20%20%20if%20%28isEmpty%28queue%29%29%0A%20%20%20%20%20%20%20%20return%20INT_MIN%3B%0A%20%20%20%20return%20queue-%3Earray%5Bqueue-%3Erear%5D%3B%0A%7D%0A%0A//%20Driver%20code%0Aint%20main%28%29%0A%7B%0A%20%20%20%20Queue*%20queue%20%3D%20createQueue%285%29%3B%0A%0A%20%20%20%20enqueue%28queue,%2010%29%3B%0A%20%20%20%20enqueue%28queue,%2020%29%3B%0A%20%20%20%20enqueue%28queue,%2030%29%3B%0A%20%20%20%20enqueue%28queue,%2040%29%3B%0A%0A%20%20%20%20cout%20%3C%3C%20dequeue%28queue%29%0A%20%20%20%20%20%20%20%20%3C%3C%20%22%20dequeued%20from%20queue%5Cn%22%3B%0A%0A%20%20%20%20cout%20%3C%3C%20%22Front%20item%20is%20%22%0A%20%20%20%20%20%20%20%20%3C%3C%20front%28queue%29%20%3C%3C%20endl%3B%0A%20%20%20%20cout%20%3C%3C%20%22Rear%20item%20is%20%22%0A%20%20%20%20%20%20%20%20%3C%3C%20rear%28queue%29%20%3C%3C%20endl%3B%0A%0A%20%20%20%20return%200%3B%0A%7D%0A%0A//%20This%20code%20is%20contributed%20by%20rathbhupendra&codeDivHeight=400&codeDivWidth=350&cumulative=false&curInstr=0&heapPrimitives=nevernest&origin=opt-frontend.js&py=cpp_g%2B%2B9.3.0&rawInputLstJSON=%5B%5D&textReferences=false

Click to interact...

``` {figure} img/w5_queue_array.png
:align: center
```

_Note: may need a few seconds to execute code..._

````
`````

```` {admonition} Arrays Linked Lists

- **enqueue** and **dequeue** at <u>different</u> ends

``` {figure} imgs/08_s15.png
```

[https://www.cs.usfca.edu/~galles/visualization/QueueArray.html](https://www.cs.usfca.edu/~galles/visualization/QueueLL.html)

````

```` {admonition} Queue: LL Sample

```cpp
void enQueue(int x)
{
  QNode* temp = new QNode(x);     

  if (rear == NULL) {
    front = rear = temp;
    return;
  }

  rear->next = temp;
  rear = temp;
}
```

```cpp
void deQueue()
{
  if (front == NULL)
    return;

  QNode* temp = front;  
  front = front->next;

  if (front == NULL)
    rear = NULL;

  delete (temp);
}
```

[https://www.geeksforgeeks.org/queue-linked-list-implementation/](https://www.geeksforgeeks.org/queue-linked-list-implementation/)

````


````` {admonition} Visualize: Queue LL (in Memory)
:class: tip

```` {card} 
:link: https://pythontutor.com/visualize.html#code=//%20C%2B%2B%20program%20for%20the%20above%20approach%0A%0A%23include%20%3Cbits/stdc%2B%2B.h%3E%0Ausing%20namespace%20std%3B%0A%0Astruct%20QNode%20%7B%0A%20%20%20%20int%20data%3B%0A%20%20%20%20QNode*%20next%3B%0A%20%20%20%20QNode%28int%20d%29%0A%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20data%20%3D%20d%3B%0A%20%20%20%20%20%20%20%20next%20%3D%20NULL%3B%0A%20%20%20%20%7D%0A%7D%3B%0A%0Astruct%20Queue%20%7B%0A%20%20%20%20QNode%20*front,%20*rear%3B%0A%20%20%20%20Queue%28%29%20%7B%20front%20%3D%20rear%20%3D%20NULL%3B%20%7D%0A%0A%20%20%20%20void%20enQueue%28int%20x%29%0A%20%20%20%20%7B%0A%0A%20%20%20%20%20%20%20%20//%20Create%20a%20new%20LL%20node%0A%20%20%20%20%20%20%20%20QNode*%20temp%20%3D%20new%20QNode%28x%29%3B%0A%0A%20%20%20%20%20%20%20%20//%20If%20queue%20is%20empty,%20then%0A%20%20%20%20%20%20%20%20//%20new%20node%20is%20front%20and%20rear%20both%0A%20%20%20%20%20%20%20%20if%20%28rear%20%3D%3D%20NULL%29%20%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20front%20%3D%20rear%20%3D%20temp%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20return%3B%0A%20%20%20%20%20%20%20%20%7D%0A%0A%20%20%20%20%20%20%20%20//%20Add%20the%20new%20node%20at%0A%20%20%20%20%20%20%20%20//%20the%20end%20of%20queue%20and%20change%20rear%0A%20%20%20%20%20%20%20%20rear-%3Enext%20%3D%20temp%3B%0A%20%20%20%20%20%20%20%20rear%20%3D%20temp%3B%0A%20%20%20%20%7D%0A%0A%20%20%20%20//%20Function%20to%20remove%0A%20%20%20%20//%20a%20key%20from%20given%20queue%20q%0A%20%20%20%20void%20deQueue%28%29%0A%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20//%20If%20queue%20is%20empty,%20return%20NULL.%0A%20%20%20%20%20%20%20%20if%20%28front%20%3D%3D%20NULL%29%0A%20%20%20%20%20%20%20%20%20%20%20%20return%3B%0A%0A%20%20%20%20%20%20%20%20//%20Store%20previous%20front%20and%0A%20%20%20%20%20%20%20%20//%20move%20front%20one%20node%20ahead%0A%20%20%20%20%20%20%20%20QNode*%20temp%20%3D%20front%3B%0A%20%20%20%20%20%20%20%20front%20%3D%20front-%3Enext%3B%0A%0A%20%20%20%20%20%20%20%20//%20If%20front%20becomes%20NULL,%20then%0A%20%20%20%20%20%20%20%20//%20change%20rear%20also%20as%20NULL%0A%20%20%20%20%20%20%20%20if%20%28front%20%3D%3D%20NULL%29%0A%20%20%20%20%20%20%20%20%20%20%20%20rear%20%3D%20NULL%3B%0A%0A%20%20%20%20%20%20%20%20delete%20%28temp%29%3B%0A%20%20%20%20%7D%0A%7D%3B%0A%0A//%20Driver%20code%0Aint%20main%28%29%0A%7B%0A%0A%20%20%20%20Queue%20q%3B%0A%20%20%20%20q.enQueue%2810%29%3B%0A%20%20%20%20q.enQueue%2820%29%3B%0A%20%20%20%20q.deQueue%28%29%3B%0A%20%20%20%20q.deQueue%28%29%3B%0A%20%20%20%20q.enQueue%2830%29%3B%0A%20%20%20%20q.enQueue%2840%29%3B%0A%20%20%20%20q.enQueue%2850%29%3B%0A%20%20%20%20q.deQueue%28%29%3B%0A%20%20%20%20cout%20%3C%3C%20%22Queue%20Front%20%3A%20%22%20%3C%3C%20%28q.front%29-%3Edata%20%3C%3C%20endl%3B%0A%20%20%20%20cout%20%3C%3C%20%22Queue%20Rear%20%3A%20%22%20%3C%3C%20%28q.rear%29-%3Edata%3B%0A%7D%0A//%20This%20code%20is%20contributed%20by%20rathbhupendra&cumulative=false&curInstr=0&heapPrimitives=nevernest&mode=display&origin=opt-frontend.js&py=cpp_g%2B%2B9.3.0&rawInputLstJSON=%5B%5D&textReferences=false

Click to interact...

``` {figure} img/w5_queue_ll.png
```

_Note: may need a few seconds to execute code..._

````
`````

%<iframe width="800" height="500" frameborder="0" src=""> </iframe>


```````
``````````

### Considerations

`````````` {div} full-width
````` {card}

``` {figure} https://external-content.duckduckgo.com/iu/?u=https%3A%2F%2Fprepinsta.com%2Fwp-content%2Fuploads%2F2020%2F06%2FCircular-Queues-in-DSA-Limitations-with-Linear-Queues.png&f=1&nofb=1&ipt=cc9c379ca83596886121fd079623ed7fd0afb84c302ce5dabac536a1d1401366&ipo=images
```

``` {dropdown} Underflow
error can be thrown when calling **dequeue** on an empty queue
```

``` {dropdown} Overflow
error can be thrown when calling **enqueue** on a full queue (especially in fixed-length implementations)
```

`````
``````````

### Applications

`````````` {div} full-width
``` {card}

**Media Playlists (Youtube, Spotify, Music,etc.)**

**Process management in Operating Systems**

**Simulations**

**Used in other algorithms**

**etc...**

```
``````````
