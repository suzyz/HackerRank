#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> calories(n);
    for(int calories_i = 0; calories_i < n; calories_i++){
       cin >> calories[calories_i];
    }
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(calories[j]<calories[j+1])
            {
                int tmp=calories[j]; calories[j]=calories[j+1]; calories[j+1]=tmp;
            }

    long long ans=0,w=1;
    for(int i=0;i<n;i++)
    {
        ans+=w*calories[i];
        w<<=1;
    }
    cout<<ans<<endl;
    return 0;
}
