#include <iostream>
#include <cstring>

using namespace std;
int n, m;
double dist[101][101];

void floyd(){
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(dist[i][j] < dist[i][k] * dist[k][j]){
                    dist[i][j] = dist[i][k] * dist[k][j];
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while(1){
        cin >> n;
        if(n == 0) break;
        cin >> m;
        memset(dist, 0, sizeof(dist));

        for(int i=1; i<=m; i++){
            int a, b;
            double c;
            cin >> a >> b >> c;
            dist[a][b] = c / 100;
            dist[b][a] = c / 100;
        }
        floyd();
        
        cout.precision(6);
        cout << fixed;
        cout << dist[1][n] * 100 << " percent\n";
    }
    return 0;
}
