#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;
const int side=3;
const char human='O', comp='X';
void initialize();
bool checkdiag(char board[][side]);
bool checkcross(char board[][side]);
bool checkdown(char board[][side]);
bool check(char board[][side], int x, int y);
void showboard(char board[][side]);
int random();
int play(int turn, char board[][side]);
int playhard(int turn, char boar[][side]);
void compturnhard(char board[][side], int size);
void humanturn(char board[][side]);
void compturn(char board[][side], int size);
bool endgame(char board[][side]);


int random()
{
	int rando=rand()%3;
	return rando;
}

void instructions()  //Displays instructions for how to play the game.
{
	cout<<"On your turn, select an x,y coordinate on the 3x3 board."<<endl;
	cout<<"-------------------"<<endl;
	cout<<"| 0,0 | 1,0 | 2,0 |"<<endl;
	cout<<"-------------------"<<endl;
	cout<<"| 0,1 | 1,1 | 2,1 |"<<endl;
	cout<<"-------------------"<<endl;
	cout<<"| 0,2 | 1,2 | 2,2 |"<<endl;
	cout<<"-------------------"<<endl;
}
void initialize(char board[][side])  //Initializes the 2 dimensional array for the board
{
	for (int i=0;i<side;i++)
	{
		for (int j=0;j<side;j++)
		board[j][i]=' ';
	}
}

void showboard(char board[][side]) //Prints the board
{
	cout<<"-------------"<<endl;
	cout<<"| "<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<" |"<<endl;
	cout<<"-------------"<<endl;
	cout<<"| "<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<" |"<<endl;
	cout<<"-------------"<<endl;
	cout<<"| "<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<" |"<<endl;
	cout<<"-------------"<<endl;
}

int play(int turn, char board[][side]) //Carrys out the game.  Goes for 9 turns or until someone wins
{
	int coin, turn_count=0;
	cout<<"To determine who will go first, we will flip a coin."<<endl;
	system("Pause");
  	coin = (rand()%2)+ 1 ;
 	if (coin==1)
 	{
 	while (turn_count!=turn)
   	{
	
	 	if (turn_count%2==1)
	 	{
	 	humanturn(board);
	    turn_count++;
	    if (endgame(board)==true)
	    {
	    cout<<"Congratulations, you won!"<<endl;
	    return 0;
		}
		else if (turn_count==turn)
		{
		cout<<"The game was a draw."<<endl;
		showboard(board);
		}
	    
	    }
	 	if (turn_count%2==0)
	 	{
	 	compturn(board, side);
	 	turn_count++;
	 	
	 	if (endgame(board)==true)
	 	{
		showboard(board);
	 	cout<<"You got beat by a random number generator."<<endl;
	 	turn_count=turn;
		return 0;	
		}
	 	else if(turn_count==turn)
	 	{
	 	showboard(board);
		cout<<"The game was a draw!"<<endl;	
		}
	    }
	 }
	}
	else
	{
		while (turn_count!=turn)
		{
		if (turn_count%2==1)
	 	{
	 	compturn(board, side);
	    turn_count++;
	    if (endgame(board)==true)
	 	{
		showboard(board);
	 	cout<<"You got beat by a random number generator!"<<endl;
	 	turn_count=turn;
		return 0;	
		}
	 	else if(turn_count==turn)
	 	{
	 	showboard(board);
		cout<<"The game was a draw!"<<endl;	
		}
	    }
	    
	 	if (turn_count%2==0)
	 	{
	 	humanturn(board);
	 	turn_count++;
	 	if (endgame(board)==true)
	    {
	    cout<<"Congratulations, you won!"<<endl;
	    return 0;
		}
		else if (turn_count==turn)
		{
		cout<<"The game was a draw."<<endl;
		showboard(board);
		}
	    }
	 }
	}
}

