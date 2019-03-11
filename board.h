#ifndef _board_h_
#define _board_h_
#include <iostream>
#include <stdlib.h>
using namespace std;

#define antet {system("CLS");cout<<"       Proiect 1 OOP -- liste circulare(alocate dinamic) -- Florescu Andrei Gr. 212         "<<endl<<endl;}

const int N = 15;

class Board{
    char board[N][N];
public:
    void Clear();
    void Print();
    void SetValue(int, int, char);
    char GetValue(int, int);
    bool Win();

    Board();

};
#endif
