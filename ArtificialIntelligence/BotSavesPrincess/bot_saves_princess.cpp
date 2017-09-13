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

void displayPathtoPrincess(int n, vector <string> grid){
    int mx,my,px,py;

    locate(n,grid,'m',mx,my);
    locate(n,grid,'p',px,py);

    int len;
    string move;
    if(mx<px)
    {
        len = px-mx;
        move = "DOWN";
    }
    else
    {
        len = mx-px;
        move = "UP";
    }

    for (int i = 0; i < len; ++i)
        cout<<move<<endl;

    if(my<py)
    {
        len = py-my;
        move = "RIGHT";
    }
    else
    {
        len = my-py;
        move = "LEFT";
    }

    for (int i = 0; i < len; ++i)
        cout<<move<<endl;

}
int main(void) {

    int m;
    vector <string> grid;

    cin >> m;

    for(int i=0; i<m; i++) {
        string s; cin >> s;
        grid.push_back(s);
    }

    displayPathtoPrincess(m,grid);

    return 0;
}
