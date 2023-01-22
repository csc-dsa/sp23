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
  .orange {color:orange}
  .purple {color:purple}
  .brown {color:brown}
</style>

# Graphs

````````` {div} full-width
% ```````` {image} https://miro.medium.com/max/4106/1*HpYMnHjGZWmH9NKRG05lAg.jpeg
```````` {image} https://miro.medium.com/max/2664/1*HYPtf5Vk135snk07gFzy2w.png
:align: center
````````
`````````

````````` {div} full-width
```````` {card} 

`````` {grid}
````` {grid-item-card} Graph
:columns: 12
- a set of <i class="blue">vertices</i> connect pairwise by <i class="blue">edges</i>
`````
````` {grid-item-card}
:columns: 4
**Vertices**
- fundamental units of the graph known as vertex or nodes;
- every node/vertex can be labeled or unlabelled

**Edges**
- are drawn or used to connect two nodes of the graph
- can connect any two nodes in any possible way
- can be labeled or unlabelled
`````
````` {grid-item-card}
:columns: 8
``` {figure} https://media.geeksforgeeks.org/wp-content/uploads/20200630111809/graph18.jpg
:align: center
gfg: graph vertices and edges
`````
``````

````````
`````````

### Examples

````````` {div} full-width
```````` {card} 
````` {grid}

```` {grid-item-card}
:columns: 6
``` {figure} https://www.maureeneppstein.com/mve_journal/wp-content/uploads/underground-map1.gif
:align: center
:height: 200px
London Underground (Tube) Map <br> vertex = subway stop;<br> edge = direct route
```
````
```` {grid-item-card}
:columns: 6
``` {figure} https://revolution-computing.typepad.com/.a/6a010534b1db25970b0147e0ae51b2970b-800wi
:align: center
:height: 200px
Facebook Social Network Map:<br> vertex = person;<br> edge = social relationship
```
````
```` {grid-item-card}
:columns: 6
``` {figure} https://allthingsgraphed.com/public/images/twitter/twitter-follower-graph-avatars.png
:align: center
:height: 200px
Twitter followers <br> vertex = Twitter account;<br> edge = Twitter follower
```
````
```` {grid-item-card}
:columns: 6
``` {figure} https://www.researchgate.net/publication/314491781/figure/fig5/AS:470414003576837@1489166846626/Protein-protein-network-analysis-based-on-regulated-genes-in-HEK293-cells-Interactions.png
:align: center
:height: 200px
Protein-protein interation network <br> vertex = protein;<br> edge = interaction
```
````

`````
````````
`````````

## Applications...

````````` {div} full-width
```````` {card} 

| graph | vertex | edge |
| :-- | :--: | :--: |
| cell phone | phone | placed call |
| infectious disease | person | infection |
| financial | stock, currency | transactions |
| transportation | intersection | street |
| internet | router | fiber cable |
| web | web page | URL link |
| social relationship | person | friendship |

````````
`````````

```` {div} full-width
``` {image} https://cdn-images-1.medium.com/max/1600/1*fYG3B8hi4O2kk6aHvFB5mg.png
:align: center
```
````

## Undirected Graphs

````````` {div} full-width
```````` {card} 
``````` {grid}

`````` {grid-item-card}
:columns: 6
```` {glossary}
Graph
    a set of <i class="blue">vertices</i> connect pairwise by <i class="blue">edges</i> 

Path
    sequence of vertices connected by edges, with no repeated edges
````
``````
`````` {grid-item-card} 
:columns: 6
```` {glossary}
Definition
    two vertices are <i class="blue">connected</i> if there is a path between them 

Cycle
    path (with $\ge 1$ edge) whose first and last vertices are the same 
````
``````
`````` {grid-item-card}
:columns: 12
```` {figure} imgs/19_01.png
:align: center
````
``````

```````
````````
`````````

## Directed graphs

````````` {div} full-width
```````` {card} 
``````` {grid}

`````` {grid-item-card}
:columns: 6
```` {glossary}
Graph
    a set of <i class="blue">vertices</i> connect pairwise by <i class="blue">edges</i> 

Directed Path
    sequence of vertices connected by edges, with no repeated edges 
````
``````
`````` {grid-item-card} 
:columns: 6
```` {glossary}
Definition
    vertex $w$ is <i class="rhody">reachable</i> from vertex $v$ if there is a directed path from $v$ to $w$

Directed Cycle
    directed path (with $\ge 1$ edge) whose first and last vertices are the same 
````
``````
`````` {grid-item-card}
:columns: 12
```` {figure} imgs/19_02.png
:align: center
````
``````

```````
````````
`````````

## Graph Processing Problems

````````` {div} full-width
```````` {card} 

