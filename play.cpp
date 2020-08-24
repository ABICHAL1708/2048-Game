#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int maxe=0;

/*for checking the condition that the game has not 
ended yet. If ended return false else true*/
bool check(int board[][4]){
	int i, j;
	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
			if(board[i][j]==0)
				return true;
		}
	}
	return false;
}
/*display is the function for displaying the board*/
void display(int board[][4]){
	int i, j;
	cout<<"_________________________"<<endl;
	for(i=0; i<4; i++){
		cout<<"|     |     |     |     |"<<endl;
		cout<<"|";
		for(j=0; j<4; j++){
			if(board[i][j]){
				if(board[i][j]<16)
					cout<<"  "<<board[i][j]<<"  |";
				else if(board[i][j]<128)
					cout<<"  "<<board[i][j]<<" |";
				else if(board[i][j]<1024)
					cout<<" "<<board[i][j]<<" |";
				else
					cout<<board[i][j]<<" |";
			}
			else
				cout<<"     |";
		}
		cout<<endl;
		cout<<"|_____|_____|_____|_____|"<<endl;
	}
}

void right(int board[][4]){
	int i, j, mov=0, check=maxe;
	for(i=0; i<4; i++){
		int pos=3;
		for(j=2; j>=0; j--){
			int t=j;
			while(t<pos){
				if(board[i][t+1]==0){
					board[i][t+1]=board[i][t];
					if(board[i][t]!=0)
						mov++;
					board[i][t]=0;
					t++;
				}
				else{
					if(board[i][t+1]==board[i][t]){
						board[i][t]=0;
						board[i][t+1]*=2;
						if(board[i][t+1]>check){
							maxe=board[i][t+1];
						}
						mov++;
					}
					t++;
					break;
				}
			}
		}
	}
	if(mov){
		srand(time(NULL));
		int insertr=rand()%(15-0+1)+0, x=insertr/4, y=insertr%4;
		while(board[x][y]!=0){
			srand(time(NULL));
			insertr=rand()%(15-0+1)+0, x=insertr/4, y=insertr%4;
		}
		board[x][y]=2;
	}
}

void down(int board[][4]){
	int i, j, mov=0, check=maxe;
	for(i=0; i<4; i++){
		int pos=3;
		for(j=2; j>=0; j--){
			int t=j;
			while(t<pos){
				if(board[t+1][i]==0){
					board[t+1][i]=board[t][i];
					if(board[t][i]!=0)
						mov++;
					board[t][i]=0;
					t++;
				}
				else{
					if(board[t+1][i]==board[t][i]){
						board[t][i]=0;
						board[t+1][i]*=2;
						if(board[t+1][i]>check)
							maxe=board[t+1][i];
						mov++;
					}
					t++;
					break;
				}
			}
		}
	}
	if(mov){
		srand(time(NULL));
		int insertr=rand()%(15-0+1)+0, x=insertr/4, y=insertr%4;
		while(board[x][y]!=0){
			srand(time(NULL));
			insertr=rand()%(15-0+1)+0, x=insertr/4, y=insertr%4;
		}
		board[x][y]=2;
	}
}

void left(int board[][4]){
	int i, j, mov=0, check=maxe;
	for(i=0; i<4; i++){
		int pos=0;
		for(j=1; j<4; j++){
			int t=j;
			while(t>pos){
				if(board[i][t-1]==0){
					board[i][t-1]=board[i][t];
					if(board[i][t]!=0)
						mov++;
					board[i][t]=0;
					t--;
				}
				else{
					if(board[i][t-1]==board[i][t]){
						board[i][t]=0;
						board[i][t-1]*=2;
						if(board[i][t-1]>check)
							maxe=board[i][t-1];
						mov++;
					}
					t--;
					break;
				}
			}
		}
	}
	if(mov){
		srand(time(NULL));
		int insertr=rand()%(15-0+1)+0, x=insertr/4, y=insertr%4;
		while(board[x][y]!=0){
			srand(time(NULL));
			insertr=rand()%(15-0+1)+0, x=insertr/4, y=insertr%4;
		}
		board[x][y]=2;
	}
}

void up(int board[][4]){
	int i, j, mov=0, check=maxe;
	for(i=0; i<4; i++){
		int pos=0;
		for(j=1; j<4; j++){
			int t=j;
			while(t>pos){
				if(board[t-1][i]==0){
					board[t-1][i]=board[t][i];
					if(board[t][i]!=0)
						mov++;
					board[t][i]=0;
					t--;
				}
				else{
					if(board[t-1][i]==board[t][i]){
						board[t][i]=0;
						board[t-1][i]*=2;
						if(board[t-1][i]>check)
							maxe=board[t-1][i];
						mov++;
					}
					t--;
					break;
				}
			}
		}
	}
	if(mov){
		srand(time(NULL));
		int insertr=rand()%(15-0+1)+0, x=insertr/4, y=insertr%4;
		while(board[x][y]!=0){
			srand(time(NULL));
			insertr=rand()%(15-0+1)+0, x=insertr/4, y=insertr%4;
		}
		board[x][y]=2;
	}
}

int main(){
	int i, j, inserti, insertj;
	/*i and j are the pointers for accessing the row
	and column of the board, inserti is the row rand
	variable and insertj is the column rand variable*/
	int board[4][4];
	char input;

	//intializing board with all zeros
	for(i=0; i<4; i++){
		for(j=0; j<4; j++)
			board[i][j]=0;
	}
	//adding a random 2 somewhere
	srand(time(NULL));//seedng the time for rand
	inserti=rand()%(3-0 + 1) +  0;
	insertj=rand()%(3-0 + 1) +  0;
	board[inserti][insertj]=2;
	maxe=2;
	display(board);
	while(check(board)){
		if(maxe==2048){
			cout<<"GAME WON!!!"<<endl;
			break;
		}
		cin>>input;
		if(input=='d'){
			cout<<"right pressed"<<endl;
			right(board);
		}
		else if(input=='a'){
			cout<<"left pressed"<<endl;
			left(board);
		}
		else if(input=='w'){
			cout<<"up pressed"<<endl;
			up(board);
		}
		else if(input=='s'){
			cout<<"down pressed"<<endl;
			down(board);
		}
		display(board);
	}
	cout<<"Game end"<<endl;
	return 0;
}