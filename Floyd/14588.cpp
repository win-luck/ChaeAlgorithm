#include <iostream>
#include <algorithm>
#include <vector>

#define INF 987654321
using namespace std;
int dist[301][301];
int n, m;
pair<int, int> arr[301];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }

    for(int i=1; i<=n; i++){
        int a, b;
        cin >> a >> b;
        arr[i].first = a;
        arr[i].second = b;
    }

    for(int i=1; i<n; i++){
        for(int j=i+1; j<=n; j++){
            if(arr[i].second >= arr[j].first && arr[j].second >= arr[i].first){
                dist[i][j] = 1;
                dist[j][i] = 1;
            }
        }
    }

    for(int k=1; k<=n; k++){ // 플로이드-워셜
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    cin >> m;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        if(dist[a][b] == INF){
            cout << -1 << '\n';
        } else {
            cout << dist[a][b] << '\n';
        }
    }
    return 0;
}
