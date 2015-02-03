//Author: Kyle Smith
//Class: SENG 691Z
//Worksheet 1:Task2
//Test Driven Development
#include <iostream>
#include <string>
using namespace std;

//Global variables: Tic, Tac, Toe board array, Is player 1 x bool, and gameOver bool.
char tttArr[9] = {'0','1','2','3','4','5','6','7','8'};
bool IsP1X;
bool gameOver;

//Function prototypes
char displayBoard(char p1Piece, char p2Piece);
void clearBoard();
void insertPiece(char Piece, bool p1X, string player);
bool isDraw();
bool playerXorY();
bool isWinner(string playerWithXpiece, string playerWithYpiece);


//Main method
void main(){
	
	//set Game Over to false(game state is running), and get player 1 to choose X or Y for their game piece.
	gameOver=false;
	playerXorY();


	//This if statement checks whether player 1 is x piece.
	if(IsP1X==true){

			//reprints board every after turns
			displayBoard('X','Y');

			//Loops through 9 or less game play iterations.  
			for(int count = 0; count <=8; count++){

					//Decides even/odd count to rotate turns.
					if(count%2!=0){

						insertPiece('X', true, "Player1");

					}
					else{

						insertPiece('Y', true, "Player2");

					};

					//turn will call isWinner function to check for pairs of three
					isWinner("Player1", "Player2");

					//will end loop if winner is decided(game can be restarted).
					if(gameOver==true){break;};

			};

		//will call draw state if no winner is found after all turns are taken.
		if(gameOver!=true){isDraw();};
			
		}
	
		//Else statement for if player 1 is 'Y'
	else
		{
				
			//reprints board every after turns
			displayBoard('Y','X');

			//Loops through 9 or less game play iterations. 
				for(int count = 0; count <=8; count++){

					//Decides even/odd count to rotate turns.
					if(count%2!=0){

						insertPiece('Y', false, "Player1");

					}

					else{

						insertPiece('X', false, "Player2");

					};

					//turn will call isWinner function to check for pairs of three
					isWinner("Player2", "Player1");

					//will end loop if winner is decided(game can be restarted).
					if(gameOver==true){break;};

				};

				//will call draw state if no winner is found after all turns are taken.
				if(gameOver!=true){isDraw();};
			
		};

	//Allows players to restart match
	cout<<"To start a new match type -1"<<endl;
	int position;
	cin>>position;

	if(position==-1){
	
		clearBoard();
		main();

					};

}

//The whole point of this function is to display the board for the user.
//It reprints an 'X' or 'Y' in the index position on the board.
//Also will keep the piece the player is at the top of the board.
//Returns board size at the end for later use.
char displayBoard(char p1Piece, char p2Piece){

		cout << "Kyle Smith's Tic Tac Toe Game"<<endl;
		cout << "============================="<<endl<<endl;

	cout << "Player 1 ("<<p1Piece<<")  -  Player 2 ("<<p2Piece<<")" << endl << endl;
	cout << endl;


	cout << "     |     |     " << endl;
	cout << "  " << tttArr[0] << "  |  " << tttArr[1] << "  |  " << tttArr[2] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << tttArr[3] << "  |  " << tttArr[4] << "  |  " << tttArr[5] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << tttArr[6] << "  |  " << tttArr[7] << "  |  " << tttArr[8] << endl;

	cout << "     |     |     " << endl << endl;

	
	return tttArr[9];


}

//This function will take user input of 'X' or 'Y' and call displayBoard to update board.
//Clearing the board is also used here if the user desires.
void insertPiece(char Piece, bool p1X, string player){

int position;
cout<<player<<"'s turn. Enter postion to place piece, or type -1 to clear the board: ";
cin>>position;
	
	if(position==-1){
	
		clearBoard();
		main();

					}

	else if(position >=0 && position <= 8){
			
			tttArr[position] = Piece;

				if(p1X==true)
					{

				displayBoard('X','Y');

					}
				else
					{

				displayBoard('Y','X');
		

					}

		}
	//Won't allow non 0-8 or -1 numbers
	else
		{

		cout<<"Position was invalid! Try again."<<endl;
		insertPiece(Piece, p1X, player);


		};

}

