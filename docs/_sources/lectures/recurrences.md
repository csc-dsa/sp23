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

# Recurrences

`````````` {div} full-width
``` {image} https://cdn-images-1.medium.com/max/1200/1*3Kti9X9KAL0_XCk1cdjbDw.jpeg
```
``````````

## Factorial of n (formula)

`````````` {div} full-width
``````` {card} $n!$

```` {admonition} code
```{code-block} cpp
:lineno-start: 1
:emphasize-lines:
int fact(int num) {

  if (num == 0) return 1;

  else return num * fact(num - 1);   
}
```
[https://www.geeksforgeeks.org/factorial-formula/](https://www.geeksforgeeks.org/factorial-formula/)  
````

``` {card}
$$n! = n × (n-1) × (n-2) × (n-3) × … × 3 × 2 × 1$$
```

`````` {card} Use Cases

````` {admonition} Permutation
- gives the number of ways to select $r$ elements from $n$ elements when *_order matters_*

$$^nP_r = \frac{n!}{(n – r)!}$$

``` {card} Example
Three different fruits are to be distributed among a group of 10 people. Find the total number of ways this can be possible.

$$\begin {align}
n = 10,\ r = 3...\ =>\ total\ number\ of\ ways\ &=\ ^{10}P_3 \\
&= \frac{10!}{(10 – 3)!} \\
&= \frac{10!}{7!} \\ 
&= \frac{10 × 9 × 8 × 7!}{7!} \\
&= 10 × 9 × 8 \\
&= 720
\end {align}$$
```
`````
````` {admonition} Combination
- gives the number of ways to select $r$ elements from $n$ elements where *_order does not matter_*

$$^nC_r = \frac{n!}{r! (n – r)!}$$

``` {card} Example
Find the number of ways 3 students can be selected from a class of 50 students.

$$\begin {align}
n = 50,\ r = 3...\ =>\ total\ number\ of\ ways\ &=\ ^{50}C_3 \\
&= \frac{50!}{3! × 47!} \\
&= \frac{50 × 49 × 48 × 47!}{3! × 47!} \\
&= \frac{50 ×49 × 48}{6} \\
&= 19,600
\end {align}$$
```
`````
``````

```````
``````````

## Analysis of Binary Search

`````````` {div} full-width
``````` {grid}
`````` {grid-item-card}
```{code-block} cpp
:lineno-start: 1
:emphasize-lines:
int bsearch(int *A, int lo, int hi, int k) {
  
    //base case
    if (hi < lo) return NOT_FOUND;
    
    // calculate mid point index
    int mid = lo + ( (hi - lo) / 2);
    
    // key found?
    if (A[mid] == k) return mid;
    
    // key in upper subarray?
    if (A[mid] < k) return bsearch(A, mid + 1, hi, k);
    
    // key is in lower subarray?
    return bsearch(A, lo, mid - 1, k);
}
```
``` {card} cases
$$t(n) = {1\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space if\ n = 1 \brace T(n / 2) + n\space\space\space\space if\ n > 1}$$
```
``````
`````` {grid-item-card}
``` {image} imgs/09_bin_search_drawio.png
```
``````

```````
``````````

## [Recurrence relations](https://www.math.wichita.edu/discrete-book/ch_sequences.html)

`````````` {div} full-width
```` {card}
By itself, a recurrence does not describe the running time of an algorithm
- need a *closed-form* solution (non-recursive description)\
- exact closed-form solution may not exist, or may be too difficult to find

For most recurrences, an asymptotic solution of the form $\Theta()$ is acceptable
- ...in the context of analysis of algorithms
````
``````````

### [How to solve recurrences?](https://courses.engr.illinois.edu/cs473/sp2010/notes/99-recurrences.pdf)

`````````` {div} full-width
```` {card} Solving recurrances

``` {card} [Unrolling](https://courses.cs.washington.edu/courses/cse332/18su/handouts/unrolling.pdf)
Expanding the recurrence
: a.k.a. *iteration method* or repeated substitution

Keep unrolling the recurrence until you identify a general case
: then use the base case

Not trivial in all cases but it is helpful to build an intuition
: may need induction to prove correctness
```

``` {card} [Guessing](https://www.geeksforgeeks.org/method-of-guessing-and-confirming/)
- the answer and proving it correct *by induction*
```

