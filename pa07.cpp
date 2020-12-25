//Programmer: Phillip LaFrance	//Student ID: 12398940
//Intructor: Patrick Taylor		//Section: A		//Date: 04/11/2018
//File: pa07.cpp			    //Description: Tests MyHeap as a priority queue

#include <iostream>
#include "MyHeap.h"
#include "my_sort.h"
#include "my_is_sorted.h"
using std::cout;
using std::endl;

int main()
{
    // Heap
    MyHeap<int> q;

    cout << "size: " << q.size() << endl;

    for(int k = 0; k < 10; k++)
        q.push(k);

    cout << "size: " << q.size() << endl;

    cout << "PRINT" << endl;
    while(!q.empty())
    {
        cout << q.top() << " ";
        q.pop();
    }
    cout << endl;

    int my_array[6] = {4, 6, 9, 12, 124, 4};
    MyHeap<int> q2(my_array, 6);    // parameterized constructor

    MyHeap<int> q3(q2);             // copy constructor

    q3.push(77);

    MyHeap<int> q4 = q2;            // copy constructor

    cout << "PRINT q2" << endl;
    while(!q2.empty())
    {
        cout << q2.top() << " ";
        q2.pop();
    }
    cout << endl;

    cout << "PRINT q3" << endl;
    while(!q3.empty())
    {
        cout << q3.top() << " ";
        q3.pop();
    }
    cout << endl;

    cout << "PRINT q4" << endl;
    while(!q4.empty())
    {
        cout << q4.top() << " ";
        q4.pop();
    }
    cout << endl;

    cout << q4.top() << " ";
    q4.pop();
    cout << q4.top() << " ";
    q4.pop();
    cout << q4.top() << " ";
    q4.pop();
    cout << endl;

    MyHeap<int> q5;                 // default constructor
/*
    q5 = q4;                        // operator=

    while(!q4.empty())
    {
        cout << q4.top() << endl;
        q4.pop();
    }
*/
    /**
    // Sort
    int my_array2[6] = {4, 6, 9, 12, 124, 5};
    cout << my_is_sorted(my_array2, 6) << endl;
    my_sort(my_array2, 6);
    cout << my_is_sorted(my_array2, 6) << endl;

    for(int k=0; k < 6; k++)
    {
        cout << my_array2[k] << " ";
    }
    cout << endl << endl;
**/
    // Sort
    int my_array3[10] = {10,9,8,7,6,5,4,3,2,1};
    cout << my_is_sorted(my_array3, 10) << endl;
    my_sort(my_array3, 10);
    cout << my_is_sorted(my_array3, 10) << endl;

    for(int k=0; k < 10; k++)
    {
        cout << my_array3[k] << " ";
    }
    cout << endl << endl;


    int my_array9[9] = {4, 6, 9, 12, 124, 4, 57, 651, 632};
    MyHeap<int> q0(my_array9, 9);
    cout << "PRINT q3" << endl;
    while(!q0.empty())
    {
        cout << q0.top() << " ";
        q0.pop();
    }
    cout << endl;

    return 0;
}

