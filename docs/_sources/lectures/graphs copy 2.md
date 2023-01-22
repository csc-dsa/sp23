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

# Graphs

````````` {div} full-width
```````` {image} https://i.pinimg.com/originals/23/de/a8/23dea88650c8401a13af985eddee6731.jpg
:align: center
````````
`````````

## Graphs

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
:columns: 4
``` {figure} https://media.geeksforgeeks.org/wp-content/uploads/20200630111809/graph18.jpg
:align: center
gfg: graph vertices and edges
`````
``````


````````
`````````

## Examples {.flexbox .vcenter .fff}

::: {.f .ffrn .jcse .g}
::: {.flexbox .vcenter}
![](https://www.maureeneppstein.com/mve_journal/wp-content/uploads/underground-map1.gif){.fcmw3 .s}  
*London Underground (Tube) Map <br> Vertex = subway stop; edge = direct route* 
:::
::: {.flexbox .vcenter}
![](https://revolution-computing.typepad.com/.a/6a010534b1db25970b0147e0ae51b2970b-800wi){.fcmw35 .s}  
*Facebook Social Network Map <br> Vertex = person; edge = social relationship* 
:::
:::

::: {.f .ffrn .jcse .g}
::: {.flexbox .vcenter}
![](https://allthingsgraphed.com/public/images/twitter/twitter-follower-graph-avatars.png){.fcmw25 .s}  
*Twitter followers <br> Vertex = Twitter account; edge = Twitter follower* 
:::
::: {.flexbox .vcenter}
![](https://www.researchgate.net/publication/314491781/figure/fig5/AS:470414003576837@1489166846626/Protein-protein-network-analysis-based-on-regulated-genes-in-HEK293-cells-Interactions.png){.fcmw3 .s}  
*Protein-protein interation network <br> Vertex = protein; edge = interaction* 
:::
:::

::: notes

:::


<!-- SLIDE 6 -->
## Applications... {.fff}

| graph | vertex | edge |
| :-- | :--: | :--: |
| cell phone | phone | placed call |
| infectious disease | person | infection |
| financial | stock, currency | transactions |
| transportation | intersection | street |
| internet | router | fiber cable |
| web | web page | URL link |
| social relationship | person | friendship |


<!-- SLIDE 7 -->
## Undirected Graphs {.fff}

::: {.f .ffrn .jcse .g}
::: {.f .ffcn}

#### <i class="rhody">Graph</i> 
- a set of <i class="rhody">vertices</i> connect pairwise by <i class="rhody">edges</i>  

#### <i class="rhody">Path</i> 
- sequence of vertices connected by edges, with no repeated edges  

:::
::: {.f .ffcn}
#### <i class="rhody">Definition</i> 
- two vertices are <i class="rhody">connected</i> if there is a path between them  

#### <i class="rhody">Cycle</i>
- path (with $\ge 1$ edge) whose first and last vertices are the same  
:::
:::

::: {.flexbox .vcenter .fff}
![](../img/19_01.png){.fcmw7}
:::

<!-- SLIDE 8 -->
## Directed graphs {.fff}

::: {.f .ffrn .jcse .g}
::: {.f .ffcn}

#### <i class="rhody">Digraph</i> 
- a set of <i class="rhody">vertices</i> connect pairwise by <i class="rhody">directed</i> edges 

#### <i class="rhody">Directed Path</i> 
- sequence of vertices connected by edges, with no repeated edges  

::: 
::: {.f .ffcn}
#### <i class="rhody">Definition</i> 
- vertex $w$ is <i class="rhody">reachable</i> from vertex $v$ if there is a directed path from $v$ to $w$  

#### <i class="rhody">Directed Cycle</i>
- directed path (with $\ge 1$ edge) whose first and last vertices are the same  
:::
:::

::: {.flexbox .vcenter .fff}
![](../img/19_02.png){.fcmw65}
:::

<!-- SLIDE 9 -->
## Graph Processing Problems {.fff}

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


## {.flexbox .vcenter .fff}

### *_REPRESENTATION_*


## Digraph {.fff}

#### <i class="rhody">Vertex representation</i>
- for 0 through all positive values $V-1$
- Applications: use <i class="rhody">symbol table</i> to convert between names and integers

::: flxrg
![](../img/19_03.png){.fcmw5}
:::

#### <i class="rhody">Definition</i>
- a digraph is <i class="rhody">simple</i> if it has no self-loops or parallel edges

::: flxrg
![](../img/19_04.png){.fcmw5}
:::


## Adjacency-matrix {.fff}

#### Maintain a $V$-by-$V$ boolean array; for each edge $v \rightarrow w$ in the digraph: 
#### $$adj[v][w] \ =\ true$$

::: flxrg
![](../img/19_05.png){.fcmw75}
:::


## Adjacency-lists {.fff}

#### Maintain vertex-indexed array of lists

<br>

::: flxrg
![](../img/19_06.png){.fcmw65}
:::


## In Practice {.fff}

#### Use adjacency-lists
- Algorithms based on iterating over vertices adjacent from $v$
- Real-world graphs tend to be <i class="rhody">sparce</i> ($\Theta(V)$ edges), not <i class="rhody">dense</i> ($\Theta(V^2)$ edges)

<br>

| representation | space | add edge from <br> $v$ to $w$ | has edge from <br> $v$ to $w$ | iterate over vertices <br> adjacent from $v$? |
| :--: | :--: | :--: | :--: | :--: |
| adjacent matrix | $V^2$ | 1<sup>*</sup> | 1 | $V$ |
| adjacent lists | $E+V$ | 1 | $outdegree(v)$ | $outdegree(v)$ |

\* disallows parallel edges


## {.flxcn}

::: {.flxcn .mh60}
### *_DEPTH-FIRST SEARCH_*
:::

## Reachability {.fff}

#### <i class="rhody">Problem</i>
- Given a digraph $G$ and vertex $s$, find all the vertices <i class="rhody">reachable</i> from $s$

::: flxrg
![](../img/19_07.png){.fcmw35}
:::


## Depth-first search {.fff}

#### <i class="rhody">Goal</i>
- Systemically traverse a digraph

<br>

::: flxrg
::: flxcn
```cpp
void Graph::dfs( Vertex v )
{
  v.visited = true;
  for each Vertex w adjacent to v
    if( !w.visited )
      dfs( w );
}
```
:::
:::

<br>

#### <i class="rhody">Typical applications</i>
- Reachability: finding all vertices reachable from a given vertex
- Path finding: find directed path from one vertex to another


## Directed depth-first search {.fff}

To visit vertex $v$:  
- Mark vertex $v$  
- Recursively visit all unmarked vertices adjacent from $v$ 

<hr>

::: flxrg
::: flxcn
::: flxrg
::: flxc
![](../img/19_08.png){.fcmw35}

*a directed graph*
:::
::: flxc
![](../img/19_09.png){.fcmw05}

*directed edges*
:::
:::
:::
:::

::: notes
::: {.flxrg .blk}
::: flxcn
![](../img/19_10.png){.fcmw35}

*reachable from $0$*
:::
::: flxcn
![](../img/19_11.png){.fcmw15}

*reachable from vertex $0$*
:::
:::
:::


## DFS: properties {.fff}

#### <i class="rhody">Proposition</i>
- DFS marks all vertices reachable from $s$ in $\Theta(E+V)$ time in the worst case

<br>

#### <i class="rhody">Proof</i>
- Initializing an array of length $v$ takes $\Theta(V)$ time
- Each vertex is visited at most once
- Visiting a vertex takes time proportional to its outdegree:
$$outdegree(v_0) + outdegree(v_1) + outdegree(v_2) + \dots = E$$
$$in\ worst\ case,\ all\ V\ vertices\ reachable\ from\ s$$

<br>

#### <i class="rhody">Note</i>
- If all vertices are reachable from $s$, then $E \ge V - 1$, so $V$ is a lower-order term


## Reachability application: program control-flow analysis {.fff}

::: flxrg
::: flxc
#### <i class="rhody">Ever program is a digraph</i>
- Vertex = basic block of instructions (straight-line program)
- Edge = jump

<br>

#### <i class="rhody">Dead-code elimination</i>
- Find (and remove) unreachable code

<br>

#### <i class="rhody">Infinite-loop detection</i>
- Determine whether exit is unreachable
:::
::: flxcn
![](../img/19_12.png){.fcmw35}
:::
:::


## Reachability application: mark-sweep garbage collection {.fff}

::: flxrg
::: flxc
#### <i class="rhody">Ever program is a digraph</i>
- Vertex = basic block of instructions (straight-line program)
- Edge = jump

<br>

#### <i class="rhody">Roots</i>
- Objects known to be directly accessible by a program (eg stack frame)

<br>

#### <i class="rhody">Reachable objects</i>
- Objects indirectly accessible by program (starting at a root and following a chain of pointers)

<br>

#### <i class="rhody">Mark-sweep algorithm</i> 
- Mark: mark all reachable objects
- Sweep: if object is unmarked, it is garbage (so add to free list)

<br>

#### <i class="rhody">Memory cost</i>
- Uses 1 extra mark bit per object (plus DFS function-call stack)
:::
::: flxcn
![](../img/19_13.png){.fcmw35}
:::
:::


<!-- SLIDE 3 -->
## {.flexbox .vcenter .fff}

### *_PATH FINDING_* 


## Directed paths DFS {.fff}

#### <i class="rhody">Goal</i>
- DFS determines which vertices are reachable from s. How to reconstruct paths?

#### <i class="rhody">Solution</i>
- Use <i class="rhody">parent-link representation</i>

::: flxrg
::: flxcn
![](../img/19_10.png){.fcmw35}

*reachable from $0$*
:::
::: flxcn
![](../img/19_14.png){.fcmw2}

*parent-link representation of paths from vertex $0$*
:::
:::


## DFS: path finding {.fff}

#### <i class="rhody">Parent-link representation of paths from $s$</i>
- Maintain an integer array $edgeTo[]$  
- Interpretation: $edgeTo[v]$ is the next-to-last vertex on a path from $s$ to $v$  
- To reconstruct path from $s$ to $v$, trace $edgeTo[]$ backward from $s$ to $v$ (and reverse)

<br>

::: flxrg
::: flxcn
![](../img/19_15.png){.fcmw3}
:::
::: flxcn
![](../img/19_16.png){.fcmw25}
:::
::: flxrg
```cpp
public Iterable<Integer> pathTo(int v) {
  if (!marked[v]) return null; 
  Stack<Integer> path = new Stack<>(); 
  for (int x = v; x != s; x = edgeTo[x]) 
    path.push(x); 
  path.push(s); 
  return path; 
}
```
:::
:::


## {.flexbox .vcenter .fff}

### *_UNDIRECTED GRAPHS_* 

## Flood Fill {.fff}

#### <i class="rhody">Problem</i>
- Implement flood fill (Photoshop magic wand)

<br>

::: flxrg
::: flxcn
![](https://static.wixstatic.com/media/bb1bd6_591167b0be9940758124b35badf1da3a~mv2.gif){.fcmw65}

*magic wand tool*
:::
:::


## DFS: undirected graphs {.fff}

#### <i class="rhody">Problem</i>
- Given an undirected graph $G$ and vertex $s$, find all vertices connected to $s$

#### <i class="rhody">Solution</i>
- Treat undirected graph as a digraph, replacing each edge with two antiparallel edges

<br>

::: flxrg
::: flxcn
```cpp
DFS (to visit a vertex v)
------------------------
Mark vertex v.
Recursively visit all unmarked
    vertices w adjacent to v
