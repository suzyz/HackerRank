#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

long long f[40];

long long calc(int n)
{
    if (n < 0)
        return 0;
    if (f[n] >= 0)
        return f[n];
    
    f[n] = calc(n-1) + calc(n-2) + calc(n-3);
    return f[n];
}

int main(){
    int s;
    cin >> s;
    memset(f,-1,sizeof(f));
    f[0] = 1;
    
    for(int a0 = 0; a0 < s; a0++){
        int n;
        cin >> n;
        cout << calc(n) << endl;
    }
    return 0;
}

