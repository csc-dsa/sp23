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

# Left-Leaning Red-Black Trees

````````` {div} full-width
```````` {card}
``` {image} http://mew.org/~kazu/proj/red-black-tree/okasaki.png
:align: center
```
````````
`````````

## Implementing 2-3 trees with binary trees

````````` {div} full-width
```````` {card}
``````` {grid}

`````` {grid-item-card} Challenge
:columns: 12
``` {figure} imgs/llrb/17_01.png
:align: center
```
**How to represent a 3-node?**
``````

`````` {grid-item-card} Approach 1
:columns: 4

``` {figure} imgs/llrb/17_02.png
:align: center
```

``` {dropdown} Regular BST<br>&nbsp;
- No way to tell a 3-node from a 2-node
- Can't (uniquely) map from BST back to 2-3 tree
```
``````

`````` {grid-item-card} Approach 2
:columns: 4
``` {figure} imgs/llrb/17_03.png
:align: center
```
``` {dropdown} Regular BST<br>with red "glue" nodes
- Wastes space for extra node
- Messy code 
```
``````

`````` {grid-item-card} Approach 3
:columns: 4
``` {figure} imgs/llrb/17_04.png
:align: center
```
``` {dropdown} Regular BST<br> with red "glue" links
- Widely used in practice
- Arbitrary restriction: red links lean left  
```
``````

```````
````````
`````````

## Left-leaning red-black BSTs (Guibas-Sedgewick 1979 and Sedgewick 2007)

````````` {div} full-width
```````` {card}

``` {card}
1. Represent 2-3 trees as a BST
2. Use "internal" left-leaning links as "glue" for 3-nodes
```

`````` {grid}

````` {grid-item-card}
:columns: 6
```` {figure} imgs/llrb/17_05.png
:align: center
$3-node$
````
`````

````` {grid-item-card}
:columns: 6
```` {figure} imgs/llrb/17_06.png
:align: center
$b\ is\ the\ larger\ root\ key$
````
`````

``````
````````
`````````

## 1-1 correspondence with 2-3 trees

````````` {div} full-width
```````` {card} Key Properties

`````` {grid}

````` {grid-item-card}
:columns: 5
```` {figure} imgs/llrb/17_07.png
:align: center

$2-3\ tree$
````
`````

````` {grid-item-card}
:columns: 7
```` {figure} imgs/llrb/17_09.png
:align: center

$horizontal\ red\ links$
````
`````


````` {grid-item-card}
:columns: 12
```` {figure} imgs/llrb/17_08.png
:align: center

$red-black\ tree$
````
`````
``````

````````
`````````

## Definition of LLRB trees (without reference to 2-3)

````````` {div} full-width
```````` {card}

```` {card} A BST such that
- No node has two red links connected to it
- Red links lean left
- Every path from root to null has the same number of black links
````

``` {figure} imgs/llrb/17_08.png
:align: center

$red-black\ tree$
````````
`````````

## Search

### Observation

````````` {div} full-width
```````` {card}

``` {card}
Search is the same as for BST (ignore color)
```

`````` {grid}
````` {grid-item-card}
:columns: 5
```cpp
public Value get(Key key) {
  Node x = root;  
  while (x != null) {
    int cmp = key.compareTo(x.key);
    if      (cmp <  0)  x = x.left;
    else if (cmp >  0)  x = x.right;
    else if (cmp == 0)  return x.val;
  }
  return null;
}
```
`````
````` {grid-item-card}
:columns: 7
``` {figure} imgs/llrb/17_08.png
:align: center
$red-black\ tree$
```
`````

``````

``` {card}
Remark: Many other ops (floor, iteration, rank, slection) are also identical
```

````````
`````````

## Representation

````````` {div} full-width
```````` {card}

``` {card}
Each node is pointed to by precisely one link (from its parent) $\Rightarrow$ can encode color of links in nodes
```

`````` {grid}
````` {grid-item-card}
:columns: 7
```java
private static final boolean RED   = true;
private static final boolean BLACK = false;

private class Node {
  Key     key;  
  Value   val;
  Node    left;
  Node    right;
  Boolean color;                  // color of parent link
}

private boolean isRed(Node x) {
  if (x == null) return false;    // null links are black
  return x.color == red;
}
```
`````
````` {grid-item-card}
:columns: 5
``` {figure} imgs/llrb/17_10.png
:align: center
```
``` {card}
$$h = root\\$$  
$$h.left.color\ is\ RED\\$$  
$$h.right.color\ is\ BLACK$$
```
`````

``````

````````
`````````

## The road to LLRB trees

````````` {div} full-width
```````` {card}

