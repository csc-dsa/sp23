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

# Analysis of Algorithms

`````````` {div} full-width
``` {image} https://evatronix.com/images/en/offer/product-design/product-development/Evatronix_Algorithm_development_and_analysis_01_800x450.jpg
:align: center
```
``````````

## Problem, algorithm, and program

`````````` {div} full-width
```` {card}

``` {dropdown} Problem
- a task to be performed
- best thought in terms of (well-defined) inputs and outputs
- problem definition does not impose constraints on how the problem is solved but often includes resource constraints
```

``` {dropdown} Algorithm
- a sequence of steps followed to solve a problem
- it must be correct and composed of a finite number of concrete steps
- there can be no ambiguity
- it must terminate
```

``` {dropdown} Program
- a representation of an algorithm in some programming language
```

````
``````````

## Analysis of algorithms

`````````` {div} full-width
```` {card}

``` {card} Algorithms

> “Any well-defined computational procedure that takes some value,or set of values,as input and produces some value, or set of values, as output.”
>
> -- [Cormen et al., Introduction to Algorithms, 3rd.Ed.]

```

``` {card} Resources necessary to execute an algorithm?
- Time Complexity (running time)
- Space Complexity (memory)

_Resources typically depend on input size_

```

````
``````````

## Developing a usable algorithm

`````````` {div} full-width

`````` {card}
``` {figure} img/w1_algo_design.png
:width: 75%

COS 226 lectures, Princeton University
```

``````
``````````

## Why analyze algorithms?

`````````` {div} full-width
```` {card}
``` {card}
- Classify algorithms/problems
- Predict performance/resources
- Provide guarantees
- Understand underlying principles of problems
- and...
```

![image](img/w3_01.png)

````
``````````

## Analyzing computational cost

`````````` {div} full-width
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
``````````

## Empirical analysis (timing)

`````````` {div} full-width
``` {card}

- Implement algorithm
- Run on different input sizes
- Record actual running times
- Calculate hypothesis
- Predict and validate

```
``````````

## Timing Algorithms

`````````` {div} full-width
`````` {admonition} Example 1
:class: important

````` {grid}

````{grid-item-card} Euler's Constant
```{card} 
... mathematical constant that is the base of the natural logarithm. It is approximately equal to 2.71828.
```
$$
\lim_{x\to \infty} \bigg(1 + \frac{1}{n} \bigg)^n
$$
````

````{grid-item-card} Leonhard Euler (1707–1783)
```{card} 
![](https://personajeshistoricos.com/wp-content/uploads/2018/04/Leonhard-Euler-2-785x1024.jpg)
... a Swiss  mathematician, physicist, astronomer, geo  grapher, logician and engineer who made  important and influential discoveries in  many branches of mathematics.
```
````

`````

$$
\begin {align}
e & = \lim_{x\to \infty} \bigg(1 + \frac{1}{n} \bigg)^n \\
& = \frac{1}{0!} + \frac{1}{1!} + \frac{1}{2!} + \frac{1}{3!} + \frac{1}{4!} + \dotsb
\end {align}
$$

``````````

#### Algorithms

`````````` {div} full-width
````` {grid}

```` {grid-item-card} Algorithm 1
```{code-block} cpp
:lineno-start: 1
:emphasize-lines: 5-7

long double euler1 (int n) {
    long double sum = 0;
    long double fact;
    for (int i = 0; i <= n; i++) {
        fact = 1;
        for (int j = 2; j <= i; j++) {
            fact *= j; 
        }
        sum += (1.0/fact);
    }
    return sum;
}
```
````

````{grid-item-card} Algorithm 2
```{code-block} cpp
:lineno-start: 1
:emphasize-lines: 5,6

long double euler2 (int n) {
    long double sum = 0;
    long double fact = 1;
    for (int i = 0; i <= n; i++) {
        sum += (1.0/fact);
        fact *= (i + 1); 
    }
    return sum;
}
```
````

`````

**Which is more efficient?**

`````` {admonition} Example 2
:class: important

![image](https://azcoinnews.com/wp-content/uploads/2019/11/1-8.jpg)

$$
F_0 & = 0 \\
F_1 & = 1 \\
F_n & = F_{n-1} + F_{n-2} \\
& = 0, 1, 1, 2, 3, 5, 8, 13, 21, 34 \dotsb
$$

````{card} Iterative
```{code-block} cpp
:lineno-start: 1
:emphasize-lines: 5

uint64_t fibI(uint16_t n){
    uint64_t sum;
    uint64_t prev[] = {0,1};
    if (n < 2) return n;
    for (uint16_t i = 2; i <= n; i++) {
        sum = prev[0] + prev[1];
        prev[0] = prev[1];
        prev[1] = sum;
    }
    return sum;
}
```
````

```` {card} Recursive 
```{code-block} cpp
:lineno-start: 1
:emphasize-lines: 3

uint64_t fibR (uint16_t n) {
    if (n < 2) return n;
    else return fibR(n-1) + fibR(n-2);
}
```
````

````{card} Timing...
```{code-block} cpp
:lineno-start: 1

void time_func(uint16_t n, const char *name) {
    uint64_t val;
    Clock::time_point tic,toc;
    if (! strcmp(name,"Iter")) {
        tic = Clock::now();
        val = fib_iter(n);
        toc = Clock::now();
    }
    if (! strcmp(name,"Rec")) {
        tic = Clock::now();
        val = fib_rec(n);
        toc = Clock::now();
    }
    std::cout << name << "fib(" << n << "):\t" 
              << std::fixed << std::setprecision(4) 
              << Seconds(toc-tic).count() << "sec.\tOutput:"
              << val << std::endl; 
}
    
int main (int argc, char** argv) {
    if (argc != 3) {
        std::cout << "Usage:./fib<n><alg>\n";
        std::cout << "\t<n>\tn-th term to be calculated\n";
        std::cout << "\t<alg>\t algorithm to be used(RecorIter)\n";
        return 0;
    }
    uint16_t n = (uint16_t)
    atoi(argv[1]);
    time_func(n,argv[2]);
}
```
````

``` {admonition} Outcomes
:class: dropdown

![image](img/w3_02.png)

**Is this as expected?**
```

```{admonition} Hypothesis
:class: dropdown

![image](img/w3_03.png)

**Complete the graph, what would it look like?**
```

``````
``````````

## Limitations of empirical analysis

`````````` {div} full-width
```` {card}
**Requires implementing several algorithms for the same problem**
- may be difficult and time consuming
- implementation details also play a role (one particular algorithm may be “better written”)
  
**Requires extensive testing**
- time consuming
- choice of test cases might favor one of the algorithms

**Variations in hardware, software, and operating sysytem affect analysis**
````
``````````
