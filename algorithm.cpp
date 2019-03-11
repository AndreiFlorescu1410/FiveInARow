#include <iostream>
#include <conio.h>
#include "algorithm.h"
using namespace std;

#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))



char Algorithm::is_adjacent(Board board, int x, int y)
{
    if(board.GetValue(x+1, y) == 'X' || board.GetValue(x+1, y+1) == 'X' || board.GetValue(x+1, y-1) == 'X' || board.GetValue(x, y-1) == 'X' || board.GetValue(x, y+1) == 'X' || board.GetValue(x-1, y-1) == 'X' || board.GetValue(x-1, y) == 'X'|| board.GetValue(x-1, y+1) == 'X')
        return 'X';
    else if(board.GetValue(x+1, y) == 'O' || board.GetValue(x+1, y+1) == 'O' || board.GetValue(x+1, y-1) == 'O' || board.GetValue(x, y-1) == 'O' || board.GetValue(x, y+1) == 'O' || board.GetValue(x-1, y-1) == 'O' || board.GetValue(x-1, y) == 'O'|| board.GetValue(x-1, y+1) == 'O')
        return 'O';
    return '0';
}
int Algorithm::evaluation(Board board, int x, int y)
{
    int k = 0, i, j, O_count, O_countUP, X_count, X_countUP;
    int sum_O = 0, sum_X = 0,sum;
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

            if(O_count > 1 || O_countUP > 1)
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
            if(X_count == 1 || X_countUP == 1)
                sum_X++;
            else if(X_count == 2 || X_countUP == 2)
                sum_X+=5;
            if(X_count > 2 || X_countUP > 2)
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
            if(O_count > 1 || O_countUP > 1)
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
            while(board.GetValue(x+k,y) == 'X')
            {
                X_countUP++;
                k++;
            }
            k = 1;
            while(board.GetValue(x-k, y) == 'X')
            {
                X_count++;
                k++;
            }
            if(board.GetValue(x+k,y) == 'O')
                capped_up = 1;
            if(board.GetValue(x-k,y) == 'O')
                capped_down = 1;
            if(X_count == 1 || X_countUP == 1)
                sum_X++;
            else if(X_count == 2 || X_countUP == 2)
                sum_X+=5;
            if(X_count > 2 || X_countUP > 2)
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
            if(O_count > 1 || O_countUP > 1)
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
                X_countUP++;
                k++;
            }

            k = 1;
            while(board.GetValue(x-k, y-k) == 'X')
            {
                X_count++;
                k++;
            }
            if(board.GetValue(x+k,y+k) == 'O')
                capped_up = 1;
            if(board.GetValue(x-k,y-k) == 'O')
                capped_down = 1;
            if(X_count == 1 || X_countUP == 1)
                sum_X++;
            else if(X_count == 2 || X_countUP == 2)
                sum_X+=5;
            if(X_count > 2 || X_countUP > 2)
            {
                pattern_value = abs(X_count - X_countUP);
                if(capped_down == 1 || capped_up == 1)
                    X_patterns[pattern_value+3]++;
                else
                    X_patterns[pattern_value]++;
            }
        }
    sum_O += 150*O_patterns[0] + 100*O_patterns[1] + 150*O_patterns[2] + 10*O_patterns[3] + 1000*O_patterns[4] + 150*O_patterns[5] + 1*O_patterns[6];
    sum_X += 150*X_patterns[0] + 100*X_patterns[1] + 150*X_patterns[2] + 10*X_patterns[3] + 1000*X_patterns[4] + 150*X_patterns[5] + 1*X_patterns[6];
    sum = sum_X - sum_O;
    return sum;
}
//int Algorithm::minimaxAlphaBeta(Board & board, int depth, bool isMax, int alpha, int beta, int x , int y){
//
//    board.SetValue(x,y,((isMax == 1)?('X'):('O')));
////    board.Print();
////    getch();
//	if (board.Win()){
//		board.SetValue(x,y,'-');
//
//        board.Print();
//		cout<<"castig";
//        getch();
//		if (isMax){//computer wins
//			return INT_MAX;
//		}else {
//			return INT_MIN;// player wins, therefore, need to minimize score so computer will not choose this path
//		}
//	}
//	if (depth == 0){
//		int value = 0;
//		value = evaluation(board,x,y);
//		board.SetValue(x,y,'-');
//
////        board.Print();
////		cout<<value;
////        getch();
//		//cout <<"evaluation at "<<x <<" "<<y<< " is "<< value <<endl;
//		return value;
//	}
//
//	//save the X positions of available cells into firstCoord, Y positions of available cells into secondCoord
//	vector<int> firstCoord;
//	vector<int> secondCoord;
//	for (int i = 0; i < N; i++){
//		for (int j = 0; j<N; j++){
//			if (board.GetValue(i,j) == '-' && is_adjacent(board, i, j)!='0'){
//				firstCoord.push_back(i);
//				secondCoord.push_back(j);
//			}
//		}
//	}
//
//	int len = (int) firstCoord.size();
//	if (isMax == true){ // try to minimize because now is player's turn
//		int m = INT_MAX;
//		for (int i = 0; i < len; i++){
//			int temp = minimaxAlphaBeta(board,depth - 1, false, alpha, beta, firstCoord[i], secondCoord[i]);
//			if (m > temp){
//				m = temp;
//			}
//			if (beta > m){
//				beta = m;
//			 }
//			 if (alpha >= beta){
//				break;
//			 }
//		}
//		board.SetValue(x,y,'-');
//
////        board.Print();
////		cout<<m;
////        getch();
//		return m;
//	}else {//try to maximize
//		int M = INT_MIN;
//		for (int i = 0; i < len; i++){
//			int temp = minimaxAlphaBeta(board, depth - 1, true, alpha, beta, firstCoord[i], secondCoord[i]);
//			if (M < temp){
//				M = temp;
//			}
//			if (alpha < M){
//				alpha = M;
//			 }
//			 if (alpha >= beta){
//				break;
//			 }
//		}
//		board.SetValue(x,y,'-');
//
////        board.Print();
////		cout<<M;
////        getch();
//		return M;
//	}
//}


