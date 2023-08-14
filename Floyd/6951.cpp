#include <iostream>
#include <algorithm>
#include <vector>

#define INF 987654321
using namespace std;
int n, w, p;
int dist[101][101];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> w >> p;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }

    for(int i=0; i<w; i++){
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

    for(int i=0; i<p; i++){
        int a, b;
        cin >> a >> b;
        cout << dist[a][b] << '\n';
    }
    return 0;
}