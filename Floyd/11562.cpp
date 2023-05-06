#include <iostream>
#include <cstring>
#include <vector>

#define INF 10000
using namespace std;

int u, v, b;
int cnt;
int n, m;
int dist[251][251];
vector<int> vec;

int main(){
    cin >> n >> m;
    memset(dist, INF, sizeof(dist));
    for(int i=0; i<m; i++){
        cin >> u >> v >> b;
        dist[u][v] = 0;
        if(b) dist[v][u] = 0;
        else dist[v][u] = 1; // 길을 양방향으로 바꾸는 비용 1
    }

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(i == j) dist[i][j] = 0;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    cin >> cnt;
    for(int i=0; i<cnt; i++){
        cin >> u >> v;
        vec.push_back(dist[u][v]);
    }

    for(int i=0; i<vec.size(); i++){
        cout << vec[i] << '\n';
    }
    return 0;
}