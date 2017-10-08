#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

struct Player {
    string name;
    int score;
}; 

class Checker
{
public:
    static bool cmp(const Player &a,const Player &b)
    {
        if (a.score > b.score)
            return true;
        if (a.score < b.score)
            return false;
        
        return (a.name.compare(b.name) < 0);
    }
};

vector<Player> comparator(vector<Player> players) {
    vector<Player> ans = players;
    Checker ch;
    
    sort(ans.begin(),ans.end(),ch.cmp);
    return ans;
}

int main() {
    
    int n;
    cin >> n;
    vector< Player > players;
    string name;
    int score;
    for(int i = 0; i < n; i++){
        cin >> name >> score;
        Player p1;
        p1.name = name, p1.score = score;
        players.push_back(p1);
    }
    
    vector<Player > answer = comparator(players);
    for(int i = 0; i < answer.size(); i++) {
        cout << answer[i].name << " " << answer[i].score << endl;
    }
    return 0;
}
