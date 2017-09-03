nclude <bits/stdc++.h>

using namespace std;

string timeConversion(string s) {
    if(strncmp(s.c_str(),"12:00:00",8)==0)
    {
        if(s[8]=='A') return "00:00:00";
        else return "12:00:00";
    }
    
    string t(s,0,8);
    
    if(s[8]=='A')
    {
        t[0]=s[0];
        t[1]=s[1];
    }
    else
    {
        int h = (s[0]-'0')*10 + s[1]-'0' + 12;
        t[0] = '0' + h/10;
        t[1] = '0' + h%10;
    }
    return t;
}

int main() {
    string s;
    cin >> s;
    string result = timeConversion(s);
    cout << result << endl;
    return 0;
}

