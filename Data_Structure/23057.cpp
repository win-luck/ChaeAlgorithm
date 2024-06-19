#include <iostream>
#include <vector>
#include <set>

using namespace std;
int t, n;
bool visited[21] = {false, };
set<int> s;
vector<int> v;
int answer = 0;

void dfs(int idx, int cnt, int sum, int limits){
    if(cnt == limits){
        s.insert(sum);
        return;
    }

    for(int i=idx; i<n; i++){
        if(visited[i]) continue;
        visited[i] = true;
        dfs(i, cnt+1, sum + v[i], limits);
        visited[i] = false;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    v.resize(n);
    long long m = 0;
    for(int i=0; i<n; i++){
        cin >> v[i];
        m += v[i];
    }
    for(int i=1; i<=n; i++){
        dfs(0, 0, 0, i);
    }
    cout << m - s.size();
    return 0;
}
