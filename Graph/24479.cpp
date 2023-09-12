#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> v[100001];
int answer[100001];
bool visited[100001] = { false, };
int n, m, r;
int cnt = 1;
bool flag = false;

void DFS(int now){
    if(visited[now]) return;
    visited[now] = true;
    answer[now] = cnt++;

    for(int i=0; i<v[now].size(); i++){
        if(!visited[v[now][i]]){
            DFS(v[now][i]);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    fill(answer, answer + 100001, 0);
    fill(visited, visited + 100001, false);
    cin >> n >> m >> r;
    for(int i=1; i<=m; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for(int i=1; i<=n; i++){
        sort(v[i].begin(), v[i].end());
    }

    DFS(r);
    for(int i=1; i<=n; i++){
        cout << answer[i] << '\n';
    }
    return 0;
}
