//Author: Kyle Smith
//Class: SENG 691Z
//Worksheet 1:Task1
//Test Driven Development
#include <iostream>
using namespace std;

//Prototype Fibonacci Function
void FibSeq(int n, int num1, int num2);

int main()
{

  int n;

  //Initial prompt to enter position to find value in Fibonacci Sequence
  cout << "Please type in position for Fibonacci Sequence to return value: ";
   cin >> n;
	FibSeq(n, 0, 1);
  
 
}

void FibSeq(int n, int num1, int num2) {

//Print error for 0 and negative values
if(n<=0){
	
	cout<<"Error"<<endl;

 }

//Print total value when n==1.
 else {

	   if(n==1){
    cout <<"Value in position was: "<< num1 <<endl;

		cout << "Please type in position for Fibonacci Sequence to return value: ";
		
		//Just used so program doesn't have to rerun to print next inputted number
		//Continuous
		cin >> n;
		FibSeq(n, 0, 1);
  
	 };

	   //Keep recursion going until n==1 
	   if(n != 1){
	   FibSeq(n-1, num2, num1 + num2);

	   };
	  
  }
}
