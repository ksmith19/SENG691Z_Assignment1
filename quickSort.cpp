//Author: Kyle Smith
//Class: SENG 691Z
//Worksheet 1:Task3
//Test Driven Development
#include "quickSort.h"
#include <iostream>
#include <array>
using namespace std;

//define QuickSort variables
int tmp;
const int QarrSize=10;
const int QarrL2 = QarrSize-2;
int QkylesList[QarrSize];
int QarrL1= QarrSize-1;
int QsearchKey;


int quickSort(int arr[], int left, int right) {
     
	 int i = left, j = right;
     int pivot = arr[(left + right) / 2];
 
     //partition
	 while (i <= j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      };
 
	  
	 
      // recursion 
	 bool wasSorted;
	   for(int x = 0; x<= QarrL2; x++){
			if(arr[x] <= arr[x+1]){
				
				cout<<"Element "<<x<<" ("<<arr[x]<<") WAS less than OR equal to the Element "<<x+1<<" ("<<arr[x+1] <<")"<<endl;


				//Can only make it here if all elements are sorted
				if(x == QarrL2){
					wasSorted = true;
				//for loop to print
					cout<<"--------Sorted Array--------"<<endl;

					for(int x = 0; x <=QarrL2; x++){

						cout<< arr[x]<<" , ";

					}
						cout<<arr[QarrL1]<<endl<<endl;
				}
			}
			//Goes here when ever iteration array is not sorted.
			else
			{
			cout<<"Element "<<x<<" ("<<arr[x]<<") was NOT less than Element "<<x+1<<" ("<<arr[x+1] <<")"<<endl;
			cout<<"Array was not yet sorted!"<<endl;
			wasSorted = false;
			x=11111;

			//will go left or right
			 if (left < j)
		  quickSort(arr, left, j);
	  
			if (i < right)
		  quickSort(arr, i, right);
			
			}
	};

	   return arr[QarrSize];
}
