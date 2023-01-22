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

# 2-3 Trees

````````` {div} full-width
``` {image} https://algorithmtutor.com/images/23TreeExample.png
:align: center
```
`````````

## [2-3 Trees](https://www.geeksforgeeks.org/2-3-trees-search-and-insert/)

````````` {div} full-width
```````` {grid}
`````` {grid-item-card}
:columns: 4

```` {card}
<b class="blue">Allow 1 or 2 keys per node</b>

- 2-node: one key, two children
- 3-node: two keys, three children
````
```` {card}
<b class="blue">Symmetric order</b>

- Inorder traversal yields keys in ascending order
````
```` {card}
<b class="blue">Perfect Balance</b>

- Every path from the root null link has same length
````
``````
`````` {grid-item-card}
:columns: 8

```{figure} imgs/16_s4.png
:alt: tree
:align: center

$tree = \{M, E, R, P, S, X, A, J, C, H, L \}$
```
``````

````````
`````````

### [$search$](https://www.geeksforgeeks.org/k-ary-heap/?ref=gcse)

````````` {div} full-width
```````` {grid}
`````` {grid-item-card}
:columns: 3

```` {card} 
<b class="blue">Compare search key against key(s) in node</b>
````
```` {card} 
<b class="blue">Find Interval containing search key</b>
````
```` {card}
<b class="blue">Follow associated link (recursively)</b>
````
``````
`````` {grid-item-card}
:columns: 9

```{image} https://algs4.cs.princeton.edu/33balanced/images/23tree-search.png
:align: center
:width: 125%

```
search for $H$ & $B$
``````

````````
`````````

### [$insert$](https://youtu.be/bhKixY-cZHE)

````` {div} full-width
```` {card} Add a new key to 2-node to create a 3-node
```{figure} https://algs4.cs.princeton.edu/33balanced/images/23tree-insert2.png
:align: center
:width: 50%


```
````
`````

````` {div} full-width
```` {card} Create a 4-node and break it down into three 2-nodes
```{figure} https://algs4.cs.princeton.edu/33balanced/images/23tree-insert3a.png
:align: center
:width: 50%


```
````
`````

````` {div} full-width
```` {card} Another view of each...
``` {figure} https://iq.opengenus.org/content/images/2020/06/Insert-Operation.JPG
:align: center
:width: 75%

$tree\ = \{9, 5, 8, 3, 2, 4, 7 \}$
```
````
`````

````` {div} full-width
```` {card} To a 3-node whose parent is a 2-node
``` {figure} https://algs4.cs.princeton.edu/33balanced/images/23tree-insert3b.png
:align: center
:width: 50%

create a temporary 4-node, remove middle child from 4-node, and add to parent to create 3-node
```
````
`````

````` {div} full-width
```` {card} Insert into a tree consisting of a single 3-node
``` {figure} https://algs4.cs.princeton.edu/33balanced/images/23tree-insert3c.png
:align: center
:width: 25%

create a 4-node and break it down into three 2-nodes
```
````
`````

## Performance

```````` {div} full-width
``````` {card}
````` {card} Perfect balance
Every path from the root to null has the same length
`````

```` {figure} https://algs4.cs.princeton.edu/33balanced/images/23tree-random.png
:align: center
:width: 50%
````

```` {card} Tree Height
- Min: $log_3 \ n \approx 0.631\ \ log_2 \ n$
- Max: $log_2 \ n$
- Between 12 and 20 for a million nodes
- Between 18 and 30 for a billion nodes
````

```` {dropdown} Bottomline
Guarenteed logarithmic performance for search and insert
````
```````
````````

## Summary

```````` {div} full-width
``````` {card}
```` {figure} imgs/16_summary.png
:align: center

but hidden constant $c$ is large (depends on implementation)
````
```````
````````

## Implementation

```````` {div} full-width
``````` {card}

```` {card} Direct implementation is complicated, because
- Maintaining multiple node types is cumbersome
- Need Multiple compares to move down tree
- Need to move back up the tree to split 4-nodes
- Large number of cases for splitting
````

```` {card}
```cpp
void put(Key key, Value val) {
  Node x = root;
  while (x.getCorrectChild(key) != null) {
    x = x.getCorrectChildKey();
    if (x.is4Node()) x.split();
  }
  if (x.is2Node()) x.make3Node(key, val) 
  else if (x.is3Node()) x.make4Node(key, val) 
}
```
````

``` {dropdown} Bottomline
Could do it, but there's a better way
```

```````
````````
