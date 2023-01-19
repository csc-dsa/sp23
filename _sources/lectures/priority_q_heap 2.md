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

# Priority Queues

``` {image} https://i.ytimg.com/vi/wptevk0bshY/maxresdefault.jpg
```

## Definitions

```` {card}

``` {card}
Collections
: Insert and delete items. Which items to delete?
```

``` {card}
Stack
: Remove the item most recently added

Queue
: Remove the item least recently added

Randomized Queue
: Remove a random item

Generalizes
: stack, queue, randomized queue
```

``` {card}
Priority Queue
: Remove the largest (or smallest) item
```

````

## [Queues](https://www.geeksforgeeks.org/queue-data-structure/?ref=gcse)

```` {card}
``` {image} https://miro.medium.com/max/3148/0*TRbfsq86lqDoqW6b.png
```
````

## [Priority Queue](https://www.geeksforgeeks.org/priority-queue-set-1-introduction/)

```` {card}
``` {image} https://netmatze.files.wordpress.com/2014/08/priorityqueue.png
```
````

## [Applications](https://www.geeksforgeeks.org/applications-priority-queue/)

`````` {div} full-width
````` {grid}
:padding: 2 2 2 2
```` {grid-item-card} pq huffman tree
:columns: 4
``` {image} https://forum.nwoods.com/uploads/db3963/optimized/2X/a/aee3daf4aaa56da16df5f083c5c6f5a3c8324eb8_2_1024x749.png
```
````
```` {grid-item-card} network routing
:columns: 4
``` {image} https://cdncontribute.geeksforgeeks.org/wp-content/uploads/DVP1.jpg
```
````
```` {grid-item-card} process scheduling
:columns: 4
``` {image} https://img1.daumcdn.net/thumb/R800x0/?scode=mtistory2&fname=https:%2F%2Ft1.daumcdn.net%2Fcfile%2Ftistory%2F2110D84751C24CE41C
```
````
```` {grid-item-card} Other examples...
:columns: 12
- Artificial Intelligence (search)
- Graph Algorithms
- Stream Data Algorithms
- HPC Task Scheduling
````
`````
``````

### Priority Queues

````` {div} full-width
```` {card}
**Collections of $<key, value>$ pairs**
- *_keys_* are objects on which an *_order_* is defined

Every pair of keys must be comparable according to a *_total order_*:
````
`````

`````` {div} full-width
````` {card} Properties
```` {grid}
``` {grid-item-card} Reflexive
$$k_1 \le k_2$$
```
``` {grid-item-card} Antisymmetric
$$k_1 \le\ k_2 \ \ \ \land \ \ \ k_2 \le k_1$$
$$\Rightarrow$$
$$k_1 = k_2$$
```
``` {grid-item-card} Transitive
$$k_1 \le k_2 \ \ \ \land \ \ \ k_2 \le k_3$$
$$\Rightarrow$$
$$k_1 \le k_3$$
```
````
`````
``````

`````` {div} full-width
````` {grid}
```` {grid-item-card} Queues
:columns: 6
- basic operations: 
  - *_$enqueue$_*, *_$dequeue$_*
- always remove the item least recently added
````
```` {grid-item-card} Priority Queues
:columns: 6
- basic operations: 
  - *_$insert$_*, *_$removeMax$_*
- MaxPQ: 
  - always remove the item with the highest (max) priority
- MinPQ: 
  - always remove the item with the lowest (min) priority
````
```` {grid-item-card}
:columns: 12
``` {image} https://studyalgorithms.com/wp-content/uploads/2013/12/priority_queue.png
```
````
`````
``````

``` {image} imgs/13_minpq.png
```

credit: Algorithm Design & Applications, Goodrich & Tamassia

### Performance

```` {card}
``` {list-table}
:header-rows: 1

* -
  - Sorted Array/List
  - Unsorted Array/List
* - insert
  - $O(n)$<br><br>must find place where to insert item
  - $O(1)$<br><br>item can be inserted at head or tail
* - removeMax<br>max
  - $O(1)$<br><br>largest/smallest key is at:<br> $arr[0]$/$arr[n-1]$
  - $O(n)$<br><br>must traverse entire sequence to find largest/smallest
```
````

### [cppreference.com](https://en.cppreference.com/w/cpp/container/priority_queue)

`````` {div} full-width
````` {grid}
```` {grid-item-card}
:columns: 12
``` {image} imgs/13_cppref_pq_1.png
```
````
```` {grid-item-card}
:columns: 6
``` {image} imgs/13_cppref_pq_2.png
```
````
```` {grid-item-card}
:columns: 6
``` {image} imgs/13_cppref_pq_3.png
```
````
`````
``````

## Heaps

### [(max) Heap](https://www.geeksforgeeks.org/difference-between-min-heap-and-max-heap/?ref=gcse)

``` {card}
Structure Property
: a heap is a [*_complete binary tree_*](https://www.geeksforgeeks.org/complete-binary-tree/)

Heap-Order Property
: for every node $x$:
  - $key\ parent\ x\ \ge\ key \ x$
  - except the root, which has no parent
```

``` {image} https://media.geeksforgeeks.org/wp-content/uploads/20201106115254/MaxHeap.jpg
```

