// GAME 2001 - Assignment 1
// Submitted by Shane Holloway - 101273911

#include <iostream>
#include "Array.h"
#include "UnorderedArray.h"
#include "OrderedArray.h"

using namespace std;

// I definitely messed up with my class setups somewhere along the way, but I got the program working
// as outlined in the assignment using these methods. If possible, after grading these assignments would
// you be able to put out a solution video? I'm still not super comfortable with template classes inheriting
// from other template classes.

int main()
{
	// Unordered array testing
	UnorderedArray<int> intArray(3, 2);
	intArray.push(17);
	intArray.push(12);
	intArray.push(38);
	
	// This should cause the array to expand in size as it is already at the capacity of 3
	intArray.push(42);
	// Pushing identical values into the array is fine as it is unordered
	intArray.push(42);
	intArray.push(42);
	intArray.push(42);
	intArray.push(56);
	intArray.push(42);
	intArray.push(93);
	intArray.push(42);
	intArray.push(69);

	// Test searching. One will work the other will return nothing
	intArray.search(69);
	intArray.search(8675309);

	// Test pop and remove functions. Pop will work but remove is out of bounds
	intArray.GetArrayPTR()->pop();
	intArray.remove(55);

	// Output array contents to show it is not ordered
	for (int i = 0; i < intArray.GetArrayPTR()->GetSize(); i++)
	{
		std::cout << "Value at index " << i + 1 << ": " << intArray[i] << endl;
	}

	// Test clear function
	intArray.GetArrayPTR()->clear();

	// Push value into the start of the array as array was cleared, and retrieve it
	intArray.push(5);
	intArray.search(5);

	

	cout << endl << endl;
	
	// Ordered array testing
	OrderedArray<float> floatArrayO(1, 3);
	floatArrayO.push(25.0f);
	floatArrayO.push(28.0f);
	floatArrayO.push(14.2f);
	cout << "Current size of ordered array: " << floatArrayO.GetArrayPTR()->GetSize() << endl;
	// Will not insert this value as it is already in the array
	floatArrayO.push(25.0f);
	cout << "Current size of ordered array: " << floatArrayO.GetArrayPTR()->GetSize() << endl;
	floatArrayO.push(185.8f);
	floatArrayO.push(185.8f);

	// Test search function
	floatArrayO.search(14.2f);
	floatArrayO.search(188.5f);

	// Output array contents to show it is ordered
	for (int i = 0; i < floatArrayO.GetArrayPTR()->GetSize(); i++)
	{
		std::cout << "Value at index " << i + 1 << ": " << floatArrayO[i] << endl;
	}
	
	return 0;
}