#ifndef _algortihm_h_
#define _algorithm_h_

#include <iostream>
#include <stdlib.h>
#include <vector>
#include "board.h"
using namespace std;



class Algorithm{
    vector <int > adjacents;
public:
    char is_adjacent(Board, int, int);
    int evaluation(Board, int, int);
    int minimaxAlphaBeta(Board & board, int depth, bool isMax, int alpha, int beta, int x , int y);
    int AlphaBeta(Board&, int, int, int, int, int, bool);
    vector <int> BestMove(Board);
};
#endif
