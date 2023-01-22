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

# Mergesort

`````````` {div} full-width
``` {image} https://gifimage.net/wp-content/uploads/2017/10/merge-sort-gif-5.gif
:align: center
```
``````````

## [Divide & Conquer](https://www.khanacademy.org/computing/computer-science/algorithms/merge-sort/a/divide-and-conquer-algorithms)

`````````` {div} full-width
``````` {card}

``` {card}

<b class="orange">Divide</b> the problem into <u>smaller</u> subproblems

<b class="orange">Conquer</b> recursively
- ... each subproblem

<b class="orange">Combine</b> Solutions

```

````` {card} Example
``` {image} imgs/mergesort/11_s04_1.png
```

- sorting with insertion sort is $n^2$   
- we can divide the array into two halves and sort them separately 

````` {grid}
```` {grid-item}
:columns: 6
``` {image} imgs/mergesort/11_s04_2.png

```
````
```` {grid-item}
:columns: 6
``` {image} imgs/mergesort/11_s04_3.png

```
````
`````

- each subproblem could be sorted in $≈\frac{n^2}{4}$
- sorting both halves will require $≈2\frac{n^2}{4}$ 🤔
- we need an additional operation to combine both solutions

*_Time “reduced” from $≈n^2$ to\ $≈\frac{n^2}{2}+n$_*


```````
``````````

## [Merge Sort](https://www.khanacademy.org/computing/computer-science/algorithms/merge-sort/a/overview-of-merge-sort)

`````````` {div} full-width
```` {card}

<span class="orange">Divide</span> the array into two halves

- just need to calculate the midpoint

Conquer <span class="orange">Recursively</span> each half

- call Merge Sort on each half (i.e. solve 2 smaller problems)

<span class="orange">Merge</span> Solutions

- after both calls are finished, proceed to *_merge_* the solutions

````
``````````

## Divide & Conquer

`````````` {div} full-width
````` {card} Consider how this breaks out...
```` {dropdown} ![image](imgs/mergesort/11_s06_before.png)
``` {image} imgs/mergesort/11_s06_after.png
```
``` {image} imgs/mergesort/11_s06_2.png
```
````
`````
``````````

### [Merge Sort](https://www.geeksforgeeks.org/merge-sort/)

`````````` {div} full-width
``````` {card}

`````` {tab-set}
````` {tab-item} pseudocode
``` {code-block} cpp
:lineno-start: 1
:emphasize-lines:

if (hi <= lo) return;

int mid = lo + (hi - lo) / 2;

mergesort(A, lo, mid);

mergesort(A, mid + 1, hi);

