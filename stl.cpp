/*An STL is a library of generic functions and classes which saves you time and 
energy which you would have spent constructing for your use. 
This helps you reuse these well tested classes and functions umpteenth number of times
 according to your own convenience. 
To put this simply, STL is used because it is not a good idea to reinvent something which
 is already built and can be used to innovate things further. 
 Suppose you go to a company who builds cars, they will not ask you to start from scratch, 
 but to start from where it is left. This is the basic idea behind using STL.
COMPONENTS OF STL:
We have three components in STL:
    Containers
    Algorithm
    Iterators
Let’s deal with them individually;
Containers:
Container is an object which stores data. We have different containers having their own benefits.
 These are the implemented template classes for our use, which can be used just by including this library.
  You can even customise these template classes.
  Containers are themselves of three types: 

    Sequence Containers
    Associative Containers
    Derived Containers

Algorithms:
Algorithms are a set of instructions which manipulates the input data to arrive at some desired result. 
In STL, we have already written algorithms, for example, to sort some data structure,
 or search some element in an array. These algorithms use template functions. 
Iterators:
Iterators are objects which refer to an element in a container. 
And we handle them very much similarly to a pointer.
 Their basic job is to connect algorithms to the container and
 play a vital role in manipulation of the data. 
I’ll give you a quick illustration of how they work combinedly.
Figure 1: Illustration of how these three components work together
Suppose we have a container of integers, and we want to sort them in ascending order.
 We will have pointers which will help moving elements to places by pointing to it, 
following a well-constructed algorithm. So, here a container gets sorted by following an 
algorithm by the use of pointers. This is how they work in accordance with each other.*/

/*
    Sequence Containers
A sequence container stores that data in a linear fashion. 
Refer to the illustration below to understand what storing something in a linear fashion means.
Figure 1: Elements stored in a linear fashion
Sequence containers include Vector, List, Dequeue etc. 
These are some of the most used sequence containers.
    Associative Containers
An associative container is designed in such a way that enhances the accessing of some element in that container.
 It is very much used when the user wants to fastly reach some element. 
 Some of these containers are, Set, Multiset, Map, Multimap etc.  
 They store their data in a tree-like structure.
    Derived Containers 
 As the name suggests, these containers are derived from either the sequence or
  the associative containers. They often provide you with some better methods to deal with your data. 
  They deal with real life modelling. Some examples of derived containers are Stack, Queue, Priority Queue, etc. 
  The following illustration give you the idea of how a stack works.
Figure 3: A stack, works on the first in first out [FIFO] method
Now since we have got the basic idea of all the three types of containers,
 a question which might arise is when to use which.  So, let’s deal with that,
In sequence containers, we have Vectors, which has following properties:
    Faster random access to elements in comparison to array
    Slower insertion and deletion at some random position, except at the end.
    Faster insertion at the end.
In Lists, we have,
    Random accessing elements is too slow, because every element is traversed using pointers.
    Insertion and deletion at any position is relatively faster, because they only use pointers,
     which can easily be manipulated.
In associative containers, every operation except random access is faster in comparison to any other containers, 
be it inserting or deleting any element.
In associative containers, we cannot specifically tell which operation is faster or slower, 
we’ll have to inspect every data stucture*/

// VECTORS
//  we define the vector as 
vector<data_type> vector_name;

// Code Snippet 1: Syntax of declaring a vector
#include<iostream>
#include<vector>
 
int main(){
 
    vector<int> vec1;
    return 0;
}
// Code Snippet 2: Declaring a vector of integers
#include<iostream>
#include<vector>
using namespace std;
void display(vector<int> &v){
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
int main(){ 
    vector<int> vec1;
    int element, size;
    cout<<"Enter the size of your vector"<<endl;
    cin>>size;
    for (int i = 0; i < size; i++)
    {
        cout<<"Enter an element to add to this vector: ";
        cin>>element;
        vec1.push_back(element);
    }
    display(vec1);    
    return 0;
}
    // Insert (iterator, element to insert):
// This method of vectors inserts an element to the position the iterator is pointing to
vec1<int> :: iterator iter = vec1.begin();
// Code Snippet 5: Declaring a vector iterator
display(vec1);
    vector<int> :: iterator iter = vec1.begin();
    vec1.insert(iter,566);
    display(vec1);
    /*Similarly, v.at(i) can be used instead of v[i]. They will work the same.
We have different ways to declare a vector. I’ll list some of them through the snippet below.
    First one is a vector with no length and elements specified.
    Second one is a vector of length 4 and no elements.
    Third one is a vector made from the second one.
    And last one, is a vector with length 6 and all the elements being 3.
*/
    vector<int> vec1;      //zero length integer vector
    vector<char> vec2(4);  //4-element character vector
    vector<char> vec3(vec2);//4-element character vector from vec2
    vector<int> vec4(6,3); //6-element vector of 3s

    // LIST
/*A List is a bi-directional linear storage of elements. Few key features as to why a list should be used is, 

    It gives faster insertion and deletion operations.
    Its access to random elements is slow.
*/
#include<iostream>
#include<list>
void display(list<int> &l1){
    l1<int> :: iterator iter;
    for (iter = l1.begin();iter!= l1.end(); i++)
    {
        cout<<*it<<" ";
    }
}
int main(){
    list<int> l1;
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    l1.push_back(4);
    list<int> :: iterator iter;
    iter = l1.begin();
    // cout<<*iter;
    // iter++;
    // cout<<*iter;
    display(l1);
    l1.sort();
    l1.reverse();
    

}