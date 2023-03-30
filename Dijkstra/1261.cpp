#include <iostream>
#include <queue>

#define MAX 101
#define INF 987654321
using namespace std;
int n, m, result;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int map[MAX][MAX];
int visited[MAX][MAX]; // 특정 좌표 기준 방을 바꾼 횟수

void dijkstra(){
    result = 0;
    priority_queue<pair<int, int> > pq; // 행/열 우선순위 큐
    pq.push(make_pair(0, 0));
    visited[0][0] = 0;

    while(!pq.empty()){
        int nowR = pq.top().first;
        int nowC = pq.top().second;
        pq.pop();

        for(int i=0; i<4; i++){
            int newR = nowR + dx[i];
            int newC = nowC + dy[i];

            if(newR < 0 || newR >= n || newC < 0 || newC >= m) continue; // 맵 범위 이탈

            if(map[newR][newC] == 0){ // 평범한 길
                if(visited[newR][newC] > visited[nowR][nowC]){ // 최소를 찾아야 하므로 최소로 갱신해야 한다. 최초로 INF로 초기화되어 있다.
                    visited[newR][newC] = visited[nowR][nowC];
                    pq.push(make_pair(newR, newC));
                }
            } else { // 막힌 길이면 뚫어야 한다. (+1)
                if(visited[newR][newC] > visited[nowR][nowC] + 1){
                    visited[newR][newC] = visited[nowR][nowC] + 1;
                    pq.push(make_pair(newR, newC));
                }
            }
        }
    }
    result = visited[n-1][m-1];
}

int main() {
    string str;
    cin >> m >> n;
    for(int i=0; i<n; i++){
        cin >> str;
        for(int j=0; j<str.length(); j++){
            map[i][j] = str[j] - '0';
            visited[i][j] = INF;
        }
    } // 입력

    dijkstra();
    cout << result << '\n';
    return 0;
}
