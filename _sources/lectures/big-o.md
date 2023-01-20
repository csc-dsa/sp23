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
</style>

# Big-O Notiation

`````````` {div} full-width
```` {card}
``` {image} https://big-o.io/assets/graph_animated.svg
```

``` {image} https://era86.github.io/assets/images/posts/big-o-chart.png
```
````
``````````

## The story so far...

`````````` {div} full-width
``` {card}
Can measure actual runtime to compare algorithms  
- however, runtime is noisy (highly sensitive to hardware/software and implementation details)
```

``` {card}
Can count instructions to compare algorithms  
- can define $T(n)$, which depends on the input size  
- for large inputs, our focus should be on the dominant terms of $T(n)$
```
``````````

## Inline Math

`````````` {div} full-width
``` {card}
$$\sum_{i = 1}^n i = 1 + 2 + 3 + \dots + (n - 1) + n$$
```

```` {card}
$$\sum_{i = 1}^{n - 1} i = 1 + 2 + 3 + \dots + (n - 2) + (n - 1)$$

``` {image} imgs/04_s05.png
:width: 600px
:class: centered

```

````

```{margin} Desmos
[Desmos : Graphing Calculator](https://www.desmos.com/calculator/7vmsklh8o9)  
Used to create the images below...
```
``````````

## Comparing Algorithms

### Comparing two algorithms, respectively

``````` {div} full-width
`````` {card} $Are\ these\ the\ same?$

$$\color{green}{T(n) = 2n} \ \ \ \ \ \ \ \ \color{orange}{T(n) = 25n}$$

````` {grid}

```` {grid-item-card}
:columns: 6
:text-align: center

<iframe src="https://www.desmos.com/calculator/61er8lxhiy?embed" width="450" height="400" style="border: 1px solid #ccc" frameborder=0></iframe>
````

````{grid-item-card}
:columns: 6
:text-align: center

<iframe src="https://www.desmos.com/calculator/amlwrfh9sd?embed" width="450" height="400" style="border: 1px solid #ccc" frameborder=0></iframe>
````

`````

$$Why\ / Why\ Not?$$

````` {admonition} Explantion
:class: dropdown, important
Looking closely at the graphs, the left graph has low input ($n$) values...when we look to the right and reveal the graph for high input ($n$) values, the behavior of the lines on the graph remains the same. Therefore the algorithms themselves are the same...
`````

``````
```````

### Comparing three algorithms, respectively

``````` {div} full-width
`````` {card} $Are\ these\ the\ same?$

$$\color{green}{T(n) = 2n} \ \ \ \ \ \ \ \ \color{orange}{T(n) = 25n} \ \ \ \ \ \ \ \ \color{blue}{T(n) = n^2}$$

````` {grid}

```` {grid-item-card}
:columns: 12 12 4 4
:text-align: center

<iframe src="https://www.desmos.com/calculator/z8ay5kpdtl?embed" width="250" height="400" style="border: 1px solid #ccc" frameborder=0></iframe>
````

````{grid-item-card}
:columns: 12 12 4 4
:text-align: center

<iframe src="https://www.desmos.com/calculator/8zgxexrima?embed" width="250" height="400" style="border: 1px solid #ccc" frameborder=0></iframe>
````

````{grid-item-card}
:columns: 12 12 4 4
:text-align: center

<iframe src="https://www.desmos.com/calculator/eq5m3nq2zq?embed" width="250" height="400" style="border: 1px solid #ccc" frameborder=0></iframe>
````

`````

$$Why\ / Why\ Not?$$

````` {admonition} Explantion
:class: dropdown, important
Looking closely at the graphs, the left graph has low input ($n$) values...when we look to the right and reveal the graph for high input ($n$) values, the behavior of the lines on the graph remains the same. Therefore the algorithms themselves are the same...
`````

``````
```````

### Comparing two algorithms, respectively, again...

``````` {div} full-width
`````` {card} $Are\ these\ the\ same?$

$$\color{green}{T(n) = 1000n + 500} \ \ \ \ \ \ \ \ \color{orange}{T(n) = n^2}$$

````` {grid}

```` {grid-item-card}
:columns: 12 12 6 6
:text-align: center

<iframe src="https://www.desmos.com/calculator/rcyaujqwho?embed" width="450" height="200" style="border: 1px solid #ccc" frameborder=0></iframe>
````

````{grid-item-card}
:columns: 12 12 6 6
:text-align: center

