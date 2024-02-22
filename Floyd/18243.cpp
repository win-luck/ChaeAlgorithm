#include <iostream>
#include <vector>

#define INF 987654321
using namespace std;
int n, K;
int dist[101][101];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> K;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }
    
    for(int i=1; i<=K; i++){
        int a, b;
        cin >> a >> b;
        dist[a][b] = 1;
        dist[b][a] = 1;
    }

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    bool flag = true;
    for(int i=1; i<n; i++){
        for(int j=i+1; j<=n; j++){
            if(dist[i][j] >= 7){
                flag = false;
                break;
            }
        }
    }
    cout << (flag ? "Small World!" : "Big World!");
    return 0;
}
