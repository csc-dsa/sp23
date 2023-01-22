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

# Lab 10 : Hash Tables

## 1. Introduction

### Hash Tables

The goal of this lab is to provide background on **Hash Tables, Chaining, & Open-Addressing**.

Hash Tables are a Data Structure that maps keys to values via a Hash Function.

The core concept is to have an array of size *n* with efficient storage/retrieval time.

Let's take a brief look at how these work. Using an example w/ a table size of 5, we have the following:

| Index | Value |
| ----- | ----- |
| 0     |       |
| 1     |       |
| 2     |       |
| 3     |       |
| 4     |       |

But how do we store values? We need a Hash Function!

A Hash Function is (surprise) a function that generates some Hash out of the value to be stored. This is an entire field of research, so we'll keep it simple for now. Let's use the following function:

$$f(x) = x \% n$$

Let's use it to store the following values: 1, 14, 13, 16

`````` {tab-set}
```` {tab-item} 1
```{card}
:text-align: center
$1 \% 5 = 1$
```
``` {list-table}

* - Index
  - 0
  - 1
  - 2
  - 3
  - 4
* - Value
  - 
  - 1
  - 
  - 
  - 
```
````

```` {tab-item} 14
```{card}
:text-align: center
$$14 \% 5 = 4$$
```
``` {list-table}

* - Index
  - 0
  - 1
  - 2
  - 3
  - 4
* - Value
  - 
  - 1
  - 
  - 
  - 14
```
````

```` {tab-item} 13
```{card}
:text-align: center
$$13 \% 5 = 3$$
```
``` {list-table}

* - Index
  - 0
  - 1
  - 2
  - 3
  - 4
* - Value
  - 
  - 1
  - 
  - 13
  - 14
```
````
```` {tab-item} 16
```{card}
:text-align: center
$$16 \% 5 = 1$$
```
``` {list-table}

* - Index
  - 0
  - 1
  - 2
  - 3
  - 4
* - Value
  - 
  - 1 <br> already a value!
  - 
  - 13
  - 14
```
````
``````

We've found an issue with our new Data Structure! This is known as a Hash Collision. Let's look at methods to combat this.

## 2. Open Addressing

Open Addressing is a method of collision resolution in hash tables. This method uses **probing** in order to find an open spot in the array to place a value that has encountered a collision. Let's look at a few:

### Linear Probing

For this method, we simply keep checking the next spot to see if it is available. Let's use the example collision from above and see where we end up:

| Index | Value                  |
| ----- | ---------------------- |
| 0     |                        |
| 1     | 1 <-- already a value! |
| 2     | 16                     |
| 3     | 13                     |
| 4     | 14                     |

Since the very next spot was open, 16 gets placed at index 2.

### Double Hashing

Another open addressing method is to use double hashing. In this strategy, a second hash function is utilized to re-hash a value that has collisions. Let's view that example from above again using this new definition:

$$f(x, i) = [(x % n) + (i * f'(x))] % n$$
$$f'(x) = x+3$$
$$Where `i` is the number of collisions so far$$

At the first attempt there are no recorded collisions yet for the input 16 so `i` is 0

$$f(16, 0) = [(16 % n) + (0 * 19)] % n = 1$$

After encountering a collision on the first pass, `i` will now be 1

$$f(16, 1) = [(16 % n) + (1 * 19)] % n = [(1) + 19] % n = 0$$

| Index | Value |
| ----- | ----- |
| 0     | 16    |
| 1     | 1     |
| 2     |       |
| 3     | 13    |
| 4     | 14    |

A slightly different result than Linear Probing. There are many different strategies for implementing these functions, such as quadratic probing. Let's look at another method entirely.

#### Chaining

In Chaining, instead of an array of keys, we have an array of lists that hold keys. This means probing strategies are not needed, and we just need to push a new value onto the list. For efficiency's sake, we typically push onto the front of the list to maintain O(1) time. Thus, our example values from earlier create the following table:

| Index | Value   |
| ----- | ------- |
| 0     |         |
| 1     | 16 -> 1 |
| 2     |         |
| 3     | 13      |
| 4     | 14      |

## 3. Your Task

Your goal for this lab is to complete the following tasks **in order**:

1. Implement a Hash Table that uses Linear Probing. Generate test cases to prove it works.
2. Implement a Hash Table that uses Double Hashing. Generate test cases to prove it works.
3. Implement a Hash Table that uses Chaining. Generate test cases to prove it works.

To complete the above objectives, create a Hash Table class using a vector as the underlying data structure. Then write a hash function, insert function and an accessing function.

Insert: Insert will call the hash function to find the index to insert into, as well as handle collisions/calculating the new index.

Access: The accessing function will call the hashing function and return the data stored at that spot. It will also need to re-calculate an index if it
        doesn't find the data in the case of the data having been stored somewhere else due to a collision. Finally it will need to handle missing entries.

The lecture slides have Java code outlining these functions. Use them for additional clarity if necessary.

Note: You will need `doctest.h` and `test.cpp` from last week to use as a base for your test cases. These files have been provided but the tests in `test.cpp` will need replacing with new tests for your Hash Tables. Having a `makefile` wouldn't hurt either!

## 4. Submission

You will submit files `hashTable.h` and `hashTable.cpp` along with `test.cpp`
