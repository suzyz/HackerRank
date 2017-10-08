#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int maxn = 100010;

int n,arr[maxn],aux[maxn];

long long merge(int (&s)[maxn],int (&t)[maxn],int st,int mid,int en)
{
    int i = st, j = mid+1, idx = st;
    long long res = 0;
    while (i<=mid && j<=en)
    {
        if (s[i] <= s[j])
            t[idx++] = s[i++];
        else
        {
            t[idx++] = s[j++];
            res += mid+1 - i;
        }
    }

    while (i<=mid)
    {
        t[idx++] = s[i++];
    }
    while (j<=en)
    {
        t[idx++] = s[j++];
    }
    return res;
}

long long merge_sort(int (&s)[maxn],int (&t)[maxn],int st,int en)
{
    if (st >= en)
        return 0;

    long long count = 0;
    int mid = st + ((en-st)>>1);
    count += merge_sort (t,s,st,mid);
    count += merge_sort (t,s,mid+1,en);

    count += merge(s,t,st,mid,en);
    return count;
}

int main() {
    
    int Q;
    cin >> Q;

while (Q--)
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
        aux[i] = arr[i];
    }
    
    cout << merge_sort(arr,aux,0,n-1) << endl;
}

    return 0;
}
