#include <iostream>
#include <queue>
#include <cstring>

#define INF 987654321
#define MAX 101
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
char map[MAX][MAX];
int dist[MAX][MAX][4];
int w, h;
pair<int, int> s;

void dijkstra(){
    int res = INF;
    queue<pair<int, pair<int, int> > > q; // 방향, 좌표
    for(int i=0; i<4; i++){
        q.push(make_pair(i, make_pair(s.first, s.second)));
        dist[s.first][s.second][i] = 0;
    }

    while(!q.empty()){
        int d = q.front().first; // 현재 진행 방향
        int nowx = q.front().second.first; // 현재 x좌표
        int nowy = q.front().second.second; // y좌표
        q.pop();

        if(map[nowx][nowy] == 'C'){
            res = min(res, dist[nowx][nowy][d]); // 커브를 더 하고 일찍 도착할 수도 있기에 마지막까지 지켜봐야함
            continue;
        }

        for(int i=0; i<4; i++){
            int newx = nowx + dx[i];
            int newy = nowy + dy[i];

            if(newx < 0 || newx >= h || newy < 0 || newy >= w) continue;
            if(map[newx][newy] == '*') continue;
            if(i == d && dist[newx][newy][i] > dist[nowx][nowy][d]){ // 같은 방향
                dist[newx][newy][i] = dist[nowx][nowy][d];
                q.push(make_pair(i, make_pair(newx, newy))); 
            } else if(i != d && dist[newx][newy][i] > dist[nowx][nowy][d]+1){ // 다른 방향
                dist[newx][newy][i] = dist[nowx][nowy][d] + 1;
                q.push(make_pair(i, make_pair(newx, newy))); 
            }
        }
    }
    cout << res;
}

void input() {
    cin >> w >> h;
    string str;
    int flag = 0;
    for(int i=0; i<h; i++){
        cin >> str;
        for(int j=0; j<w; j++){
            map[i][j] = str[j];
            for(int a=0; a<4; a++){
                dist[i][j][a] = INF;
            }
            if(map[i][j] == 'C'){ // 시작점과 도착점을 저장
                if(flag == 0){
                    s.first = i;
                    s.second = j;
                    map[i][j] = '.';
                    flag = 1;
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    dijkstra();
    return 0;
}
