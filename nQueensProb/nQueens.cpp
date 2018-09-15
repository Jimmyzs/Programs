/*
	Jimmy Yuan
	The program outputs 10 ways to put queens on a chess board where they are not in the same row,column
	or diagonal. Then the program takes the user input to create an nxn board with queens that are not in
	the same row,column or diagonal.
*/


#include <iostream>
#include <string>
using namespace std;

//Checks if the queen is in the same row, column or diagonal of a previous queen
bool check(int board[],int row){
	//Loops through the previous queens to compare with the current queen
	for(int i=0;i<row;i++){
		//Checks if they are in the same column
		if(board[i]==board[row]){
			return false;
		}
		//Checks if they are in the same right diagonal
		else if((board[i]+i)==(board[row]+row)){
			return false;
		}
		//Checks if they are in the same left diagonal
		else if((i-board[i])==(row-board[row])){
			return false;
		}
	}
	//Queens are not in the same row,column or diagonal
	return true;
}

//Gets the column of the queen for each row
bool solve(int board[],int size,int row){
	bool works;
	//If the row is equal to the size it means all the queens are arranged
	if(row==size){
		return true;
	}
	//Loops through all of the columns of a row
	for(int i=0;i<=size;i++){
		//If the column is equal to the size of the board it is out of bounds and there are available positions on the row
		if(i==size){
			return false;
		}

		board[row]=i;
		//Checks if the position works
		works=check(board,row);
		if(works){
			//Goes to the next row if a position for the current row is found
			works=solve(board,size,row+1);
			//If true it means that all positions for the queens have been found
			if(works){
				return true;
			}

		}
	}
	//Does nothing
	return true;
}

//Prints the board
void print(int board[],int size){
	//Goes throught all of the rows and columns
	for(int i=0;i<size;i++){
		for(int k=0;k<size;k++){
			//board contains the position of the queens on the i row and a 1 is placed, else a 0 is placed
			if(k!=board[i]){
				cout<<"0";
			}
			else{
				cout<<"1";
			}
		}
		cout<<endl;
	}
	cout<<endl;
}

//Reflects the board though the left diagonal
void reflect(int board[]){
	int refl[8];
	int num;
	//Swaps the row and column for all rows and columns
	for(int i=0;i<8;i++){
		num=board[i];
		refl[num]=i;
	}
	print(refl,8);
}


int main(){

	int board[8];
	//Solves the board for when the queen is in each column of the first row
	for(int i=0;i<8;i++){
		board[0]=i;
		if(solve(board,8,1)){
			print(board,8);
			//Reflects the boards where the queen is at the 0th column and 7th column
			if(i==0||i==7){
				reflect(board);
			}
		}
	}

	//Gets the user inputed size for the board
	int n=0;
	string s;
	bool good=false;
	//Loops until a number between 8 and 21 is given
	while(!good){
		cout<<"What is the size of the board?(8<n<21):";
		cin>>s;
		do{
			good=true;
			//Number should be 1 or 2 digits
			if(s.length()>2){
				good=false;
			}
			else{
				//Should only contain 0-9
				for(int i=0;i<s.length();i++){
					if(s[i]>57||s[i]<48){
					 	good=false;
					 	i=s.length();
					}
				}
			}
			//Asks for another entry until a number 0<=x=<100 is given
			if(good==false){
				cout<<"Enter a number between 8 and 21: ";
				cin>>s;
			}

		}while(!good);
		//Turns the string into an int
		n=stoi(s);
		//Makes sure the number is between 8 and 21
		if(n>20||n<9){
			good=false;
		}
	}

	int boardn[n];
	//Solve and prints the solution for the nxn board or outputs that it is not possible
	if(solve(boardn,n,0)){
		print(boardn,n);
	}
	else{
		cout<<"Not possible"<<endl;
	}
	return 0;
}
