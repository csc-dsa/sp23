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

# Recursive Algorithms (Analysis)

`````````` {div} full-width
``` {image} https://cdn.slidesharecdn.com/ss_thumbnails/recursion-130206094649-phpapp01-thumbnail-4.jpg?cb=1360144228
:align: center
```
``````````

## Recursion

`````````` {div} full-width
``````` {card}

``` {admonition} Define
The process of solving a problem by reducing it to smaller versions of itself

- Solve a task by reducing it to smaller tasks (of the same structure)
- Technically, a recursive function is one that calls itself
```

`````` {admonition} General Form
````` {grid}
```` {grid-item}
:columns: 12
```cpp
int someFunction() {
    if (base_case) {
        return // calculate trival solution       
    } else {
        // break task into subtasks
        // solve each task recursively
        // merge solutions if necessary
        return someFunction();
    }
}
```
````

```` {grid-item}
:columns: 6
``` {dropdown} base case
- solution for a **trivial case**
- it can be used to stop the recursion (prevents _“stack overflow”_)  
- every recursive algorithm needs at least one base case
```
````
```` {grid-item}
:columns: 6
``` {dropdown} recursive calls
- divide problem into **smaller instance(s)** of the **same structure**
```
````
`````
``````

```` {admonition} Rules
:class: tip

1. Every recursive definition must have one (or more) base cases.
2. The general case must eventually be reduced to a base case.
3. The base case stops the recursion.
````

```` {card} Why recursion?
Can we live without it?
- yes, you can write “any program” with arrays, loops, and conditionals

However ...
- some formulas are explicitly recursive  
- some problems exhibit a natural recursive solution 

``` {figure} imgs/09_s05.png
```

[https://courses.cs.washington.edu/courses/cse120/17sp/labs/11/tree.html](https://courses.cs.washington.edu/courses/cse120/17sp/labs/11/tree.html)

````

```````
``````````

### Recursive Call Tree

`````````` {div} full-width
``````` {card}

`````` {admonition} Sum Array

````` {card}

```cpp
int sum_array(int *A, int n) {
  //basecase  
  if (n == 1)
    return A[0];

  //solve sub-task
  int sum = sum_array(A, n - 1);

  //return
  return A[n - 1] + sum;
}
```

``` {card} cases & calls

$$
T(n) =
\begin{cases}
sum = A[0],  & \text{if $n\ = 1$},  & \text{// base case}  \\[2ex]
A(n - 1), & \text{if $n \gt 1$ },  & \text{// recursive calls}
\end{cases}
$$

```

``` {card} visualize
<iframe allow="fullscreen" width="675" height="675" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%23include%20%3Ciostream%3E%0A%0A%0Aint%20sum_array%28int%20*A,%20int%20n%29%20%7B%0A%20%20//basecase%20%20%0A%20%20if%20%28n%20%3D%3D%201%29%0A%20%20%20%20return%20A%5B0%5D%3B%0A%0A%20%20//solve%20sub-task%0A%20%20int%20sum%20%3D%20sum_array%28A,%20n%20-%201%29%3B%0A%0A%20%20//return%0A%20%20return%20A%5Bn%20-%201%5D%20%2B%20sum%3B%0A%7D%0A%0Aint%20main%20%28%29%20%7B%0A%20%20%20%20int%20arr%5B%5D%20%3D%20%7B%2010,%2020,%2030,%2040%7D%3B%0A%20%20%20%20sum_array%28arr,%204%29%3B%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&cumulative=false&curInstr=0&heapPrimitives=nevernest&origin=opt-frontend.js&py=cpp_g%2B%2B9.3.0&rawInputLstJSON=%5B%5D&textReferences=false"> </iframe>
```
`````

````` {card}
``` {figure} imgs/09_sum_array_drawio.png
```
`````

``````

`````` {admonition} Largest

```` {card} pseudocode
```cpp
To find the largest element in list[a]...list[b]  

a. Find the largest element in `list[a + 1]...list[b]` 
    and call it max
b. Compare the elements `list[a]` and `max`  
  `if (list[a] >= max)`  
    the largest element in list[a]...list[b] is list[a]  
  otherwise   
    the largest element in list[a]...list[b] is max 
```
````

````{card} code
```cpp
int largest (const int list[], int lowerIndex, int upperIndex) {
  int max;
  if (lowerIndex == upperIndex) //size of the sublist is one 
    return list[lowerIndex];
  else {
    max = largest(list, lowerIndex + 1, upperIndex);
    if (list[lowerIndex] >= max) 
      return list[lowerIndex];
    else
      return max;
  }
}