<iframe src="https://www.desmos.com/calculator/c1bcn6r7wx?embed" width="450" height="200" style="border: 1px solid #ccc" frameborder=0></iframe>
````

`````

````` {grid}

```` {grid-item-card}
:columns: 12 12 6 6
:text-align: center

<iframe src="https://www.desmos.com/calculator/ifozextlng?embed" width="450" height="200" style="border: 1px solid #ccc" frameborder=0></iframe>
````

````{grid-item-card}
:columns: 12 12 6 6
:text-align: center

<iframe src="https://www.desmos.com/calculator/4ii7sbfoom?embed" width="450" height="200" style="border: 1px solid #ccc" frameborder=0></iframe>
````

`````

$$Why\ / Why\ Not?$$

``````

```````

### Bottom line...

`````````` {div} full-width
```` {card}
``` {card}
We are trying to compare $T(n)$ functions, but...
- we also care about large values of $n$  
```

``` {card}
Can we properly define $\le$ for functions?
- we can group functions into $sets$ and make our lives easier
```
````

## Asymptotic Analysis

`````````` {div} full-width
``` {card}
- refers to the study of an algorithm as the input size “gets big” or reaches a limit (in the calculus sense)
```
``````````

### Growth rate

`````````` {div} full-width
````` {card}

``` {card}
- rate at which the cost of an algorithm grows as the size of its input grows
```

```` {grid}
``` {grid-item-card}
$$c_1n$$
```
``` {grid-item-card}
$$c_2n^2$$
```
````
`````
``````````

### Common sets of functions

`````````` {div} full-width
````` {grid}
```` {grid-item-card}
``` {image} imgs/04_s11.png
```
````
```` {grid-item-card}
Algorithm $A$ is better than Algorithm $B$ if... 

- for large values of $n$, $TA(n)$ grows slower than $TB(n)$

_Note: Faster growth rate...slower algorithm..._

````

`````
``````````

#### Examples

````` {div} full-width
``` {list-table}
:header-rows: 1

* - order of growth
  - name
  - typical code framework
  - description
  - example
* - $$1$$
  - **constant**
  - $$a = b + c;$$
  - statement
  - add two numbers
* - $$log\ n$$
  - **logarithmic**
  - $$while\ (n > 1)\\ \{ \ \ \ \ \ \ \ \dots \ \ \ \ \ \ \ \}$$
  - divide in half
  - binary search
* - $$n$$
  - **linear**
  - $$for\ (int\ i\ = 0; i \lt n; i++)\\ \{ \ \ \ \ \ \ \ \dots \ \ \ \ \ \ \ \}$$
  - single loop
  - find the maximum
* - $$n\ log\ n$$
  - **linearithmic**
  - $$see\ mergesort$$
  - divide & conquer
  - mergesort
* - $$n^2$$
  - **quadratic**
  - $$for\ (int\ i\ = 0; i \lt n; i++)\ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \\ for\ (int\ j\ = 0; j \lt n; j++)\ \ \ \ \ \ \ \ \ \\ \ \ \ \ \ \ \ \ \{ \ \ \ \ \ \ \ \dots \ \ \ \ \ \ \ \}$$
  - double loop
  - check all pairs
* - $$n^3$$
  - **cubic**
  - $$for\ (int\ i\ = 0; i \lt n; i++)\ \ \ \ \ \ \ \ \ \ \ \ \ \ \\ for\ (int\ j\ = 0; j \lt n; j++)\ \ \ \ \ \ \ \ \ \\ \ \ \ \  for\ (int\ k\ = 0; k \lt n; k++)\\ \{ \ \ \ \ \ \ \ \dots \ \ \ \ \ \ \ \}$$
  - double loop
  - check all pairs
* - $$2^n$$
  - **exponential**
  - $$see\ combinatorial\ search$$
  - exhaustive search
  - check all subsets
```
`````

### Big-O

````` {div} full-width
```` {admonition} Definiiton

``` {image} imgs/04_s13.png
:width: 90%
:align: center
```

``` {card} Translation
$T$ of $n$ is upper bounded by $F$ of $n$ if and only if $T$ of $n$ is less than or equal to some constant $C$ times $F$ of $n$ the function we chose to bound with for all $N$ greater than the initial $n$ or and not
```

``` {card} Examples

