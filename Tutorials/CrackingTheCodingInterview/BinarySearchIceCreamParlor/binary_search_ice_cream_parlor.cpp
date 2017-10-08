#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int m,n;
int price[10010],idx[10010];

int binary_search(int st,int target)
{
    int l = st, r = n-1;
    while (l<r)
    {
        int mid = l + ((r-l)>>1);
        if (price[idx[mid]] == target)
            r = mid;
        else
        if (price[idx[mid]] < target)
            l = mid+1;
        else
            r = mid-1;
    }
    if (l < n && price[idx[l]] == target)
        return idx[l];
    else
        return -1;
}

bool cmp(int a,int b)
{
    if (price[a]<price[b])
        return true;
    if (price[a]>price[b])
        return false;
    return a<b;
}

int main() {
    
    int Q;
    cin >> Q;

while (Q--)
{
    cin >> m >> n;
    for (int i = 0; i < n; ++i)
    {
        idx[i] = i;
        cin >> price[i];
    }
    
    sort(idx,idx+n,cmp);

    for (int i = 0; i < n-1; ++i)
    {
        if (price[idx[i]] >= m)
            break;

        int x = binary_search(i + 1, m - price[idx[i]]);
        if (x < 0)
            continue;
        if (idx[i] < x)
            cout << idx[i] + 1 << " " << x+1 << endl;
        else
            cout << x + 1 << " " << idx[i]+1 << endl;
        break;
    }
}

    return 0;
}
