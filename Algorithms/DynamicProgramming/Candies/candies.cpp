#include <bits/stdc++.h>

using namespace std;

int f[100002];

long long candies(int n, vector <int> arr) {
    
    if(n==1) return 1;
    
    for(int i=0;i<n;i++)
    if((i==0 && arr[0]<=arr[1]) || (i==n-1 && arr[n-1]<=arr[n-2]) || (arr[i]<=arr[i-1] && arr[i]<=arr[i+1]))
           {
               f[i]=1;
               int j=i-1,k=2;
               while(j>=0 && arr[j]>arr[j+1])
               {
                   f[j]=max(f[j],k);
                   k++;
                   j--;
               }
               j=i+1,k=2;
               while(j<n && arr[j]>arr[j-1])
               {
                   f[j]=max(f[j],k);
                   k++;
                   j++;
               }
           }
    
    long long ans=0;
    for(int i=0;i<n;i++)
        ans+=f[i];
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    cout << candies(n, arr) << endl;
    return 0;
}

