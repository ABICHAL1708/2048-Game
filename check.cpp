#include<bits/stdc++.h>
#include<iostream>

#include "play2048.h"
using namespace std;

bool check(state* board_state){
	int i, j;
	if(!board_state->free_spaces.empty())
		return true;
	for(i=0; i<4; i++){
		for(j=1; j<4; j++){
			if(board_state->board[i][j]==board_state->board[i][j-1])
				return true;
		}
	}
	for(i=1; i<4; i++){
		for(j=0; j<4; j++){
			if(board_state->board[i][j]==board_state->board[i-1][j])
				return true;
		}
	}
	return false;
}