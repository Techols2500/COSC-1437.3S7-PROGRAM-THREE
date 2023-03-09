//************************************************************************** 
//
// Programming Excerise 3   
// CLASS: COSC 1437.3S7 
// AUTHOR: TYLER ECHOLS 
// DATE: Jun 2017
//
//************************************************************************** 

#include <iostream>

using namespace std;

#include "Array.h"

void Func(const Array <int, 3, 50> &);
void Func2(const Array <int, 2, 80> &);

void main()
{
	try
	{

		Array <int, 3, 50> A1;
		Array <int, 2, 80> A2;


		char * pTemp;
		A1[4] = 55;
		A2[79] = 15;


		pTemp = new char[80];
		Func(A1);
		Func2(A2);
		delete[]pTemp;
	}

	catch (Array <int, 3, 50> ::ErrorCodes e)
	{
		switch (e)
		{
		case Array <int, 3, 50> ::ChangingValues:
			cout << "Error with Changing Values" << endl;
			break;
		case Array <int, 3, 50> ::DisplayingValues:
			cout << "Error with Showing Values" << endl;
			break;
		default:
			cout << "Something isn't right " << endl;
		}
	}
	catch (Array <int, 2, 80> ::ErrorCodes e)
	{
		switch (e)
		{
		case Array <int, 2, 80> ::ChangingValues:
			cout << "Error with Changing Values" << endl;
			break;
		case Array <int, 2, 80> ::DisplayingValues:
			cout << "Error with Showing Values" << endl;
			break;
		default:
			cout << "Something isn't right " << endl;
		}
	}
}



void Func(const Array <int, 3, 50> & A)
{
	cout << A[4] << endl;

}

void Func2(const Array <int, 2, 80> & A)
{
	cout << A[82] << endl;


}