| problem | description |
| :--: | :--: |
| s-t path | Find a path between $s$ and $t$ |
| shortest s-t path | Find a path with the fewest edges between $s$ and $t$ |
| cycle | Find a cycle |
| Euler cycle | Find a cycle that uses each edge exactly once |
| Hamilton cycle | Find a cycle that uses each vertex exactly once |
| connectivity | Is there a path between ev ery pair of vertices? |
| graph isomorphism | Are two graphs isomorphic? |
| planarity | Draw the graph in the plane with no crossing edges |

````````
`````````

## Representation

### Digraph

````````` {div} full-width
```````` {card} 

``` {glossary}
Vertex representation
    For 0 through all positive values $V-1$
    Applications: use <i class="blue">symbol table</i> to convert between names and integers
```

``` {figure} imgs/19_03.png
:align: center
```

<br>

``` {glossary}
Definition
    a digraph is <i class="blue">simple</i> if it has no self-loops or parallel edges
```

``` {figure} imgs/19_04.png
:align: center
```

````````
`````````

### Adjacency-matrix

````````` {div} full-width
```````` {card} 

``` {card}
Maintain a $V-by-V$ boolean array; 

For each edge $v \rightarrow w$ in the digraph   
    
$$adj[v][w] \ =\ true$$
```

``` {figure} imgs/19_05.png
:align: center
```

````````
`````````

## Adjacency-lists

````````` {div} full-width
```````` {card} 

``` {card}
Maintain vertex-indexed array of lists
```

``` {figure} imgs/19_06.png
:align: center
```

````````
`````````

## In Practice

````````` {div} full-width
```````` {card} 

``` {glossary}
Use adjacency-lists
    Algorithms based on iterating over vertices adjacent from $v$  
    Real-world graphs tend to be <i class="blue">sparce</i> ($\Theta(V)$ edges), not <i class="blue">dense</i> ($\Theta(V^2)$ edges)
```

<br>

| representation | space | add edge from <br> $v$ to $w$ | has edge from <br> $v$ to $w$ | iterate over vertices <br> adjacent from $v$? |
| :--: | :--: | :--: | :--: | :--: |
| adjacent matrix | $V^2$ | 1<sup>*</sup> | 1 | $V$ |
| adjacent lists | $E+V$ | 1 | $outdegree(v)$ | $outdegree(v)$ |

\* disallows parallel edges
````````
`````````

## Depth-first Search

### Reachability

````````` {div} full-width
```````` {card} 

``` {glossary}
Problem
    Given a digraph $G$ and vertex $s$, find all the vertices <i class="rhody">reachable</i> from $s$
```

``` {figure} imgs/19_07.png
:align: center
```

````````
`````````

### Depth-first search

````````` {div} full-width
```````` {card} 

``` {glossary}
Goal
   Systemically traverse a digraph 
```

```cpp
void Graph::dfs( Vertex v )
{
  v.visited = true;
  for each Vertex w adjacent to v
    if( !w.visited )
      dfs( w );
}
```

``` {glossary} 
Typical applications
    Reachability: finding all vertices reachable from a given vertex
    Path finding: find directed path from one vertex to another
```

````````
`````````

### Directed depth-first search {.fff}

````````` {div} full-width
```````` {card} 

``` {glossary}
To visit vertex $v$:  
    Mark vertex $v$  
    Recursively visit all unmarked vertices adjacent from $v$ 
```

``` {figure} https://techtalkdotorg.files.wordpress.com/2015/01/graph_trees.jpg?w=1024&h=629
:align: center

directed dfs
```

_Errata: E(G,J) should read, E(G,I)_

````````
`````````

## DFS: properties

````````` {div} full-width
```````` {card} 

``` {glossary}
Proposition
    DFS marks all vertices reachable from $s$ in $\Theta(E+V)$ time in the worst case
```

``` {glossary}
Proof
    Initializing an array of length $v$ takes $\Theta(V)$ time
    Each vertex is visited at most once
    Visiting a vertex takes time proportional to its outdegree:
```

