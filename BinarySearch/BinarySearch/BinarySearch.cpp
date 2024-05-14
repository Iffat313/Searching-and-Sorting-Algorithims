// BinarySearch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

//in a binary search algorihtim, we assume that the list passed into the parameter is already sorted.

int BinarySearch(int numbers[], int key, int size) {

    int low = 0;
    int high = size - 1;

    while (high >= low) {
        
        int mid = (low + high) / 2;

        if (numbers[mid] > key) {
        
            high = mid - 1;
            //this means that the element in the middle was greateer than our key, therefore it only makes sense that the possible key is on the left or before the middle element. As a result, in our second iteration, we must reconsider the formula of mid
            //as we know the key can no longer be be after and including what the element "mid" originally was.
        }

        else if (numbers[mid] < key) {
        
            low = mid + 1;
            //this means that key can only possibly be in the array after the middle element till the end of the list. Therefore, in our future iteration, this means that the middle element must be determined where the value of low changes. As stated in the code above
            //perferably mid + 1;
        }

        else  if(numbers[mid]==key){
        
            return mid;
            
        }

        else {
            
            return -1;
        
        }
    
    
    }

}

int main()
{
    int list[5] = { 1,2,3,4,5 };

   cout <<  BinarySearch(list, 4, 5);
}