`````` {tab-set}
````` {tab-item} 1
``` {figure} imgs/llrb/17_11.png
:align: center
BSTs can get imbalanced
```
`````
````` {tab-item} 2
``` {figure} imgs/llrb/17_07.png
:align: center
2-3 trees (balanced but awkward to implement)
```
`````
````` {tab-item} 3
``` {figure} imgs/llrb/17_09.png
:align: center
3-nodes "glued" together with red links
```
`````
````` {tab-item} 4
``` {figure} imgs/llrb/17_08.png
:align: center
LLRB trees (color in links)
```
`````
````` {tab-item} 5
``` {figure} imgs/llrb/17_12.png
:align: center
implementing LLRB trees (color in nodes)
```
`````
``````

````````
`````````

## Red-Black Tree Operations

### Overview

````````` {div} full-width
```````` {card}

``` {card} Basic strategy
Maintain 1-1 correspondence with 2-3 trees
```

``` {card} During internal operations, maintain
- Symmetric order.
- Perfect black balance.
- [ but not necessarily color invariants ]
```

`````` {grid} Example violations of color invariants
````` {grid-item-card}
:columns: 3
``` {figure} img/llrb/17_13.png
right-leaning red link
```
`````
````` {grid-item-card}
:columns: 3
``` {figure} img/llrb/17_14.png
two red children (a temporary 4-node)
```
`````
````` {grid-item-card}
:columns: 3
``` {figure} img/llrb/17_15.png
left-left red (a temporary 4-node)
```
`````
````` {grid-item-card}
:columns: 3
``` {figure} img/llrb/17_16.png
left-right red (a temporary 4-node)
```
`````
``````

``` {card}
<var class="blue">To restore color invariants</var>: perform <var class="red">rotations</var> and <var class="red">color flips</var>
```

````````
`````````

### Left rotation

````````` {div} full-width
```````` {card} 
``` {card}
**Orient a (temporarily) right-leaning red link to lean left**
```

`````` {grid}
````` {grid-item-card} Rotate E left
:columns: 4
``` {figure} imgs/llrb/17_17.png
:align: center
before...
```
`````
````` {grid-item-card} Pseudocode
:columns: 4
```cpp
private Node rotateLeft(Node h) {
  assert isRed(h.right);
  Node x  = h.right;
  h.right = x.left;
  x.left  = h
  x.color = h.color;
  h.color = RED;
  return x;
}
```
`````
````` {grid-item-card} Rotate E left
:columns: 4
``` {figure} imgs/llrb/17_18.png
:align: center
after...
```
`````
``````

``` {card}
<var class="blue">Invariants</var>: Maintains symmetric order and perfect balance
```

````````
`````````

### Right rotation

````````` {div} full-width
```````` {card} 
``` {card}
**Orient a left-leaning red link to (temporarily) lean right**
```

`````` {grid}
````` {grid-item-card} Rotate E right
:columns: 4
``` {figure} imgs/llrb/17_18.png
:align: center
before...
```
`````
````` {grid-item-card} Pseudocode
:columns: 4
```cpp
private Node rotateLeft(Node h) {
  assert isRed(h.right);
  Node x  = h.left;
  h.left  = x.right;
  x.right = h
  x.color = h.color;
  h.color = RED;
  return x;
}
```
`````
````` {grid-item-card} Rotate E right
:columns: 4
``` {figure} imgs/llrb/17_17.png
:align: center
after...
```
`````
``````

``` {card}
<var class="blue">Invariants</var>: Maintains symmetric order and perfect balance
```

````````
`````````

### Color flip

````````` {div} full-width
```````` {card} 

``` {card}
**Recolor to split a (temporary) 4-node**
```

`````` {grid}
````` {grid-item-card} Color flip
:columns: 4
``` {figure} imgs/llrb/17_19.png
:align: center
before...
```
`````
````` {grid-item-card} Pseudocode
:columns: 4
```cpp
private Node rotateLeft(Node h) {
  assert isRed(h);
  assert isRed(h.left);
  assert isRed(h.right);
  h.color        = RED;
  h.left.color   = BLACK;
  h.right.color  = BLACK;
}
```
`````
````` {grid-item-card} Color flip
:columns: 4
``` {figure} imgs/llrb/17_20.png
:align: center
after...
```
`````
``````

``` {card}
<var class="blue">Invariants</var>: Maintains symmetric order and perfect balance
```

````````
`````````

## Insertions

### Implementation

``````````` {div} full-width
`````````` {card} 

``` {card}
**Do standard BST insert** $\ \ \ \ \ \ \ \ \ \ \ \ \leftarrow$ preserves symmetric  order
```

``` {card}
**Color new link red** $\ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \leftarrow$ preserve perfect black balance
```

``` {card} Repeat up the tree until color invariants restored
- two left red links in a row?      $\ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \Rightarrow$ rotate right
- left and right links both red?    $\ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \Rightarrow$ color flip
- right link only red?              $\ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \Rightarrow$ rotate left
```

