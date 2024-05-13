
#include <iostream>
using namespace std;

int LinearSearch(int array[], int size, int key) {
    bool conditonal;
    //synatx to find size of array, the number of elements
    for (int i = 0; i < size; i++) {
        if (key == array[i]) {
            return i; //should exit the function
            break;
        }
    }
    conditonal = false;

    if (conditonal == false) {
        return -1;
    }
}

int main()
{
    int numbers[5] = { 1,2,3,4,5 };
    cout << LinearSearch(numbers, 5, 49);
    cout << endl;
    cout << LinearSearch(numbers, 5, 3);

    return 0;
}