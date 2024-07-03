// BubbleSort Algorithim.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

//bubble sort function should take a parameter of two, were doing this in the prespective of a vector and size reps the total number of elements in the vector, no were not doing 
//reminder, purpose of a sorting algorithim is to place elements in increasing order: 55, 56, 78.....
void BubbleSort(vector<int>passed, int size) {

	//takes three int variables
	int temp;
	int iteration;
	int index;

	//takes one outer for loop and one inner for loop, note that the inner for loop resets everytime the conditional statement turns false. In the grand scheme of things, the inner for loop will continue until the outer loop conditonal statement is false

	for (iteration = 1; iteration < size; iteration++) { //once iteration == size, the for loop will recognize that the conditional statement is false and will not continue.

		for (index = 0; index < size - iteration; index++) { //once index == size - iteration the inner for loop will recognize that the condtional statement is false and will go back to the outer loop

			if (passed[index] > passed[index + 1]) {

				//when swapping the value of two variables we need a temp variable, the same thing applies for two different indexes of an array 
				temp = passed[index];
				passed[index] = passed[index + 1];
				passed[index + 1] = temp;
			}
		
		}
		
	}

}

int main()
{
	//ask the user to input numbers into an array 
	vector<int>user;
	int nums;
	int data;
	cout << "Enter the number of elements for the vector: ";
	cin >> nums;
	for (int i = 0; i < nums; i++) {
		cout << "Enter number ";
		cout << i;
		cout << ": ";
		cin >> data;
		user[i] = data;
	}
	BubbleSort(user, nums);

	//let's call the function to sort the bubble sort

}