$$outdegree(v_0) + outdegree(v_1) + outdegree(v_2) + \dots = E$$
$$in\ worst\ case,\ all\ V\ vertices\ reachable\ from\ s$$

``` {glossary}
Note
    If all vertices are reachable from $s$, then $E \ge V - 1$, so $V$ is a lower-order term
```

````````
`````````

### Reachability application

````````` {div} full-width
```````` {admonition} Program control-flow analysis
``````` {grid}

`````` {grid-item-card}
``` {glossary}
Every program is a digraph
    Vertex = basic block of instructions (straight-line program)
    Edge = jump

Dead-code elimination
    Find (and remove) unreachable code

Infinite-loop detection
    Determine whether exit is unreachable
```
``````
`````` {grid-item-card}
``` {figure} imgs/19_12.png
:align: center
```
``````

```````
````````
```````` {admonition} Mark-sweep garbage collection
``````` {grid}

`````` {grid-item-card}
``` {glossary}
Every program is a digraph
    Vertex = basic block of instructions (straight-line program)
    Edge = jump

Roots
    Objects known to be directly accessible by a program (eg stack frame)

Reachable objects
    Objects indirectly accessible by program (starting at a root and following a chain of pointers)

Memory cost
    Uses 1 extra mark bit per object (plus DFS function-call stack)
```
``````
`````` {grid-item-card}
``` {figure} imgs/19_13.png
:align: center
```
``````

```````
````````
`````````

## Path Finding

### Directed paths DFS

`````````` {div} full-width
````````` {card}

``` {glossary}
Goal
    DFS determines which vertices are reachable from s. How to reconstruct paths?

Solution
    Use <i class="blue">parent-link representation</i>
```

`````` {grid}
````` {grid-item}
``` {figure} imgs/19_10.png
:align: center
reachable from $0$
```
`````
````` {grid-item}
``` {figure} imgs/19_14.png
:align: center
parent-link representation of paths from vertex $0$
```
`````

``````
`````````
``````````

### DFS: path finding

`````````` {div} full-width
````````` {card}

``` {glossary}
Parent-link representation of paths from $s$
    Maintain an integer array $edgeTo[]$  
    Interpretation: $edgeTo[v]$ is the next-to-last vertex on a path from $s$ to $v$  
    To reconstruct path from $s$ to $v$, trace $edgeTo[]$ backward from $s$ to $v$ (and reverse)
```

`````` {grid}
````` {grid-item}
``` {figure} imgs/19_15.png
:align: center
reachable from $0$
```
`````
````` {grid-item}
``` {figure} imgs/19_16.png
:align: center
parent-link representation of paths from vertex $0$
```
`````
````` {grid-item}
``` {code-block} cpp
public Iterable<Integer> pathTo(int v) {
  if (!marked[v]) return null; 
  Stack<Integer> path = new Stack<>(); 
  for (int x = v; x != s; x = edgeTo[x]) 
    path.push(x); 
  path.push(s); 
  return path; 
}
```
`````
``````

`````````
``````````

## Undirected Graphs

### Flood Fill

`````````` {div} full-width
````````` {card}

``` {glossary}
Problem
    Implement flood fill (Photoshop magic wand)
```

``` {figure} https://static.wixstatic.com/media/bb1bd6_591167b0be9940758124b35badf1da3a~mv2.gif
:align: center
magic wand tool
```

`````````
``````````

## DFS: undirected graphs

`````````` {div} full-width
````````` {card}

``` {glossary}
Problem
    Given an undirected graph $G$ and vertex $s$, find all vertices connected to $s$

Solution
    Treat undirected graph as a digraph, replacing each edge with two antiparallel edges
```

``` cpp
DFS (to visit a vertex v)
------------------------
Mark vertex v.
Recursively visit all unmarked
    vertices w adjacent to v
```

``` {glossary}
Typical applications
    Find all vertices connected to a given vertex
    Find a path between two vertices
```

`````````
``````````

### DFS: undirected search

`````````` {div} full-width
````````` {card}

``` {glossary}
To visit vertex $v$:  
    Mark vertex $v$  
    Recursively visit all unmarked vertices adjacent from $v$ 
```

