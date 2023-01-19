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

# Binary Search

`````````` {div} full-width
``` {image} https://www.cdn.geeksforgeeks.org/wp-content/uploads/Binary-Search.png
:align: center
```
``````````

## [Searching Algorithms](https://www.geeksforgeeks.org/searching-algorithms/?ref=lbp)

`````````` {div} full-width
`````` {card}

``` {dropdown} Binary Search
- repeatedly target the center of the search structure and divide the search space in half.
- ex. [binary search](https://www.geeksforgeeks.org/binary-search/)
- _note: specifically designed for searching in sorted data-structures..._
```

``` {figure} https://blog.penjee.com/wp-content/uploads/2015/04/binary-and-linear-search-animations.gif
```

``` {dropdown} Sequential Search
- the list or array is traversed sequentially and every element is checked.
- ex. [linear search](https://www.geeksforgeeks.org/linear-search/)
```

``````
``````````

## Linear Search

`````````` {div} full-width
`````` {card}

``` {figure} https://www.tutorialspoint.com/data_structures_algorithms/images/linear_search.gif
```

[https://www.tutorialspoint.com/data_structures_algorithms/images/linear_search.gif](https://www.tutorialspoint.com/data_structures_algorithms/images/linear_search.gif)

````` {admonition} Linear Search: Implementation 


```cpp
// Pseudocode
// -
// Iterate from 0 to N-1, 
// compare the value of every index with x 
// if they match, return index
### <b>

int linearSearch(int array[], int n, int x) {      
    // Going through array sequencially
    for (int i = 0; i < n; i++)
        if (array[i] == x) return i;
    return -1;
}
```

[Linear Search: Implementation](https://www.geeksforgeeks.org/linear-search-vs-binary-search/?ref=rp)

`````

````` {admonition} Rules
:class: tip

- Consider all possible cases.
- Find the number of comparisons for each case.
- Add the number of comparisons and divide by the number of cases.
`````

````` {grid}

```` {grid-item-card}
**Best-case $ \Rightarrow T(n) = O(1)$**

$$target = A[0] = 1\ comparison$$
````

```` {grid-item-card}
**Worst-case $ \Rightarrow T(n) = O(n)$**

$$target = A[n - 1] = n\ comparisons$$
````

```` {grid-item-card}
**Average-case _(in a successful search)_ $ \Rightarrow T(n) = O(n)$**

$$\frac{1 + 2 + ... + n}{n} = \frac{1}{n}*\frac{n(n - 1)}{2} = \frac{n - 1}{n}$$
````

`````

``````
``````````

## Binary Search

### Pseudocode

`````````` {div} full-width
````` {card}

``` {card} Iterative Approach
- Consider start index to be at $0$ and last index to be $n-1^{th}$ index at starting 
    - $n \rightarrow length$ 
- Find middle $index(mid)$ of the array
- If $key$ is found to be less than $mid\ index\ element$ then update last index of the array to $mid\ -1$
- Else if $key$ is found to be greater than $mid\ index\ element\$ then update start index of the array to $mid\ + 1$
- Else check for $mid\ index\ element$ with $key$ if not match repeat the above steps til start index is less than end index
```

``` {card} Recursive Approach
- If $start$ is less than $end$ perform Binary search else terminate the algorithm.
- If the element at the $middle\ index$ is equal to the $key$ then return the index as it found the key
- Else if the $key\ $ is less than the element at the $middle\ index$ then call the function by passing end as $mid\ - 1$ (as the key will be less than mid element)
- Else if the $key$ is greater than the element at the $middle\ index$ then call the function by passing start as $mid + 1$ (as the key will be greater than mid)
```

[https://www.geeksforgeeks.org/linear-search-vs-binary-search/?ref=rp](https://www.geeksforgeeks.org/linear-search-vs-binary-search/?ref=rp)

[https://takeuforward.org/data-structure/binary-search-explained/](https://takeuforward.org/data-structure/binary-search-explained/)

`````
``````````

### Binary Search

`````````` {div} full-width
````` {card}

```` {admonition} iterative
:class: note

```cpp
int binarySearch(int array[], int x, int low, int high) {
    // Repeat until the pointers low and high meet each other
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (array[mid] == x) return mid;
        if (array[mid] < x) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}
```

[Binary Search: Iterative](https://www.geeksforgeeks.org/linear-search-vs-binary-search/?ref=rp)

````

```` {admonition} visualize: iterative
:class: tip
<iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=//%20C%2B%2B%20program%20to%20implement%20iterative%20Binary%20Search%0A%23include%20%3Cbits/stdc%2B%2B.h%3E%0Ausing%20namespace%20std%3B%0A%0A//%20A%20iterative%20binary%20search%20function.%20It%20returns%0A//%20location%20of%20x%20in%20given%20array%20arr%5Bl..r%5D%20if%20present,%0A//%20otherwise%20-1%0Aint%20binarySearch%28int%20arr%5B%5D,%20int%20l,%20int%20r,%20int%20x%29%0A%7B%0A%20%20%20%20while%20%28l%20%3C%3D%20r%29%20%7B%0A%20%20%20%20%20%20%20%20int%20m%20%3D%20l%20%2B%20%28r%20-%20l%29%20/%202%3B%0A%0A%20%20%20%20%20%20%20%20//%20Check%20if%20x%20is%20present%20at%20mid%0A%20%20%20%20%20%20%20%20if%20%28arr%5Bm%5D%20%3D%3D%20x%29%0A%20%20%20%20%20%20%20%20%20%20%20%20return%20m%3B%0A%0A%20%20%20%20%20%20%20%20//%20If%20x%20greater,%20ignore%20left%20half%0A%20%20%20%20%20%20%20%20if%20%28arr%5Bm%5D%20%3C%20x%29%0A%20%20%20%20%20%20%20%20%20%20%20%20l%20%3D%20m%20%2B%201%3B%0A%0A%20%20%20%20%20%20%20%20//%20If%20x%20is%20smaller,%20ignore%20right%20half%0A%20%20%20%20%20%20%20%20else%0A%20%20%20%20%20%20%20%20%20%20%20%20r%20%3D%20m%20-%201%3B%0A%20%20%20%20%7D%0A%0A%20%20%20%20//%20if%20we%20reach%20here,%20then%20element%20was%0A%20%20%20%20//%20not%20present%0A%20%20%20%20return%20-1%3B%0A%7D%0A%0Aint%20main%28void%29%0A%7B%0A%20%20%20%20int%20arr%5B%5D%20%3D%20%7B%202,%203,%204,%2010,%2040%20%7D%3B%0A%20%20%20%20int%20x%20%3D%2010%3B%0A%20%20%20%20int%20n%20%3D%20sizeof%28arr%29%20/%20sizeof%28arr%5B0%5D%29%3B%0A%20%20%20%20int%20result%20%3D%20binarySearch%28arr,%200,%20n%20-%201,%20x%29%3B%0A%20%20%20%20%28result%20%3D%3D%20-1%29%0A%20%20%20%20%20%20%20%20%3F%20cout%20%3C%3C%20%22Element%20is%20not%20present%20in%20array%22%0A%20%20%20%20%20%20%20%20%3A%20cout%20%3C%3C%20%22Element%20is%20present%20at%20index%20%22%20%3C%3C%20result%3B%0A%20%20%20%20return%200%3B%0A%7D&codeDivHeight=400&codeDivWidth=350&cumulative=false&curInstr=0&heapPrimitives=nevernest&origin=opt-frontend.js&py=cpp_g%2B%2B9.3.0&rawInputLstJSON=%5B%5D&textReferences=false"> </iframe>
````

```` {admonition} recursive
:class: note

```cpp
int binarySearch(int arr[], int start, int end, int k) {
  if (start > end) return -1;
  int mid = (start + end) / 2;
  if (k == arr[mid]) return mid;
  else if (k < arr[mid]) return binarySearch(arr, start, mid - 1, k);
  else return binarySearch(arr, mid + 1, end, k);
}
```

[Binary Search: Recursive](https://www.geeksforgeeks.org/linear-search-vs-binary-search/?ref=rp)

````

```` {admonition} visualize: recursive
:class: tip
<iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=//%20C%2B%2B%20program%20to%20implement%20recursive%20Binary%20Search%0A%23include%20%3Cbits/stdc%2B%2B.h%3E%0Ausing%20namespace%20std%3B%0A%0A//%20A%20recursive%20binary%20search%20function.%20It%20returns%0A//%20location%20of%20x%20in%20given%20array%20arr%5Bl..r%5D%20is%20present,%0A//%20otherwise%20-1%0Aint%20binarySearch%28int%20arr%5B%5D,%20int%20l,%20int%20r,%20int%20x%29%0A%7B%0A%20%20%20%20if%20%28r%20%3E%3D%20l%29%20%7B%0A%20%20%20%20%20%20%20%20int%20mid%20%3D%20l%20%2B%20%28r%20-%20l%29%20/%202%3B%0A%0A%20%20%20%20%20%20%20%20//%20If%20the%20element%20is%20present%20at%20the%20middle%0A%20%20%20%20%20%20%20%20//%20itself%0A%20%20%20%20%20%20%20%20if%20%28arr%5Bmid%5D%20%3D%3D%20x%29%0A%20%20%20%20%20%20%20%20%20%20%20%20return%20mid%3B%0A%0A%20%20%20%20%20%20%20%20//%20If%20element%20is%20smaller%20than%20mid,%20then%0A%20%20%20%20%20%20%20%20//%20it%20can%20only%20be%20present%20in%20left%20subarray%0A%20%20%20%20%20%20%20%20if%20%28arr%5Bmid%5D%20%3E%20x%29%0A%20%20%20%20%20%20%20%20%20%20%20%20return%20binarySearch%28arr,%20l,%20mid%20-%201,%20x%29%3B%0A%0A%20%20%20%20%20%20%20%20//%20Else%20the%20element%20can%20only%20be%20present%0A%20%20%20%20%20%20%20%20//%20in%20right%20subarray%0A%20%20%20%20%20%20%20%20return%20binarySearch%28arr,%20mid%20%2B%201,%20r,%20x%29%3B%0A%20%20%20%20%7D%0A%0A%20%20%20%20//%20We%20reach%20here%20when%20element%20is%20not%0A%20%20%20%20//%20present%20in%20array%0A%20%20%20%20return%20-1%3B%0A%7D%0A%0Aint%20main%28void%29%0A%7B%0A%20%20%20%20int%20arr%5B%5D%20%3D%20%7B%202,%203,%204,%2010,%2040%20%7D%3B%0A%20%20%20%20int%20x%20%3D%2010%3B%0A%20%20%20%20int%20n%20%3D%20sizeof%28arr%29%20/%20sizeof%28arr%5B0%5D%29%3B%0A%20%20%20%20int%20result%20%3D%20binarySearch%28arr,%200,%20n%20-%201,%20x%29%3B%0A%20%20%20%20%28result%20%3D%3D%20-1%29%0A%20%20%20%20%20%20%20%20%3F%20cout%20%3C%3C%20%22Element%20is%20not%20present%20in%20array%22%0A%20%20%20%20%20%20%20%20%3A%20cout%20%3C%3C%20%22Element%20is%20present%20at%20index%20%22%20%3C%3C%20result%3B%0A%20%20%20%20return%200%3B%0A%7D&codeDivHeight=400&codeDivWidth=350&cumulative=false&curInstr=0&heapPrimitives=nevernest&origin=opt-frontend.js&py=cpp_g%2B%2B9.3.0&rawInputLstJSON=%5B%5D&textReferences=false"> </iframe>
````

`````
``````````

### Analysis

`````````` {div} full-width
`````` {card}

````` {admonition} Rules
:class: tip

- Break down the problem into subproblems
- Solve the sub problems
- Merge the sub problems to get desired Output
- *_Note: Must be sorted_*
- 
`````

````` {grid}

```` {grid-item-card}
Best-case $ \Rightarrow T(n) = O(1)$

$$target\ is\ first\ comparison$$
````

```` {grid-item-card}
Worst-case $ \Rightarrow T(n) = O(log\ n)$

$$target\ is\ last\ comparison$$
````

```` {grid-item-card}
Average-case _(in a successful search)_ $ \Rightarrow T(n) = O(log\ n)$

$$target\ is\ neither first\ nor\ last\ comparison$$
````

`````

``````
``````````

## Linear v. Binary

`````````` {div} full-width
````` {card}

```` {list-table}
:header-rows: 1

* - Linear
  - Binary
* - Input data need not to be in sorted.
  - Input data need to be in sorted order.
* - Also called sequential search.
  - Also called half-interval search.
* - $T(n) = O(n)$
  - $T(n) = O(log\ n)$
* - Multidimensional array can be used
  - Only single dimensional array is used
* - Performs equality comparisons
  - Performs ordering comparisons
* - Less complex.
  - More complex.
* - Very slow process.
  - Very fast process.

````

`````
``````````
