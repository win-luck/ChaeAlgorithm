#include <iostream>
#include <algorithm>
#include <vector>

#define INF 1e9
using namespace std;
int n, m, k, q;
int dist[201][201];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k >> q;
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
    }

    for(int p=1; p<=n; p++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(dist[i][p] + dist[p][j] < dist[i][j]){
                    dist[i][j] = dist[i][p] + dist[p][j];
                }
            }
        }
    }

    int cnt = 0;
    long long sum = 0;
    for(int i=0; i<q; i++){
        int a, b;
        cin >> a >> b;
        int val = INF;
        for(int i=1; i<=k; i++){
            val = min(val, dist[a][i] + dist[i][b]);
        }
        if(val != INF){
            cnt++;
            sum += val;
        }
    }
    cout << cnt << '\n';
    cout << sum;
    return 0;
}