`````` {grid}
````` {grid-item}
:columns: 6
```` {dropdown} ![image](imgs/19_17.png)
``` {figure} imgs/19_19.png
:align: center
vertices connected to $0$ (and associated paths)
```
`````
````` {grid-item}
:columns: 6
```` {dropdown} ![image](imgs/19_18.png)
``` {figure} imgs/19_20.png
:align: center

```
`````
``````

`````````
``````````

## Graph search {.fff}

`````````` {div} full-width
````````` {card}

``` {glossary}
Tree traversal
    Many ways in a binary tree
```

`````` {grid}
````` {grid-item}
```` {card} 
``` {glossary}
stack/recursion  
    Inorder | A C E H R S X |  
    Preorder | S E A C R H M X |  
    Postorder | C A M H R E X S |  

queue  
    Level-order | S E X A R C H M |
```
````
`````
````` {grid-item}
``` {figure} imgs/19_21.png
:align: center
parent-link representation of paths from vertex $0$
```
`````
``````

``` {glossary}
Graph search
    Many ways to explore a graph
```

``` {card}
- DFS preorder: vertices in order of calls to $dfs(G,v)$
- DFS postorder: vertices in order of return calls from $dfs(G,v)$
- Breadth-first: vertices in increasing order of distance from $s$
```

`````````
``````````

## Breadth-first (in digraphs)

### Shortest paths in a digraph

`````````` {div} full-width
````````` {card}

``` {glossary}
Problem
    Find directed path from $s$ to each other vertex that uses the <i class="rhody">fewest edges</i>

Key idea
    Visit vertices in increasing order of distance from $s$
```

`````` {grid}
````` {grid-item} 
:columns: 6
``` {card} Try writing some of the paths from  0 $\Rightarrow$ 6
Click below to enter your path...
<div contenteditable>0 - 2 - 7 - 4 - 5 - 1 - 3 - 6</div>
`````
````` {grid-item} 
:columns: 6
``` {figure} imgs/19_22.png
:align: center
```
`````
````` {grid-item} 
:columns: 6
``` {dropdown} directed paths from $0$ to $6$
$$0 \rightarrow 2  \rightarrow 7  \rightarrow 4  \rightarrow 5  \rightarrow 1  \rightarrow 3  \rightarrow 6  $$
$$0 \rightarrow 4  \rightarrow 5  \rightarrow 1  \rightarrow 3  \rightarrow 6   $$
$$0 \rightarrow 2  \rightarrow 7  \rightarrow 3  \rightarrow 6 $$
$$0 \rightarrow 2  \rightarrow 7  \rightarrow 0  \rightarrow 2  \rightarrow 7  \rightarrow 3  \rightarrow 6  $$
```
`````
````` {grid-item} 
:columns: 6
``` {dropdown} shortest path from $0$ to $6\ (length = 4)$
$$0 \rightarrow 2  \rightarrow 7  \rightarrow 3  \rightarrow 6 $$
```
`````
``````
 
``` {glossary}
Key idea
    Visit vertices in increasing order of distance from $s$

Key data structure
    Queue of vertices to visit
```

``` {figure} imgs/19_23.png
:align: center
```
`````````
``````````

## Breadth-first search

`````````` {div} full-width
````````` {card}

``` {glossary}
Repeat until queue is empty
    Remove vertex $v$ from queue  
    Add to queue all unmarked vertices adjacent from $v$ and mark them
```

`````` {grid}
````` {grid-item-card}
:columns: 12
```cpp
BFS (from source s)
-----------------------------------------------
Add s to FIFO queue and mark s
Repeat until the queue is marked empty:
- remove the least recently added vertex
- for each unmarked vertex w adjacent from v:
  - add w to queue and mark w
```
`````
````` {grid-item-card}
:columns: 4
```` {dropdown} ![image](imgs/19_24.png)
``` {figure} imgs/19_26.png
:align: center
graph g
```
````
_Fig 58_
`````
````` {grid-item-card}
:columns: 3
``` {figure} imgs/19_25.png
:align: center
```
`````
````` {grid-item-card}
:columns: 5
| $v$ | $edgeTo[]$ | $marked[]$ | $distTo[]$ |
| :--: | :--: | :--: | :--: |
| 0 | - | T | 0 | 
| 1 | 0 | T | 1 |
| 2 | 0 | T | 1 |
| 4 | 2 | T | 2 |
| 3 | 4 | T | 3 |
| 5 | 3 | T | 4 |
`````

``````
`````````
``````````

