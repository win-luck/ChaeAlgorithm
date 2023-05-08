#include <iostream>
#include <cstring>

#define INF 1000000001
using namespace std;
int a, b, c;
int n, m;
long long dist[501][501];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(dist, INF, sizeof(dist)); // 초기화

    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> dist[i][j];
        }
    }

    for(int k=1; k<=n; k++){ // 플로이드-워셜 기본 문제
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for(int i=0; i<m; i++){
        cin >> a >> b >> c;
        if(dist[a][b] <= c){
            cout << "Enjoy other party" << '\n';
        } else {
            cout << "Stay here" << '\n';
        }
    }
    return 0;
}