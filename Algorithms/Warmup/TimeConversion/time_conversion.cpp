#include <iostream>
#include <cstring>

using namespace std;

string timeConversion(string s) {
    
    string t(s,0,8);

    int h = (s[0]-'0')*10 + s[1]-'0';
    
    if(s[8]=='A' && h==12)
        h=0;
    else
    if(s[8]=='P' && h<12)
        h+=12;

    t[0] = '0' + h/10;
    t[1] = '0' + h%10;

    return t;
}

int main() {
    string s;
    cin >> s;
    string result = timeConversion(s);
    cout << result << endl;
    return 0;
}

