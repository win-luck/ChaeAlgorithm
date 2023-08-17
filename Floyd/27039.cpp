#include <iostream>
#include <vector>
#include <algorithm>

#define INF 987654321
using namespace std;
int s, n, m;
int dist[801][801];
vector<int> v;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> s >> n >> m;
    for(int i=0; i<s; i++){
        int a;
        cin >> a;
        v.push_back(a);
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }

    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = c;
        dist[b][a] = c;
    }

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int ans = INF;
    int len = v.size();
    for(int i=1; i<=n; i++){
        int sum = 0;
        for(int j=0; j<len; j++){
            sum += dist[i][v[j]];
        }
        ans = min(ans, sum);
    }
    cout << ans;
    return 0;
}