````````` {grid}
```````` {grid-item}
:columns: 6
``````` {card} Inserting H
`````` {tab-set}
````` {tab-item} 1
``` {figure} imgs/llrb/17_21.png
:align: center
[R]: add new node here
```
`````
````` {tab-item} 2
``` {figure} imgs/llrb/17_22.png
:align: center
[S]: two lefts in a row, rotate right
```
`````
````` {tab-item} 3
``` {figure} imgs/llrb/17_23.png
:align: center
[R]: both chidren red, flip colors
```
`````
````` {tab-item} 4
``` {figure} imgs/llrb/17_24.png
:align: center
[E]: right link, so rotate left
```
`````
````` {tab-item} 5
``` {figure} imgs/llrb/17_25.png
:align: center
complete
```
`````
``````
```````
````````
```````` {grid-item}
:columns: 6
``````` {card} Inserting P
`````` {tab-set}
````` {tab-item} 1
``` {figure} imgs/llrb/17_26.png
:align: center
[M]: add new node here
```
`````
````` {tab-item} 2
``` {figure} imgs/llrb/17_27.png
:align: center
[M]: both chidren red, flip colors
```
`````
````` {tab-item} 3
``` {figure} imgs/llrb/17_28.png
:align: center
right link red, rotate left
```
`````
````` {tab-item} 4
``` {figure} imgs/llrb/17_29.png
:align: center
two lefts in a row, rotate right
```
`````
````` {tab-item} 5
``` {figure} imgs/llrb/17_30.png
:align: center
both children red, flip colors
```
`````
````` {tab-item} 6
``` {figure} imgs/llrb/17_31.png
:align: center
complete
```
`````
``````
```````
````````

``````````
```````````

<!-- SLIDE 15 -->
## Visualize

````````` {div} full-width
```````` {card} Click the image to hyperlink and interact
:link: https://www.cs.usfca.edu/~galles/visualization/RedBlack.html
```` {image} imgs/llrb/17_rbt.png
:align: center
````

````````
`````````

## Implementation

````````` {div} full-width
```````` {card}

```` {card}
**Do standard BST insert and color new link red**
````

```` {card} Repeat up the tree until color invariants restored
- two left red links in a row?      $\ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \Rightarrow$ rotate right
- left and right links both red?    $\ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \Rightarrow$ color flip
- right link only red?              $\ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \Rightarrow$ rotate left
````

```cpp
private Node put(Node h, Key, k, Value v) {
  if (h == null) return new Node(key, val, RED;         // insert at bottom and color red
  
  int cmp = key.compareTo(h.key)
  if      (cmp <  0) h.left = put(h.left, key, val);
  else if (cmp >  0) h.left = put(h.right, key, val);
  else if (cmp == 0) h.val  = val);
  
  // following lines restore color invariants
  if (isRed(h.right) && !isRed(h.left))        h = rotateLeft(h);
  if (isRed(h.left ) && !isRed(h.left.left))   h = rotateRight(h);
  // only a few extra lines of code provides near-perfect balance
  if (isRed(h.left ) && isRed(h.right))        h = flipColors(h);           
  
  return h;
}
```

````````
`````````

## Visualizations | $n=255$

````````` {div} full-width
```````` {card} 

`````` {grid}
````` {grid-item-card} Random order
:columns: 6
$height = 9$  
$average\ depth = 6.3$
`````
````` {grid-item-card}
:columns: 6
``` {figure} imgs/llrb/17_32.png
:align: center
random
`````

````` {grid-item-card} Ascending order
:columns: 6
$height = 7$  
$average\ depth = 6.0$
`````
````` {grid-item-card}
:columns: 6
``` {figure} imgs/llrb/17_33.png
:align: center
ascending
`````

````` {grid-item-card} Descending order
:columns: 6
$height = 13$  
$average\ depth = 6.5$
`````
````` {grid-item-card}
:columns: 6
``` {figure} imgs/llrb/17_34.png
:align: center
desscending
`````
``````

````````
`````````

## Balance

````````` {div} full-width
```````` {card} 

``` {card} Proposition
Height of corresponding 2-3 tree is $\le log_2\ n$ 
```

``` {card} Proof
- Black height = height of corresponding 2-3 tree $\le log_2\ n$
- Never two red links in a row  
$\ \ \ \ \ \Rightarrow$ height of LLRB tree $\le (2 \times black\ height) + 1 \le 2\ log_2\ n$
- [A slightly more refined argument show $height\ \le 2\ log_\ n$]
```

``` {figure} imgs/llrb/17_35.png
:align: center
$height\ \le 2\ log_2\ n$
```
````````
`````````

## Summary

````````` {div} full-width
```````` {card} 
``` {figure} imgs/llrb/17_table.png
:align: center
hidden constant $c$ is small for r-b BST<br> (at most $2\ log_2\ n$ compares)
```
````````
`````````
