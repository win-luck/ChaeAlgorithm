#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
int n, cnt = 1;
bool flag;
vector<int> v[100001];
vector<int> path, real;
int order[100001];
bool visited[100001];

bool cmp(int a, int b){
    return order[a] < order[b];
} // 우선순위가 빠른 순으로 정렬

void DFS(int idx){
    visited[idx] = true;
    real.push_back(idx);

    for(int i=0; i<v[idx].size(); i++){
        if(!visited[v[idx][i]]){
            DFS(v[idx][i]);
        }
    }
} // DFS

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0; i<n-1; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    } // 트리는 양방향 그래프이다..

    for(int i=1; i<=n; i++){
        int a;
        cin >> a;
        path.push_back(a); // 이동할 노드 입력
        order[a] = i; // a의 우선순위는 i번쨰
    }

    for(int i=0; i<=n; i++){
        sort(v[i].begin(), v[i].end(), cmp);
    } // 입력에 따른 우선순위대로 정렬

    DFS(1);
    if(path == real) cout << 1 << '\n';
    else cout << 0 << '\n';    
    return 0;
}