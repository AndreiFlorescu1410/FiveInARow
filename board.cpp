#include <iostream>
#include "board.h"
#include "algorithm.h"
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

bool Board::Win()
{
    int k = 0, i, j, O_count, O_countUP, X_count, X_countUP;
    for(int x = 0; x < N; x++)
        for(int y = 0; y < N; y++)

        {
            if(GetValue(x, y+1) != '-' || GetValue(x, y-1) != '-')
                if(GetValue(x, y+1) == 'O' || GetValue(x, y-1) == 'O')
                {
                    O_count = 0, O_countUP = 0;
                    k = 1;
                    while(GetValue(x,y+k) == 'O')
                    {
                        O_countUP++;
                        k++;
                    }
                    k = 1;
                    while(GetValue(x, y-k) == 'O')
                    {
                        O_count++;
                        k++;
                    }

                }
                else
                {
                    X_count = 0, X_countUP = 0;
                    k = 1;
                    while(GetValue(x,y+k) == 'X')
                    {
                        X_countUP++;
                        k++;
                    }
                    k = 1;
                    while(board.GetValue(x, y-k) == 'X')
                    {
                        X_count++;
                        k++;
                    }
                }
        //caut pe verticala
        if(board.GetValue(x+1, y) != '-' || board.GetValue(x-1, y) != '-')
            if(board.GetValue(x+1, y) == 'O' || board.GetValue(x-1, y) == 'O')
            {
                O_count = 0, O_countUP = 0;
                k = 1;
                capped_up = 0, capped_down = 0;
                while(board.GetValue(x+k,y) == 'O')
                {
                    O_countUP++;
                    k++;
                }
                k = 1;
                while(board.GetValue(x-k, y) == 'O')
                {
                    O_count++;
                    k++;
                }

            }
            else
            {
                X_count = 0, X_countUP = 0;
                k = 1;
                capped_up = 0, capped_down = 0;
                cout<<board.GetValue(x+k,y);
                while(board.GetValue(x+k,y) == 'X')
                {
                    cout<<"dreapta ";
                    X_countUP++;
                    k++;
                }
                k = 1;
                while(board.GetValue(x-k, y) == 'X')
                {
                    cout<<"stanga ";
                    X_count++;
                    k++;
                }

            }
        //Caut pe diagonala
        if(board.GetValue(x+1, y+1) != '-' || board.GetValue(x-1, y-1) != '-')
            if(board.GetValue(x+1, y+1) == 'O' || board.GetValue(x-1, y-1) == 'O')
            {
                O_count = 0, O_countUP = 0;
                k = 1;
                capped_up = 0, capped_down = 0;
                while(board.GetValue(x+k,y+k) == 'O')
                {
                    O_countUP++;
                    k++;
                }
                k = 1;
                while(board.GetValue(x-k, y-k) == 'O')
                {
                    O_count++;
                    k++;
                }
            }
            else
            {
                X_count = 0, X_countUP = 0;
                k = 1;
                capped_up = 0, capped_down = 0;
                while(board.GetValue(x+k,y+k) == 'X')
                {
                    cout<< "Up ";
                    X_countUP++;
                    k++;
                }

                k = 1;
                while(board.GetValue(x-k, y-k) == 'X')
                {
                    cout<< "down ";
                    X_count++;
                    k++;
                }
            }

}
