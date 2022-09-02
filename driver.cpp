#include<bits/stdc++.h>
#include<iostream>

#include "play2048.h"
using namespace std;

int main(){
	int i, j, n;
	/*i and j are the pointers for accessing the row
	and column of the board, inserti is the row rand
	variable and insertj is the column rand variable*/
	state* root=new state();
	state* tail=new state();
	state* board_state=new state();
	board_state->next=NULL;
	board_state->prev=NULL;
	char input;

	//intializing board with all zeros
	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
			board_state->board[i][j]=0;
			board_state->free_spaces.insert(i*4+j);
		}
	}
	//adding 2 random values somewhere
	//srand((time(NULL)));
	random_insert(board_state);
	random_insert(board_state);
	root=board_state;
	tail=board_state;
	//root for the head of the linked list and tail the current part of the board
	cout<<"enter the max value of tile that you want :"<<endl;
	cin>>n;
	// n is to be 8 for the for theimplementations given
	display(tail);//displays the current call of the board
	cout<<"type i for instructions"<<endl;
	while(check(tail)){
		state* temp=new state();
		if(board_state->maxe==n){
			cout<<"GAME WON!!!"<<endl;
			break;
		}
		cin>>input;
		if(input=='d'){
			cout<<"right pressed"<<endl;
			temp=right(board_state);
		}
		else if(input=='a'){
			cout<<"left pressed"<<endl;
			temp=left(board_state);
		}
		else if(input=='w'){
			cout<<"up pressed"<<endl;
			temp=up(board_state);
		}
		else if(input=='s'){
			cout<<"down pressed"<<endl;
			temp=down(board_state);
		}
		else if(input=='c'){
			cout<<"the sum of all the tiles is :"<<endl;
			cout<<board_state->sum_of_tiles<<endl;
		}
		else if(input=='i'||input=='I'){
			instructions();
		}
		else{
			cout<<"enter I/i for instructions!!!"<<endl;
		}
		board_state=temp;
		display(board_state);
	}
	cout<<"Game end"<<endl;
	return 0;
}
