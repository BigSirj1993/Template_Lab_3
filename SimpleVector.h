#pragma once


#include <iostream>
#include <cstdlib>
using namespace std;

// Creating class template and then inheritate from SimpleVector
// If Having trouble, can created non templated versions

// Assumption: We are creating a vector of ints

//Non Templated Version
/*class SimpleVector
{

private: // Need an array, needs to be dynamically allocated
	int* aptr; // Need a pointer to integer; points to base or element 0
	int arraySize; // Need an array size
	void subError() const; // Error message generates when access array out of bounds

public:
	SimpleVector(int); // Constructor that takes in a size
	SimpleVector(const SimpleVector&); // Copy constructor
	~SimpleVector(); // Destructor
	int size() const // Best to use 'int size' instead of getArraySize
	{
		return arraySize; // Returns the array size
	}
	int& operator[](int); // Returning a reference of int after reading value from array
	void print() const; // Include print function to print out enemy stats


};*/

// Templated Version
// Can now use generic items
// Lab 3: 1. Add a push_back and pop_back function
// push_back should accept argument and insert value at end of array. Display message if array is full
// pop_back should accept no arguments and remove last element from array
template<class T>
class SimpleVector
{

private: // 
	T* aptr; // Array of something
	int arraySize; // Need an array size, doesn't change to T
	void subError() const; // Error message generates when access array out of bounds, doesn't change
	
public:
	SimpleVector(int); // Constructor that takes in a size
	SimpleVector(const SimpleVector&); // Copy constructor, taking an instance of SimpleVector
	~SimpleVector(); // Destructor
	int size() const // Best to use 'int size' instead of getArraySize
	{
		return arraySize; // Returns the array size
	}
	T getElementAt(int position); // Accessor to return a specific element
	T& operator[](int); // Returning a reference of int (Now T) after reading value from array
	void print() const; // Include print function to print out enemy stats for example
	void push_back(int);
	void pop_back();
};

// Now going to implement functions from the templated class
// Constructor. Sets the size of array and allocates memory for it.
template <class T> // Need to include Template function
SimpleVector<T> ::SimpleVector(int s) // Name Of class with a generic type, need to inlcude when defining functions
{
	arraySize = s; // Setting the array size
	aptr = new T[s]; // Dynamically Allocating pointer of array, provide size of array 's'
	for (int i = 0; i < arraySize; i++)  // This is new, trick. Want to initialize array to default value
	{
		aptr[i] = T(); // Assuming that the datatype being used has a default constructor. Results in value of zero in parameters. But don't put = 0.
	}

}

// Copy Constructor
// When working with data types, create several versions of constructors, including ones that take multiple parameters
// Example: Similar Enemies and Similar Weapons, or Similar Items
template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector& obj) // Have to make both of them equal
{
	// Copy array size
	arraySize = obj.arraySize;
	
	// Do NOT Do: aptr = obj.aptr; Why?: gets 2 pointters from same location and then changes what's there

	// Instead do this:
	aptr = new T[arraySize];
	for (int i = 0; i < arraySize; i++)
	{
		aptr[i] = obj.aptr[i]; // Eventually overriding square bracket operator
	}	// Left side can't change, but want to change right side by reducing a few characters or aptr.
	// Which can lead to simplification of for loop

	//SimpleVector s;
	// s[0] = 10;
}


// Destructor
template<class T>
SimpleVector<T>::~SimpleVector()
{ // Deallocate the memory
	if (arraySize > 0) // Make sure the arraySize is greater than zero or else will delete memory if less than zero
	{
		delete[] aptr; // Deletes memory that pointer is pointing to
	}
}

// The SubScript Error Function
// Will desplay error message and destroys program when subscript is out of range of array size.
// Will learn execption handling.

template <class T>
void SimpleVector<T> ::subError() const
{
	cout << "ERROR: Subscript out of range. " << endl;
	exit(0);
}

// Here is where i'm having errors
// Need to add getElementAt function so can return the value stored at the subscript
// in the array
/*template<class T>
T SimpleVector<T> ::getElementAt(int sub)
{
	if (sub < || sub >= arraySize)
	{
		subError();
	}
	return aptr[sub];
}*/

// Need to create push_back function base class for SimpleVector
// 1a. Implenting a push back function
template<class T>
void SimpleVector<T> ::push_back(int newValue)
{
	// Need to allocate memory for array in the temporary array.
	T* tmpArray = new T[arraySize + 1];

	// Copy Elements of old array
	for (int i = 0; i < arraySize; i++)
	{
		*(tmpArray + i) = *(aptr + i);
	}

	// Need push new value
	*(tmpArray + arraySize) = newValue;

	// Delete Old Array
	delete[] aptr;

	// Copy Array
	aptr = tmpArray;

	// Increase size of array
	arraySize++;


	/*arraySize = obj.arraySize + 1;

	// Allocate memory for array
	aptr = new T[arraySize];
	if (aptr == 0)
		subError();

	//Then copy elements of obj array
	for (int i = 0; i < (arraySize - 1); i++)
	{
		*(aptr + i) = *(obj.aptr + i);
	}

	obj.aptr[(arraySize)] = newValue;*/
}

// Trying to erase the last element from the array
template <class T>
void SimpleVector<T> ::pop_back()
{
	
	
	
	
	//if (!empty()) // If the array is NOT empty
	//{
		//delete arr[arraySize - 1]; // Should deallocate array memory by 1
		//arraySize--; // Should decrement by 1
	//}

}

// Overloaded [] operator. 
// Takes in subscript value and returns element from the array
template <class T>
T& SimpleVector<T>::operator[](int sub) // Sub = SubError
{
	if (sub < 0 || sub >= arraySize)
	{
		//Out of bounds
		subError();
	}
	// If have legit sub value
	return aptr[sub]; // Returns pointers and passes in sub
}


// Print all entries in the array
template<class T>
void SimpleVector<T>::print() const
{
	for (int i = 0; i < arraySize; i++)
	{
		cout << aptr[i] << "  " << endl;
	}

	cout << endl;
}
