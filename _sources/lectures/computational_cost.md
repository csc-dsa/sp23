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

# Computational Cost

## Analyzing running time

`````` {div} full-width
````` {card}
```` {grid}

``` {grid-item-card} Empirical Model
- **Run** algorithm
- Measure actual time
```

```{grid-item-card} Mathematical Model
- **Analyze** algorithm
- Develop Model
```

````
`````
``````

## Theoretical Models

`````` {div} full-width
````` {card}
```` {grid}
```{grid-item-card} Mathematical Model
- High-level analysis
  - <b class="brown">no need to implement</b>
- Independent of hardware / software
- Based on **counts** of basic <b class="brown">instructions</b>
  - additions, multiplications, comparisons,etc
  - exact definition <u>not important</u> but <b class="brown">must be relevant</b> to the problem
```

```{grid-item-card} Basic assumptions
- In order to use a **formal framework**, we will make  certain assumptions
  - count basic instructions: additions, multiplications, comparisons, assignments
  - each instruction takes one time unit
  - instructions are executed sequentially
  - infinite memory
- Focus on <span class="green">analyzing <b>running time</b></u>
```
````
`````
``````

### Example

``````` {div} full-width
`````` {card}
What to count?
- only relevant instructions? 
- all instructions?

```{code-block} cpp
:lineno-start: 1
:emphasize-lines:

for (int i = 0; i < n; i++) {
    std::cout << (2 * i);
}
```
- lets also plot both cases...

````` {admonition} Why...
:class: dropdown, tip

```` {card} $O(N)$ – Linear Time Algorithms  

> The $O(n)$ is also called linear time, it is in direct proportion to the number of inputs. For example, if the array has 6 items, it will print 6 times. 
>
> _Note: In $O(n)$ the number of elements increases, the number of steps also increases._
>
> -- [codingninjas.com](https://www.codingninjas.com/blog/2021/01/05/what-is-big-o-notation/)

````

```` {card} Graphical View

::: {image} img/w3_04.png

:::

````

:::: {card} Time Complexity

Here we have only one loop: 

```{code-block} cpp
:lineno-start: 1
:emphasize-lines:

for (int i = 0; i < n; i++)
```  

Disregarding the looping body, we can see from the stopping parameter, the loop will run $n$-times.  

Therefore the time complexity for this loop is: $O(n)$

::::

```` {card} Summation Notation

If we assume $n\ = 5$, (an arbitrary value):

$$\begin{align}
\sum_{i=0}^{n} 2 * i & = (2 * 0) + (2 * 1) + (2 * 2) + (2 * 3) + (2 * 4)  \\
& = 0 + 2 + 4 + 6 + 8 \\
& = 20
\end{align}$$

````


`````

``````
```````

### Example 1

``````` {div} full-width
`````` {card}

````` {code-block} cpp
:lineno-start: 1
:emphasize-lines:

for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        std::cout << (i * j);
    }
}
`````

````` {admonition} Why...
:class: dropdown, tip

``` {card} $O(N^2)$ – Polynomial-Time Algorithms

>  The $O(N^2)$ is also called quadratic time, it is directly proportional to the square of the input size. For example, if the array has 3 items, it will print nine times. 
>
> _Note: In $O(N^2)$ as the number of steps increases exponential, the number of elements also increases. It is the worst-case Time Complexity method._

```

``` {card} Graphical View

::: {image} img/w3_05.png
:::

From the outcomes directly, it can be difficult to tell which complexity we're seeing, but when we apply a trendline to show the progression/shape of the graph, the complexity becomes clear.

```

:::: {card} Time Complexity

```{code-block} cpp
:lineno-start: 1
:emphasize-lines:

# Pseudo
#
# for I in 1 .. N loop 
#    for J in 1 .. M loop
#        sequence of statements 
#    end loop;
# end loop;

// first loop
for (int i = 0; i < n; i++) {            // -> N + 1
    // second loop
    for (int j = 0; j < n; j++) {        // -> M * (N + 1)
        std::cout << (i * j);            // output -> N * M
    }
}
                                         // Time complexity = O(N^2)
```  

