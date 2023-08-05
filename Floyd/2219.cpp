#include <iostream>
#include <vector>
#include <algorithm>

#define INF 1000000
using namespace std;
int n, m;
int a, b, c;
int dp[201][201];

bool cmp(pair<int, int> p1, pair<int, int> p2){
    if(p1.first == p2.first){
        return p1.second < p2.second;
    }
    return p1.first < p2.first;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            if(i == j) dp[i][j] = 0;
            else dp[i][j] = INF;
        }
    }

    for(int i=0; i<m; i++){
        cin >> a >> b >> c;
        dp[a][b] = c;
        dp[b][a] = c;
    }

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    vector<pair<int, int> > v;
    for(int i=1; i<=n; i++){
        int tmp = 0;
        for(int j=1; j<=n; j++){
            tmp += dp[i][j];
        }
        v.push_back(make_pair(tmp, i));
    }
    sort(v.begin(), v.end(), cmp);
    cout << v.front().second << '\n';
    return 0;
}