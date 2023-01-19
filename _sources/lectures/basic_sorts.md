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

# Basic Sorts (Analysis)

`````````` {div} full-width
``` {figure} https://cdn-images-1.medium.com/max/1600/1*bPpvELo9_QqQsDz7CSbwXQ.gif
:align: center
```
``````````

## Internships & Jobs

`````````` {div} full-width
``` {card} Google
[https://careers.google.com/how-we-hire/interview](https://careers.google.com/how-we-hire/interview)
```

``` {card} Amazon
[https://www.amazon.jobs/en/landing_pages/software-development-topics](https://www.amazon.jobs/en/landing_pages/software-development-topics)
```

``` {card} Meta
[https://www.metacareers.com/life/](https://www.metacareers.com/life/)
```

``` {card} Handshake
[URI Handshake](https://uri.joinhandshake.com/login)
```
``````````

## Worst-case, Average-case, Best-case

`````````` {div} full-width
```` {card} Warm-up 1: Analyze this code

``` {code-block} cpp
:lineno-start: 1
:emphasize-lines:

unsigned int argmin (const std::vector<int> &values) { 
  unsigned int length = values.size();
  assert(length > 0);
  unsigned int idx = 0;
  int current = values[0];
  for (unsigned int i = 1; i < length; i++) {
    if (values[i] < current) {
      current = values[i];
      idx = i;
    }
  }
  return idx;
}
```

$$T(n)\ =\ ?$$
$$based\ on\ number\ of\ comparisons$$

````

```` {card} Warm-up 2: Analyze this code

``` {code-block} cpp
:lineno-start: 1
:emphasize-lines:

bool argk (const std::vector<int> &values, int k, unsigned int &idx) {  
  unsigned int length = values.size();
  for (unsigned int i = 0; i < length; i++) {
    if (values[i] == k) {
      idx = i;
      return true;
    }
  }
  return false;
}
```

$$T(n)\ =\ ?$$
$$based\ on\ number\ of\ comparisons$$

````
``````````

### Analysis types

`````````` {div} full-width
```` {card}

``` {dropdown} 😕 Worst-case
- **maximum** time of algorithm on **any** input
```

``` {dropdown} 🤔 Average-case
- **expected** time of algorithm over **all** inputs
```

``` {dropdown} 🦄 Best-case
- **minimum** time of algorithm on **some** (optimal) input
```

``` {note}

While <b class="red">asymptotic analysis</b> describes $T(n) \Rightarrow \infty$...

- _asymptotic notation: big-O, big-$\Omega$, $\Theta$_

<b class="red">Case analysis</b> looks into the different input types

- best-case, worst-case, average-case

```

$$Both\ analysis\ types\ are\ orthogonal\ to\ each\ other$$

````
``````````

### Examples

`````````` {div} full-width
```` {card} Factorial of a number (iterative algorithm)
``` {code-block} cpp
:lineno-start: 1
:emphasize-lines:

// pseudocode

function factorial(n):
  if n <= 1:
    return 1
  result = 1
  for i in range(1, n+1):
    result *= i
  return result
```

``` {dropdown} ???-Case
**Average-case**
```
````

```` {card} Sequential search (return first occurrence)
``` {code-block} cpp
:lineno-start: 1
:emphasize-lines:

// pseudocode

function find_first(items, target):
  index = 0
  while index < len(items):
    if items[index] == target:
      return index
    index += 1
  return -1
```

``` {dropdown} ???-Case
**Best-case**
```
````

```` {card} Sequential search (return last occurrence)
``` {code-block} cpp
:lineno-start: 1
:emphasize-lines:

// pseudocode

function find_last(items, target):
  index = len(items) - 1
  while index >= 0:
    if items[index] == target:
      return index
    index -= 1
  return -1
```

``` {dropdown} ???-Case
**Worst-case**
```
````
``````````

## Basic Sorting Algorithms

### Sorting

`````````` {div} full-width
``` {card}

Given $n$ elements that can be compared according to a **total order** relation

- we want to rearrange them in non-increasing/non-decreasing order
- for example (non-decreasing):
  - `input`: sequence of items $\ \ \ \ \ \ \ \ \ \ \ A = [k_0, k_1, \dots, k_{n - 1}]$
  - `output`: permutation of A $\ \ \ \ \ \ \ \ \ \ \ B\ |\ B[0]\ \le\ B[1]\ \le \dots B[n - 1]$

$$\\ \\ \\ Central\ problem\ in\ computer\ science$$

```
``````````

