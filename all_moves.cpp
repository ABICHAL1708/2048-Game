#include<bits/stdc++.h>
#include<iostream>

#include "play2048.h"
using namespace std;

void moves(state* board_state, char move){
	int i, j, mov=0, check=board_state->maxe;
	for(i=0; i<4; i++){
		int pos;
		if(move=='w'||move=='a')
			pos=0;
		else
			pos=3;
		for(j=1; j<4; j++){
			int t=j;
			while(t>pos){
				if(board_state->board[t-1][i]==0){
					board_state->board[t-1][i]=board_state->board[t][i];
					if(board_state->board[t][i]!=0){
						board_state->free_spaces.insert(4*t+i);
						auto rem=board_state->free_spaces.find(4*(t-1)+i);
						board_state->free_spaces.erase(rem);
						mov++;
					}
					board_state->board[t][i]=0;
					t--;
				}
				else{
					if(board_state->board[t-1][i]==board_state->board[t][i]){
						board_state->board[t][i]=0;
						board_state->free_spaces.insert(4*t+i);
						board_state->board[t-1][i]*=2;
						if(board_state->board[t-1][i]>check)
							board_state->maxe=board_state->board[t-1][i];
						mov++;
						pos++;
					}
					t--;
					break;
				}
			}
		}
	}
	if(mov){
		random_insert(board_state);
	}
}