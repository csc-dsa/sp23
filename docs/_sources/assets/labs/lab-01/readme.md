# C++ Crash Course

Welcome to the first CSC 212 lab. Your goal for this lab will be to set up your environment and familiarize yourself with some basic terminal commands. **Be sure to read and follow all instructions unless otherwise specified.**  You'll find the table of contents for this lab below.

1. [Introduction](#part-1-introduction)
2. [Command-Line Exploration](#part-2-basic-unix-command-line-exploration)
3. [Command-Line Arguments](#part-3-command-line-arguments)
4. [Proper Programming Practices](#part-4-proper-programming-practices)
5. [Object-Oriented Programming](#part-5-object-oriented-programming)
6. [Debugging](#part-6-debugging)
7. [Exercise](#part-7-exercise)

## Part 1. Introduction

Hopefully you have chosen your C++ IDE for use throughout the semester, have it setup, and are ready to program. If not, we will support Clion by JetBrains for the term.

Setup:

- Go here, [https://www.jetbrains.com/shop/eform/students](https://www.jetbrains.com/shop/eform/students), and create an account using your URI student email
  - _Note: Remmber to keep you login information handy_
- Download & install `ToolBox App` here, [https://www.jetbrains.com/toolbox-app/](https://www.jetbrains.com/toolbox-app/)
  - Use your login information to access the app
- Find `Clion` (professional or community edition) and click <kbd>install</kbd>

In lieu of an IDE, feel free to simply use a text editor (I recommend [Visual Studio Code](https://code.visualstudio.com)) & the terminal commands we'll be covering today.

The next section will deal with Unix commands, as Unix is a common environment for C++ development. For those of you in a Windows environment, you can install the [Windows Subsystem for Linux](https://itsfoss.com/install-bash-on-windows/) and gain access to a Unix Shell.

## Part 2. Basic Unix Command-Line Exploration

Now that you've set up your environment, we can start to learn some basic UNIX command line. Unix and [Unix-like operating systems](http://www.doc.ic.ac.uk/~wjk/unixintro/Lecture1.html), like Linux, can all use the following commands to interact with [file systems](http://homepages.uc.edu/~thomam/Intro_Unix_Text/File_System.html). Basic tasks like changing directories, creating or modifying files, or removing files all together are just a few examples of things we can do using a Shell terminal.

To really understand what you'll be doing for this section of the lab, having a strong understanding of what a file system is and how we can navigate it will be critically important.

### Opening a New Terminal

Mac OS: Run the 'Terminal' program

Windows: If you followed the above steps to install the 'Windows Subsystem for Linux' then run the 'Ubuntu' program to open a terminal.

### Making a file

We can make empty files on the fly with the `touch <filename>` command. Try the following below:

```bash
$ touch test.cpp
```

Now, you should see `test.cpp` in your file manager on the left-hand side.

### Removing files

Before your workspace gets too cluttered, let's remove that test file you just created with the `touch` command. You can do this by typing:

```bash
$ rm test.cpp
```

The test file you just created should be removed if this command ran properly.

Ok, lets create another empty file with the following command:

```bash
$ touch hello.cpp
```

### Creating a new directory

Making and deleting files is great but we often need to organize them in a sensible way. We usually do this by making **directories**. You can think of directories as folders. They're named locations that can hold other files or directories.

To make a directory type the following terminal command:

```bash
$ mkdir projects
```

Now you should see your `hello.cpp` and `projects` folder in your file manager.

### Removing a directory

Just like how we created and removed a file, we can do the same with directories. Lets make a test directory named `testd` with the following command:

```bash
$ mkdir testd
```

To delete this directory (only if is empty), we can simply run:

```bash
$ rmdir testd
```

### Moving files

Lets clean up our workspace by moving that `hello.cpp` file into our projects folder.  The syntax to move one file from one location to another location is `mv <source> <target>`. In this case, it would be:

```bash
$ mv hello.cpp projects
```

Now, our `hello.cpp` file is in our `projects` directory.

### Print Working Directory

To see where we are, the command `pwd` will print the current directory you are operating in to the command line. Currently, running the command

```bash
$ pwd
```

If you are running on 'Ubuntu', it should print out `/home/ubuntu`, if at any point you changed directory with the following command your output will be different. The output of this line will differ based on your environment.

### Change Directory

Now that we have made a new directory named `projects` and moved our `hello.cpp` file to it, we need to navigate our terminal to this directory in order to have easy access to our file for editing/compiling/file management. This is accomplished with the `cd` command with syntax as follows, `cd <directory_path>`, meaning we can move more than one file at a time. For now the following command should get you to where you need to be,

```bash
$ cd projects/
```

Now that we have changed directory, we can execute the earlier commands to validate our position within the file system. Executing `pwd` from this file should output `/home/ubuntu/projects` (again, assuming you are running on 'Ubuntu') and executing `ls` should show that there is a file named `hello.cpp` present.

Some useful cd commands:
```bash
#### to change your working directory to its parent directory, i.e. one step back
$ cd ..
#### to change back to your user directory, i.e. "/home/ubuntu" or "~/" in the case of CS50 IDE's file system
$ cd
#### to change back to the file system root directory, i.e. "/" for short
$ cd /
```

> Note that `cd` can accept full paths, so for example `cd ../..` will move your working directory two steps back in the file system, though **don't do this now** as this will put you behind your root directory which is out of the scope of this lab

### Displaying File Contents

Another (popular) command-line utility available to us is `cat`, which is short for concatenate. In its simplest form, `cat` can display the contents of a text file; it can also be used to concatenate together many text files.

For example, if we had a text document named `test.txt` with the contents 

```text
I love CSC 212
```

The contents of that file would print out to our terminal by running:

```bash
$ cat test.txt
```

Spend some time to create a text file with some content in it and use the `cat` command to report those contents to the console.

### Shell Hints

Before we move on, there are a few things about the shell you should know. The up arrow goes to previous commands. And if you think the computer can guess what you are typing, you can hit TAB to have it completed for you. For example, if `cd pro` is typed in terminal, and the TAB key is hit, the rest of the file name will be filled in. You can find more information on terminal commands [here](http://mally.stanford.edu/~sr/computing/basic-unix.html).

## Part 3. Command-Line Arguments

It is often helpful for us to specify how a program will run by providing arguments during the execution process. For example, normally compiling a program and running may look like this:

```
g++ main.cpp -o prog && ./prog
```

But if we wanted the execution of our program to change based on some variable (number of loops, size of a data structure, etc.) we can provide an argument here like so:

```
g++ main.cpp -o prog && ./prog 5
```

Or even multiple arguments

```
g++ main.cpp -o prog && ./prog 5 3 6 local
```

Our code would look like so:

```c++
int main(int argc, char*argv[]){
    
}
```

Here are some resources on C++ Strings:

- https://www.tutorialspoint.com/cplusplus/cpp_strings.htm
- https://www.youtube.com/watch?v=h2LGTzQXzJU
- https://eecs280staff.github.io/notes/05_Strings_Streams_IO.html#c-style-strings
- https://www.cprogramming.com/tutorial/lesson9.html

Where `argc` stands for the number of arguments passed (including the command to run the program!) and `argv` holds those arguments. Note the type! They will all be treated as char arrays or C-Style strings. You will need to convert them if you want to use them as different types (int, float, etc.) Using the last argument example, this is how we would extract them:

```c++
#include <string> // string, stoi (string to integer)
int main(int argc, char*argv[]){
    int num1 = std::stoi(argv[1]); // extracts the 5
    int num2 = std::stoi(argv[2]); // extracts the 3
    int num3 = std::stoi(argv[3]); // extracts the 6
    std::string str(argv[4]); // converts the C-Style string to a C++ String Object
}
```

Additional reading can be found in [this tutorial](https://www.geeksforgeeks.org/command-line-arguments-in-c-cpp/)

## Part 4. Proper Programming Practices 

There are many ways to solve a problem. This too holds true for programming; there are multiple ways to code a solution to a problem. This section will go over a few tried-and-true rules to live by in order to create code that won't get you banished from polite society.

### Plan before you code!

A common trap students fall into is programming as they solve a problem; this has a tendency to spiral out of control into an unsalvageable mess that ends in a waste of time. Take the time to plan your solution BEFORE you even touch code. What functions, and variables, you'll need, the flow of your program, etc. I **guarantee** that the time spent planning before hand will more than makeup for the time you'd waste backtracking & re-writing code otherwise.

### K.I.S.S (Keep it Simple, Stupid!)

Your code will not be efficient if you do not first solve the underlying problem in a simple manner. Over-complication is common in these early programming courses; don't be afraid to reach out to staff and ask for feedback on your strategy! You can [read more about this amazing principle] here.(https://www.interaction-design.org/literature/article/kiss-keep-it-simple-stupid-a-design-principle)

### Naming Conventions

This is a [good reference page](https://google.github.io/styleguide/cppguide.html) for writing "proper" C++ code. 

On top of following the guidelines here, make sure to give your functions & variables **clear, proper** names! When you ask the staff for help its *incredibly* unhelpful (and time consuming) to attempt and parse hundreds of lines of code that look like ` int a;`

### Functions

- Follow the "Rule of Three"
  - If you have a piece of code that is replicated (read: copy & pasted) more than twice, this task should be a function.
- Any section of code that performs a specific task in your program should be a function. Some examples:
  - Reading from a file
  - Writing to a file
  - Performing calculations on an array

### Variables

Don't be afraid to create variables to improve code clarity! As mentioned before, name them appropriately!

### Ninety-ninety rule

This is a fantastic quote that really captures the main pitfalls many of you will fall into:

``` {epigraph}
"The first 90 percent of the code accounts for the first 90 percent of the development time. The remaining 10 percent of the code accounts for the other 90 percent of the development time."

-- Tom Cargill, Bell Labs
```

To clarify, software has a tendency to take longer than anticipated to finish. **Start your assignments early!**

### Chasing false efficiency

While I (Christian) am a huge proponent of writing efficient code, it is important to realize that not everything needs to be coded in the most efficient manner. Often times code clarity/development speed take a higher priority. As an example: if it takes 5 minutes to code a function that runs once in 0.005 seconds, is it really worth spending an hour to get that same function to run in 0.002 seconds? Probably not. A solid rule of thumb while you're learning is to get something that **works** first, **then** worry about efficiency to improve your skill afterwards.

### Avoid Hard-coding!

You should **always** use variables to represent values in your code. This makes your code easier to modify later on if needed & adds clarity to your code.

As an example:

```c++
// Bad
for(int i = 0; i < 5; i++){
    // Do stuff
}
```

```c++
// Good
unsigned int num_rows = 5;
for(int i = 0; i < num_rows; i++){
    // Do stuff
}
```

## Part 5. Object-Oriented Programming

There are four primary principles of Object-Oriented Programming that are enumerated in any OOP introductory text, video, lecture, {insert medium of education here}. These are: Encapsulation, Abstraction, Inheritance, Polymorphism.

The core idea of OOP is that you design Classes which are then used to instantiate Objects that communicate with one another to solve a problem.

The following code is used to highlight the four principles mentioned:

```c++
// Animal.h
#pragma once
#include <iostream>

class Animal{
    private:
    	float hunger;

    public:
      Animal(float initial_hunger);
    	void Eat(float sustenance);
    	float GetHunger();
    	virtual void Speak() = 0;
};
```

> `#pragma once` is a non-standard pragma that is supported by the vast majority of modern compilers. If it appears in a header file, it indicates that it is only to be parsed once, even if it is (directly or indirectly) included multiple times in the same source file ([read more](https://en.cppreference.com/w/cpp/preprocessor/impl)).
<br><br>
The `virtual` keyword, when applied to a function, denotes a function that will be overridden by a child/derived class.
<br><br>
When a class derives another class, we say it has an **is-a** relationship. This relationship allows the derived class to behave as itself and as its parent (the base class)-- this is called **polymorphism**. In the classes below, for example, we have a `Cat` class that we say **is-a** `Animal` and therefore it has all the same functionality as an `Animal`. While we can create an instance of a `Cat`, we cannot create an instance of an `Animal`.

```c++
// Animal.cpp
#include "Animal.h"

Animal::Animal(float initial_hunger){
    this->hunger = initial_hunger;
}

float Animal::GetHunger(){
    return this->hunger;
}

void Animal::Eat(float sustenance){
    this->hunger += sustenance;
}


```

> While the dot operator (`.`) simply accesses a data member, using the arrow operator (`->`) access them via a pointer ([read more](https://www.tutorialspoint.com/cplusplus/cpp_member_operators.htm)).

```c++
// Cat.h
#include "Animal.h"

class Cat : public Animal{
    public:
        Cat(float initial_hunger) : Animal(initial_hunger){};
        void Speak() { std::cout << "Meow!" << std::endl; }
};
```

```c++
// Dog.h
#include "Animal.h"

class Dog : public Animal{
    public:
        Dog(float initial_hunger) : Animal(initial_hunger){};
        void Speak() { std::cout << "Woof!" << std::endl; }
};
```

```c++
// main.cpp
#include "Cat.h"
#include "Dog.h"

int main(){
    Cat cat1(50);	// object constructed during compile-time
    Dog* dog1 = new Dog(40);	// object constructed during run-time. 'dog1' is a pointer.

    std::cout << "Cat hunger: " << cat1.GetHunger() << std::endl;
    // Note the '->' operator. This is used as a shortcut to de-reference a pointer & access the object.
    // The long-form version would be '(*dog1).GetHunger()' and yes, that set of '()' is required.
    std::cout << "Dog hunger: " << dog1->GetHunger() << std::endl;

    cat1.Eat(10);
    dog1->Eat(40);

    std::cout << "Cat hunger: " << cat1.GetHunger() << std::endl;
    std::cout << "Dog hunger: " << dog1->GetHunger() << std::endl;

    cat1.Speak();
    dog1->Speak();
}
```

### Encapsulation

Also known as "data hiding", this is the principle that each Object keeps its state (content of memory) private (no one else can read it). Every field, method, and function in a class is given an encapsulation type of **Private, Protected, or Public**.

- Private
  - Can **only** be accessed by that object.
- Protected
  - Can **only** be access that that object **and** any object created from a subclass of that object.
- Public
  - Can be accessed by anything and everything in that program.

### Abstraction

This is a tool in modeling higher-level mechanisms. In practice, this is used to code shared features that are implemented differently. 

In the above code, `Animal` is an Abstract class (the 'pure virtual' designation of `virtual void Speak() = 0;` makes this so ([read more](https://www.geeksforgeeks.org/virtual-function-cpp/)).) If we tried to instantiate it, we would get an error. This makes sense model-wise, as there is no such thing as an "Animal". An animal is a higher-level classification for specific species. However, `Cat` and `Dog` are specific animals that we want to be able to create. Setting up our program like this allows us to only have to program changes we wish to make to multiple classes **once**. So if we wanted to start tracking age, placing it in Animal (then modifying the Cat/Dog constructors) is much more preferable than coding the same feature twice. While this seems overkill for this example, remember that this is **scalable**! I can now model any number of types of animals, that all have the same variables/functions, very quickly without copy/pasting a ton of times!

### Inheritance

This principle allows us to "re-use" code by deriving multiple classes from a base class. In the example we just gave, `Animal` is the base class while `Dog` and `Cat` are the derived classes.

### Polymorphism

This principle allows an object to be treated as a different type so long as it falls within the correct inheritance hierarchy. As an example, in the code we just reviewed we have an "is-a" relationship between Animal and Dog (A Dog is-a Animal.) This allows any Dog object to be stored as a Dog (`Dog myDog(50);`) or as an Animal pointer (`Animal* animal_ptr = new Dog(50);`).

## Part 6. Debugging

The hardest part of programming is figuring out where you went wrong. There are a few techniques we can use to narrow in on our mistakes:

1. Rubber-duck debugging
   - Often we just need to methodically work through the code. Unfortunately, we tend to make assumptions while reviewing code that we wrote. In an effort to prevent glossing over key portions, the goal of this type of debugging is to explain the code to someone as if they had never seen it before. Since it can be difficult to find someone to speak to every time you get stuck (hint: a lot) it is helpful to substitute in a rubber duck. Yes, the generic kind you find in/around bath tubs. Here is a bit more reading on the subject (I recommend giving this a quick read!) https://www.thoughtfulcode.com/rubber-duck-debugging-psychology/
2. Print Statements
   - Sometimes we just need to output everything our program is doing to track down the issue. This is *very* primitive, and does not scale well. But in an isolated environment is a quick and dirty way to discover where a calculation is going wrong. Bonus tip: Read input from the keyboard to "pause" your program and step through it slowly!
3. Use a real debugger
   - This is the proper way to perform technique #2. Set breakpoints accordingly, compile your code, run it through a debugger, and use the tools given to you to explore the values in all of the variables, check scope, trace the program control, etc. This process will differ based on the IDE you are using, lookup tutorials and reach out to staff for help.

## Part 7. Exercise

Use what you learned in this lab to complete the following exercises:

1. Copy the above sample code into the appropriate files in your IDE (e.g. create `Animal.h` and copy the code given above commented `Animal.h`)
2. Add in three more types of Animals to the given sample code: Bird, Hamster, Snake. Ensure your code compiles & runs correctly with 1 object of each type, similar to how Cat and Dog are created (in main).
3. Add a feature to Animal that makes sense. Justify your decision, and make sure all 5 classes still compile & run just fine.
4. Add command line arguments to facilitate the following: number_of_animals, {constructor values for each animal to be created}
  - number_of_animals will control a loop that prompts the user for what type of animal they wish to be created (you should have 5 types).
  - The values will be stored in `argv` and used when you create each Animal.

  An example:

   ```
   g++ main.cpp Animal.cpp -o prog && ./prog 4 30 40 50 60
   ```

   This should prompt the user four times for an animal type. If the user enters:

   ```
   Dog
   Cat
   Bird
   Snake
   ```

   then your program should populate an array of Animals that looks like this:

   ```
   | Dog: hunger = 30 | Cat: hunger = 40 | Bird: hunger = 50 | Snake: hunger = 60 |
   ```

4. Create a simple loop to output each animal speaking & its hunger value to show that it works properly. Ex:

   ```
   Woof!
   30
   Meow!
   40
   Chirp!
   50
   Hiss!
   60
   ```

   Notes: 
   
   - `Animal**` is how you will create the array to store the animals in step 3. i.e. `Animal** arr = new Animal*[5];` would create an array that stores 5 animal pointers. Use the `new` keyword to instantiate each animal during run-time!

## Requirements

1. 3 additional classes added & program compiles & runs.
2. Feature added to the `Animal` class then properly propagated to child classes.
3. Properly converted all command-line arguments to the appropriate type.
4. Loop the correct # of times based on the given argument.
5. Correctly instantiate the user-requested objects.
