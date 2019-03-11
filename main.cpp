#include <iostream>
#include <fstream>
#include <conio.h>
#include "board.h"
#include "algorithm.h"
using namespace std;

int main()
{
    Board masa;
    Algorithm brain;
    masa.Print();
    cout<<endl;
    int x, y,n;
    ifstream f("input.in");
    while(masa.Win() == 0)
    {
        masa.Print();
        cout<<"E randul tau";cin>>x>>y;
        masa.SetValue(x,y,'O');
        masa.Print();
        vector <int> next;
        cout<<endl<<"Ma gandesc...";
        next = brain.BestMove(masa);
        masa.SetValue(next[0],next[1],'X');
    }
    int numar=0;
    cout<<masa.Win();
    brain.BestMove(masa);

    return 0;
}
