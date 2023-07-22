#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <iostream>

using namespace std;

bool visited[5][5];
vector<int> answer;
vector<pair<int, int> > v;
bool flag;
char map[5][5];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void BFS(int sx, int sy){
    queue<pair<int, pair<int, int>>> q;
    q.push(make_pair(0, make_pair(sx, sy)));
    visited[sx][sy] = true;
    
    while(!q.empty()){
        int move = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();
        
        if(move >= 3) continue; // 전염 시도 실패
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
            if(visited[nx][ny]) continue;
            if(map[nx][ny] == 'X') continue;
            if(map[nx][ny] == 'P' && !visited[nx][ny] && move <= 1){ // 조건 충족(전염 성공)
                flag = true;
                return;
            }
            q.push(make_pair(move + 1, make_pair(nx, ny)));
            visited[nx][ny] = true;
        }
    }
}

vector<int> solution(vector<vector<string>> places) {    
    for(int a=0; a<5; a++){
        flag = false;
        v.clear();
        vector<string> strs = places[a];
        
        for(int i=0; i<5; i++){
            string str = strs[i];
            for(int j=0; j<5; j++){
                map[i][j] = str[j];
                if(str[j] == 'P'){
                    v.push_back(make_pair(i, j));
                }
            }
        } // 대기실 상황 저장
        
        for(int i=0; i<v.size(); i++){
            memset(visited, false, sizeof(visited));
            BFS(v[i].first, v[i].second); // 각 사람별로 BFS
            if(flag) break;
        }
        if(flag) answer.push_back(0);
        else answer.push_back(1);
    }
    return answer;
}