## Insertion Sort

`````````` {div} full-width
```` {admonition} Defined as...
:class: tip

Array is divided into <b class="orange">sorted</b> and **unsorted** parts

- algorithm scans array from <b class="orange">left to right</b>

Invariants

- elements in <b class="orange">sorted</b> are in ascending order
- elements in **unsorted** have not been seen

``` {figure} imgs/06_s12.png
:align: center
:width: 92%
```

````

```` {card} Pseudocode

``` {code-block} cpp
:lineno-start: 1
:emphasize-lines:

void insertion_sort(int* items, int size) {
  //grows the left part (sorted)
  for (int i = 1; i < size; i++) {
    int j = i;
    //inserts j in sorted part
    while (j > 0 && items[j-1] > items[j]) {
      swap(items[j-1], items[j]);
      j--;
    }
  }
}
```

$$Number\ of\ comparisons?\ |\ Number\ of\ exchanges?$$
````
``````````

## Analysis — Insertion Sort(comparisons)

[demo: https://www.hackerearth.com/practice/algorithms/sorting/insertion-sort/visualize/](https://www.hackerearth.com/practice/algorithms/sorting/insertion-sort/visualize/)

`````````` {div} full-width
`````` {card}

**Running time depends on the input**

````` {grid}

```` {grid-item-card}
``` {glossary} 
Worst-case?
    input is already sorted in descending order
```
$$\begin {align}
\sum_{i = 1}^{N - 1} i &= 1 + 2 + 3 + \dots + (N - 1) \\
&= \frac{N(N - 1)}{2} \\
&= O(N^2) \\
\end {align}$$
````

```` {grid-item-card}
``` {glossary} 
Average-case?
    each element $\approx$ halfway order  
    expect every element to move O(n/2) times
```
$$\begin {align}
\sum_{i = 1}^{N - 1} \frac{i}{2} &= \frac{1}{2} (1 + 2 + 3 + \dots + (N - 1)) \\
&= \frac{N(N - 1)}{4} \\
&= O(N^2) \\
\end {align}$$
````

```` {grid-item-card}
``` {glossary} 
Best-case?
    input is already sorted in ascending order
```
$$\begin {align}
\sum_{i = 1}^{N - 1} 1 &= (N - 1) \\
&= O(N) \\
\end {align}$$
````

`````
``````
``````````

### Partially sorted arrays

`````````` {div} full-width
````` {card}

```` {card} inversion

A pair of keys that are out of order

``` {figure} imgs/06_s16.png
:align: center
```

> “array is **partially sorted** if the number of pairs that are out-of-order is $O(n)$”

For partially-sorted arrays, insertion sort runs in <b class="orangelinear time_.

$$Θ(n)$$

````

`````
``````````

## Selection Sort

`````````` {div} full-width
````` {card}

``` {card} Defined
Array is divided into <b class="orange">sorted</b> and **unsorted** parts
- algorithm scans array from left to right
```

``` {card} invariants
- elements in <b class="orange">sorted</b> are **fixed** and in ascending order
- no element in **unsorted** is smaller than any element in <b class="orange">sorted</b>
```

``` {figure} imgs/06_s17.png
:align: center
```

```` {card} code
``` {code-block} cpp
:lineno-start: 1
:emphasize-lines:

void selectionsort (int *A, unsigned int n) {
  int temp;
  unsigned int i, j, min;
  // grows the left part (sorted) 
  for (i = 0; i < n; i++) {
    min = i;
    // find min in unsorted part
    for (j = i + 1; j < n; j++) {
      if (A[j] < A[min]) {
        min = j;
      }
    }
    // swap A[i] and A[min]
    temp = A[i];  
    A[i] = A[min];
    A[min] = temp;
  }
}
```
$$Number\ of\ comparisons?\ |\ Number\ of\ exchanges?$$

````

``` {dropdown} Notes

Selection Sort: moves through each element finding the minimum value and replacing the current element value as it goes.

$$A[0] \rightarrow A [1] \rightarrow A[2] \rightarrow A[n - 1]$$

- sorted portion left order, fixed, untouched
- unsorted iterated through to find remaining min value to swap current element value

`````
``````````

## Summary

`````````` {div} full-width
```` {card}
``` {figure} imgs/06_s20.png
:align: center
```
````
``````````