## Breadth-first search properties

`````````` {div} full-width
````````` {card}

``` {glossary}
Proposition
    In the worst case, BFS takes $\Theta(E + V)$ time

Proof
    Each vertex reachable from $s$ is visited once
```

`````` {grid}
````` {grid-item-card}
:columns: 6
``` {figure} imgs/19_28.png
:align: center
digraph g
```
`````
````` {grid-item-card}
:columns: 6
``` {figure} imgs/19_29.png
:align: center
&nbsp;
```
`````
``````

`````````
``````````

### Examples

`````````` {div} full-width
````````` {admonition} Single-sink Shortest Paths

Given a digraph and a <i class="blue">target</i> vertex $t$, find shortest path from every vertex to $t$

``````` {card} Example</i> $t = 0$  
`````` {grid}
````` {grid-item}
:columns: 4
``` {dropdown} Shortest path from $7$ 
$7 \rightarrow 6 \rightarrow 0$
```
``` {dropdown} Shortest path from $5$
$5 \rightarrow 4 \rightarrow 2 \rightarrow 0$
```
``` {dropdown} Shortest path from $12$
$12 \rightarrow 9 \rightarrow 11 \rightarrow 4 \rightarrow 2 \rightarrow 0$ 
```
`````
````` {grid-item-card}
:columns: 8
``` {figure} imgs/19_31.png
:align: center
```
`````
``````
`````````
``````````

`````````` {div} full-width
````````` {admonition} Multiple-source Shortest Paths

Given a digraph and a <i class="rhody">set</i> of source vertices, find shortest path from <i class="rhody">any</i> vertex in the set to every other vertex

``````` {card} Example</i> $S = \{ 1, 7, 10 \}$  
`````` {grid}
````` {grid-item}
:columns: 4
``` {dropdown} Shortest path from $4$ 
$7 \rightarrow 6 \rightarrow 4$
```
``` {dropdown} Shortest path from $5$
$7 \rightarrow 6 \rightarrow 0 \rightarrow 5$
```
``` {dropdown} Shortest path from $12$
$10 \rightarrow 12$
```
`````
````` {grid-item-card}
:columns: 8
``` {figure} imgs/19_31.png
:align: center
```
`````
``````
`````````
``````````

## Breadth-firest Search (in graphs)

### Application: routing

````` {div} full-width
```` {card}

``` {card}
Fewest number of hops in a communication network
```

``` {figure} https://images.theconversation.com/files/144160/original/image-20161102-27228-1iicfpi.jpg?ixlib=rb-1.1.0&q=45&auto=format&w=600&h=390&fit=crop&dpr=1
:align: center
ARPANET 1969 - 1977
```

## BFS: undirected graphs

`````````` {div} full-width
````````` {card}

``` {glossary}
Problem
    Find path between $s$ and each other vertex that uses fewest edges
Solution
    Treat as a digraph, replacing each undirected edge with two antiparallel edges
```

```cpp
BFS (from source s)
-----------------------------------------------
Add s to FIFO queue and mark s
Repeat until the queue is empty:
- remove the least recently added vertex v
- for each unmarked vertex w adjacent from v:
  - add w to queue and mark w
```
````
`````

## Summary

### Graph traversal

`````````` {div} full-width
````````` {card} BFS and DFS enables efficient solution to many (but not all) graph and digraph problems

| graph problem | BFS | DFS | time |
| :-- | :--: | :--: | :--: |
| s-t path | ✔︎ | ✔︎ | E + V |
| shortest s-t path | ✔︎ |  | E + V |
| shortest directed cycle | ✔︎ |  | E V |
| Euler cycle |  | ✔︎ | E + V |
| Hamilton cycle |  |  | $2^{1.657 V}$ |
| bipartiteness | ✔︎ | ✔︎ | E + V |
| connected components | ✔︎ |  ✔︎| E + V |
| strong conmponents |  | ✔︎ | E + V |
| planarity |  | ✔︎ | E + V |
| graph morphism |  |  | $2^{c\ ln^{3}\ V}$ |

`````````
``````````


%``` {figure} http://i1.wp.com/blog.hackerearth.com/wp-content/uploads/2015/05/dfsbfs_animation_final.gif?resize=640%2C333
%```