------------------------
```
:::
:::

<br>

#### <i class="rhody">Typical applications</i>
- Find all vertices connected to a given vertex
- Find a path between two vertices


## DFS: undirected search {.fff}

To visit vertex $v$:  
- Mark vertex $v$  
- Recursively visit all unmarked vertices adjacent from $v$ 

<hr>

::: flxrg
::: flxcn
::: flxrg
::: flxc
![](../img/19_17.png){.fcmw45}

*graph g*
:::
::: flxc
![](../img/19_18.png){.fcmw1}

*connected edges*
:::
:::
:::
:::

::: notes
::: {.flxrg .blk}
::: flxcn
![](../img/19_19.png){.fcmw35}

*vertices connected to $0$<br>(and associated paths)*
:::
::: flxcn
![](../img/19_20.png){.fcmw15}
:::
:::
:::


## Graph search {.fff}

#### <i class="rhody">Tree traversal</i> Many ways in a binary tree

<br>

::: flxrg
::: flxc
stack/recursion  

- Inorder | A C E H R S X |  
- Preorder | S E A C R H M X |  
- Postorder | C A M H R E X S |  

queue  

- Level-order | S E X A R C H M |
:::
:::flxc
![](../img/19_21.png){.fcmw3}
:::
:::

#### <i class="rhody">Graph search</i> Many ways to explore a graph

<br>

- DFS preorder: vertices in order of calls to $dfs(G,v)$
- DFS postorder: vertices in order of return calls from $dfs(G,v)$
- Breadth-first: vertices in increasing order of distance from $s$

## {.flexbox .vcenter .fff}

### *_BREADTH-FIRST SEARCH_* (in digraphs) 

## Shortest paths in a digraph {.fff}

#### <i class="rhody">Problem</i> Find directed path from $s$ to each other vertex that uses the <i class="rhody">fewest edges</i>

<br>

::: flxrg
::: flxcn
![](../img/19_22.png){.fcmw3}
:::
:::

<br>

::: flxrg
::: flxcn
#### <i class="rhody">directed paths from $0$ to $6$</i>
:::
::: flxcn
#### <i class="rhody">shortest path from $0$ to $6 (length = 4)$</i>
:::
:::
::: flxrg
::: flxcn
$$0 \rightarrow 2  \rightarrow 7  \rightarrow 4  \rightarrow 5  \rightarrow 1  \rightarrow 3  \rightarrow 6  $$
$$0 \rightarrow 4  \rightarrow 5  \rightarrow 1  \rightarrow 3  \rightarrow 6   $$
$$0 \rightarrow 2  \rightarrow 7  \rightarrow 3  \rightarrow 6 $$
$$0 \rightarrow 2  \rightarrow 7  \rightarrow 0  \rightarrow 2  \rightarrow 7  \rightarrow 3  \rightarrow 6  $$
:::
::: flxcn
$$0 \rightarrow 2  \rightarrow 7  \rightarrow 3  \rightarrow 6 $$
$$ $$
$$ $$
$$ $$
$$ $$
:::
:::


## Shortest paths in a digraph {.fff}

#### <i class="rhody">Problem</i> Find directed path from $s$ to each other vertex that uses the <i class="rhody">fewest edges</i>

<br>

#### <i class="rhody">Key idea</i> Visit vertices in increasing order of distance from $s$

<br>

::: flxrg
![](../img/19_23.png){.fcmw75}
:::

<br>

#### <i class="rhody">Key data structure</i> Queue of vertices to visit


## Breadth-first search {.fff}

Repeat until queue is empty:  
- Remove vertex $v$ from queue  
- Add to queue all unmarked vertices adjacent from $v$ and mark them

<hr>

::: flxrg
::: flxcn
::: flxrg
::: flxc
![](../img/19_24.png){.fcmw45}

*graph g*
:::
::: flxc
![](../img/19_25.png){.fcmw2}

*&nbsp;*
:::
:::
:::
:::


## Breadth-first search, con't {.fff}

Repeat until queue is empty:  
- Remove vertex $v$ from queue  
- Add to queue all unmarked vertices adjacent from $v$ and mark them

<hr>

::: flxrg
::: flxcn
::: flxrg
::: flxc
![](../img/19_26.png){.fcmw45}

*vertices reachable from $0$<br>(and the shortest directed paths)*
:::
::: flxc

| $v$ | $edgeTo[]$ | $marked[]$ | $distTo[]$ |
| :--: | :--: | :--: | :--: |
| 0 | - | T | 0 | 
| 1 | 0 | T | 1 |
| 2 | 0 | T | 1 |
| 4 | 2 | T | 2 |
| 3 | 4 | T | 3 |
| 5 | 3 | T | 4 |

:::
:::
:::
:::


## Breadth-first search, con't {.fff}

Repeat until queue is empty:  
- Remove vertex $v$ from queue  
- Add to queue all unmarked vertices adjacent from $v$ and mark them

<br><hr><br>

::: flxrg
::: flxcn
```cpp
BFS (from source s)
-----------------------------------------------
Add s to FIFO queue and mark s
Repeat until the queue is marked empty:
- remove the least recently added vertex
- for each unmarked vertex w adjacent from v:
  - add w to queue and mark w
