#include <iostream>
#include <queue>

using namespace std;
int visited[1001];
int maps[1001];
int n;

void BFS(){
    queue<int> q;
    q.push(1);
    visited[1] = 1;
    while(!q.empty()){
        int x = q.front(); // 실제 좌표
        q.pop();

        if(x == n){
            cout << visited[n]-1 << '\n';
            return;
        }

        for(int i=x+maps[x]; i>=x+1; i--){
            if(!visited[i]){
                visited[i] = visited[x] + 1;
                q.push(i);
            }
        }
    }
    cout << -1 << '\n';
}

int main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> maps[i];
    }
    BFS();
    return 0;
}
