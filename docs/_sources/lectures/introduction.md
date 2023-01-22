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
  .blue {color:blue}
  .green {color:green}
  .orange {color:orangered}
  .purple {color:purple}
  .brown {color:brown}
  .img {align: center}
  summary {text-align: center}
</style>

# Introduction

## Welcome

```````` {div} full-width
``````` {card}
```` {glossary}
Course
  CSC 212 Data Structures & Algorithms

Lectures
  TR 3:30 - 4:45p @ Coastal Auditorium Room 

Labs
  W 10 -11:45a @ Library Room 166  
  W 12 -1:45p @ Library Room 166

Staff
  Jonathan Schrader, Instructor  
  Christian Esteves, Lead TA  
  Calvin Higgins, Daniel Diaz Pereyra, Stephanie Poncin, Cameron Castillo, TAs  

Course Technology
  Github, EdStem, Gradescope
````
```````
````````

## CSC 212

```````` {div} full-width
``````` {card}
Review of basic principles of <span class="orange">analysis of algorithm</span>

Introduction to fundamental <span class="orange">data structures</span> and their <span class="orange">algorithms</span>
    arrays, lists, stacks, queues, trees, hash tables,graphs

Survey of classic algorithms for <span class="orange">sorting</span> and <span class="orange">searching</span>

Prerequisites: CSC 211 (at least C-) and MTH 180

```````
````````

## Familiar Structures