//Used at the beginning of the game for player 1 choose piece, and will automatically assign the other piece to player 2.
bool playerXorY(){

	char Piece;
	cout<<"Player 1 enter your piece selection(X or Y): ";
	cin>>Piece;
	
	//checks if player 1 is x.
	if(Piece=='X' || Piece=='x'){
	
		cout<<"Player 1 is X and Player 2 is Y"<<endl;
		IsP1X=true;
		return IsP1X;
	
	}
	//checks if player 1 is y.
	else if(Piece=='Y' || Piece=='y'){

		cout<<"Player 1 is Y and Player 2 is X"<<endl;
		IsP1X=false;
		return IsP1X;
	}
	
	//checks for invalid character
	else{

		cout<<"Piece choice was invalid! Please try again.(X or Y)"<<endl;
		return playerXorY();

	};

	



}

//Checks if game was a draw. Returns gameOver bool.
bool isDraw(){

	
	cout<<"Game was a draw."<<endl;
	cout<<"Game over."<<endl;
	gameOver=true;
	return gameOver;
	
}



//Checks for specific winner of the game after a three char squence(x or y). Returns gameOver bool.
bool isWinner(string playerWithXpiece, string playerWithYpiece){
	
	char winnerValue;
	bool hasWon = false;

	//This logic is used for checking x and y squences of 3.
	//When 3 char sequence is found a value from that sequence will be stored to determin if it was x or y.
	//will then return true bool value for hasWon to be associated with player.
	if(tttArr[0]==tttArr[1]&&tttArr[1]==tttArr[2]){
	
		winnerValue=tttArr[0];
		hasWon=true;

	}
	else if(tttArr[3]==tttArr[4]&&tttArr[4]==tttArr[5]){
	
		winnerValue=tttArr[3];
		hasWon= true;

	}
		else if(tttArr[6]==tttArr[7]&&tttArr[7]==tttArr[8]){
	
		winnerValue=tttArr[6];
		hasWon= true;
	
	}
		else if(tttArr[0]==tttArr[3]&&tttArr[3]==tttArr[6]){
	
		winnerValue=tttArr[0];
		hasWon= true;
		
	}
		else if(tttArr[1]==tttArr[4]&&tttArr[4]==tttArr[7]){
	
		winnerValue=tttArr[1];
		hasWon= true;
		

	}
		else if(tttArr[2]==tttArr[6]&&tttArr[6]==tttArr[9]){
	
		winnerValue=tttArr[2];
		hasWon= true;
	

	}

		else if(tttArr[0]==tttArr[4]&&tttArr[4]==tttArr[8]){
	
		winnerValue=tttArr[0];
		hasWon= true;
		

	}

	else if(tttArr[2]==tttArr[4]&&tttArr[4]==tttArr[6]){
	
		winnerValue=tttArr[2];
		hasWon= true;

	}

	//This logic uses the knowledge of what piece the player was useing to decide who the winner was.
	//Ex. if player2 was using 'X' and the sequence was 3 x's, this logic shows player 2 won.
	if(hasWon==true && winnerValue=='X'){
	
		cout<<playerWithXpiece<<" has won!"<<endl;
		cout<<"Game Over."<<endl;
		gameOver = true;
	
		return gameOver;

	}
	else if(hasWon==true &&winnerValue== 'Y'){

		cout<<playerWithYpiece<<" has won!"<<endl;
		cout<<"Game Over."<<endl;
		gameOver = true;
	
		return gameOver;
	
	};

	
}

//Clears the board by using a temp array and storing the original chars used on the board at game start.
void clearBoard(){


	char tempArr[9] ={'0','1','2','3','4','5','6','7','8'};	
	
	for(int count = 0; count <=8; count++){
	
			tttArr[count]=tempArr[count];
	
	};
}