merge(A, lo, mid, hi);
```
[Merge Sort: pseudocode](https://www.geeksforgeeks.org/merge-sort/)
`````
````` {tab-item} mergesort
``` {code-block} cpp
:lineno-start: 1
:emphasize-lines:
void mergesort(int *A, int n) {
  int *aux = new int[n];  
  r_mergesort(A, aux, 0, n - 1);
  delete[] aux;
}
```
`````
````` {tab-item} r_mergesort
``` {code-block} cpp
:lineno-start: 1
:emphasize-lines:
void r_mergesort(int *A, int *aux, int lo,int hi) {
  
    //basecase(single element or empty list)
  if (hi <= lo) return;

  //divide
  int mid = lo + (hi - lo) / 2;

  //recursively sort halves  
  r_mergesort(A, aux, lo, mid);
  r_mergesort(A, aux, mid + 1, hi);

  //merge results 
  merge(A, aux, lo, mid, hi);
}
```
`````
````` {tab-item} merge
``` {code-block} cpp
:lineno-start: 1
:emphasize-lines:
void merge (int *A, int *aux, int lo, int mid,int hi) {

    // copy array
    std::memcpy(aux + lo, A + lo, (hi - lo + 1 * sizeof(A)));
    
    // merge 
    int i = lo, j = mid + 1;

    for (int k = lo; k <= hi; k++) {  

        if (i > mid) A[k]=aux[j++];  

        else if (j > hi) A[k] = aux[i++];

        else if(aux[j] < aux[i]) A[k] = aux[j++];

        else A[k] = aux[i++];
    }
}
```
`````
``````
```````
``````````

### [Merging two sorted arrays](https://www.geeksforgeeks.org/merge-two-sorted-arrays/)

`````````` {div} full-width
```` {card}

``` {image} imgs/mergesort/11_s09.png
```

*_A secondary array is necessary_*

*_to guarantee a_* **[lineartime](https://www.khanacademy.org/computing/computer-science/algorithms/merge-sort/a/linear-time-merging)** *_operation_*

````
``````````

## [Analysis (recurrence)](https://www.khanacademy.org/computing/computer-science/algorithms/merge-sort/a/analysis-of-merge-sort)

`````````` {div} full-width
```` {list-table}
:header-rows: 1

* - 
  - Worst Case
  - Average Case
  - Best Case
* - Time Complexity
  - $O(n\ log\ n)$
  - $O(n\ log\ n)$
  - $O(n\ log\ n)$
````

```` {card} Breakdown (generalization)
A merge sort consists of several passes over the input.  

$1^{st}$ Pass: merges segments of size 1  
$2^{nd}$ Pass: merges segments of size 2  
$i^{th}$ Pass: merges segments of size $2^{i-1}$.  
Total number of passes: $log_2 n$  

As merge showed, we can merge two sorted segments in linear time, which means that each pass takes $O(n)$ time. 
Since there are $log_2\ n$ passes, the total computing time is $O(n\ log\ n)$, or expressed as:

$$T(n) = 2T(\frac{n}{2}) + O(n)$$

````
``````````

## [Recursion Tree (trace)](https://youtu.be/C4JjXc0htp0)

`````````` {div} full-width
````````` {card}

``` {figure} https://cdn.kastatic.org/ka-perseus-images/5fcbebf66560d8fc490de2a0d8a0e5b1d65c5c54.png
```

``````` {admonition} code
`````` {tab-set}
````` {tab-item} mergesort
``` {code-block} cpp
:lineno-start: 1
:emphasize-lines:
void mergesort(int *A, int n) {
  int *aux = new int[n];  
  r_mergesort(A, aux, 0, n - 1);
  delete[] aux;
}
```
`````
````` {tab-item} r_mergesort
``` {code-block} cpp
:lineno-start: 1
:emphasize-lines:
void r_mergesort(int *A, int *aux, int lo,int hi) {     
  if (hi <= lo) return;
  int mid = lo + (hi - lo) / 2;
  r_mergesort(A, aux, lo, mid);
  r_mergesort(A, aux, mid + 1, hi);
  merge(A, aux, lo, mid, hi);
}
```
`````
``````
```````

```` {card}
Total time for $mergeSort$ is: the sum of the merging times for all the levels  
- If there are $l$ levels in the tree, then the total merging time is $l * cn$  
- Where $l$ is the number of subproblem levels until subproblems reach size $n$  
For total time, we end up with:

$$cn(log_2 n + 1)$$

- Discard the low-order term (constant) and the coefficient  

$$O(n\ log_2\ n)$$
````

`````````
``````````

## [Sorting Visualizer](https://clementmihailescu.github.io/Sorting-Visualizer/)

`````````` {div} full-width
````` {card}
:link: https://clementmihailescu.github.io/Sorting-Visualizer/
_Click to open in new tab/window_
``` {image} img/w7_mergesort.png
```
KEY: Blue - element, Green - Sequential, Red - Swap, Purple - placed
`````
``````````

## Comments on Merge Sort

`````````` {div} full-width
````` {card}
```` {card} Major disadvantage
- it is _not_ **in-place**
- in-place algorithm exists but it is complex and inefficient
````
```` {card} Improvements
- use insertion sort for small arrays
  - avoid overhead on small instances (~10 elements)
- stop if already sorted
  - avoids unnecessary merge
  - works well with partially sorted arrays
