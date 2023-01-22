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
  summary {align: center}
  iframe {width: 100%; height: 800px}
</style>

# Quicksort

`````````` {div} full-width
``` {image} https://gifimage.net/wp-content/uploads/2018/04/quick-sort-gif-5.gif
:align: center
```
``````````

## [Quick Sort](https://www.geeksforgeeks.org/quick-sort/)

`````````` {div} full-width
````` {card}

<b class="orange">Divide</b> the array into **two** partitions (subarrays)

- need to pick a _pivot_ and rearrange the elements into two  partitions

Conquer <b class="orange">Recursively</b> each half

- call Quick Sort on each partition (i.e. solve 2 smaller problems)

<b class="orange">Combine</b> Solutions

- there is no need to combine the solutions

``````````

## Partition

`````````` {div} full-width
``` {figure} imgs/12_s04.png
```
``````````

### [Partition: algorithm](https://medium.com/@vladitech/partition-algorithm-basics-of-quick-sort-pivoting-286f97f251f1)

`````````` {div} full-width
``` {figure} imgs/12_s05.png
```


``````````

### [Partition: do it yourself](https://youtu.be/zyoVdrFW6E8)

`````````` {div} full-width
`````` {card}

``` {figure} imgs/12_s06.png
```

````` {tab-set}

```` {tab-item} Step 1
**Set the $pivot$...**
``` {figure} imgs/12_s_s1.png
```
````

```` {tab-item} Step 2
**Find and evaluate $i$ and $j$ initial values**
for all $i \ge pivot$, *_swap_*  
for all $j \le pivot$, *_swap_*  
``` {figure} imgs/12_s_s2.png
```
````

```` {tab-item} Step 3
**Evaluate all $i$ and $j$ values, until...**
``` {figure} imgs/12_s_s3.png
```
````

```` {tab-item} Step 4
**$i$ and $j$ cross pathes...**

**Sorted...sorta...**

``` {figure} imgs/12_s_s4.png
```
````

```` {tab-item} Step 5 
**Continue partitioning until sorted**

``` {figure} https://i.etsystatic.com/10445000/r/il/5408d7/1387979513/il_1140xN.1387979513_c4bo.jpg
```
````

`````
``````
``````````

## Implementaton

`````````` {div} full-width
````````` {card}

``````` {tab-set}
`````` {tab-item} quicksort
```{code-block} cpp
:lineno-start: 1
:emphasize-lines: 

void quicksort(int *A, int n, int m)              
{
    // shuffle the array  
    std::random_shuffle(A, A + n);
    
    // call recursive quicksort  
    r_quicksort(A, 0, n - 1);
}
```
``````
`````` {tab-item} pseudo
```{code-block} cpp
:lineno-start: 1
:emphasize-lines: 

while (true)

    scan i left-to-right (while a[i] < a[lo])
    
    scan j right-to-left (while a[j] > a[lo])
    
    if i and j crossed then break
    
    swap a[i] with a[j]

swap a[lo] with a[j]
```
``````
`````` {tab-item} r_quicksort
```{code-block} cpp
:lineno-start: 1
:emphasize-lines: 

void r_quicksort(int *A,int lo, int  hi)                                           
{
    if (hi <= lo) return;
    
    int p = partition(A, lo, hi);  
    
    r_quicksort(A, lo, p - 1);  
    
    r_quicksort(A, p + 1, hi);
}
```
``````
`````` {tab-item} pseudo
```{code-block} cpp
:lineno-start: 1
:emphasize-lines: 1

if (hi <= lo) return;

int p = partition(A, lo, hi);

quicksort(A, lo, p - 1);

quicksort(A, p + 1, hi);
```
``````
`````` {tab-item} partition
```{code-block} cpp
:lineno-start: 1
:emphasize-lines: 

int partition (int *A, int lo, int hi)                      
{
    int i = lo;
    int j = hi + 1;  
    while (1) {
      
        // while A[i] < pivot, increase i 
        while (A[++i] < A[lo])
            if (i == hi) break;

        // while A[i] > pivot, decrease j 
        while (A[lo] < A[--j])
            
            if (j == lo) break;
          
            // if i and j cross exit theloop
            if(i >= j) break;
            
            // swap A[i] and A[j]
            std::swap(A[i], A[j]);
    }
    // swap the pivot with A[j]  
    std::swap(A[lo], A[j]);

    //return pivot's position
    return j;
}

