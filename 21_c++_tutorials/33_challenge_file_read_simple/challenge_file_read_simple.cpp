/*
File name: challenge_file_read_simple.cpp
Date: 16 Jan 2017
Author: Andrew Roberts
*/


#include <iostream>
#include <fstream> // reading, writing and creating files

#include <stdlib.h> // exit

using namespace std;

double column_1 = 0.0;
double column_2 = 0.0;
double column_1_total = 0.0;
double column_2_total = 0.0;
int count = 0;

int error_signal=666;

int main()
{
	ifstream inputfile;
	try
	{
		inputfile.open("numbers.txt", ios::in);
		if(inputfile.fail())
		{
			throw error_signal;
		}
	}
	catch(int error_number)
	{
		if(error_number==error_signal)
		{
			cout << "File reading error." << endl;
			exit(1);
		}
	}

	while(!inputfile.eof())
	{
		inputfile >> column_1;
		column_1_total += column_1;
		inputfile >> column_2;
		column_2_total += column_2;
		count++;
	}

	cout << "Average of column 1: " << column_1_total/count << endl;
	cout << "Average of column 2: " << column_2_total/count << endl;

}
