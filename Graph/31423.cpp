#include <iostream>
#include <vector>

using namespace std;
int n;
vector<string> v;
bool visited[500001] = {false, };
vector<int> edge[500001];
int parent[500001];
string answer = "";

int find(int num){
    if(num == parent[num]) return num;
    return parent[num] = find(parent[num]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);
    parent[b] = a;
}

void dfs(int idx){
    if(visited[idx]) return;
    visited[idx] = true;
    answer += v[idx];
    for(int i=0; i<edge[idx].size(); i++){
        int next = edge[idx][i];
        if(!visited[next]){
            dfs(next);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    v.resize(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
        parent[i] = i;
    }
    for(int i=0; i<n-1; i++){
        int a, b;
        cin >> a >> b;
        edge[a-1].push_back(b-1);
        if(find(a-1) != find(b-1)) merge(a-1, b-1);
    }
    dfs(find(0));
    cout << answer;
    return 0;
}
