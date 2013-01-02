#include <iostream>
#include <cstdio>
#include <assert.h>
using std::endl;
using std::cout;

const int ChessBoardLen = 8;
const int StartValue = 9;
int g_Tried = 0;
int g_Failed = 0;


/*
 knight moves!
    8---1
      |
 7    |    2
 |---------|
 6    |	   3
      |
    5---4

*/

//We can find last move by this formula
int lastMove( const int &n )
{
	// we have 8 moves! so <=> 0 < n < 9
	int d = n >= 5 ? -4 : 4 ;
	return ( n + d );
}

//printing chessboard
template<int N>
void print( int board[N][N] )
{
	cout << "\t";
	for(int i =0; i < N; ++i )
		cout << i <<"  ";
	cout << "\n\n";
	for ( int i=0; i < N; ++i )
	{
		cout << i << ":\t";
		for ( int j= 0; j < N; ++j )
			cout << board[i][j] << "  ";
		cout << endl;
	}
	cout << "\n\n";
}

//checking if is x , y real?!
template<int N>
bool isMovable(const int &x, const int &y)
{
	++ g_Tried;
	if ( ( x < N &&  x >= 0 ) && ( y < N &&  y >= 0 ) )
		return true;
	++ g_Failed;
	return false;
}


static				//1  2   3  4  5   6  7  8	
int Moves[2][8] = { { 1, 2, 2, 1, -1, -2, -2, -1}, //x
                    {-2, -1, 1, 2, 2,  1, -1, -2} };//y



void findPosByMove(int &x, int &y, int move)
{
#define X_INDEX 0
#define Y_INDEX 1

// move is 1..8 but we need to use it as a index for Moves[0..7]

	x += Moves[X_INDEX][move-1];
	y += Moves[Y_INDEX][move-1];
}

template<int N>
int findNextMove( int &x, int &y, const int board[N][N] )
{
	const int cx = x;
	const int cy = y;
	int move = 1;
	for (  ; move <= 8; ++move )
	{
		findPosByMove(x, y, move);
		
		if ( board[y][x] == 0 && isMovable<N>( x, y ) ) 
			return move;

		x = cx;
		y = cy;
	}

	move = lastMove(board[y][x]);
	findPosByMove(x, y, move);
	
	// not cool! we gotta find something in that above loop

	return (board[y][x] == StartValue) ? StartValue : findNextMove(x, y, board); 
}


int main()
{
	int chess_board[ChessBoardLen][ChessBoardLen] = {0};

	//start from
	int x = 0, y = 0;

	chess_board[y][x] = StartValue;

	int move = 0;
	int i = 0;

	do {
		move = findNextMove(x, y, chess_board);
		chess_board[y][x] = move;
		++i;
	} while ( chess_board[y][x] != StartValue );

	print(chess_board);

	cout << "Filled  " << i << " squares." << endl;
	printf("Tried %d and failed %d.\n" , g_Tried, g_Failed);
	return 0;
}