```
````

```` {card} base case & recursive calls

$$
T(n) =
\begin{cases}
size\ of\ list\ = 1,  & \text{// base case}  \\[2ex]
size\ of\ list\ is\ \gt 1, & \text{// recursive calls}
\end{cases}
$$

````

``` {figure} imgs/09_largest_drawio.png
```

``````

`````` {admonition} Serpinski

```` {card} code
```cpp
void printSierpinski(int n)
{
    for (int y = n - 1; y >= 0; y--) {
        for (int i = 0; i < y; i++)
            cout << " ";
    
        for (int x = 0; x + y < n; x++) {
            if(x & y)
            cout << " " << " ";
        else
            cout << "* ";
        }
        cout << endl;
    }
}
```
[https://www.geeksforgeeks.org/sierpinski-triangle/](https://www.geeksforgeeks.org/sierpinski-triangle/)
````

```` {card} Visualize: structure
``` {figure} https://runestone.academy/ns/books/published/pythonds/_images/stCallTree.png
````

```` {card} Example: Triangle
``` {figure} https://www.researchgate.net/profile/Askander-Kaka/publication/264872595/figure/fig4/AS:669568435494921@1536648963162/First-four-steps-to-configure-Sierpinski-triangle.png
````

```` {card} Example: Pyramid
``` {figure} https://upload.wikimedia.org/wikipedia/commons/b/b4/Sierpinski_pyramid.png
````

```````
``````````

## Recursion v. Iteration

`````````` {div} full-width
``````` {card}

`````` {grid}

````` {grid-item-card} recusive
```cpp
double power (double x, int n) {
  //basecase  
  if (n == 0) 
    return 1;

  //recursive call
  return x * power(x, n - 1);
}
```
`````

````` {grid-item-card} iterative
```cpp
double power (double x, int n) {
  if (n == 0)
    return 1;
  
  double half = power(x, n / 2);
  if (n % 2 == 0)
    return half * half;
  else
    return x * half * half;
}
```
`````

+++

