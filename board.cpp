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
    cout<<"  ";
    for(int i = 0; i < N; i++)
        cout <<i << " ";
    cout << endl;
    for(int i = 0; i < N; i++)
    {
        cout<< i << " ";
        for(int j = 0; j < N; j++)
            cout << board[i][j] << " ";
        cout<<endl;
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
                    if(abs(O_count - O_countUP) == 5)
                        return 1;

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
                    while(GetValue(x, y-k) == 'X')
                    {
                        X_count++;
                        k++;
                    }
                    if(abs(X_count - X_countUP) == 5)
                        return 1;
                }
        //caut pe verticala
        if(GetValue(x+1, y) != '-' || GetValue(x-1, y) != '-')
            if(GetValue(x+1, y) == 'O' || GetValue(x-1, y) == 'O')
            {
                O_count = 0, O_countUP = 0;
                k = 1;
                while(GetValue(x+k,y) == 'O')
                {
                    O_countUP++;
                    k++;
                }
                k = 1;
                while(GetValue(x-k, y) == 'O')
                {
                    O_count++;
                    k++;
                }
                if(abs(O_count - O_countUP) == 5)
                        return 1;

            }
            else
            {
                X_count = 0, X_countUP = 0;
                k = 1;
                while(GetValue(x+k,y) == 'X')
                {
                    X_countUP++;
                    k++;
                }
                k = 1;
                while(GetValue(x-k, y) == 'X')
                {
                    X_count++;
                    k++;
                }
                if(abs(X_count - X_countUP) == 5)
                    return 1;

            }
        //Caut pe diagonala
        if(GetValue(x+1, y+1) != '-' || GetValue(x-1, y-1) != '-')
            if(GetValue(x+1, y+1) == 'O' || GetValue(x-1, y-1) == 'O')
            {
                O_count = 0, O_countUP = 0;
                k = 1;
                while(GetValue(x+k,y+k) == 'O')
                {
                    O_countUP++;
                    k++;
                }
                k = 1;
                while(GetValue(x-k, y-k) == 'O')
                {
                    O_count++;
                    k++;
                }
                if(abs(O_count - O_countUP) == 5)
                    return 1;
            }
            else
            {
                X_count = 0, X_countUP = 0;
                k = 1;
                while(GetValue(x+k,y+k) == 'X')
                {
                    X_countUP++;
                    k++;
                }

                k = 1;
                while(GetValue(x-k, y-k) == 'X')
                {
                    X_count++;
                    k++;
                }
                if(abs(X_count - X_countUP) == 5)
                    return 1;
            }
        }

}
