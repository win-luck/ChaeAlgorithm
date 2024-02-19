#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, y, m;
vector<pair<int, int> > v;
int dp[120001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    fill(dp, dp+120001, 0);

    cin >> n;
    for(int i=1; i<=n; i++){
        string s, e;
        cin >> s >> e;
        int news = stoi(s.substr(0, 4)) * 12 + stoi(s.substr(5));
        int newe = stoi(e.substr(0, 4)) * 12 + stoi(e.substr(5));
        dp[news]++; // 입대일
        dp[newe+1]--; // 전역일 다음
    }
    sort(v.begin(), v.end());

    int maxval = 0;
    for(int i=24001; i<120001; i++){ // 2000년 1월 ~ 9999년 12월
        dp[i] += dp[i-1];
        if(dp[i] > maxval){ // 군인 수 최대
            maxval = dp[i];
            y = i / 12;
            m = i % 12;
        }
    }

    if(m == 0){
        y--;
        m = 12;
    }

    if(m < 10){
        cout << to_string(y) + "-0" + to_string(m);
    } else {
        cout << to_string(y) + "-" + to_string(m);
    }
    return 0;
}
