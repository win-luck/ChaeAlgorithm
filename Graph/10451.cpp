#include <iostream>
#include <algorithm>

using namespace std;
int parent[1001] = {0, };
bool visited[1001] = {false, };
int cnt = 0;

void init(){
    cnt = 0;
    fill(parent, parent+1001, 0);
    fill(visited, visited+1001, false);
}

void dfs(int now){
    visited[now] = true;
    if(!visited[parent[now]]) dfs(parent[now]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        init();
        int n;
        cin >> n;
        for(int i=1; i<=n; i++){
            cin >> parent[i];
        }
        for(int i=1; i<=n; i++){
            if(!visited[i]){
                dfs(i);
                cnt++;
            }
        }
        dfs(0);
        cout << cnt << '\n';
    }
    return 0;
}
