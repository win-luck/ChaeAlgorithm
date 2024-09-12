#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> v[100001];
int visited[100001] = {0, };
int n, m, r;

void dfs(int now, int depth){
    visited[now] = depth;

    for(int i=0; i<v[now].size(); i++){
        int next = v[now][i];
        if(!visited[next]){
            dfs(next, depth+1);
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

    for(int i=1; i<=n; i++){
        sort(v[i].begin(), v[i].end());
        reverse(v[i].begin(), v[i].end());
    }
    
    dfs(r, 1);
    for(int i=1; i<=n; i++){
        cout << visited[i]-1 << '\n';
    }
    return 0;
}
