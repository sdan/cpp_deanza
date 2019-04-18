/*
Surya Dantuluri
CIS 22B
Spring 2019
Assignment A
Problem A1
Gets array of heap size requested by user, stores strings within that array, prints
strings stored in the array, then frees all the space back to heap
*/
#import <iostream>
#import <string>
using namespace std;
void getSize(int *size);
void getSpace(int size, string *&arr);
void inputData(int size, string *&arr);
void printData(int size, string *&arr);
void destroy(string*&arr);



int main()
{
	int size = 0;
	string *arr = NULL;

	getSize(&size);
	getSpace(size,arr);
	inputData(size,arr);
	printData(size,arr);
	destroy(arr);

	return 0;

}

/* ******************** getSize ******************** 
Asks user for size 
Size saved in calling function via reference parameter 
*/
void getSize(int *size)
{
	cout << "\nEnter the number of strings you want : ";
	cin >> *size;
}

/* ******************** getSpace ******************** 
Gets an array in the heap of the size requested by the user
Uses array by reference to intialize it
*/
void getSpace(int size, string*& arr)
{
	arr = new string[size];
}

/* ******************** inputData ******************** 
Allows the user to input the strings and stores them in the array
using its reference parameter
*/
void inputData(int size, string*& arr)
{
	cout << "\nEnter the strings:\n";
	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}
}

/* ******************** printData ******************** 
Prints all the strings, one string per line
using array's reference parameter
*/
void printData(int size, string*& arr)

{
	cout <<"\nThe strings are:\n";
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "\n";
	}
}

/* ******************** destroy ******************** 
Returns space used by array back to heap, essentially destroying the array
by deleting the space it refers to by the reference parameter
*/
void destroy(string *&arr)
{
	delete[] arr;
	cout << "\nReturned all space to heap" << "\n";
}

/* Execution results 

Enter the number of strings you want : 3

Enter the strings:
Surya is cool

The strings are:
Surya
is
cool

Returned all space to heap

*/




