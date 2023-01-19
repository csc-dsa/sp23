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

# Binary Search Tree

Getting into the basics is simple being able to implement some basic functionality within the langauge. Enter the infamous "Hello world" problem soon...

## C++ Basics

Program 2-1 exemplifies the most minimal structure necessary to compile an output.

````{admonition} A simple C++ program
```{code-block} c++
---
caption: | 
emphasize-lines: 0
lineno-start: 1
---
#include<iostream>

using namespace std;
int main ()
{
  cout << "Hello world";
  return 0;
}
```  

```cpp
Programming is great fun!!
```
````  

Line 1  
: The first two lines of text in the sample are called comments. A comment is denoted by a `//` [double forward slash] and can be easily distingusied from the rest of the code as is it lighter than the rest or grayscaled.

Line 2  
: This allows use of the compiler and its abilities of input and output controls. Without this, the compiler will not be able to compile the program.

Line 4  
<!-- TODO: CHANGE THIS TO A NON-BULLSHIT DESCRIPTION -->
: Nobody knows what this does, they just know it's important...

Line 5
: Here we define a function to complete a set of tasks. We will cover functions in depth later in the term. Just know the `{}` [curly braces] are used to encapsulate, or contain, each task the function will complete before ending.

## Input/Output



## Data Types



## Expressions

<!-- 
With MyST Markdown, you can define code cells with a directive like so:

```{code-cell}
print(2 + 2)
```

When your book is built, the contents of any `{code-cell}` blocks will be
executed with your default Jupyter kernel, and their outputs will be displayed
in-line with the rest of your content.

```{seealso}
Jupyter Book uses [Jupytext](https://jupytext.readthedocs.io/en/latest/) to convert text-based files to notebooks, and can support [many other text-based notebook files](https://jupyterbook.org/file-types/jupytext.html).
```

## Create a notebook with MyST Markdown

MyST Markdown notebooks are defined by two things:

1. YAML metadata that is needed to understand if / how it should convert text files to notebooks (including information about the kernel needed).
   See the YAML at the top of this page for example.
2. The presence of `{code-cell}` directives, which will be executed with your book.

That's all that is needed to get started!

## Quickly add YAML metadata for MyST Notebooks

If you have a markdown file and you'd like to quickly add YAML metadata to it, so that Jupyter Book will treat it as a MyST Markdown Notebook, run the following command:

```
jupyter-book myst init path/to/markdownfile.md
``` -->


def main () => int:
  return 0