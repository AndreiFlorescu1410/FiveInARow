#include <iostream>
#include <fstream>
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
    f>>n;
    for(int i=1;i<=n;i++)
    {
        f>>x>>y;
        masa.SetValue(x,y,'X');
        masa.Print();
    }
    brain.evaluation(masa,5,10);
    return 0;
}