> The outer loop executes N times. Every time the outer loop executes, the inner loop executes M times. As a result, the statements in the inner loop execute a total of N * M times. Thus, the complexity is O(N * M).
> 
> -- [Big O Notation #Nested Loops](https://web.mit.edu/16.070/www/lecture/big_o.pdf)

Recall, working with nested loops, complexity is $O(N \times M)$

Therefore the time complexity for this loop is: $O(N^2)$

::::

``` {card} Summation Notation

If we assume $n\ = 3$, (an arbitrary value):

$$\begin{align}
\sum_{i=0}^{n} \sum_{j=0}^{n} i \times j & = \\
& = (0 \times 0) + (0 \times 1) + (0 \times 2) + \\
& \ \ \ \ \ (1 \times 0) + (1 \times 1) + (1 \times 2) + \\
& \ \ \ \ \ (2 \times 0) + (2 \times 1) + (2 \times 2)  \\
\\
& = 0 + 0 + 0 + 0 + 1 + 2 + 0 + 2 + 4 \\
& = 1 + 2 + 2 + 4 \\
& = 9
\end{align}$$

```

`````

``````
```````

### Example 2

`````````` {div} full-width
`````` {card}
````` {code-block} cpp
:lineno-start: 1
:emphasize-lines:

for (int i = 0; i < n; i++) {
    for (int j = 0; j < n * n; j++) {
        std::cout << (i * j);
    }
}
`````
````` {admonition} Why...
:class: dropdown, tip



``` {card} Summation Notation

If we assume $n\ = 3$, (an arbitrary value):

$$\begin{align}
\sum_{i=0}^{n = 3} \sum_{j=0}^{n \times n = 9} i \times j & = \\
& = (0 \times 0) + (0 \times 1) + (0 \times 2) + (0 \times 3) + (0 \times 4) + (0 \times 5) + (0 \times 6) + (0 \times 7) + (0 \times 8) + \\
& \ \ \ \ \ (1 \times 0) + (1 \times 1) + (1 \times 2) + (1 \times 3) + (1 \times 4) + (1 \times 5) + (1 \times 6) + (1 \times 7) + (1 \times 8) + \\
& \ \ \ \ \ (2 \times 0) + (2 \times 1) + (2 \times 2) + (2 \times 3) + (2 \times 4) + (2 \times 5) + (2 \times 6) + (2 \times 7) + (2 \times 8) + \\
\\
& = 0 + 0 + 0 + 0 + 0 + 0 + 0 + 0 + 0 \\
& \ \ \ \ \ 0 + 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8\\
& \ \ \ \ \ 0 + 2 + 4 + 6 + 8 + 10 + 12 + 14 + 16  \\
& = 108
\end{align}$$

```

`````
``````
``````````

### Example 3

`````````` {div} full-width
`````` {card}
````` {code-block} cpp
:lineno-start: 1
:emphasize-lines:

for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
        sum = sum * j;
    }
}
`````
````` {admonition} Why...
:class: dropdown, tip

``` {card} $O(N^2)$ – Polynomial-Time Algorithms

>  The $O(N^2)$ is also called quadratic time, it is directly proportional to the square of the input size. For example, if the array has 3 items, it will print nine times. 
>
> _Note: In $O(N^2)$ as the number of steps increases exponential, the number of elements also increases. It is the worst-case Time Complexity method._

```

``` {card} Graphical View

::: {image} img/w3_07.png
:::

From the outcomes directly, it can be difficult to tell which complexity we're seeing, but when we apply a trendline to show the progression/shape of the graph, the complexity becomes clear.

```

:::: {grid}

::: {grid-item-card} Time Complexity

``` {code-block} cpp
:lineno-start: 1
:emphasize-lines:

# Pseudo
#
# for I in 1 .. N loop 
#    for J in 1 .. M loop
#        sequence of statements 
#    end loop;
# end loop;

// first loop
for (int i = 0; i < n; i++) {
    // second loop
    for (int j = 0; j < i; j++) {
        std::cout << (i * j); 
    }
}
```  

Based on the looping to the right, we see that the \# of iteration is consistent with the value of $i$.

As such we can think of it as:

$$\begin{align}
1 + 2 + 3 + 4 + \dots + n & = \frac{n(n\ + 1)}{2} \\
f(n) & = \frac{n^2 + 1}{2} \\
& = O(N^2)
\end{align}$$


:::

::: {grid-item-card} Time Complexity: looping approaching $n$

``` {list-table}
:header-rows: 1

* - $i$
  - $j$
  - \# of iterations
* - 0
  - 0*
  - 0
* - 1
  - 0<br>1*
  - 1
* - 2
  - 0<br>1<br>2*
  - 2
* - 3
  - 0<br>1<br>2<br>3*
  - 3
* - •<br>•<br>•<br>n
  -
  - •<br>•<br>•<br>n

```


:::

::::

> The outer loop executes N times. Every time the outer loop executes, the inner loop executes M times. As a result, the statements in the inner loop execute a total of N * M times. Thus, the complexity is O(N * M).
> 
> -- [Big O Notation #Nested Loops](https://web.mit.edu/16.070/www/lecture/big_o.pdf)

Recall, working with nested loops, complexity is $O(N \times M)$

Therefore the time complexity for this loop is: $O(N^2)$

`````
``````
``````````

### Example 4

`````````` {div} full-width
```` {card}
``` {code-block} cpp
:lineno-start: 1
:emphasize-lines:

for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
            //count 1 instruction
        }
    }
}
```
``` {admonition} Why...
:class: dropdown, tip
<!-- placeholder -->
```
````
``````````

### Example 5

`````````` {div} full-width
```` {card}
``` {code-block} cpp
:lineno-start: 1
:emphasize-lines:

for (int i = 0; i < n; i++) {
    for (int j = 0; j < i * i; j++) {
        for (int k = 0; k < j; k++) {
            // count 1 instruction
        }
    }
}
```
``` {admonition} Why...
:class: dropdown, tip
<!-- placeholder -->
```
````
``````````

## Some rules...

`````````` {div} full-width
```` {card}
``` {card} Single loops
- essentially, $total\ iterations\ \times total\ instructions\ performed\ per\ iteration$
```
``` {card} Nested loops
- count instructions inside out
- careful with the range of the loop
- when possible, multiplications can be used for counts from each loop
```
``` {card} Consecutive statements
- just add the counts
```
``` {card} Conditionals
- consider the branch with the highest count
```
````
``````````

## Computational cost

`````````` {div} full-width
```` {card}

Number of <b class="brown">basic instructions</b> required by the algorithm to process an input of a certain <b class="brown">size $n$</b>

$$\begin{align}
T(n) \\
\end{align}$$

- basic instructions are always  <b class="brown">relevant</b> to the problem
  - ex: find max in an array
    - \# of comparisons
  - ex: sum elements in an array
    - \# of additions

````
``````````

## Comparing computational cost

`````````` {div} full-width
```` {card} $Cost$

``` {list-table} 
:header-rows: 2

* - 
  - $find (x,y,z)s.t.x+y+z = k$
  - $find (x,y)s.t.x+y = k$
  - $find\ x = k$
* - Size of input
  - $n^3$
  - $n^2$
  - $n$
* - $n = 1$
  - 1
  - 1
  - 1
* - $n = 10$
  - 1000
  - 100
  - 10
* - $n = 100$
  - 1000000
  - 10000
  - 100
* - $n = 1000$
  - 1000000000
  - 1000000
  - 1000
* - $n = 10000$
  - 1000000000000
  - 100000000
  - 10000
* - $n = 100000$
  - 1000000000000000
  - 10000000000
  - 100000
* - $n = 1000000$
  - 1000000000000000000
  - 1000000000000
  - 1000000
* - $n = 10000000$
  - 1000000000000000000000
  - 100000000000000
  - 10000000

```
````
``````````

## Growth Rate

`````````` {div} full-width
```` {card}

``` {list-table} $Growth\ of\ T(n)\ as\ n\to\infty$
:header-rows: 1

* - $n$
  - $log\ log\ n$
  - $log\ n$
  - $n$
  - $n\ log\ n$
  - $n^2$
  - $n^3$
  - $2^n$
* - $16$
  - $2$
  - $4$
  - $2^4$
  - $4 \times 2^4 = 2^6$
  - $2^8$
  - $2^{12}$
  - $2^{16}$
* - $256$
  - $3$
  - $8$
  - $2^8$
  - $8 \times 2^8 = 2^{11}$
  - $2^{16}$
  - $2^{24}$
  - $2^{256}$
* - $1024$
  - $\approx 3.3$
  - $10$
  - $2^{10}$
  - $10 \times 2^{10} = 2^{13}$
  - $2^{20}$
  - $2^{32}$
  - $2^{1024}$
* - $64K$
  - $4$
  - $16$
  - $2^{16}$
  - $16 \times 2^{16} = 2^{20}$
  - $2^{32}$
  - $2^{48}$
  - $2^{64K}$
* - $1M$
  - $\approx 4.3$
  - $20$
  - $2^{20}$
  - $20 \times 2^{20} = 2^{24}$
  - $2^{40}$
  - $2^{60}$
  - $2^{1M}$
* - $1G$
  - $\approx 4.9$
  - $30$
  - $2^{30}$
  - $30 \times 2^{30} = 2^{35}$
  - $2^{60}$
  - $2^{90}$
  - $2^{1G}$

```

````
``````````
