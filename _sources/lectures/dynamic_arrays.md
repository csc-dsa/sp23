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
  .blue {color:blue}
  .green {color:green}
  .orange {color:darkorange}
  .purple {color:purple}
  .brown {color:brown}
</style>

# Dynamic Arrays

```` {div} full-width
``` {image} https://i.ytimg.com/vi/jzJlq35dQII/maxresdefault.jpg
:width: 600px
:align: center
```
````

## Arrays

````` {div} full-width
```` {card} Definition

- An array is a **contiguous** sequence of elements of the <b class="green">same type</b>
- Each element can be accessed using <b class="green">index</b>

+++

- Array Name: $A$
- Array Length: $n$

``` {image} imgs/05_s04.png
:align: center
```

$$note:\ all\ elements\ of\ the\ same\ data\ type$$

````

```` {card} Declaration

```cpp
//array declaration by specifying size  
int myarray1[100];

//can also declare an array of user specified
//size (must be const for many compilers!)  
int n = 8;
int myarray2[n];

// can declare and initialize elements  
double arr[] = { 10.0, 20.0, 30.0, 40.0 };
// size is implicitly understood by the compiler when initialized at declaration

// alternative way  
int arr[5] = { 1, 2, 3 };
// size is explicitly manipulated for the compiler
// size = 5, element count = 3, empty elements remaining = 2 

```

````
`````

### Static arrays

````` {div} full-width
```` {card}
So far... we have seen examples of arrays, <b class="brown">allocated in the stack</b> (fixed length)

```cpp
//array declaration by specifying size  
int myarray1[100];
```

You can allocate memory dynamically, <b class="brown">allocated in the heap</b> (still fixed length)

```cpp
int *myarray = new int[100];
//...
//work with the array
//...
delete []myarray;
```
````
`````

## Memory Allocation

````` {div} full-width
```` {card}
``` {admonition} Memory layout of C/C++ programs
:class: tip

![](https://media.geeksforgeeks.org/wp-content/uploads/memoryLayoutC.jpg)

[https://www.geeksforgeeks.org/memory-layout-of-c-program/](https://www.geeksforgeeks.org/memory-layout-of-c-program/)

```
````
`````

### stack v. heap

```` {div} full-width
``` {card}
<iframe width="1000" height="600" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=//%20Example%20C%2B%2B%20code%20for%20OPT%0Aint%20main%28%29%20%7B%0A%20%20float%20var1%3B%0A%20%20float%20var2%3B%0A%20%20int%20static_array%5B10%5D%3B%0A%20%20int%20*static_array_heap%20%3D%20new%20int%20%5B10%5D%3B%0A%20%20//%20...%0A%20%20//%20work%20with%20this%20array%0A%20%20//%20...%0A%20%20delete%20%5B%5D%20static_array_heap%3B%0A%20%20return%200%3B%0A%7D&codeDivHeight=400&codeDivWidth=350&cumulative=false&curInstr=0&heapPrimitives=nevernest&origin=opt-frontend.js&py=cpp_g%2B%2B9.3.0&rawInputLstJSON=%5B%5D&textReferences=false"> </iframe>
```
````

``````` {div} full-width
`````` {card}
````` {admonition} A few notes...
:class: tip

```` {admonition} Creating variables in the stack

- variables are automatically created and freed
- variables only exist while the function is running
- faster and good for small local variables
````
```` {admonition} Allocating memory in the heap

- memory is allocated at runtime
- programmer is responsible for allocating/deallocating memory
- variables can be accessed globally (in theprogram)
- memory may become fragmented
- slower but good for large variables
````

`````

````` {admonition} What if...?
:class: attention

``` {admonition} Case 1
:class: note

We don't know the max size of an array before running the program!

- user specified inputs/decisions!
- e.g. read an image or video and display

```

``` {admonition} Case 2
:class: note

The sequence changes over time (during the  execution of the program)

- e.g. you develop a text editor and represent the sequence of characters as anarray

```

``` {admonition} Question
:class: attention

Which data structure (studied so far) would you use in each case?
```
`````
``````
```````

## Dynamic Arrays (resizing, growing)

### Dynamic Array

````` {div} full-width
```` {card}

**Dynamically allocated arrays that change their size over time**

- can <b class="orange">grow</b> automatically
- can <b class="orange">shrink</b> automatically

**Operations on arrays**

- `append`
- `remove_last`
- `get`  $\Theta(1)$
- `set`  $\Theta(1)$

````
`````

### First try

````` {div} full-width
```` {card}

**Start with an empty array**  

**For every *_append_*:**

- increase the size of the array by 1 then write the new element

**For every *_remove_last_*:**

- remove the last element and then decrease the size of the array by 1
````
`````

### Analyzing cost

```````` {div} full-width
``````` {card}
`````` {card} _Grow by 1_

Count array accesses (reads and writes) of adding first $n$ elements

- will ignore the cost of allocating/deallocating arrays

````` {grid}

```` {grid-item-card}

``` {list-table}
:header-rows: 1

* - `n`
  - `append`
  - `copy`
* - 1
  - 1
  - 1
* - 2
  - 2
  - 2
* - ...8
  - ...8
  - ...8
* - ...16
  - ...16
  - ...16
* - ...128
  - ...128
  - ...128

```

````

```` {grid-item-card}

``` {card}
Each row indicates the number of **reads and writes** necessary for appending an element into an **existing array of length $n$**
```

$$n + \sum_{i=0}^{n-1} i^2 = n + n^2 - n$$

$$\Theta(n^2)$$

````

`````

``````

`````` {card} _Doubling array_

Count array accesses (reads and writes) of adding first $n = 2^i$ elements

- will ignore the cost of allocating/deallocating arrays

````` {grid}

```` {grid-item-card}

``` {list-table}
:header-rows: 1

* - `n`
  - `append`
  - `copy`
* - 1
  - 1
  - 1
* - 2
  - 1
  - 2
* - ...8
  - 1
  - 3
* - ...16
  - 1
  - 4
* - ...128
  - 1
  - 7

```

````

```` {grid-item-card}

``` {card}
Each row indicates the number of **reads and writes** necessary for appending an element into an **existing array of length $n$**
```

$$n + \sum_{i = 1}^{log\ n} 2^i = n + 2^{log\ n + 1} - 1$$

$$\Theta(n)$$

$$\sum_{i=0}^n c^i = \frac{c^{n^2 + 1} - 1}{c - 1}$$

````
`````
``````
```````
````````

### Proof

````` {div} full-width
```` {card}
``` {image} imgs/05_s20.png
:align: center
```
````
`````


### Worst-case and average-case

````` {div} full-width
```` {card}
``` {dropdown} Analysis for appending a *single element* using increase-by-1
$$\Theta(n^2)$$
```

``` {dropdown} Analysis for appending a *single element* using repeated doubling
$$\Theta(n)$$
```
````
