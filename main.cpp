//Author: Kyle Smith
//Class: SENG 691Z
//Worksheet 1:Task2
//Test Driven Development

#include <iostream>
#include <array>
#include "main.h"
using namespace std;


//define functions
int quickSort(int arr[], int left, int right);
int binSearch(int arr[], int key, int min, int max);


//define variables
const int arrSize=10;
const int arrL2 = arrSize-2;
int kylesList[arrSize];
int arrL1= arrSize-1;
int searchKey;

void main()
{
	cout<<"Enter "<<arrSize<<" numbers to sort below."<<endl;
		
	int count = 0;
			
			//takes a list of numbers from user
			while(count < arrSize){
			
				cin>>kylesList[count];
				count++;
			
			};

			count = 0;
			//Prints list unordered
			while(count<arrL1){
			
				cout<<kylesList[count]<<" , ";
				count++;

			};
			cout<<kylesList[arrL1]<<endl;

	//sort array in ascending order
	quickSort(kylesList, 0, arrL1);

	cout<<"Enter a number from the sort to be found in a Binary search:"<<endl;
	cin>>searchKey;
	
	//Runs Binary search to find number is sorted list.
	binSearch(kylesList, searchKey, 0, arrL1);

}






