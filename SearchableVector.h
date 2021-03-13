#pragma once
#include "SimpleVector.h"

// Have to include template structure
// Inheritance will take our vector class and expand it
// Lab 3: 2. Modify SearchVector class template so it performs binary search instead of linear search
template <class T>
class SearchVector : public SimpleVector<T> // Here to define to say that were inheriting from template class
{
	// No additonal variables to define
public:
	SearchVector(int s) : SimpleVector<T>(s) { } // Constructor; Once call search vector going to call simple vector that takes in simple vector in SimpleVecotr Header in Class SimpleVector
	SearchVector(SearchVector& obj) : SimpleVector<T>(obj) { } // Copy Constructor
	SearchVector(SimpleVector<T>& obj) : SimpleVector<T>(obj) { } // Want to do with this is going to tab in base class of copy constructor, produces search vector
	int findItem(T); // Searches for item; returns the subscript
};

// Copy Constructor
//template<class T>
// Taking one of the copy constructor and defining outside the class
//SearchVector<T> :: SearchVector(SearchVector& obj): SimpleVector<T>(obj){ } 

// Looks for an item and returns subscript of where its located
// Lab 3: 2. Modify SearchVector class template so it performs binary search instead of linear search
template <class T>
int SearchVector<T>::findItem(T item)
{
	// Implementing simple version search, known as linear search brute force, going thru every single item and comparing 
	for (int i = 0; i < this->size(); i++)// Should have access to size because inheriting from base class
	{
		// can't go thru aptr directly because aptr is private
		// Wants to call operator[] (int sub) on overloaded function
		if (this->operator[](i) == item) // Will go thru every item in the array vs. "item'
		{
			return i;

		}

	}
	return -1; // Indicates if item hasn't been found
}
