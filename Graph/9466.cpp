#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int t, n;
int cnt = 0;
int parent[100001];
bool visited[100001];
bool finished[100001];

void dfs(int now){
    visited[now] = true;
    int next = parent[now];
    if(!visited[next]) dfs(next);
    else if(!finished[next]){ // 방문했으며 아직 종료되지 않음 -> 사이클 속에 존재
        for(int i=next; i!=now; i=parent[i]){
            cnt++;
        }
        cnt++;
    }
    finished[now] = true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--){
        fill(visited, visited+100001, false);
        fill(finished, finished+100001, false);
        cnt = 0;

        cin >> n;
        for(int i=1; i<=n; i++){
            cin >> parent[i];
        }

        for(int i=1; i<=n; i++){
            if(!visited[i]) dfs(i);
        }
        cout << n-cnt << '\n';
    }
    return 0;
}
