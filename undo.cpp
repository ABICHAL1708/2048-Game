#include<bits/stdc++.h>
#include<iostream>

#include "play2048.h"
using namespace std;

state* undo(state* board_state){
	if(board_state->prev==NULL){
		return board_state;
	}
	state* temp=new state();
	temp=board_state->prev;
	temp->next=NULL;
	return temp;
}