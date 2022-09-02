#include<bits/stdc++.h>
#include<iostream>

#include "play2048.h"
using namespace std;

void display(state* board_state){
	int i, j;
	cout<<"_________________________"<<endl;
	for(i=0; i<4; i++){
		cout<<"|     |     |     |     |"<<endl;
		cout<<"|";
		for(j=0; j<4; j++){
			if(board_state->board[i][j]){
				if(board_state->board[i][j]<16)
					cout<<"  "<<board_state->board[i][j]<<"  |";
				else if(board_state->board[i][j]<128)
					cout<<"  "<<board_state->board[i][j]<<" |";
				else if(board_state->board[i][j]<1024)
					cout<<" "<<board_state->board[i][j]<<" |";
				else
					cout<<board_state->board[i][j]<<" |";
			}
			else
				cout<<"     |";
		}
		cout<<endl;
		cout<<"|_____|_____|_____|_____|"<<endl;
	}
}