//Programmer: Phillip LaFrance	//Student ID: 12398940
//Intructor: Patrick Taylor		//Section: A		//Date: 04/11/2018
//File: my_sort.h			    //Description: Defines my_sort for sorting array from greatest to least

#ifndef MY_SORT_H_INCLUDED
#define MY_SORT_H_INCLUDED

//http://en.cppreference.com/w/cpp/algorithm/sort
//sort should take two parameters, a templated array, and an integer representing the size of the array.
//It should have void return type. The array that is passed should then be sorted by the function.
//The array should be sorted max-first.

template <typename E>
inline void swap(E& i, E& j){
    E temp = i;
    i = j;
    j = temp;
}

template <typename E>
void my_sort(E *A, int n)
{
    /*
    int pos;
    int start = 0;
    int last = n-1;

    // build the heap
    for(int i = n / 2 - 1; i >= 0; i--)
    {
        pos = i;

        while(pos < n / 2)
        {
            int j = 2 * pos + 1;

            if(((j + 1) < n) && (A[j] < A[j + 1]))
                j++;

            if(!(A[pos] < A[j]))
                break;

            swap(A[pos], A[j]);
            pos = j;
        }
    }
    cout << "\t";
    for(int k=0; k < 6; k++)
    {
        cout << A[k] << " ";
    }
    cout << endl;

    // remove and store in non-heap part of array
    for(n--; n > 0; n--)
    {
        swap(A[0], A[n]);
        pos = 0;

        while(pos < n / 2)
        {
            int j = 2 * pos + 1;

            if(((j + 1) < n) && (A[j] < A[j + 1]))
                j++;

            if(!(A[pos] < A[j]))
                break;

            swap(A[pos], A[j]);
            pos = j;
        }
    }
    cout << "\t";
    for(int k=0; k < 6; k++)
    {
        cout << A[k] << " ";
    }
    cout << endl;

    while (start < last)
    {
        swap(A[start], A[last]);
        start++;
        last--;
    }
*/
    int pos;

    // build the heap
    for(int i = n / 2 - 1; i >= 0; i--)
    {
        pos = i;

        while(pos < n / 2)
        {
            int j = 2 * pos + 1;

            if(((j + 1) < n) && (A[j] > A[j + 1]))//
                j++;

            if(A[pos] < A[j])//
                break;

            swap(A[pos], A[j]);
            pos = j;
        }
    }
    /*
    cout << "\t";
    for(int k=0; k < 6; k++)
    {
        cout << A[k] << " ";
    }
    cout << endl;
    */
    // remove and store in non-heap part of array
    for(n--; n > 0; n--)
    {
        swap(A[0], A[n]);
        pos = 0;

        while(pos < n / 2)
        {
            int j = 2 * pos + 1;

            if(((j + 1) < n) && (A[j] > A[j + 1]))//
                j++;

            if(A[pos] < A[j])
                break;

            swap(A[pos], A[j]);
            pos = j;
        }
    }

    /*
    cout << "\t";
    for(int k=0; k < 6; k++)
    {
        cout << A[k] << " ";
    }
    cout << endl;
    */
    //for (int q=0; q < arraySize/2; q++)
        //swap(A[q], A[arraySize-1]);
}

#endif // MY_SORT_H_INCLUDED