`````` {card}
``` {figure} imgs/09_recur_v_iter_drawio.png
```
``````
```````
``````````

## Binary Search

`````````` {div} full-width
`````` {card}

````` {admonition} code
```cpp
int bsearch(int *A, int lo, int hi, int k) {
  //base case
  if (hi < lo)
    return NOT_FOUND;

  // calculate mid point index
  int mid = lo + ( (hi - lo) / 2);
  // key found?
  if (A[mid] == k)
    return mid;
  // key in upper subarray?
  if (A[mid] < k)
    return bsearch(A, mid + 1, hi, k);
  // key is in lower subarray?
  return bsearch(A, lo, mid - 1, k);
}
```
[https://www.geeksforgeeks.org/binary-search/](https://www.geeksforgeeks.org/binary-search/)
`````

````` {admonition} visuzalize: general form
:class: tip
[https://www.cs.usfca.edu/~galles/visualization/Search.html](https://www.cs.usfca.edu/~galles/visualization/Search.html)
`````


``````
``````````

### Recursion Tree Call

`````````` {div} full-width
```````` {card}

`````` {admonition} binary search

```cpp
int bsearch(int *A, int lo, int hi, int k) {
  //base case
  if (hi < lo)
    return NOT_FOUND;

  // calculate mid point index
  int mid = lo + ( (hi - lo) / 2);
  // key found?
  if (A[mid] == k)
    return mid;
  // key in upper subarray?
  if (A[mid] < k)
    return bsearch(A, mid + 1, hi, k);
  // key is in lower subarray?
  return bsearch(A, lo, mid - 1, k);
}
```

``````

```` {card}
``` {figure} imgs/09_bin_search_drawio.png
````

```` {card} visualize: in memory
<iframe allow="fullscreen" width="675" height="675" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=//%20C%2B%2B%20program%20to%20implement%20recursive%20Binary%20Search%0A%23include%20%3Cbits/stdc%2B%2B.h%3E%0Ausing%20namespace%20std%3B%0A%0A//%20A%20recursive%20binary%20search%20function.%20It%20returns%0A//%20location%20of%20x%20in%20given%20array%20arr%5Bl..r%5D%20is%20present,%0A//%20otherwise%20-1%0Aint%20binarySearch%28int%20arr%5B%5D,%20int%20l,%20int%20r,%20int%20x%29%0A%7B%0A%20%20%20%20if%20%28r%20%3E%3D%20l%29%20%7B%0A%20%20%20%20%20%20%20%20int%20mid%20%3D%20l%20%2B%20%28r%20-%20l%29%20/%202%3B%0A%0A%20%20%20%20%20%20%20%20//%20If%20the%20element%20is%20present%20at%20the%20middle%0A%20%20%20%20%20%20%20%20//%20itself%0A%20%20%20%20%20%20%20%20if%20%28arr%5Bmid%5D%20%3D%3D%20x%29%0A%20%20%20%20%20%20%20%20%20%20%20%20return%20mid%3B%0A%0A%20%20%20%20%20%20%20%20//%20If%20element%20is%20smaller%20than%20mid,%20then%0A%20%20%20%20%20%20%20%20//%20it%20can%20only%20be%20present%20in%20left%20subarray%0A%20%20%20%20%20%20%20%20if%20%28arr%5Bmid%5D%20%3E%20x%29%0A%20%20%20%20%20%20%20%20%20%20%20%20return%20binarySearch%28arr,%20l,%20mid%20-%201,%20x%29%3B%0A%0A%20%20%20%20%20%20%20%20//%20Else%20the%20element%20can%20only%20be%20present%0A%20%20%20%20%20%20%20%20//%20in%20right%20subarray%0A%20%20%20%20%20%20%20%20return%20binarySearch%28arr,%20mid%20%2B%201,%20r,%20x%29%3B%0A%20%20%20%20%7D%0A%0A%20%20%20%20//%20We%20reach%20here%20when%20element%20is%20not%0A%20%20%20%20//%20present%20in%20array%0A%20%20%20%20return%20-1%3B%0A%7D%0A%0Aint%20main%28void%29%0A%7B%0A%20%20%20%20int%20arr%5B%5D%20%3D%20%7B%202,%203,%204,%2010,%2040%20%7D%3B%0A%20%20%20%20int%20x%20%3D%2010%3B%0A%20%20%20%20int%20n%20%3D%20sizeof%28arr%29%20/%20sizeof%28arr%5B0%5D%29%3B%0A%20%20%20%20int%20result%20%3D%20binarySearch%28arr,%200,%20n%20-%201,%20x%29%3B%0A%20%20%20%20%28result%20%3D%3D%20-1%29%0A%20%20%20%20%20%20%20%20%3F%20cout%20%3C%3C%20%22Element%20is%20not%20present%20in%20array%22%0A%20%20%20%20%20%20%20%20%3A%20cout%20%3C%3C%20%22Element%20is%20present%20at%20index%20%22%20%3C%3C%20result%3B%0A%20%20%20%20return%200%3B%0A%7D&codeDivHeight=400&codeDivWidth=350&cppShowMemAddrs=true&cumulative=false&curInstr=0&heapPrimitives=nevernest&origin=opt-frontend.js&py=cpp_g%2B%2B9.3.0&rawInputLstJSON=%5B%5D&textReferences=false"> </iframe>
````

````````
``````````

## Unimodal arrays

`````````` {div} full-width
``````` {card}

``` {admonition} Define
An array is (<span class="blue">strongly</span>) **unimodal** if it can be split into an increasing part followed by a decreasing part

An array is (<span class="blue">weakly</span>) **unimodal** if it can be split into a nondecreasing part followed by a nonincreasing part
```

```` {card} Various modalities 
``` {figure} https://i0.wp.com/makemeanalyst.com/wp-content/uploads/2017/05/Unimodal-Bomodal-Multimodal-Uniform.png?resize=813%2C530
```
````

```````
``````````

### Find the max (strongly unimodal)

`````````` {div} full-width
``````` {card}

```` {admonition} code
```cpp
int max_s_unimodal (int *A, int low, int hi) {  
  if (low == hi)
    return A[low];

  int mid = (low + hi) / 2;  

  if (A[mid] < A[mid+1])
    return max_s_unimodal(A, mid + 1, hi);
  else 
    return max_s_unimodal(A, low, mid);
}
```
````

`````` {grid}
````` {grid-item-card}
``` {figure} imgs/09_s29.png
```
`````
````` {grid-item-card}
``` {figure} imgs/09_unimodal_strong.png
```
`````
``````

```````
``````````

### Find the max (weakly unimodal)

`````````` {div} full-width
``````` {card}

```` {admonition} code
```cpp
int max_w_unimodal (int *A, int low, int hi) {
  if (low == hi)
    return A[low];

  int mid = (low + hi) / 2;

  if (A[mid] < A[mid + 1])
    return max_w_unimodal(A, mid + 1, hi);
  else if (A[mid] > A[mid + 1])
    return max_w_unimodal(A, low, mid);
  else {
    int left = max_w_unimodal(A, mid+1, hi);  
    int right = max_w_unimodal(A, low, mid);
    return std::max(left, right);
  }
}
```
````

`````` {grid}
````` {grid-item-card}
``` {figure} imgs/09_s31.png
```
`````
````` {grid-item-card}
``` {figure} imgs/09_unimodal_weak.png
```
`````
``````

```````
``````````
