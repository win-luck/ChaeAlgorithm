#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
int s;
int visited[1001][1001];
queue<pair<int, int> > q;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    memset(visited, 0, sizeof(visited));

    q.push(make_pair(1, 0));
    visited[1][0] = 0;
    
    while(!q.empty()){
        int x = q.front().first;
        int clip = q.front().second;
        q.pop();

        if(x == s){ // 도착
            cout << visited[x][clip] << '\n';
            break;
        }

        // 복사
        if(!visited[x][x]){
            q.push(make_pair(x, x));
            visited[x][x] = visited[x][clip] + 1;
        }

        // 붙여넣기
        if(x + clip <= s){
            if(!visited[x+clip][clip]){
                q.push(make_pair(x+clip, clip));
                visited[x+clip][clip] = visited[x][clip] + 1;
            }
        }

        // 삭제
        if(x > 1){
            if(!visited[x-1][clip]){
                q.push(make_pair(x-1, clip));
                visited[x-1][clip] = visited[x][clip] + 1;
            }
        }
    }
    return 0;
}