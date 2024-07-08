// InsertionSort Algorithm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Inst

#include <iostream>
using namespace std;

class Sort {
    friend void GrabInsertionSort(Sort *ptrobj, int array[], int ArraySize); //friend function (has access to all members of the class, regardless of access specifier. 
public:
    Sort(int first = 1, int second = 2, int third = 3) { //inline non-default constructor 
        i = first;
        j = second;
        temp = third;
    }
private:
    void InsertionSort(int array[], int ArraySize); //not inline function
    int i, j, temp;
};

void Sort::InsertionSort(int array[], int ArraySize) { //define the private method
    for (i = 1; i < ArraySize; i++) {
        j = i; //after we check through the for loop, j will always be in sync with i
        //swap array[j] and array[j-1] when needed to
        while (j > 0 and array[j - 1] > array[j]) {
            //swap the values of the two index's with the help of the temp variable
            temp = array[j];
            array[j] = array[j - 1];
            array[j - 1] = temp;
            j--; 
            //similar to bubble sort in the sense that it will look at the adjacent element, however it DOES NOT continue to do so. Instead it will only do so if the while loop condition is met. It will continue to work and check the adjacent elements on the left instead of the right.
        }
    }
}

void GrabInsertionSort(Sort *ptrobj, int array[], int ArraySize) {
    ptrobj->InsertionSort(array, ArraySize);
}

int main()
{
    int userarray[5] = { 5, 4, 3, 2, 1 };
    Sort *ptrclassobj = new Sort; //must be a default constructor or default value constructor for this to work
    GrabInsertionSort(ptrclassobj, userarray, 5);
    delete ptrclassobj;

    

    
}
