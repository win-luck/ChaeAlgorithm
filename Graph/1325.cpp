#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
vector<int> v[10001];
vector<int> answer;
int cnt = 0;
int Max = 0;
int n, m;
bool visited[10001];

bool cmp(int a, int b){
    return a > b;
} // 내림차순 정렬

void DFS(int idx){
    if(visited[idx]) return;
    visited[idx] = true;
    cnt++;
    for(int i=0; i<v[idx].size(); i++){
        DFS(v[idx][i]);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=1; i<=m; i++){
        int a, b;
        cin >> a >> b;
        v[b].push_back(a);
    } // 입력

    for(int i=1; i<=n; i++){
        DFS(i);
        memset(visited, false, sizeof(visited));
        Max = max(cnt, Max);
        answer.push_back(cnt);
        cnt = 0;
    }

    for(int i=0; i<answer.size(); i++){
        if(answer[i] == Max){
            cout << i+1 << " ";
        }
    }
    return 0;
}