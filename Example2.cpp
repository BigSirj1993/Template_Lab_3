#include <iostream>
#include "SearchableVector.h"
#include "SimpleVector.h"
#include "SortVector.h"
using namespace std;

//SimpleVector Holds Numbers
//SearchVector can look for something

int main()
{
	const int SIZE = 10; // Defining array size, will call SearchVector in SearchVector.h base class
	int amtToPrint = 10;
	//iTable.push_back(10);
	int i; // This is supposed to be the loop counter


	// Defining the 2 vectors
	SearchVector<int> iTable(SIZE);
	SearchVector<double> dTable(SIZE);

	


	for (int i = 0; i < SIZE; i++)
	{
		iTable[i] = (i * 2);
		dTable[i] = (i * 2.14);
	}

	// Displaying values in the SimpleVectors
	cout << "The values in iTable are: " << endl;
	//iTable.print();
	for (i = 0; i < amtToPrint; i++)
		cout << iTable[i] << "  " << endl;

	cout << "The values in dTable are: " << endl;
	//dTable.print();
	for (i = 0; i < amtToPrint; i++)
		cout << dTable[i] << "  " << endl;

	// Searching the Vectors
	int result {};
	cout << "Searching for the number 22 in iTable. " << endl;
	if (result == -1)
	{
		cout << "22 was not found. " << endl;
	}
	else 
	{
		cout << "22 was found in subscript " << result << endl;
	}

	return 0;
}
