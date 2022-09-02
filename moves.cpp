#include<bits/stdc++.h>
#include<iostream>

#include "play2048.h"
using namespace std;

state* right(state* board_state){
	int i, j, mov=0, check=board_state->maxe;
	state* temp=new state();
	*temp=*board_state;
	for(i=0; i<4; i++){
		int pos=3;
		for(j=2; j>=0; j--){
			int t=j;
			while(t<pos){
				if(temp->board[i][t+1]==0){
					temp->board[i][t+1]=temp->board[i][t];
					if(temp->board[i][t]!=0){
						temp->free_spaces.insert(4*i+t);
						auto rem=temp->free_spaces.find(4*(i)+t+1);
						temp->free_spaces.erase(rem);
						mov++;
					}
					temp->board[i][t]=0;
					t++;
				}
				else{
					if(temp->board[i][t+1]==temp->board[i][t]){
						temp->board[i][t]=0;
						temp->free_spaces.insert(4*i+t);
						temp->board[i][t+1]*=2;
						if(temp->board[i][t+1]>check){
							temp->maxe=temp->board[i][t+1];
						}
						mov++;
						pos--;
					}
					t++;
					break;
				}
			}
		}
	}
	if(mov){
		random_insert(temp);
	}
	board_state->next=temp;
	temp->prev=board_state;
	temp->next=NULL;
	return temp;
}

state* down(state* board_state){
	int i, j, mov=0, check=board_state->maxe;
	state* temp=new state();
	*temp=*board_state;
	for(i=0; i<4; i++){
		int pos=3;
		for(j=2; j>=0; j--){
			int t=j;
			while(t<pos){
				if(temp->board[t+1][i]==0){
					temp->board[t+1][i]=temp->board[t][i];
					if(temp->board[t][i]!=0){
						temp->free_spaces.insert(4*t+i);
						auto rem=temp->free_spaces.find(4*(t+1)+i);
						temp->free_spaces.erase(rem);
						mov++;
					}
					temp->board[t][i]=0;
					t++;
				}
				else{
					if(temp->board[t+1][i]==board_state->board[t][i]){
						temp->board[t][i]=0;
						temp->free_spaces.insert(4*t+i);
						temp->board[t+1][i]*=2;
						if(temp->board[t+1][i]>check)
							temp->maxe=temp->board[t+1][i];
						mov++;
						pos--;
					}
					t++;
					break;
				}
			}
		}
	}
	if(mov){
		random_insert(temp);
	}
	board_state->next=temp;
	temp->prev=board_state;
	temp->next=NULL;
	return temp;
}

state* left(state* board_state){
	int i, j, mov=0, check=board_state->maxe;
	state* temp=new state();
	*temp=*board_state;
	for(i=0; i<4; i++){
		int pos=0;
		for(j=1; j<4; j++){
			int t=j;
			while(t>pos){
				if(temp->board[i][t-1]==0){
					temp->board[i][t-1]=temp->board[i][t];
					if(temp->board[i][t]!=0){
						temp->free_spaces.insert(4*i+t);
						auto rem=temp->free_spaces.find(4*i+t-1);
						temp->free_spaces.erase(rem);
						mov++;
					}
					temp->board[i][t]=0;
					t--;
				}
				else{
					if(temp->board[i][t-1]==temp->board[i][t]){
						temp->board[i][t]=0;
						temp->free_spaces.insert(4*i+t);
						temp->board[i][t-1]*=2;
						if(temp->board[i][t-1]>check)
							temp->maxe=temp->board[i][t-1];
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
		random_insert(temp);
	}
	board_state->next=temp;
	temp->prev=board_state;
	temp->next=NULL;
	return temp;
}

state* up(state* board_state){
	int i, j, mov=0, check=board_state->maxe;
	state* temp=new state();
	*temp=*board_state;
	for(i=0; i<4; i++){
		int pos=0;
		for(j=1; j<4; j++){
			int t=j;
			while(t>pos){
				if(temp->board[t-1][i]==0){
					temp->board[t-1][i]=temp->board[t][i];
					if(temp->board[t][i]!=0){
						temp->free_spaces.insert(4*t+i);
						auto rem=temp->free_spaces.find(4*(t-1)+i);
						temp->free_spaces.erase(rem);
						mov++;
					}
					temp->board[t][i]=0;
					t--;
				}
				else{
					if(temp->board[t-1][i]==temp->board[t][i]){
						temp->board[t][i]=0;
						temp->free_spaces.insert(4*t+i);
						temp->board[t-1][i]*=2;
						if(temp->board[t-1][i]>check)
							temp->maxe=temp->board[t-1][i];
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
		random_insert(temp);
	}
	temp->next=NULL;
	board_state->next=temp;
	temp->prev=board_state;
	return temp;
}
