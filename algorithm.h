#include <iostream>
#include <stdlib.h>
#include <vector>
#include "board.h"
using namespace std;


#define antet {system("CLS");cout<<"       Proiect 1 OOP -- liste circulare(alocate dinamic) -- Florescu Andrei Gr. 212         "<<endl<<endl;}

class Algorithm{
    vector <int > adjacents;
public:
    char is_adjacent(Board, int, int);
    int evaluation(Board, int, int);
};
