#include <iostream>
#include "board.h"
using namespace std;

void Board::Clear()
{
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            board[i][j] = '-';
}

Board::Board()
{
    Clear();
}

void Board::Print()
{
    antet
    for(int i = 0; i < N; i++)
        cout <<char(65+i) << " ";
    cout << endl;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
            cout << board[i][j] << " ";
        cout << " " << char(65+i) << endl;
    }
}

void Board::SetValue(int x, int y, char c)
{
    board[x][y] = c;
}

char Board::GetValue(int x, int y)
{
    return board[x][y];
}
