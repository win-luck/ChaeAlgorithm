#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
int n, m;
int dx[8] = {1, 1, 2, 2, -1, -1, -2, -2};
int dy[8] = {2, -2, 1, -1, 2, -2, -1, 1};
int visited[501][501];
vector<pair<int, int> > v;
vector<int> answer;
pair<int, int> s;

void BFS(int sx, int sy){
    queue<pair<int, int> > q;
    visited[sx][sy] = 1;
    q.push(make_pair(sx, sy));

    while(!q.empty()){
        pair<int, int> now = q.front();
        q.pop();

        for(int i=0; i<8; i++){
            int nx = now.first + dx[i];
            int ny = now.second + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if(!visited[nx][ny]){
                visited[nx][ny] = visited[now.first][now.second] + 1;
                q.push(make_pair(nx, ny));
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    cin >> s.first >> s.second;
    BFS(--s.first, --s.second);
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        answer.push_back(visited[a-1][b-1] - 1);
    }
    for(int i=0; i<answer.size(); i++){
        cout << answer[i] << " ";
    }
    return 0;
}
