#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int n, m, r;
vector<int> v[100001];
int visited[100001] = {0,};

bool cmp(int a, int b){
    return a > b;
}

void bfs(int r){
    int cnt = 1;
    queue<int> q;
    visited[r] = cnt;
    q.push(r);

    while(!q.empty()){
        int x = q.front();
        q.pop();

        for(int i=0; i<v[x].size(); i++){
            if(!visited[v[x][i]]){
                visited[v[x][i]] = ++cnt;
                q.push(v[x][i]);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> r;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=0; i<=n; i++){
        sort(v[i].begin(), v[i].end(), cmp);
    }
    bfs(r);
    for(int i=1; i<=n; i++){
        cout << visited[i] << '\n';
    }
    return 0;
}
