#include<bits/stdc++.h>
#include<iostream>

#include "play2048.h"
using namespace std;

void random_insert(state* board_state){
	int num_insert_prob, i;
	srand(time(NULL));
	int insertr=rand()%(board_state->free_spaces.size()-0)+0;
	auto itr = board_state->free_spaces.begin();
	for(i=0; i<insertr; i++)
		itr++;
	int x=*itr/4, y=*itr%4;
	num_insert_prob=rand()%(99-0 + 1) + 0;
	//cout<<num_insert_prob<<endl;
	if(num_insert_prob>20){
		board_state->board[x][y]=2;
		board_state->sum_of_tiles+=2;
	}
	else{
		board_state->board[x][y]=4;
		board_state->sum_of_tiles+=4;
	}
	board_state->free_spaces.erase(itr);
}