Part 1
======

> 1. Given an array,
>   1. find the longest continuous increasing subsequence.
>   2. find the longest increasing subsequence.
> 2. Given two linked lists, return the intersection of the two lists: i.e. return a list containing only the elements that occur in both of the input lists.

Firstly I created two classes: Array and List (in `Array.h` and `List.h`).  
The Array class allow to create, copy and display the array.  
The List class represent a linked list. There is a function sort, that sort the list with the merge sort algorithm.

To compile, there is a `Makefile`, just type `make` to compile and `make run` to run the examples.  
Note that C++11 is required.

Intersection
------------

To return the intersection of two linked lists, the two lists are firstly sorted with the merge sort algorithm,
then the values of the two lists are compared.  

You can see my function and some examples in `intersection.cpp`.

Longest Continuous Increasing Subsequence
-----------------------------------------

To find the longest continuous increasing subsequence, there is 4 variables: the `max_start` and `max_length` store the 
start index and the length of the longest subsequence encountered for now, the `start` and `length` variables store the 
start index and the length of the current subsequence. At the the end of the subsequence, `max_length` is compared with 
`length`. If the length is superior to max_length, we store the start value in max_start and the length value in 
max_length.  

You can see the function and some examples in `increasing_subsequence.cpp`.

Longest Increasing Subsequence
------------------------------

- L represent the size of the longest increasing subsequence found yet
- The array P store the different indexes of the previous element in a subsequence.
- The array M store the indexes of the end of the different subsequences found.

The algorithm iterate the array. Firstly, it will find the biggest element inferior to the current value in the part of the
array that is already iterate (the predecessor of the current element), with binary search. Then, it will store the index  
of the predecessor in the array P.  
If the `newL` variable is superior to the size of the longest  
subsequence found so far, it will store this index in M and change the value of `L`.
If the value is inferior than the value of the last item of the increasing subsequence of the same size, it will store this
value in M.

After that, we just need to construct the array of the longest increasing subsequence with the two arrays.

Part 2
======

To organize the project, I used npm and bower for dependencies and grunt for the differents tasks.  
To run the project, you need to install dependencies and then run a grunt task.

```bash
bower install && npm install
grunt serve
```

You need to install some dependencies, `sass` and `compass`, `bower` and `grunt-cli`

```
gem install compass
npm install -g bower
npm install -g grunt-cli
```

To do this task, I used the public feed of Flickr, that doesn't require an API key. I made a factory, Flickr, that have a 
function: `search` which make a `$http` request with the query as a parameter for `tags`.  
When an change occure in the input, the function search is called in the controller. This function take the query of the  
input and send it to the Factory. After that, ng-reapeat is used to display the images.
