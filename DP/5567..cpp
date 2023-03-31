#include <iostream>

using namespace std;
int n, m;
bool visited[501];
bool ffriend[501];
int map[501][501];

int main(){
    int cnt = 0;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        map[a][b] = 1;
        map[b][a] = 1;
    }

    for(int i=1; i<=n; i++){
        if(map[1][i]){
            visited[i] = true; // 방문 완료
            ffriend[i] = true; // 최초 친구
        }
    }

    for(int i=2; i<=n; i++){
        if(ffriend[i]){
            for(int j=1; j<=n; j++){
                if(map[i][j]){
                    visited[j] = true; // 친구의 친구
                }
            }
        }
    }

    for(int i=2; i<=n; i++){ // 친구 수
        if(visited[i]) cnt++;
    }
    cout << cnt;
    return 0;
}