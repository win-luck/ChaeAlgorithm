#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
vector<int> v[10001];
int cnt = 0;
int root = 0;
int n, m, target;
bool visited[10001];

int DFS(int idx){
    if(idx == target) return -1; // 지울 노드에 도달
    if(v[idx].size() == 0){ // 리프 노드에 도달
        cnt++;
        return 0;
    }
    for(int i=0; i<v[idx].size(); i++){
        int check = DFS(v[idx][i]); // 삭제 대상 노드인지 검증
        if(check == -1 && v[idx].size() == 1) cnt++; // 삭제한 노드가 부모의 유일한 자식 노드면 부모가 리프
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        if(a == -1){
            root = i; // root 결정
            continue;
        }
        v[a].push_back(i);
    } // 입력

    cin >> target;
    DFS(root);
    cout << cnt << '\n';
    return 0;
}