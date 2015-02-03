//Author: Kyle Smith
//Class: SENG 691Z
//Worksheet 1:Task3
//Test Driven Development
#include <iostream>
#include <array>

using namespace std;

//Binary Search Function
int binSearch(int arr[], int key, int min, int max){

	//Checks for empty array
	if(max<min){
	
	cout<<"Array was empty"<<endl;

	}
	else
	{
	
	int i = min, j = max;
	int midElement = min+(max-min)/2;
     int midValue = arr[midElement];
	
	 //Checks if key is less than upper bound. Will then decrease it by 1
	 if(key<midValue){
	
		 cout<<"Key less than upper bound value "<<midValue<<" at element "<<midElement<<endl;
		 cout<<"Decreasing upper bound to element "<<--midElement<<endl;
		 

		 --midElement;
		 //Prints new list
		 cout<<"New list is: ";
		 for(int count=0;  count <= midElement; count++){
		 cout<<arr[count]<<" , ";
		
		 };

		 midElement++;
		 cout<<arr[midElement]<<endl;
		
		 //Starts binary Search over
		 return binSearch(arr, key, min, midElement);
	 }

	 //Checks if key is greater than midpoint value.  Will increase lower bound by 1
	 else if(key>midValue){

		 cout<<"Key is greater than midpoint value "<<midValue<<" at element "<<midElement<<endl;
		 cout<<"Increasing lower bound to element "<<++midElement<<endl;

		 //Prints new list
		 cout<<"New list is: ";
		 for(int count=midElement;  count < max; count++){
		 cout<<arr[count]<<" , ";
		 };
		 cout<<arr[max]<<endl;
	
		 //Starts binary search over
		return binSearch(arr, key, midElement, max);
	 
	 
	 }
	 //If key is the same as the mid value then the number search for has been found. Should return key.
	 else if(key==midValue){
		 cout<<endl<<endl;
		 cout<<"----------------Key Located-----------------"<<endl;
		 cout<<"Key was found with midpoint "<<midValue<<" which was element "<<midElement<<endl;
		 cout<<"Key equals "<<key<<" and midpoint equals "<<midValue<<", so binary search for key was successful!"<<endl;
		 
	 }
	  return key;
	};
}