int playhard(int turn, char board[][side])  //Same thing as the play function, but for the hard game.
{
	int coin, turn_count=0;
	cout<<"To determine who will go first, we will flip a coin."<<endl;
	system("Pause");
  	coin = (rand()%2)+ 1 ;
 	if (coin==1)
 	{
 	while (turn_count!=turn)
   	{
	
	 	if (turn_count%2==1)
	 	{
	 	humanturn(board);
	    turn_count++;
	    if (endgame(board)==true)
	    {
	    cout<<"Congratulations, you won!"<<endl;
	    return 0;
		}
		else if (turn_count==turn)
		{
		cout<<"The game was a draw."<<endl;
		showboard(board);
		}
	    
	    }
	 	if (turn_count%2==0)
	 	{
	 	compturnhard(board, side);
	 	turn_count++;
	 	
	 	if (endgame(board)==true)
	 	{
		showboard(board);
	 	cout<<"You lost"<<endl;
	 	turn_count=turn;
		return 0;	
		}
	 	else if(turn_count==turn)
	 	{
	 	showboard(board);
		cout<<"The game was a draw!"<<endl;	
		}
	    }
	 }
	}
	else
	{
		while (turn_count!=turn)
		{
		if (turn_count%2==1)
	 	{
	 	compturnhard(board, side);
	    turn_count++;
	    if (endgame(board)==true)
	 	{
		showboard(board);
	 	cout<<"You lost"<<endl;
	 	turn_count=turn;
		return 0;	
		}
	 	else if(turn_count==turn)
	 	{
	 	showboard(board);
		cout<<"The game was a draw!"<<endl;	
		}
	    }
	 	if (turn_count%2==0)
	 	{
	 	humanturn(board);
	 	turn_count++;
	 	if (endgame(board)==true)
	    {
	    cout<<"Congratulations, you won!"<<endl;
	    return 0;
		}
		else if (turn_count==turn)
		{
		cout<<"The game was a draw."<<endl;
		showboard(board);
		}
	    }
	 }
	}
}
void humanturn(char board[][side])  //Takes input from player and outputs an O in their desired position
{ 
	int x,y;
	bool turn=false;
	cout<<"It is your turn"<<endl;
	showboard(board);
	cout<<"Please select an x,y coordinate to place your O."<<endl;
	cout<<"X: ";
	cin>>x;
	cout<<endl;
	cout<<"Y: ";
	cin>>y;
	while (turn==false)
	{
	if(board[y][x]!=human && board[y][x]!=comp && (x<=2) && (y<=2))
	{
	cout<<endl;
	board[y][x]=human;
	cout<<"You chose "<<x<<","<<y<<"."<<endl;
	showboard(board);
	cout<<endl<<endl<<endl;	
	turn=true;
	}
	else
	{
	cout<<"Please enter a valid coordinate."<<endl;
	cout<<"X:";
	cin>>x;
	cout<<"Y:";
	cin>>y;	
	}
	}

	
}


void compturn(char board[][side],int size)  //chooses a random location for the computer to go (used for the easy game)
{
	int turn=false;
	int g,l;
	cout<<"It is the computer's turn"<<endl;
		 g=random();
		 l=random();
	while (turn==false)
	{
	if(board[l][g]!=human && board[l][g]!=comp)
	{
	board[l][g]=comp;
	cout<<"The computer chose "<<g<<","<<l<<"."<<endl;
	cout<<endl<<endl<<endl;
	turn=true;
	}
	else
	{
	g=random();
	l=random();
	}
	
}
}

