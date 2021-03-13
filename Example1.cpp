#include <iostream>
#include "SimpleVector.h"
using namespace std;


/*int main()
{
	// 1. Need to define a size
	const int SIZE = 10;

	// 2. Creating 2 vectors
	SimpleVector<int> intTable(SIZE);
	SimpleVector<double> doubleTable(SIZE);

	// 3. Populate info
	for (int i = 0; i < SIZE; i++)
	{
		intTable[i] = (i * 2); // Gets value from array then multiplies by 2
		doubleTable[i] = (i * 2.14);
	}

	// Prof made an error in lab 5
	// Create simple vector of int
	// Creating copy of Simple Vector object
	// Then will go thru printing 
	SimpleVector<int> iTable2(intTable);


	// 4. Display the values
	cout << "The values are in intTable: " << endl;
	intTable.print();

	cout << "The values are in intTable2: " << endl;
	iTable2.print(); // Will get error, takes to copy constuctor on SimpleVector header
	// Hasn't defined the function to overload the square bracket, doesn't know how to resolve right side of copy constructor on SimpleVector

	cout << "The values are in doubleTable: " << endl;
	doubleTable.print();

	// Can set values out of the bounds
	iTable2[10] = 20; // Should come back as ERROR: Subscript is out of range, cause array size is 10, but its over the range so why error message

	return 0;
}*/
