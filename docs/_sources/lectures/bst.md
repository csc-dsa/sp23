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

# Binary Search Tree

```` {div} full-width
``` {image} https://cdn.slidesharecdn.com/ss_thumbnails/binarysearchtreebst-140928072705-phpapp01-thumbnail-4.jpg?cb=1411889704
:align: center
```
````

## [$k$-ary trees](https://www.geeksforgeeks.org/k-ary-heap/?ref=gcse)

`````` {div} full-width
````` {grid}
```` {grid-item-card}
In a <b class="blue">$k$-ary tree</b>, every node has between $0$ and $k$ children

In a <b class="red">full (proper)</b> $k$-ary tree, every node has exactly $0$  or $k$ children

In a <b class="red">complete</b> $k$-ary tree, every level is entirely filled,  except possibly the deepest, where all nodes are as far left as possible

In a <b class="red">perfect</b> $k$-ary tree, every leaf has the same depth and the tree is full
````
```` {grid-item-card}
``` {image} https://external-content.duckduckgo.com/iu/?u=https%3A%2F%2Ftse1.mm.bing.net%2Fth%3Fid%3DOIP.7TSf_YpdLyF0uIfW0Rm_GgHaHa%26pid%3DApi&f=1&ipt=1187f0ed9de515a480afca769ea805a6e4e566d0faeae559c7cf2c0b42873442&ipo=images
:align: center
```
````
`````
``````
<!-- ![](https://miro.medium.com/max/1104/1*WEIGkEtQndEvPVwHAh4aSA.png) -->

## [examples](https://towardsdatascience.com/5-types-of-binary-tree-with-cool-illustrations-9b335c430254)

`````` {div} full-width
````` {grid}
```` {grid-item-card} full
:columns: 6
``` {image} https://miro.medium.com/max/1400/1*fh2By4u-SxTlt6u2xHqnCg.png
```
````
```` {grid-item-card} complete
:columns: 6
``` {image} https://miro.medium.com/max/1400/1*M1qfRR59TR9-i4pmI-_Clg.png
```
````
```` {grid-item-card} perfect
:columns: 6
``` {image} https://miro.medium.com/max/1400/1*EgcvwUHXnmdOpbHQwgCknA.png
```
````
```` {grid-item-card} degenerate
:columns: 6
``` {image} https://miro.medium.com/max/1400/1*m5BjLJeSrSGH4US-QXj4aA.png
```
````
`````
``````

<!-- ![](https://mathworld.wolfram.com/images/eps-gif/BinaryTrees_800.gif) -->

## Binary Tree

````` {div} full-width
```` {card}

``` {image} https://upload.wikimedia.org/wikipedia/commons/thumb/5/5e/Binary_tree_v2.svg/1920px-Binary_tree_v2.svg.png
:align: center
:width: 50%

```
$$bin\_tree = \{1, 7, 9, 2, 6, 9, 5, 11, 5 \}$$


````
`````

## [Implementing binary trees](https://www.geeksforgeeks.org/applications-priority-queue/)  

``````` {div} full-width
`````` {card}
````` {grid}
```` {grid-item-card}
:columns: 3
Node
: $data$
: $left$ child
: $right$ child
````
```` {grid-item-card}
:columns: 9
``` {image} imgs/15_s7.png
```
Tree  
$bst= \{a, b, c, d, e, f\}$
````
`````
``````
```````

## Binary Search Trees

`````` {div} full-width
````` {grid}
```` {grid-item-card}
:columns: 3

A BST is a <var class="rd">binary tree</var>

A BST has <var class="rd">symmetric order</var>

- each node $x$ in a BST has a key 

$$key(x)$$

- for all nodes $y$ in the left subtree of $x$, 

$$key(y) < key(x)^{**}$$

- for all nodes $y$ in the right subtree of $x$, 

$$key(y) > key(x)^{**}$$
````
```` {grid-item-card}
:columns: 9

``` {image} https://i.pinimg.com/originals/4e/5a/00/4e5a00c98d5b46ed4cbf224ac11dc115.png
:height: 600px
:align: center
```
(**) assume that the keys of a BST are pairwise distinct
````
```` {grid-item-card} Tree Parts
:columns: 12
![](https://codestandard.net/articles/en/images/binary-search-tree_0.jpg#article_image)
````
`````
``````

<!-- SLIDE 10 -->
### BST Classes

``````` {div} full-width
`````` {card}
````` {grid}
```` {grid-item-card} BSTNode
```{code-block} cpp
:lineno-start: 1
:emphasize-lines: 
class BSTNode { 
  
  private: 
    int data;  
    BSTNode *left;  
    BSTNode *right;
  
  public:
    BSTNode(int d);
    ~BSTNode();
  
  friend class BSTree;

};

```
````

```` {grid-item-card} BSTree
```{code-block} cpp
:lineno-start: 1
:emphasize-lines: 
class BSTree{
  
  private:
    BSTNode *root;
    void destroy(BSTNode *p);
    
  public:
    BSTree();
    ~BSTree();
    void insert(int d);
    void remove(int d);  
    BSTNode *search(int d);

};
```
````
`````
``````
```````

### Search

``````` {div} full-width
`````` {card}
````` {grid}
```` {grid-item-card}
:columns: 4

1. Start at root node
2. If the search key:  
    a. matches the current node’s key  
        * then <span class="green">found</span>  
    b. If search key $>$ current node’s key  
        * <span class="red">search</span> on $right$ child  
    c. If search key is less than current node’s  
        * <span class="red">search</span> on $left$ child   
3. Stop when current node is NULL (<span class="rrd">not found</span>)
````
```` {grid-item-card}
:columns: 8

``` {image} https://www.happycoders.eu/wp-content/uploads/2021/06/binary-search-tree-insertion-800x467.png
:align: center
```
$Search\ for\ \ 8$
````
`````
``````
```````

### [insert](https://www.geeksforgeeks.org/height-complete-binary-tree-heap-n-nodes/)

`````` {div} full-width
````` {card}
```` {grid}
``` {grid-item-card}
Perform a Search operation
: If <var class="grn">found</var>, no need to insert (may increase counter)
: If <var class="rd">not found</var>, insert node where Search stopped
```
``` {grid-item-card}
![](https://blog.penjee.com/wp-content/uploads/2015/11/binary-search-tree-insertion-animation.gif)
```
````
`````
``````

### Try it...

```` {div} full-width
``` {card}
![](https://external-preview.redd.it/bV2UoE-3zHRu97yghkNj0z9hWHRx-JNPh9YZcXLoiGg.jpg?auto=webp&s=fbcb59d31dd335e897ae53e4b1d968f544d7a408)

$$Serach...\ 23, 67, 18...$$
$$Insert...\ 65, 27, 90, 11, 51...$$
```
````

## Remove from BSTs

`````` {div} full-width
````` {card} remove
```` {tab-set} 
``` {tab-item} leaf
![remove : leaf](https://mycloudology.com/algorithm-binary-tree-search/algorithm-binary-tree-search_4.JPG)
```
``` {tab-item} 1 child
![$remove:\ with\ 1\ child$](https://mycloudology.com/algorithm-binary-tree-search/algorithm-binary-tree-search_5.JPG)
```
``` {tab-item} 2 children
![$remove:\ with\ 2\ children$](https://mycloudology.com/algorithm-binary-tree-search/algorithm-binary-tree-search_6.JPG)
```
``` {tab-item} trivial
![$$trivial,\ set\ parent's\ pointer\ to\ the\ only\ child\ an delete\ node$$](https://mycloudology.com/algorithm-binary-tree-search/algorithm-binary-tree-search_7.JPG)
```
``` {tab-item} find / copy/ delete successor
![$$find\ successor \\ copy\ successor's\ data\ to\ node \\ delete\ successor$$](https://mycloudology.com/algorithm-binary-tree-search/algorithm-binary-tree-search_8.JPG)
```
````
`````
``````

## [Traversals](https://www.geeksforgeeks.org/binary-search-tree-traversal-inorder-preorder-post-order/)

### Implications

``````` {div} full-width
`````` {card}
````` {grid}
```` {grid-item}
:columns: 4
```cpp
algorithm preorder (p) {
  if (p) {
    visit(p)
    inorder(p -> left)
    inorder(p -> right)
  }
}
```
````
```` {grid-item}
:columns: 4
```cpp
algorithm postorder (p) {
  if (p) {
    inorder(p -> left)
    inorder(p -> right)
    visit(p)
  }
}
```
````
```` {grid-item}
:columns: 4
```cpp
algorithm inorder (p) {
  if (p) {
    inorder(p -> left)
    visit(p)
    inorder(p -> right)
  }
}
```
````
```` {grid-item}
:columns: 6
``` {card}
![](https://www.bogotobogo.com/GoLang/images/BinarySearchTree_BST/print_functions.png)
```
````
```` {grid-item}
:columns: 6
``` {card}
How would we:
: Destroy a binary tree
: Print all elements ascending order
```
````
``````
```````

````````` {div} full-width
```````` {card}
``````` {tab-set} 

`````` {tab-item} preorder
````` {grid}
```` {grid-item}
```cpp
algorithm preorder (p) {
  if (p) {
    visit(p)
    inorder(p -> left)
    inorder(p -> right)
  }
}
```
````
```` {grid-item-card}
![[https://sbme-tutorials.github.io/2020/data-structure-FALL/notes/week08.html#preorder-traversals](https://sbme-tutorials.github.io/2020/data-structure-FALL/notes/week08.html#preorder-traversals)](https://sbme-tutorials.github.io/2020/data-structure-FALL/images/Tree06.png)
````
`````
``````

`````` {tab-item} postorder
````` {grid}
```` {grid-item} 
```cpp
algorithm postorder (p) {
  if (p) {
    inorder(p -> left)
    inorder(p -> right)
    visit(p)
  }
}
```
````
```` {grid-item-card}
![[https://sbme-tutorials.github.io/2020/data-structure-FALL/notes/week08.html#postorder-traversals](https://sbme-tutorials.github.io/2020/data-structure-FALL/notes/week08.html#postorder-traversals)](https://sbme-tutorials.github.io/2020/data-structure-FALL/images/Tree07.png)
````
`````
``````

`````` {tab-item} inorder
````` {grid}
```` {grid-item}
```cpp
algorithm inorder (p) {
  if (p) {
    inorder(p -> left)
    visit(p)
    inorder(p -> right)
  }
}
```
````
```` {grid-item-card}
![[https://sbme-tutorials.github.io/2020/data-structure-FALL/notes/week08.html#inorder-traversals](https://sbme-tutorials.github.io/2020/data-structure-FALL/notes/week08.html#inorder-traversals)](https://sbme-tutorials.github.io/2020/data-structure-FALL/images/Tree08.png)
````
`````
``````

```````
````````
`````````

``````` {div} full-width
`````` {card}
````` {tab-set}
```` {tab-item} before
``` {list-table}
:header-rows: 1

* - 
  - best-case
  - worst-case
  - average-case
* - search
  - <span contenteditable></span>
  - <span contenteditable></span>
  - <span contenteditable></span>
* - insert
  - <span contenteditable></span>
  - <span contenteditable></span>
  - <span contenteditable></span>
* - remove
  - <span contenteditable></span>
  - <span contenteditable></span>
  - <span contenteditable></span>
```
$$Cost\ of\ basic\ operations??$$
````

```` {tab-item} after
``` {list-table}
:header-rows: 1

* - 
  - best-case
  - worst-case
  - average-case
* - search
  - $O(1)$
  - $O(n)$
  - $O(log\ n)$
* - insert
  - $O(1)$
  - $O(n)$
  - $O(log\ n)$
* - remove
  - $O(log\ n)$
  - $O(n)$
  - $O(log\ n)$
```
$$Cost\ of\ basic\ operations??$$
````
`````
``````
```````

### Average-case analysis

```` {div} full-width
``` {card}
If **$n$** **distinct keys** are inserted into a BST in random  order, expected number of compares for basic  operations is

$$\sim2\ ln\ n \approx 1.39\ log\ n$$
- proof: 1-1 correspondence with quick-so

![](imgs/15_s32.png)

$$h = O(log\ n)$$
```
````

````` {div} full-width
```` {card} inserting n keys in a random order

$n=255$

``` {figure} https://algs4.cs.princeton.edu/32bst/media/bst-255random.mov

[https://algs4.cs.princeton.edu/32bst/](https://algs4.cs.princeton.edu/32bst/)
```
````
`````

## Collections / Dictionaries


````` {div} full-width
```` {card}
``` {list-table}
:header-rows: 1

* - 
  - What?
  - Sequential (unordered)
  - Sequential (ordered)
  - BST
* - search
  - search for a key
  - $O(n)$
  - $O(log\ n)$
  - $O(h)$
* - insert
  - insert a key
  - $O(n)$
  - $O(n)$
  - $O(h)$
* - delete
  - delete a key
  - $O(n)$
  - $O(n)$
  - $O(h)$
* - min/max
  - smallest/largest key
  - $O(n)$
  - $O(1)$
  - $O(h)$
* - floor/ceiling
  - predecessor / successor
  - $O(n)$
  - $O(log\ n)$
  - $O(h)$
* - rank
  - \# of keys less than key
  - $O(n)$
  - $O(log\ n)$
  - $O(h)$**
```
````
`````

(**) requires the use of ‘size’ at every node)
