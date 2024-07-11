// QuickSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
// This code will also incorporate a copy constructor

#include <iostream>
#include <vector> 
using namespace std;

//abstact class has a pure virtual function, no object created, and runtime polymorphsim can occur during run time 
class abstract { 
public:
    virtual void QuickSort(int array[], int i, int k)  = 0;
    virtual int partition(int array[], int i, int k)  = 0;
    int array[5];
    string *ptr_array; //dynamically allocated memory of an array of type string of 5 components 

};

class concrete : public abstract{
public:
    concrete(); //default consgtructor required to create a ptr to a class object 
    concrete(concrete *ptrobj); //copy constructor will execute deep copy. Note, all attributes must be  re-initailized here
    void QuickSort(int array[], int i, int k) override;
    int partition(int array[], int i, int k) override;
    ~concrete(); //destructor required

};

concrete::concrete() {
    cout << "Everytime you create an object (sending no parameters) typically the default constructor is called. " << endl;
}

concrete::concrete(concrete *ptrobj) {
    cout << "Copy constructor was called " << endl;
    ptr_array = new string[5];
    for (int i = 0; i < 5; i++) {
        ptr_array[i] = ptrobj->ptr_array[i];
        //the ptr_array for our class object (under this for loop) will slowly retrieve the same data of the pointer to the class object in the parameter
        //As usual, in order to access a attribute from a pointer to a class object, simply use the member access operator.
    }


}

void concrete::QuickSort(int array[], int i, int k) {
    int j;

    //base case: If there are one or zero elements to sort, the partition is not needed
    if (i >= k) {
        return; 
    }

    j = partition(array, i, k);

    //recursive case: Quicksort on the two sublists, eventually will be reduced to down to base case
    QuickSort(array, i, j);
    QuickSort(array, j+1, k);

    
}

int concrete::partition(int array[], int i, int k) {
    //regular int variables
    int l = i;
    int h = k;

    //int variables for determining pivot and swap
    int midpoint;
    int pivot;
    int temp;

    //bool variable for conditon 
    bool done = false;

    //the method in choosing the pivot element
    midpoint = i + (k - i) / 2;
    pivot = array[midpoint];

    //outer while loop
    while (!done) {

        //first inner while loop conditon, if true l++
        while (array[l] < pivot) {
            l++;
        }

        //second inner while loop conditon if true h--
        while (pivot < array[h]) {
            h--;
        }

        //if statement 
        if (l >= h) {
            done = true; //!true = false, thus causing the outewr while loop condition to be false
        }

        //swap elements in their index's
        else {
            temp = array[l];
            array[l] = array[h];
            array[h] = temp;
        }

    }
    return h;
    


}

concrete:: ~concrete() {
    delete ptr_array; //dynamically allocated attributes should be deallocated in the destructor
    cout << "A class object has been deallocated from the memory " << endl; 
}

int main()
{
    vector<concrete*>list; //created a an array of pointers to a class object

    concrete *ptr_one = new concrete; //dynamically allocated memory of a class object type concrete 
    concrete *ptr_two = new concrete; //dynamically allocated memeory of a class object type concrete

    for (int i = 0; i < 5; i++) {
        int userinput;
        cout << "Enter a number in index ";
        cout << i;
        cout << " in to the array: ";
        ptr_one->array[i] >> userinput; //derived class object conversion to a bass class object, this occurs when you create a pointer to a derived class object (regardless if dynamic is true or not) 
        cout << endl;
    }
                        //access the attribute array from base class, data should remain the same
    ptr_one->QuickSort(ptr_one->array, 0, 5);

    for (int i = 0; i < 5; i++) {
        int userinput;
        cout << "Enter a number in index ";
        cout << i;
        cout << " in to the array: ";
        ptr_two->array[i] >> userinput;
        cout << endl;
    }

    ptr_two->QuickSort(ptr_two->array, 0, 5);

    //ptr_two = ptr_one; //this is a shawllow copy, now both pointer's share the same memory address and the contents stored at the memory address. Deallocating or deleting one pointer can cause a memory leak as the other pointer will no longer be accessible
    //let us create a deep copy instead! The example below uses deep copy on the int arra

    for (int i = 0; i < 5; i++) {
        ptr_two->array[i] = ptr_one->array[i];
    }
   

    //store the pointer's to the class object to the array 
    list.push_back(ptr_one);
    list.push_back(ptr_two);

    //call the copy constructor on third pointer to the class object
    concrete nonptr_three = ptr_one; //notice how it's a nonptr


    for (int i = 0; i < list.size(); i++) {
        delete list[i]; //deallocating a dynamically allocated memory of a class object will call the destructor via deleting the pointer storing said memory address 
        //Because were not dealing with automatic or static storage we must do this explicitly!
    }
    
}

