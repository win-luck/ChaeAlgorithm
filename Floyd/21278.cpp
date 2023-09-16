#include <iostream>
#include <algorithm>
#include <cstring>

#define INF 987654321
using namespace std;
int dist[101][101];
int n, m;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }

    for(int i=1; i<=m; i++){
        int a, b;
        cin >> a >> b;
        dist[a][b] = 1;
        dist[b][a] = 1;
    }

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(i == j) continue;
                dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
            }
        }
    }

    int answer = INF;
    int first = 0;
    int second = 0;
    for(int i=1; i<n; i++){
        for(int j=i+1; j<=n; j++){
            int sum = 0;
            for(int k=1; k<=n; k++){
                sum += min(dist[i][k], dist[j][k]);
            }

            if(answer > sum){
                answer = sum;
                first = i;
                second = j;
            }
        }
    }
    cout << first << " " << second << " " << answer * 2 << '\n';
    return 0;
}
