#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main() {
    
    int Q;
    cin >> Q;

while (Q--)
{
    int n;
    cin >> n;
    if (n<2)
    {
        cout << "Not prime" << endl;
        continue;
    }
    int lim = sqrt(n);
    bool flag = true;
    for (int i = 2; i <= lim; ++i)
        if (n % i == 0)
        {
            flag = false;
            break;
        }

    if (flag)
        cout << "Prime" << endl;
    else
        cout << "Not prime" << endl;
}

    return 0;
}