``` {card} Recursion Tree
```

``` {card} [Master Theorem](http://homepages.math.uic.edu/~leon/cs-mcs401-s08/handouts/master_theorem.pdf)
```

````
``````````

### [Unrolling the binary search recurrence](https://youtu.be/XcZw01FuH18)

`````````` {div} full-width
``````` {card}
$$
T(n) =
\begin{cases}
1,  & \text{$if\ n\ = 1$}  \\[2ex]
T(n / 2) + n, & \text{$if\ n\ \ge 1$}
\end{cases}
$$

`````` {grid}
````` {grid-item-card}
``` {image} imgs/10_rec_bin_search_tree.png
```
`````
````` {grid-item-card}
$$\begin {align}
T(n) &= n + \frac{n}{2} + \frac{n}{2^2} + \frac{n}{2^3} + \frac{n}{2^k} \\
&= \bigg[1 + \frac{1}{2} + \frac{1}{4} + \frac{1}{8} + \frac{1}{2^k}\bigg] \\
\sum_{i=0}^k \frac{1}{2^i} &= 1 \\
& = n * 1 \\
T(n) &= n \\
&= \Theta(n)
\end {align} $$
`````
``````

```````
``````````

## Recurrence Relations

`````````` {div} full-width
```````` {card}

``````` {admonition} [Recurrence Relation: Linear](https://youtu.be/4V30R3I1vLI)

```{code-block} cpp
:lineno-start: 1
:emphasize-lines:
int fact(int b, int n) {
  if (n == 0)
    return 1;
  return b * fact(b, n - 1);
}
```

```` {admonition} Can you write (and solve) the recurrence?
:class: dropdown, tip

``` {card} Breakdown
$$\begin {align}
T(n) &= T(n - 1) + 1 \\
T(n - 1) &= T(n - 2) + 2(1) \\
T(n - 2) &= T(n - 3) + 3(1) \\ 
• \\
• \\
• \\
T(n - k) &= T(n - k) + k \\
\end {align}$$
```

``` {card} Substitution $T(n - 1)$
$$\begin {align}
T(n) &= \bigg[T(n - 1) - 1 + n\bigg] + n \\ 
T(n) &= T(n - 2) + 2n \\
T(n) &= \bigg[T(n - 2) - 1 + n\bigg] + 2n \\
T(n) &= T(n - 3) + 3n \\
\end {align}$$ 
```

``` {card} For $k$ times

$$\begin {align}
\text{For: } & T(n) & = T(n - k) + k \\
\text{Assume: } & n\ - k\ & = 0 \\
& n\ & = k \\
\end {align}$$ 

$$\begin {align}
T(n) &= T(n - n) + n \\
T(n) &= T(0) + n \\
• \\
T(n) &= 1 + n \\
T(n) &= \Theta(n) \\
&= \Theta(n) \\
\end {align}$$

```

````

`````` {grid}
````` {grid-item-card}

$$
T(n) =
\begin{cases}
1,  & \text{$if\ n\ = 0$}  \\[2ex]
T(n - 1) + 1, & \text{$if\ n\ \ge 0$}
\end{cases}
$$

`````
````` {grid-item-card}
$$\begin {align}
T(n) &= n + \frac{n}{2} + \frac{n}{2^2} + \frac{n}{2^3} + \frac{n}{2^k} \\
&= \bigg[1 + \frac{1}{2} + \frac{1}{4} + \frac{1}{8} + \frac{1}{2^k}\bigg] \\
\sum_{i=0}^k \frac{1}{2^i} &= 1 \\
& = n * 1 \\
T(n) &= n \\
&= \Theta(n) \\
\end {align} $$
`````
``````
[2.1.1 Recurrence Relation (T(n)= T(n-1) + 1) #1](https://youtu.be/4V30R3I1vLI)

```````

``````` {admonition} [Recurrence Relation: Divide & Conquer](https://youtu.be/1K9ebQJosvo)

``` {card}
$$
T(n) =
\begin{cases}
1,  & \text{$if\ n\ = 0$}  \\[2ex]
2T(\frac{n}{2}) + n, & \text{$if\ n\ \gt 0$}
\end{cases}
$$
```

```` {card} Tree Method
``` {image} imgs/10_ex_2.png
```

$$
For\ k\ times\ = \frac{n}{2^k}\ \Rightarrow\ n = 2^k \\
Hence,\ k\ = log\ n \\
T(n) = O(n\ log\ n)
$$
````

````` {card} Substitution Method

