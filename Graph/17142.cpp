#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;
int n, m;
int visited[51][51];
int arr[51][51];
vector<pair<int, int> > v;
vector<pair<int, int> > act;
int answer = 987654321;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(int idx, int cnt){
    if(cnt == m){
        memset(visited, false, sizeof(visited));
        queue<pair<int, int> > q;
        int tmp = 0;

        for(int i=0; i<act.size(); i++){
            visited[act[i].first][act[i].second] = 1;
            q.push(make_pair(act[i].first, act[i].second));
        }

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if(arr[x][y] == 0)
                tmp = max(tmp, visited[x][y]-1);

            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx < 0 || ny < 0 || nx >= n || ny >= n || arr[nx][ny] == 1) continue;
                if(!visited[nx][ny]){
                    q.push(make_pair(nx, ny));
                    visited[nx][ny] = visited[x][y] + 1;
                }
            }
        }

        for(int i=0; i<n; i++){ // 0이 살아남았는지 검토
            for(int j=0; j<n; j++){
                if(arr[i][j] == 0 && !visited[i][j]) return;
            }
        }

        answer = min(answer, tmp);
        return;
    }

    for(int i=idx; i<v.size(); i++){
        act.push_back(v[i]);
        dfs(i+1, cnt+1);
        act.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 2) v.push_back(make_pair(i, j));
        }
    }

    dfs(0, 0);
    cout << ((answer == 987654321) ? -1 : answer);
    return 0;
}