```````` {div} full-width
``````` {card}

``` {dropdown} ![image](https://meribold.org/assets/cache-paper/oo-picture.png)
**ARRAY**
```

``` {dropdown} ![image](http://www.cs.southern.edu/halterman/Courses/Winter2018/318/Assignments/SPM/adj-matrix-1.png)
**MATRIX**
```

```````
````````

## New Structures

```````` {div} full-width
``````` {card}

````` {grid}
```` {grid-item}
:columns: 12
``` {dropdown} ![image](img/intro_linked_list.png)
Linked List
```
````

```` {grid-item}
:columns: 12
``` {dropdown} ![image](img/intro_binary_tree.png)
Binary Tree
```
````

```` {grid-item}
:columns: 6
``` {dropdown} ![image](img/intro_1.png)

```
````
```` {grid-item}
:columns: 6
``` {dropdown} ![image](img/intro_2.png)

```
````
`````

```````
````````

## Making Connections

```````` {div} full-width


``` {dropdown} ![image](img/intro_courses.png)

```


````````

## Importance?

```````` {div} full-width
``````` {card} What can be deduced??

``` {dropdown} ![image](img/intro_google_search.png)
This many hits denotes two things:
1. There is an impossible amount of information out there on the subject
1. When results fall in the ballpark of 20 million results, it's safe to safe it may be a topic worth understanding well...
```

```````
````````

## Recommended Textbooks

```````` {div} full-width
``````` {card} Click on any of the images to bring you to a pdf resource for the respective text

`````` {grid}
````` {grid-item-card}
:columns: 6
:link: https://github.com/Nam-H-Nguyen/NYUTandonBridge2018/blob/master/Books/Data%20Structures%20And%20Algorithm%20Analysis%20In%20C%2B%2B%20-%20Mark%20Allen%20Weiss%204th%20Edition.pdf
``` {image} https://cs.cheggcdn.com/covers2/31920000/31929311_1375774127_Width288.jpg
:align: center
:height: 350px
```
`````
````` {grid-item-card}
:columns: 6
:link: https://github.com/GenoWong/IntroductionToAlgorithms/blob/main/Introduction.to.Algorithms.4th.pdf
``` {image} https://4.bp.blogspot.com/-9bpk-ze4034/UiF37qd4hTI/AAAAAAAAAZU/V41wrgfPtqk/s1600/Introduction+to+Algorithms-Cormen.jpg
:align: center
:height: 350px
```
`````
````` {grid-item-card}
:columns: 6
:link: https://github.com/Igors78/Books/blob/master/Algorithm%20Design%20and%20Applications.pdf
``` {image} https://cdn.shopify.com/s/files/1/0282/2769/8787/products/medium_d235b08f-28fe-458e-909a-c65a77340e6c_1134x1498.jpg?v=1623753970
:align: center
:height: 350px
```
`````
````` {grid-item-card}
:columns: 6
:link: https://github.com/Igors78/Books/blob/master/Algorithms%2C%204th%20edition%20(2011).pdf
``` {image} https://www.informit.com/ShowCover.aspx?isbn=032157351X
:align: center
:height: 350px
```
`````

```````
````````

## C++ / Programming Refresher??

```````` {div} full-width
``````` {card}

`````` {card} Read a book
````` {grid}
```` {grid-item-card}
:columns: 4
:link: https://github.com/Acry/CPP-Starter/blob/master/C%2B%2B%20Crash%20Course%20A%20Fast-Paced%20Introduction%20by%20Josh%20Lospinoso.pdf
``` {image} https://cdn11.bigcommerce.com/s-gibnfyxosi/products/166105/images/167762/511Ui1iac8L__45873.1615580005.386.513.jpg?c=1
:align: center
:height: 250px
```
````
```` {grid-item-card}
:columns: 4
:link: https://ia801808.us.archive.org/20/items/think-like-a-programmer/Think_Like_a_Programmer.pdf
``` {image} https://external-content.duckduckgo.com/iu/?u=https%3A%2F%2Fnostarch.com%2Fsites%2Fdefault%2Ffiles%2Fstyles%2Fuc_product_full%2Fpublic%2Ftlap2.png%3Fitok%3DX2kWA4Kp&f=1&nofb=1&ipt=935ce77b254b3746f81101f84fa13c8ae2b843c3f2916aa0645f662c6e48ee0e&ipo=images
:align: center
:height: 250px
```
````
```` {grid-item-card}
:columns: 4
:link: https://www.papiro-bookstore.com/wp-content/uploads/2021/12/Algorithmic-Thinking-Content.pdf
``` {image} https://external-content.duckduckgo.com/iu/?u=https%3A%2F%2Fnostarch.com%2Fsites%2Fdefault%2Ffiles%2Fstyles%2Fuc_product_full%2Fpublic%2Falgorithmic-thinking_frontcvr.png%3Fitok%3D1CGO_-51&f=1&nofb=1&ipt=623dcbf20adbb68d9d7c8724fb896a469d93f090ed1e2487ce58f6a3a41e86a4&ipo=images
:align: center
:height: 250px
```
````
`````
``````

`````` {card} Enroll in a MOOC (massive open online course)
````` {grid}
```` {grid-item-card}
:columns: 8
:link: https://www.coursera.org/search?query=c%2B%2B&
``` {image} https://external-content.duckduckgo.com/iu/?u=https%3A%2F%2Flever-client-logos.s3.us-west-2.amazonaws.com%2F63a8149d-79fd-4c15-8241-2a3d73c0445b-1607995671294.png&f=1&nofb=1&ipt=a500e56e0cc065a4b86d0342cedd85d5a8a42b0f901711affe4ce9354eab1aa2&ipo=images
:align: center

```
````
```` {grid-item-card}
:columns: 4
:link:  https://www.edx.org/search?q=c%2B%2B
``` {image} https://edx-cdn.org/v3/prod/logo.png
:align: center
```
````
`````
``````

`````` {card} Solve Challenges
````` {grid}
```` {grid-item-card}
:columns: 8
:link: https://www.kattis.com
``` {image} https://open.kattis.com/images/kattis/judge.png?7f7dbf=?7f7dbf=
:align: center
:height: 150px
```
````
```` {grid-item-card}
:columns: 4
:link: https://www.hackerrank.com
``` {image} https://geeksgod.com/wp-content/uploads/2020/08/hackerrank.png
:align: center
```
````
`````
``````

```````
````````

## CLion

```````` {div} full-width
``````` {card} Click anywhere to be hyperlinked to the sign up form...
:link: https://www.jetbrains.com/shop/eform/students

``` {image} https://altari2.com/wp-content/uploads/2022/08/clion_logo_300x300.png
:height: 150px
```

``` {image} https://dashboard.snapcraft.io/site_media/appmedia/2017/12/Screen_Shot_2017-12-20_at_19.40.03.png
:align: center
```

```````
````````

## Grading

```````` {div} full-width
``````` {card}
`````` {glossary}

Lectures: 
    No formal grade

Labs: 
    **200 points**  
    12 labs / 20 points each  
    2 Lowest dropped  

Assignments: 
    **200 points**  
    2 practical assignments [50 points each]  
    2 conceptual assignments [50 points each]  

Projects: 
    **500 points**  
    1 Review Project [150 points]  
    1 Term Project [350 points]  

Final Exam: 
    **100 points**  
    1 exam  
    (cumulative, mcq, 2.5 hours, open note/book, closed human)  

_Note: Hold a 90 of better for the term and you'll be exempt from the final exam and granted an `A` for the term_

``````
```````
````````

## Labs & Assignments

```````` {div} full-width
``````` {card}
`````` {glossary}

Labs  
    Discussion and collaboration are allowed and encouraged. However, you must write your own code and/or commment each collaborators contribution.

Assignments  
    Discussions and collaboration are allowed, however you must write your own code and solutions. This is non-negotiable.  

All labs and assignments are to be turned in on time via Gradescope  
    Late submissions are <b class="red">NOT</b> accepted  
    Submissions via means other than Gradescope are <b class="red">NOT</b> accepted  

Plagiarism?  
    Just don’t do it  
    _If you get caught (chances are very high), your name(s) will be immediately reported for further sanctions_

``````
```````
````````

## Setting Expectations

```````` {div} full-width
``````` {card}
`````` {glossary}

Attend Lectures & Labs
    You get out what you put in...

Organize your time
    Schedule your time accordingly...
    Use a calendar/planner

Participate / Think Critically
    Lectures are discusion-based and conceptual, ask questions!!  
    Labs are practical: try, fail, try again...  if fail, ask questions!!  
    Office hours: there are five TAs and one instructor on staff hired to help you succeed. Take advantage!!

Start early!!
    Time is your biggest enemy in this course, plan accordingly!!

``````
```````
````````

## Need Help??

```````` {div} full-width
``````` {card}
`````` {glossary}

Post on EdStem  
    Answer questions  
    Share information  

Contact TAs
    Once again, they're there for you!

Come to Office Hours
    Scheduled or by appointment, they're available for you... 

``````
```````
````````

## Get Help!!

```````` {div} full-width
``````` {card}

```` {card} Facts

- Data Structures & Algorithms courses tend to have a lower success rate than many of their counterparts. This is the nature of the subject matter being difficult to grasp.

- Traditionally, these courses have about a 3:1 fail rate, meaning nearly 33% of students who enroll fail the course.

``` {figure} https://www.seton.com/media/catalog/product/d/i/directional-traffic-signs-look-double-arrow-l6432-lg.jpg
:align: center

_if it isn't one of them..._
```
````

```` {card} Reasons for Unsuccessful Outcomes
- <b class="red">No submission</b>
- <b class="red">No project</b>
````

```````
````````