int Algorithm::AlphaBeta(Board &board, int depth, int alpha, int beta, int x, int y, bool maximizingPlayer)
{
    int value;
    board.SetValue(x,y,((maximizingPlayer == 1)?('X'):('O')));
    if(board.Win() == 1)
    {
        board.SetValue(x,y,'-');
        if(maximizingPlayer == 1)

            return INT_MAX;
        else
            return INT_MIN;
    }
    if(depth == 0)
    {
//        board.Print();
//		cout<<x<<" "<<y<<" "<<evaluation(board,x,y);
//        getch();
        value = evaluation(board,x,y);
        board.SetValue(x,y,'-');
        return value;
    }
    vector <int> adjacents_x,adjacents_y;
    int i, j;
    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++)
            if (board.GetValue(i,j) == '-' && is_adjacent(board, i, j) != '0')
            {
                adjacents_x.push_back(i);
                adjacents_y.push_back(j);
            }
    if(maximizingPlayer == 1)
    {
        value = INT_MIN;
        for(i = 0; i < adjacents_x.size(); i++)
        {
            value = MAX(value, AlphaBeta(board, depth-1, alpha, beta, adjacents_x[i], adjacents_y[i], 0));
            alpha = MAX(alpha, value);
            if(alpha >= beta)
                break;
        }
        board.SetValue(x,y,'-');
        return value;
    }
    else
    {
        value = INT_MAX;
        for(i = 0; i < adjacents_x.size(); i++)
        {
            value = MIN(value, AlphaBeta(board, depth-1, alpha, beta, adjacents_x[i], adjacents_y[i], 1));
            alpha = MIN(alpha, value);
            if(alpha >= beta)
                break;
        }////
        board.SetValue(x,y,'-');
        return value;
    }
}

vector <int> Algorithm::BestMove(Board board)
{
    int i, j;
    vector <int> adjacents_x,adjacents_y;
    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++)
            if (board.GetValue(i,j) == '-' && is_adjacent(board, i, j) != '0')
            {
                adjacents_x.push_back(i);
                adjacents_y.push_back(j);
            }
    int best = AlphaBeta(board,3,INT_MIN,INT_MAX,adjacents_x[i],adjacents_y[i],0), best_i, best_j;
    int value=0;
    for(i = 0; i < adjacents_x.size(); i++)
    {
        value = AlphaBeta(board,3,INT_MIN,INT_MAX,adjacents_x[i],adjacents_y[i],0);
        //value = AlphaBeta(board, 3, INT_MIN, INT_MAX, adjacents_x[i], adjacents_y[i],0);
        //cout << adjacents_x[i] << " " << adjacents_y[i] << " " << value<< " " << evaluation(board, adjacents_x[i],adjacents_y[i])<<endl;

        if (value <= best)
        {
            best = value;
            best_i = adjacents_x[i];
            best_j = adjacents_y[i];
        }
    }
    vector <int> re;

    re.push_back(best_i);
    re.push_back(best_j);
    return re;


}