````
*_In-place Sorting_*
`````
``````````

## Example

`````````` {div} full-width
```` {card} Think about reversing an array or string
``` {card} *_solution 1:_* use an additional array of equal size
- what is the required extra memory?
```
``` {card} *_solution 2:_* exchange first and last and work recursively on the inner part
  - can do it iteratively as well
  - what is the required extra memory?
```
````
``````````

## [In-place sorting](https://www.geeksforgeeks.org/in-place-algorithm/)

`````````` {div} full-width
`````` {card}
``` {card}
A sorting algorithm is *_in-place_* if it uses *_$O(log\ n)$_* extra memory

Are selection and insertion sorts *_in-place_*?
```

```` {admonition} selection sort
``` {code-block} cpp
:lineno-start: 1
:emphasize-lines:
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
 
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++) {
       
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
            
            if (arr[j] < arr[min_idx]) min_idx = j;
 
        // Swap the found minimum element with the first element
        if(min_idx!=i)
            swap(&arr[min_idx], &arr[i]);
    }
}
```
````

```` {admonition} insertion sort
``` {code-block} cpp
:lineno-start: 1
:emphasize-lines:
void insertionSort(int arr[], int n) 
{ 
    int i, key, j; 
    
    for (i = 1; i < n; i++) 
    { 
        key = arr[i]; 
        j = i - 1; 
  
        // Move elements of arr[0..i-1],  
        // that are greater than key, to one 
        // position ahead of their 
        // current position
        while (j >= 0 && arr[j] > key)
        { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key; 
    } 
} 
```
````

``````
``````````

## Stable Sorting

`````````` {div} full-width
``````` {card}

```` {admonition} Stability
A sorting algorithm is *_stable_* if it preserves the order of equal elements

Consider sorting (in ascending order) a list $A$ into a sorted list $B$. Let $f(i)$ be the index of element $A[i]$ in $B$. The sorting algorithm is stable if:

for any pair $(i,j)$ such that $A[i] = A[j]$ and $i < j$, then $f(i) < f(j)$

``` {image} imgs/mergesort/11_s19.png
:width: 92%
```
````
`````` {admonition} Stable?
:class: tip

````` {grid}
```` {grid-item} 
``` {image} imgs/mergesort/11_s20_1.png
:width: 375px
```
unsorted
````
```` {grid-item} 
``` {image} imgs/mergesort/11_s20_2.png
:width: 375px
```
sorted
````
`````
``` {dropdown} Stable?
<b class="red">NOT STABLE</b>
```
``````
`````` {admonition} How about now?
:class: tip
````` {grid}
```` {grid-item} 
``` {image} imgs/mergesort/11_s20_1.png
:width: 400px
```
unsorted
````
```` {grid-item} 
``` {image} imgs/mergesort/11_s20_3.png
:width: 400px
```
sorted
````
`````
``` {dropdown} Stable?
<b class="green">STABLE</b>
```
``````
``````````

## Stability

`````````` {div} full-width
````` {card}

``` {dropdown} Is selection sort stable?
Selection sort algorithm picks the minimum and swaps it with the element at current position.

Suppose the array is:

$$[5,\ 2,\ 3,\ 8,\ 4,\ 5,\ 6]$$

$$[5_a,\ 3,\ 4,\ 5_b,\ 2,\ 6,\ 8]$$

- After iteration 1:
  - 2 will be swapped with the element in 1st position:

- So our array becomes:

$$[2,\ 3,\ 4,\ 5_b,\ 5_a,\ 6,\ 8]$$

- Since now our array is in sorted order and we clearly see that $5_a$ comes before $5_b$ in initial array but not in the sorted array.

- Therefore, selection sort is not stable.

<b class="red">NOT</b> STABLE
```
- long distance swaps
- try: 5 2 3 8 4 5 6

``` {dropdown} Is insertion sort stable?
<b class="green">STABLE</b> 
```
- equal items never pass each other (depends on correct implementation)

`````
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
```
`````
``````
```````
``````````