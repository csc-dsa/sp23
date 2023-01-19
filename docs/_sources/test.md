# test

`````` {div} full-width
````` {grid}
```` {grid-item-card}
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
```` {grid-item-card}
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
```` {grid-item-card}
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
```` {grid-item-card}
:columns: 6
``` {card}
![](https://www.bogotobogo.com/GoLang/images/BinarySearchTree_BST/print_functions.png)
```
````
```` {grid-item-card}
:columns: 6
``` {card}
How would we:
: Destroy a binary tree
: Print all elements ascending order
```
````
`````
``````

````````` {div} full-width
```````` {card} traversal
``````` {tab-set} 

`````` {tab-item} preorder
````` {grid}
```` {grid-item-card}
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
```` {grid-item-card} 
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
```` {grid-item-card}
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


