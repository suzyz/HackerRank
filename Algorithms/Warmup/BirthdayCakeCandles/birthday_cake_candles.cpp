#include <bits/stdc++.h>

using namespace std;

int birthdayCakeCandles(int n, vector <int> ar) {
    int maxh = ar[0];
    int sum = 1;
    
    for(int i=1;i<n;i++)
        if(ar[i]==maxh)
            sum++;
        else
        if(ar[i]>maxh)
        {
            maxh=ar[i];
            sum=1;
        }
    
    return sum;
}

int main() {
    int n;
    cin >> n;
    vector<int> ar(n);
    for(int ar_i = 0; ar_i < n; ar_i++){
       cin >> ar[ar_i];
    }
    int result = birthdayCakeCandles(n, ar);
    cout << result << endl;
    return 0;
}