```
``````
```````
```` {card}
:link: https://clementmihailescu.github.io/Sorting-Visualizer/
_Click to open in new tab/window_
``` {figure} img/w7_quicksort.png
```
KEY: Blue - element, Green - Sequential, Red - Swap, Purple - placed
````
`````````
``````````

## [Analysis of Quick Sort](https://www.khanacademy.org/computing/computer-science/algorithms/quick-sort/a/analysis-of-quicksort)

`````````` {div} full-width
````` {admonition} [Worst-Case](https://youtu.be/4nVbJV5pZa8?t=80)

```` {card}

``` {figure} imgs/12_worst_case.png
```
$$
c \{ n + (n-1) + (n-2) + (n-3) + ... 1 \} \\
c * \frac{n(n+1)}{2} \\
= \Theta(n^2)
$$

````

**input sorted, reverse order, equal elements**

$$\begin {align}
T(n) &= T(n - 1) + T(0) + \Theta(n) \\
&= T(n - 1) + \Theta(1) + \Theta(n) \\
&= T(n - 1) + \Theta(n) \\
&= \dots \\
&= \Theta(n^2) \\
\end {align}$$

can shuffle or [randomized](https://youtu.be/HY64dw_Af94) the array (to avoid the worst-case)

`````

````` {admonition} [Best-Case](https://youtu.be/4nVbJV5pZa8?t=374)

``` {figure} imgs/12_best_case.png
```

- pivot partitions array evenly (almost never happens)

$$ \begin {align}
T(n) &= 2T(\frac{n}{2}) + \Theta(n) \\
&= \dots \\
&=\ \Theta(n\ log\ n)
\end {align}$$

`````

````` {admonition} [Average-Case](https://youtu.be/4nVbJV5pZa8?t=482)

- analysis is more complex

``` {card}
- Consider a 9-to-1 proportional split
- Even a 99-to-1 split yields same running time
- Faster than merge sort in practice (less data movement)
```

$$\begin {align}
T(n) &= T(\frac{n}{10}) + T(\frac{9n}{10}) + \Theta(n) \\
&= \dots \\
&= \Theta(n\ log\ n) \\
\end {align}$$

``` {figure} https://cdn-images-1.medium.com/max/600/1*h6C8WodiZvZ04CwgOKOgBA.png
```

Add all cn from side of tree with greatest depth (right-side tree):

$$
= cn * log_{\frac{10}{9}}\ n \\
= \Theta(n\ log\ n) \\
$$

``````````

## Comments on Quick Sort

`````````` {div} full-width
`````` {card}

``` {card} Properties
- it is **in-place** but not **stable**
- benefits substantially from code tuning
```

``` {card} Improvements
use insertion sort for small arrays
- avoid overhead on small instances (~10 elements)
median of 3 elements
- estimate true median by inspecting 3 random elements
[three-way partitioning](https://www.toptal.com/developers/sorting-algorithms/quick-sort-3-way)
- create three partitions < pivot, == pivot, >pivot
```

``````
``````````

## Sorting Algorithms

`````````` {div} full-width
``````` {card}
`````` {tab-set}
````` {tab-item} incomplete
``` {list-table}
:header-rows: 1

* - 
  - Best-Case
  - Average-Case
  - Worst-Case
  - Stable
  - In-place
* - Selection Sort
  - <b contenteditable></b>
  - <b contenteditable></b>
  - <b contenteditable></b>
  - <b contenteditable></b>
  - <b contenteditable></b>
* - Insertion Sort
  - <b contenteditable></b>
  - <b contenteditable></b>
  - <b contenteditable></b>
  - <b contenteditable></b>
  - <b contenteditable></b>
* - Merge Sort
  - <b contenteditable></b>
  - <b contenteditable></b>
  - <b contenteditable></b>
  - <b contenteditable></b>
  - <b contenteditable></b>
* - Quick Sort
  - <b contenteditable></b>
  - <b contenteditable></b>
  - <b contenteditable></b>
  - <b contenteditable></b>
  - <b contenteditable></b>
```
`````
````` {tab-item} complete
``` {list-table}
:header-rows: 1

* - 
  - Best-Case
  - Average-Case
  - Worst-Case
  - Stable
  - In-place
* - Selection Sort
  - $\Theta(n^2)$
  - $\Theta(n^2)$
  - $\Theta(n^2)$
  - No
  - Yes
* - Insertion Sort
  - $\Theta(n)$
  - $\Theta(n^2)$
  - $\Theta(n^2)$
  - Yes
  - Yes
* - Merge Sort
  - $\Theta(n\ log\ n)$
  - $\Theta(n\ log\ n)$
  - $\Theta(n\ log\ n)$
  - Yes
  - No
* - Quick Sort
  - $\Theta(n\ log\ n)$
  - $\Theta(n\ log\ n)$
  - $\Theta(n^2)$
  - No
  - Yes
```
`````
``````
```````
``````````

## Empirical Analysis

`````````` {div} full-width
```` {card}

``` {figure} imgs/12_s16.png
```

[https://www.cs.princeton.edu/courses/archive/spring18/cos226/lectures/23Quicksort.pdf](https://www.cs.princeton.edu/courses/archive/spring18/cos226/lectures/23Quicksort.pdf)

````
``````````
