#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

char map[101][101];
bool visited[101][101];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int answer = 0;
int sx, sy, ex, ey, n, m;

void BFS(int sx, int sy){
    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(make_pair(sx, sy), 0));
    visited[sx][sy] = true;
    
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second;
        q.pop();
        
        if(x == ex && y == ey){
            answer = cnt;
            return;
        }
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m || map[nx][ny] == 'D') continue;
            while(1){
                nx += dx[i];
                ny += dy[i];
                
                if(nx < 0 || ny < 0 || nx >= n || ny >= m || map[nx][ny] == 'D'){
                    nx -= dx[i];
                    ny -= dy[i];
                    if(!visited[nx][ny]){
                        visited[nx][ny] = true;
                        q.push(make_pair(make_pair(nx, ny), cnt + 1));
                    }
                    break;
                }
            }
        }
    }
    answer = -1;
}

int solution(vector<string> board) {
    n = board.size();
    m = board[0].size();
    
    for(int i=0; i<n; i++){
        string s = board[i];
        for(int j=0; j<m; j++){
            map[i][j] = s[j];
            if(map[i][j] == 'R'){
                sx = i;
                sy = j;
            }
            if(map[i][j] == 'G'){
                ex = i;
                ey = j;
            }
        }
    }
    BFS(sx, sy);
    return answer;
}