$$\begin{align}
7n - 2 & = O(n) \\
20n^3 + 10n\ log\ n + 5 & = O(n^3) \\
3\ log\ n + log\ log\ n & = O(log\ n) \\
2^{100} & = O(1)
\end{align}$$
```

````
`````

### Big-Omega ($\Omega$)

````` {div} full-width
```` {admonition} Definition
``` {image} imgs/04_s15.png
:width: 90%
:align: center
```
````
`````

### Theta ($\Theta$)

````` {div} full-width
```` {admonition} Definition
``` {image} imgs/04_s16.png
:width: 90%
:align: center
```
````
`````

### Prove it!!

````` {div} full-width
``` {card}

$$3\ log\ n\ + log\ log\ n\ = Ω(log\ n)$$
$$3\ log\ n\ + log\ log\ n\ = Θ(log\ n)$$

^^^


+++

$$T(n)\ is\ O( f(n))\ ⟺\ ∃\  positive\  c, n_0\ ∣\ 0 ≤ T(n)\ ≤ cf(n), ∀n ≥ n0$$
$$T(n)\ is\ Ω( f(n))\ ⟺\ ∃\  positive\  c, n_0\ ∣\ 0 ≤ cf(n)\ ≤ T(n), ∀n ≥ n0$$

```

<!-- ``` {image} https://qph.cf2.quoracdn.net/main-qimg-bbaf8a664d7d89b6e469cd4738f7bedf
```

Blue Curve: $O(log\ n)$, Green Curve: $O(log(log\ n)$ -->

`````

### In practice...

``` {card}
“ignore constants and drop lower order terms”
```

### True or False?

```````` {div} full-width

$$Time\ Complexities:\ {1, log\ n, n, n\ log\ n, n^2, 2^n, n!}$$

``````` {card}

`````` {tab-set}

````` {tab-item} Test yourself

_Click near the center of a cell in each respective column to type your response..._

```` {card}

``` {list-table}
:header-rows: 1

* - 
  - $$Big\ O$$
  - $$Big\ \Omega$$
  - $$\Theta$$
* - $$10^2 + 3000n + 10$$
  - <span contenteditable></span>
  - <span contenteditable></span>
  - <span contenteditable></span>
* - $$21\ log\ n$$
  - <span contenteditable></span>
  - <span contenteditable></span>
  - <span contenteditable></span>
* - $$500\ log\ n + n^4$$
  - <span contenteditable></span>
  - <span contenteditable></span>
  - <span contenteditable></span>
* - $$\sqrt{n} + log\ n^{50}$$
  - <span contenteditable></span>
  - <span contenteditable></span>
  - <span contenteditable></span>
* - $$4^n + n^{5000}$$
  - <span contenteditable></span>
  - <span contenteditable></span>
  - <span contenteditable></span>
* - $$3000n^3 + n^{3.5}$$
  - <span contenteditable></span>
  - <span contenteditable></span>
  - <span contenteditable></span>
* - $$2^5 +n!$$
  - <span contenteditable></span>
  - <span contenteditable></span>
  - <span contenteditable></span>

```

````

`````

````` {tab-item} Outcomes

```` {card}

``` {list-table}
:header-rows: 1

* - 
  - $$Big\ O$$
  - $$Big\ \Omega$$
  - $$\Theta$$
* - $$10^2 + 3000n + 10$$
  - $$\ge n$$
  - $$\le n$$
  - $$true$$
* - $$21\ log\ n$$
  - $$\ge log\ n$$
  - $$\le log\ n$$
  - $$true$$
* - $$500\ log\ n + n^4$$
  - $$\ge n^2$$
  - $$\le log\ n$$
  - $$false$$
* - $$\sqrt{n} + log\ n^{50}$$
  - $$\ge log\ n$$
  - $$\le log\ n$$
  - $$true$$
* - $$4^n + n^{5000}$$
  - $$\ge 2^n$$
  - $$\le n^2$$
  - $$false$$
* - $$3000n^3 + n^{3.5}$$
  - $$\ge n^2$$
  - $$\le 1 n^2$$
  - $$true$$
* - $$2^5 +n!$$
  - $$\ge n!$$
  - $$\le n!$$
  - $$true$$

```

````

`````

``````

```````

````````

### Asymptotic Performance

`````````` {div} full-width
``` {card}
For $large$ values of $n$, a $Θ(n^2)$ algorithm always beats a $Θ(n^3)$ algorithm

_However, we shouldn’t completely ignore asymptotically slower algorithms_
```
``````````
