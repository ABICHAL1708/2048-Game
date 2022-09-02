#ifndef _PLAY_2048_H_
#define _PLAY_2048_H_

#include<bits/stdc++.h>
using namespace std;

// extern int maxe;
// extern set<int> free_spaces;
// extern int sum_of_tiles;
struct state{
	int maxe; //for keeping value of max element
	int sum_of_tiles; // for sum of all tiles
	int board[4][4]; //matrix for representation 
	set<int> free_spaces; // set for free elements
	state* next; // pointer to next state
	state* prev; // pointer to previous state
};
/*
declarations of all the required functions
*/

extern bool check(state* board_state);
extern bool comparestates(state* st1, state* st2);
extern void display(state* board_state);
extern state* right(state* board_state);
extern state* down(state* board_state);
extern state* left(state* board_state);
extern state* up(state* board_state);
extern void random_insert(state* board_state);
extern void instructions();
extern state* undo(state* board_state);
#endif