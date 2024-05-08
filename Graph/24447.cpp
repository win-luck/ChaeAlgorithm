#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int n, m, r;
vector<long long> v[100001];
long long visited[100001] = {0,};
long long visited2[100001] = {0,};

void bfs(int r){
    long long cnt = 1;
    queue<int> q;
    visited[r] = cnt;
    visited2[r] = cnt;
    q.push(r);

    while(!q.empty()){
        int x = q.front();
        q.pop();

        for(int i=0; i<v[x].size(); i++){
            if(!visited[v[x][i]]){
                visited[v[x][i]] = ++cnt;
                visited2[v[x][i]] = visited2[x] + 1;
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
        sort(v[i].begin(), v[i].end());
    }

    bfs(r);
    long long sum = 0;
    for(int i=1; i<=n; i++){
        sum += visited[i] * (visited2[i]-1);
    }
    cout << sum;
    return 0;
}