void compturnhard(char board[][side],int size)  //Computer turn for the hard game.  If there is an option to block you, it will, if not, it will choose a random
{
	int g,l;
	cout<<"It is the computer's turn"<<endl;
	g=1;
	l=1;
	while (board[l][g]!=' ')
	{
	if(board[0][1]==board[1][1] && (board[0][1]==human || board[0][1]==comp))  ///Checks down the board for two in a row.  
																			   ///If one is found, the computer will go in the open space to block.
	{
		g=1;
		l=2;
	}
	if (board[1][1]==board[2][1] && (board[1][1]==human || board[1][1]==comp))
	{
		g=1;
		l=0;
	}
	if (board[0][1]==board[2][1] && (board[0][1]==human || board[0][1]==comp))
	{
		g=1;
		l=1;
	}	
	if(board[0][0]==board[1][0] && (board[0][0]==human || board[0][0]==comp))  ///Checks down the board for two in a row.  
																			   ///If one is found, the computer will go in the open space to block.
	{
		g=0;
		l=2;
	}
	if (board[1][0]==board[2][0] && (board[1][0]==human || board[1][0]==comp))
	{
		g=0;
		l=0;
	}
	if (board[0][0]==board[2][0] && (board[0][0]==human || board[0][0]==comp))
	{
		g=0;
		l=1;
	}	
	if(board[0][2]==board[1][2] && (board[0][2]==human || board[0][2]==comp))  ///Checks down the board for two in a row.  
																			   ///If one is found, the computer will go in the open space to block.
	{
		g=2;
		l=2;
	}
	if (board[1][2]==board[2][2] && (board[1][2]==human || board[1][2]==comp))
	{
		g=2;
		l=0;
	}
	if (board[0][2]==board[2][2] && (board[0][2]==human || board[0][2]==comp))
	{
		g=2;
		l=1;
	}	
	if (board[0][0]==board[0][1] && (board[0][0]==human || board[0][0]==comp))   ///Checks down the board for two in a row.  
																					 ///If one is found, the computer will go in the open space to block.
	{
		g=2;
		l=0;
	}
	if (board[0][1]==board[0][2] && (board[0][1]==human || board[0][1]==comp))
	{
		g=0;
		l=0;
	}
	if (board[0][2]==board[0][0] && (board[0][2]==human || board[0][2]==comp))
 	{
		g=1;
		l=0;
	}
	if (board[1][0]==board[1][1] && (board[1][0]==human || board[1][0]==comp))   ///Checks down the board for two in a row.  
																					 ///If one is found, the computer will go in the open space to block.
	{
		g=2;
		l=1;
	}
	if (board[1][1]==board[0][2] && (board[1][1]==human || board[1][1]==comp))
	{
		g=0;
		l=1;
	}
	if (board[1][2]==board[1][0] && (board[1][2]==human || board[1][2]==comp))
 	{
		g=1;
		l=1;
	}
	if (board[2][0]==board[2][1] && (board[2][0]==human || board[2][0]==comp))   ///Checks down the board for two in a row.  
																					 ///If one is found, the computer will go in the open space to block.
	{
		g=2;
		l=2;
	}
	if (board[2][1]==board[2][2] && (board[2][1]==human || board[2][1]==comp))
	{
		g=0;
		l=2;
	}
	if (board[2][2]==board[2][0] && (board[2][2]==human || board[2][2]==comp))
 	{
		g=1;
		l=2;
	}
	if (board[0][0]==board[1][1] && (board[0][0]==human || board[0][0]==comp))
		{
			l=2;
			g=2;
		}	
		else if (board[0][2]==board[1][1] && (board[0][2]==human || board[0][2]==comp))
		{
			l=2;
			g=0;
		}
		else if (board[1][1]==board[2][2] && (board[1][1]==human || board[1][1]==comp))
		{
			l=0;
			g=0;
		}
		else if (board[2][0]==board[1][1] && (board[2][0]==human || board[2][0]==comp))
		{
			l=0;
			g=2;		
		}
		else if (board[0][2]==board[2][0] && (board[0][2]==human || board[0][2]==comp))
		{
			l=1;
			g=1;		
		}
		else if (board[2][2]==board[0][0] && (board[2][2]==human || board[2][2]==comp))
		{
			l=1;
			g=1;	
		}	
		if (board[l][g]!=' ')
		{
		while (board[l][g]==human || board[l][g]==comp)
		{
		cout<<"random"<<endl;
		g=random();
		l=random();
		}
	}
}
		board[l][g]=comp;
		cout<<"The computer chose "<<g<<","<<l<<"."<<endl;
		cout<<endl<<endl<<endl;		
}


bool endgame(char board[][side])  //Checks the entire board for three in a row
{
	if (checkcross(board)==true||checkdiag(board)==true||checkdown(board)==true)
	return true;
	return false;
}

bool checkcross(char board[][side])  //Checks all possible rows for three in a row
{ 
	for (int i=0;i<side;i++)
	{
	if (board[0][i]==board[1][i] && board[1][i]==board[2][i] && board[2][i]==board[0][i] && (board[0][i]==comp || board[0][i]==human))
	return true;
	}
	return false;
}

	
bool checkdown(char board[][side]) //Checks all possible columns for three in a row
{
	for (int i=0;i<side;i++)
	{
	if (board[i][0]==board[i][1] && board[i][1]==board[i][2] &&  (board[i][0]==comp || board[i][0]==human))
	return true;
	}
	return false;
}

	
bool checkdiag(char board[][side]) //Checks all possible diagonals for three in a row
{
if (board[0][0]==board[1][1] && board[1][1]==board[2][2] && (board[0][0]==comp || board[0][0]==human))
return true;


if (board[2][0]==board[1][1] && board[1][1]==board[0][2] && (board[2][0]==comp || board[2][0]==human))
return true;
return false;

}

int main() //Main program, user can choose hard or easy game
{
	srand(time(NULL));
	char board[side][side]={0};
	initialize(board);
	int start;
	cout<<"WELCOME TO TIC TAC TOE!!!"<<endl;
	cout<<"To play an easy game, press 1 then enter."<<endl;
	cout<<"To play a hard game, press 2 then enter."<<endl;
	cin>>start;
	if (start==1)
	{
	instructions();
	play(side*side, board);
	}	
	if (start==2)
	{
	instructions();
	playhard(side*side, board);
	}
	return 0;
}