```
:::
:::


## Breadth-first search properties {.fff}

#### <i class="rhody">Proposition</i> In the worst case, BFS takes $\Theta(E + V)$ time

#### <i class="rhody">Proof</i> Each vertex reachable from $s$ is visited once

<br>

#### <i class="rhody">Proposition</i> BFS computes shortest paths from $s$

#### <i class="rhody">Proof</i> BFS examines vertices in increasing distance (number of edges) from $s$

<br><hr><br>

::: flxrg
::: flxcn
::: flxrg
::: flxc
![](../img/19_28.png){.fcmw45}

*digraph G*
:::
::: flxc
![](../img/19_29.png){.fcmw5}

*&nbsp;*
:::
:::
:::
:::


## Single-sink Shortest Paths {.fff}

Given a digraph and a <i class="rhody">target</i> vertex $t$, find shortest path from every vertex to $t$.

::: flxrg
::: flxc
<i class="rhody">Example</i> $t = 0$  

- Shortest path from $7$ 
  - is $7 \rightarrow 6 \rightarrow 0$  
- Shortest path from $5$ 
  - is $5 \rightarrow 4 \rightarrow 2 \rightarrow 0$  
- Shortest path from $12$ 
  - is $12 \rightarrow 9 \rightarrow 11 \rightarrow 4 \rightarrow 2 \rightarrow 0$  
:::
::: flxcn
![](../img/19_30.png){.fcwm75}
:::
:::


## Multiple-source Shortest Paths {.fff}

Given a digraph and a <i class="rhody">set</i> of source vertices, find shortest path from <i class="rhody">any</i> vertex in the set to every other vertex

::: flxrg
::: flxc
<i class="rhody">Example</i> $S = \{ 1, 7, 10 \}$  

- Shortest path to $4$
  - is $7 \rightarrow 6 \rightarrow 4$
- Shortest path to $5$
  - is $7 \rightarrow 6 \rightarrow 0 \rightarrow 5$
- Shortest path to $12$
  - is $10 \rightarrow 12$  
:::
::: flxcn
![](../img/19_31.png){.fcwm75}
:::
:::


## {.flexbox .vcenter .fff}

### *_BREADTH-FIRST SEARCH_* (in graphs) 

## Breadth-first search application: routing

Fewest number of hops in a communication network

::: flxrg
![](https://images.theconversation.com/files/144160/original/image-20161102-27228-1iicfpi.jpg?ixlib=rb-1.1.0&q=45&auto=format&w=600&h=390&fit=crop&dpr=1){.fcmw75}
:::


## BFS: undirected graphs {.fff}

#### <i class="rhody">Problem</i> Find path between $s$ and each other vertex that uses fewest edges

#### <i class="rhody">Solution</i> Treat as a digraph, replacing each undirected edge with two antiparallel edges

<br><hr><br>

::: flxrg
::: flxcn
```cpp
BFS (from source s)
-----------------------------------------------
Add s to FIFO queue and mark s
Repeat until the queue is empty:
- remove the least recently added vertex v
- for each unmarked vertex w adjacent from v:
  - addw to queue and mark w
```
:::
:::


## {.flexbox .vcenter .fff}

### *_SUMMARY_*

## Graph traversal

BFS and DFS enables efficient solution to many (but not all) graph and digraph problems

<br> 

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

<style>
#c1 {
    background: url(../img/19_c1p.png) center no-repeat;
    background-size: contain;
    width: 250px;
    height: 250px;
}

#c1:hover {
  background: url(../img/19_c1s.png) center no-repeat;
  background-size: contain;
}

.bord {
  width: 50px;
  height: 30px;
  padding: 10px;
  border: 1px solid #aaaaaa;
}
</style>
<script>
function allowDrop(ev) {
  ev.preventDefault();
}

function drag(ev) {
  ev.dataTransfer.setData("Text", ev.target.id);
}

function drop(ev) {
  var data = ev.dataTransfer.getData("Text");
  ev.target.appendChild(document.getElementById(data));
  ev.preventDefault();
}
</script>
