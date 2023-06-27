#include <iostream>
#include <queue>
#include <cstring>
#include <map>

using namespace std;
int n, m;
int visited[101]; // 방문 여부 확인
map<int, int> w; // 사다리와 뱀
queue<int> q; // BFS

void BFS(){
    visited[1] = 0;
    for(int i=2; i<=7; i++){
        if(w.count(i) > 0){
            q.push(w[i]);
            visited[w[i]] = 1;
        } else {
            q.push(i);
            visited[i] = 1;
        }
    } // 최초 주사위

    while(!q.empty()){
        int x = q.front();
        q.pop();
        if(x >= 100) continue; // 범위 이탈
        for(int i=1; i<=6; i++){
            int nx = 0;
            if(w.count(x+i) > 0){ // 맵에 존재하는지 아닌지 판단
                nx = w[x+i];
            } else {
                nx = x+i;
            }
            if(nx > 100) break; // 100 초과면 더 이상 볼 필요 없음
            if(visited[nx] > visited[x] + 1){ // visited를 방문횟수로 처리하는 발상이 필요했다
                visited[nx] = visited[x] + 1;
                q.push(nx);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=0; i<n+m; i++){
        int a, b;
        cin >> a >> b;
        w[a] = b;
    } // 사다리 및 뱀에 대한 정보 입력

    memset(visited, 10000, sizeof(visited));
    BFS();
    cout << visited[100] << '\n';
    return 0;
}