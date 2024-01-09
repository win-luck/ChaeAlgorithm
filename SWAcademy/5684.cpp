#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

#define INF 4000001
using namespace std;
int n, m, t;
int dist[401][401];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    for(int a=1; a<=t; a++){
        cin >> n >> m;
        memset(dist, INF, sizeof(dist));

        for(int i=1; i<=m; i++){
            int s, e, c;
            cin >> s >> e >> c;
            dist[s][e] = c;
        }

        for(int k=1; k<=n; k++){
            for(int i=1; i<=n; i++){
                for(int j=1; j<=n; j++){
                    if(dist[i][k] + dist[k][j] < dist[i][j]){
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
        long long answer = INF;
        for(int i=1; i<=n; i++){
            if(dist[i][i] < answer){
                answer = dist[i][i];
            }
        }
        cout << "#" << a << " " << answer << '\n';
    }
    return 0;
}