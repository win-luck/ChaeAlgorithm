#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

bool visited[1001][1001];
char map[1001][1001];
int n;
vector<pair<int, int> > answer; // 면적, 둘레
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

// 가장 큰 면적을 가진 아이스크림 덩어리 찾기
// 동일한 면적의 영역 2개면 둘레가 더 적은 덩어리 찾기
// 각 BFS당 면적과 둘레를 계산하여 정렬한 후 맨 앞?
bool cmp(pair<int, int> p1, pair<int, int> p2){
    if(p1.first == p2.first){
        return p1.second < p2.second;
    }
    return p1.first > p2.first;
}

void BFS(int sx, int sy){
    queue<pair<int, int> > q;
    visited[sx][sy] = true;
    q.push(make_pair(sx, sy));
    int around = 0;
    int cnt = 1;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= n || map[nx][ny] == '.'){
                around++;
                continue;   
            } 
            if(visited[nx][ny]) continue;
            if(map[nx][ny] == '#'){
                cnt++;
                q.push(make_pair(nx, ny));
                visited[nx][ny] = true;
            }
        }
    }
    answer.push_back(make_pair(cnt, around));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    for(int i=0; i<n; i++){
        string str;
        cin >> str;
        for(int j=0; j<n; j++){
            map[i][j] = str[j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!visited[i][j] && map[i][j] == '#'){
                BFS(i, j);
            }
        }
    }
    sort(answer.begin(), answer.end(), cmp);
    cout << answer[0].first << " " << answer[0].second << '\n';
    return 0;
}
