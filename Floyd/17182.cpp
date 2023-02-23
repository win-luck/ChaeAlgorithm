#include <iostream>

using namespace std;
int n, k, result;
int d[11][11];
bool visited[11];

void DFS(int idx, int dist, int cnt){ // 최소 시간 출력 (백트래킹)
    if(cnt == n){ // 모든 행성을 탐사한 경우
        result = min(result, dist); // 최솟값 갱신
        return;
    }

    for(int i=0; i<n; i++){
        if(visited[i]) continue;
        visited[i] = true;
        DFS(i, dist + d[idx][i], cnt + 1);
        visited[i] = false;
    }
} // N-queen 문제와 굉장히 유사하다.

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    result = 987654321;

    cin >> n >> k;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> d[i][j];
        }
    } // 입력

    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(d[i][j] > d[i][k] + d[k][j]){
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    } // 플로이드-워셜 알고리즘

    visited[k] = true;
    DFS(k, 0, 1);
    cout << result << '\n';
    return 0;
}