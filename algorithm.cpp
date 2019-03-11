#include <iostream>
#include "algorithm.h"
using namespace std;

char Algorithm::is_adjacent(Board board, int x, int y)
{
    if(board.GetValue(x+1, y) != 'X' || board.GetValue(x+1, y+1) != 'X' || board.GetValue(x+1, y-1) != 'X' || board.GetValue(x, y-1) != 'X' || board.GetValue(x, y+1) != 'X' || board.GetValue(x-1, y-1) != 'X' || board.GetValue(x-1, y) != 'X'|| board.GetValue(x-1, y+1) != 'X')
        return 'X';
    else if(board.GetValue(x+1, y) != 'O' || board.GetValue(x+1, y+1) != 'O' || board.GetValue(x+1, y-1) != 'O' || board.GetValue(x, y-1) != 'O' || board.GetValue(x, y+1) != 'O' || board.GetValue(x-1, y-1) != 'O' || board.GetValue(x-1, y) != 'O'|| board.GetValue(x-1, y+1) != 'O')
        return 'O';
    return '0';
}
int Algorithm::evaluation(Board board, int x, int y)
{
    int k = 0, i, j, O_count, O_countUP, X_count, X_countUP;
    int O_patterns[8] = {0}, X_patterns[7] = {0}, pattern_value;
    bool capped_up, capped_down;
    //caut pe orizontala
    if(board.GetValue(x, y+1) != '-' || board.GetValue(x, y-1) != '-')
        if(board.GetValue(x, y+1) == 'O' || board.GetValue(x, y-1) == 'O')
        {
            O_count = 0, O_countUP = 0;
            k = 1;
            capped_up = 0, capped_down = 0;
            while(board.GetValue(x,y+k) == 'O')
            {
                O_countUP++;
                k++;
            }
            k = 1;
            while(board.GetValue(x, y-k) == 'O')
            {
                O_count++;
                k++;
            }
            if(board.GetValue(x,y+k) == 'X')
                capped_up = 1;
            if(board.GetValue(x,y-k) == 'X')
                capped_down = 1;
            if(!(capped_down == capped_up && capped_down == 1))
            {
                pattern_value = abs(O_count - O_countUP);
                if(capped_down == 1 || capped_up == 1)
                    O_patterns[pattern_value+3]++;
                else
                    O_patterns[pattern_value]++;
            }

        }
        else
        {
            X_count = 0, X_countUP = 0;
            k = 1;
            capped_up = 0, capped_down = 0;
            while(board.GetValue(x,y+k) == 'X')
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
            if(board.GetValue(x,y+k) == 'O')
                capped_up = 1;
            if(board.GetValue(x,y-k) == 'O')
                capped_down = 1;
            if(!(capped_down == capped_up && capped_down == 1))
            {
                pattern_value = abs(X_count - X_countUP);
                if(capped_down == 1 || capped_up == 1)
                    X_patterns[pattern_value+3]++;
                else
                    X_patterns[pattern_value]++;
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
            if(board.GetValue(x+k,y) == 'X')
                capped_up = 1;
            if(board.GetValue(x-k,y) == 'X')
                capped_down = 1;
            if(!(capped_down == capped_up && capped_down == 1))
            {
                pattern_value = abs(O_count - O_countUP);
                if(capped_down == 1 || capped_up == 1)
                    O_patterns[pattern_value+3]++;
                else
                    O_patterns[pattern_value]++;
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
            if(board.GetValue(x+k,y) == 'O')
                capped_up = 1;
            if(board.GetValue(x-k,y) == 'O')
                capped_down = 1;
            if(!(capped_down == capped_up && capped_down == 1))
            {
                pattern_value = abs(X_count - X_countUP);
                if(capped_down == 1 || capped_up == 1)
                    X_patterns[pattern_value+3]++;
                else
                    X_patterns[pattern_value]++;
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
            if(board.GetValue(x+k,y+k) == 'X')
                capped_up = 1;
            if(board.GetValue(x-k,y-k) == 'X')
                capped_down = 1;
            if(!(capped_down == capped_up && capped_down == 1))
            {
                pattern_value = abs(O_count - O_countUP);
                if(capped_down == 1 || capped_up == 1)
                    O_patterns[pattern_value+3]++;
                else
                    O_patterns[pattern_value]++;
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
            if(board.GetValue(x+k,y+k) == 'O')
                capped_up = 1;
            if(board.GetValue(x-k,y-k) == 'O')
                capped_down = 1;
            if(!(capped_down == capped_up && capped_down == 1))
            {
                pattern_value = abs(X_count - X_countUP);
                if(capped_down == 1 || capped_up == 1)
                    X_patterns[pattern_value+3]++;
                else
                    X_patterns[pattern_value]++;
            }
        }
    cout<<"Pentru O avem: ";
    int sum=0, sum_O, sum_X;
    sum_O = 150*O_patterns[0] + 100*O_patterns[1] + 150*O_patterns[2] + 10*O_patterns[3] + 1000*O_patterns[4] + 150*O_patterns[5] + 1*O_patterns[6];
    cout<<sum_O<<endl;
    cout<<"Pentru X avem: ";
    sum_X = 150*X_patterns[0] + 100*X_patterns[1] + 150*X_patterns[2] + 10*X_patterns[3] + 1000*X_patterns[4] + 150*X_patterns[5] + 1*X_patterns[6];
    cout<<sum_X;
}
