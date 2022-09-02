#include<bits/stdc++.h>
#include<iostream>

#include "play2048.h"
using namespace std;

/*returns true if st1 and st2 are not the same
else the function returns false
*/

bool comparestates(state* st1, state* st2){
	//if the elements which are free are not the same, 
	//then we say that the states are not the same
	if(st1->free_spaces!=st2->free_spaces)
		return true;
	int i, j;
	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
			if(st1->board[i][j]!=st2->board[i][j])
				return true;
		}
	}
	return false;
}