### [Height of a heap](https://www.geeksforgeeks.org/height-complete-binary-tree-heap-n-nodes/)

```` {card}

What is the minimum number of nodes in a complete binary tree of height $h$?

``` {image} https://media.geeksforgeeks.org/wp-content/uploads/20201106115254/MaxHeap.jpg
```

$$n \ge 2^h\Rightarrow\ log\ n \ge log\ 2^h \Rightarrow\ log\ n \ge h$$
````

## Implementation

``````` {card}
````` {grid}
```` {grid-item-card}
:columns: 12
``` {image} imgs/13_implement_2.png
```
````
```` {grid-item-card}
:columns: 12
``` {image} imgs/13_implement_1.png
```
````
``` {grid-item-card}
node(i)
: $$i$$
```
``` {grid-item-card}
parent(i)
: $$floor(\frac{i}{2})$$
```
``` {grid-item-card}
left_child(i)
: $$i * 2$$
```
``` {grid-item-card}
right_child(i)
: $$i * 2 + 1$$
```
`````
```````

### $insert$

``````` {card}
``` {card}
**Append new element to the end of array**

Check heap-order property
: if <b class="red">violated, *_Up-Heap_*</b> (swap with parent)
: **repeat** until heap-order is restored
: if <var class="grn">not</var>, $insert$ complete

Time Complexity
: $O(log\ n)$
```

`````` {card} Example
````` {tab-set}
```` {tab-item} Step 1
``` {image} imgs/13_insert_1.png
```
``` {image} imgs/13_insert_2.png
```
``` {card}
Insert 47 into the heap...
```
````
```` {tab-item} Step 2
``` {image} imgs/13_insert_1.png
```
``` {image} imgs/13_insert_47_red.png
```
``` {dropdown} Is the array sorted?
**No**

**Append 47 to either end...**
```
````
```` {tab-item} Step 3
``` {image} imgs/13_insert_apnd_47_tree.png
```
``` {image} imgs/13_insert_47_red.png
```
``` {card}
Append 47 to tree...
- Find the highest node with an open child position and append 47 to node
```
````
```` {tab-item} Step 4
``` {image} imgs/13_insert_swap_1.png
```
``` {image} imgs/13_insert_47_red.png
```
``` {card}
Validate heap-order...
- swap(47, 7)
```
````
```` {tab-item} Step 5
``` {image} imgs/13_insert_w_47.png
```
``` {image} imgs/13_insert_arr_w_47.png
```
``` {card}
Validate heap-order...
  - swap(47, 45)
```
````
```` {tab-item} Step 6
``` {image} imgs/13_insert_w_47.png
```
``` {image} imgs/13_insert_42_red.png
```
``` {card}
Insert 42...
- Append 42 to either end...
```
````
```` {tab-item} Step 7
``` {image} imgs/13_insert_42_tree.png
```
``` {image} imgs/13_insert_42_grn.png
```
``` {card}
Append 42 to tree
- Append 42 to node and validate heap-order...
```
````
`````
``````
```````

## $removeMax$

``````` {card}

```` {card}
Max element is the first element of the array**
: the $root$ of the heap

Copy last element of array to the first position**
: then decrement array size by 1 (removes the last element)

Check heap-order property**
: if <var class="red">violated, *_Down-Heap_*</var> (swap with **larger** child)
  **repeat** until heap-order is restored
: if <var class="grn">not</var>, *_insert_* complete

Time Complexity
: $O(log\ n)$
````

`````` {card} Example
````` {tab-set}
```` {tab-item} Step 1
``` {image} imgs/13_removeMax_apnd_42.png
```
``` {image} imgs/13_insert_arr_50_42.png
```
``` {card}
$removeMax$ from array and heap...
- array $\Rightarrow swap(50, 42)$
- array $\Rightarrow pop(50)$
```
````
```` {tab-item} Step 2
``` {image} imgs/13_removeMax_root_42_tree.png
```
``` {image} imgs/13_removeMax_wo_50.png
```
``` {card}
tree $\Rightarrow$ move 42 to root  
validate heap-order...
```
````
```` {tab-item} Step 3
``` {image} imgs/13_removeMax_47_42.png
```
``` {image} imgs/13_removeMax_wo_50.png
```
``` {card}
tree $\Rightarrow swap(42, 47)$  
validate heap-order...
```
````
```` {tab-item} Step 4
``` {image} imgs/13_removeMax_45_42.png
```
``` {image} imgs/13_removeMax_wo_50.png
```
``` {card}
tree $\Rightarrow swap(42, 45)$
```
````
`````
``````
```````

## Performance

```` {card}

``` {list-table}
:header-rows: 1

* - 
  - Sorted Array/List
  - Unsorted Array/List
  - Heap
* - insert
  - $O(n)$
  - $O(1)$
  - $O(log\ n)$
* - removeMax
  - $O(1)$
  - $O(n)$
  - $O(log\ n)$
* - max
  - $O(1)$
  - $O(n)$
  - $O(1)$
* - insert N
  - $O(n^2)$
  - $O(n)$
  - $O(n)^{**}$
```

(**) assuming we know the sequence in advance (*_buildHeap_*)

````
