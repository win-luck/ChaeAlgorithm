#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
int n, m, r;
int visited[100001];
vector<int> edge[100001];
queue<int> q;
int cnt = 1;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> r;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    fill(visited, visited+100001, 0);
    visited[r] = cnt++;
    q.push(r);
    for(int i=1; i<=n; i++){
        sort(edge[i].begin(), edge[i].end());
    }

    while(!q.empty()){
        int x = q.front();
        q.pop();

        for(int i=0; i<edge[x].size(); i++){
            int nx = edge[x][i];
            if(!visited[nx]){
                visited[nx] = cnt++;
                q.push(nx);
            }
        }
    }
    for(int i=1; i<=n; i++){
        cout << visited[i] << '\n';
    }
    return 0;
}
