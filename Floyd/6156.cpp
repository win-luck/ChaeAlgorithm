#include <iostream>

#define INF 100000
using namespace std;
int n, m;
int dist[101][101];

int main(){
    for(int i=0; i<=100; i++){
        for(int j=0; j<=100; j++){
            if(i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }

    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        dist[a][b] = 0;
    }

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }


    int cnt = 0;
    for(int i=1; i<=n; i++){
        int res = 0;
        for(int j=1; j<=n; j++){
            if(i == j) continue;
            if(!dist[i][j] || !dist[j][i]){ // 순위가 특정되는 횟수가 n-1번이면 순위가 명백하게 결정된다.
                res++;
            }
        }
        if(res == n-1) cnt++;
    }
    
    cout << cnt << '\n';
    return 0;
}