```` {grid}
``` {grid-item}
$$\begin {align}
T(n) &= 2T(\frac{n}{2}) + n \\
T(\frac{n}{2}) &= 2T(\frac{n}{2^2}) + \frac{n}{2} \\
&= 2\bigg[2T(\frac{n}{2^2}) + \frac{n}{2}\bigg] + n \\
&= 2^2T(\frac{n}{2^2} + n + n) \\
\end {align}$$
```
``` {grid-item}
$$\begin {align}
T(\frac{n}{2^2}) &= 2T(\frac{n}{2^3}) + \frac{n}{2^2} \\
&= 2\bigg[2T(\frac{n}{2^3}) + \frac{n}{2^2}\bigg] + 2n \\
T(n) &= 2^3T(\frac{n}{2^3}) + 3n \\
T(n) &= 2^kT(\frac{n}{2^k}) + kn \\
\end {align}$$
```
``` {grid-item}
$$
Assume...\ T(\frac{n}{2^k}) = T(1) \\
\frac{n}{2^k} = 1 \\
$$
```
``` {grid-item}
$$
Therefore...\ n\ = 2^k \\
k\ = log\ n \\
$$
```
``` {grid-item}
$$\begin {align}
T(n) &= 2^kT(1) + kn \\
&= n * 1 + n\ log\space n \\
&= \Theta(n\space log\space n) \\
\end {align}$$
```

````

`````

[2.3.3 Recurrence Relation [ T(n)= 2T(n/2) +n] #3](https://youtu.be/1K9ebQJosvo)

```````

``````` {note} 

``` {card}
$$
T(n) =
\begin{cases}
1,  & \text{$if\ n\ = 0$}  \\[2ex]
2T(n - 1) + 1, & \text{$if\ n\ \gt 0$}
\end{cases}
$$
```

````` {card} Tree Method
```` {image} imgs/10_ex_3.png
````

```` {card} Breakdown
$$\begin {align}
1 + 2 + 2^2 + 2^3 ... + 2^k &= 2^{k + 1} - 1 \\
ar + ar + ar^2 + ar^3 ... + ar^k &= \frac{a(r^{k + 1} - 1)}{r - 1} \\
\end {align} $$
````

```` {card} Where
$$\begin {align}
a = 1,\ r = 2 \\
\frac{1(2^{k + 1}1)}{2 - 1} = 2^{k + 1} - 1
\end {align} $$
````

```` {card} Assume
$$\begin {align}
n - k & = 0 \\
& = k \\
& = 2^{k + 1} - 1 => 2^{n + 1} - 1 \\
& = O(2^n) \\
\end {align}$$
````

`````

````` {card} Substitution
```` {grid} 
``` {grid-item}
$$\begin {align}
T(n) &= 2T(n - 1) + 1 \\
&= 2\bigg[2T(n - 2) + 1 \bigg] + 1 \\
&= 2^2T(n - 2) + 2 + 1 \\
&= 2^2 \bigg[2T(n - 3) + 1 \bigg] + 2 + 1 \\
&= 2^3T(n - 3) + 2^2 + 2 + 1 \\
\end {align}$$
```
``` {grid-item}
For $k$ times... $$T(n) = 2^kT(n - k) + 2^k-1 + 2^k-2 + ... 2^2 + 2 + 1$$
Assume $n - k = 0$

$$\begin {align}
n = k \\
2^nT(0) + 1 + 2 + 2^2\ + \dots\ 2^k-1 \\
2^n - 1 + 2^k - 1 \\
2^n + 2^n - 1 \\
2^n+1 - 1 \\
\Theta(2^n) \\
\end {align}$$
```
````
`````

```````

[2.1.1 Recurrence Relation (T(n)= T(n-1) + 1) #1](https://youtu.be/JvcqtZk2mng)
[Recurrence Relation: Tower of Hanoi](https://youtu.be/1K9ebQJosvo)

````````
``````````
