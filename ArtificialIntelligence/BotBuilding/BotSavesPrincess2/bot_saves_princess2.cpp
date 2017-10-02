#include <iostream>
#include <vector>
using namespace std;

void locate(int n,vector <string> grid,char target,int &x,int &y)
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (grid[i][j]==target)
            {
                x=i;
                y=j;
                return;
            }
}

void nextMove(int n, int r, int c, vector <string> grid){
    int px,py;
    locate(n,grid,'p',px,py);

    if (r<px)
        cout << "DOWN" << endl;
    else
    if (r>px)
        cout << "UP" << endl;
    else
    if (c<py)
        cout << "RIGHT" << endl;
    else
        cout << "LEFT" << endl;
}

int main(void) {

    int n, r, c;
    vector <string> grid;

    cin >> n;
    cin >> r;
    cin >> c;

    for(int i=0; i<n; i++) {
        string s; cin >> s;
        grid.push_back(s);
    }

    nextMove(n, r, c, grid);
    return 0;
}

