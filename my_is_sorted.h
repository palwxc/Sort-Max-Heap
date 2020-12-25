//Programmer: Phillip LaFrance	//Student ID: 12398940
//Intructor: Patrick Taylor		//Section: A		//Date: 04/11/2018
//File: my_is_sorted.h  	    //Description: Defines my_is_sorted for checking if array is sorted from greatest to least

#ifndef MY_IS_SORTED_H_INCLUDED
#define MY_IS_SORTED_H_INCLUDED

//http://en.cppreference.com/w/cpp/algorithm/is_sorted
//is_sorted should take the same two parameters, and return a bool, true if the array is sorted, and false if not.

template <typename E>
bool my_is_sorted(E arr[], int num)
{
    if(num==0 || num==1)
        return true;
    for (int i=0; i<num-1; i++)
        if(arr[i]<arr[i+1])
            return false;
    return true;
}

#endif // MY_IS_SORTED_H_INCLUDED
