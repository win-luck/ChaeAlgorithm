#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
vector<int> v;
int arr[101];
bool isanswer[101]; // 중복 회피를 위한 변수
bool visited[101]; // 방문 여부를 위한 변수
int n, startpoint;

void DFS(int startpoint, int now){
    if(now == startpoint && visited[now]){ // 원래 자리로 돌아옴
        for(int i=1; i<=n; i++){
            if(visited[i] && !isanswer[i]){ // 방문한 모든 노드 찾고 중복 안되게 삽입
                v.push_back(i);
                isanswer[i] = true;
            }
        }
        return;
    }
    if(visited[now]) return;
    visited[now] = true; // 현재 노드 방문하고 다음 노드로 이동
    DFS(startpoint, arr[now]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }
    for(int i=1; i<=n; i++){// DFS
        memset(visited, false, sizeof(visited));
        DFS(i, i);
    }

    sort(v.begin(), v.end()); // 정렬
    cout << v.size() << '\n';
    for(int i=0; i<v.size(); i++){
        cout << v[i] << '\n';
    }
    return 0;
}