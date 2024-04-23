#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int map[11][11];
bool visited[11][11];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int n, m, k;
int answer = -987654321;

void dfs(int cnt, int sum){
    if(cnt == k){
        answer = max(answer, sum);
        return;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(visited[i][j]) continue;
            bool flag = false;
            for(int a=0; a<4; a++){
                int ni = i + dx[a];
                int nj = j + dy[a];
                if(visited[ni][nj]){
                    flag = true;
                    break;
                }
            }
            if(flag) continue;

            visited[i][j] = true;
            dfs(cnt+1, sum + map[i][j]);
            visited[i][j] = false;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
        }
    }
    dfs(0, 0);
    cout << answer;
    return 0;
}
