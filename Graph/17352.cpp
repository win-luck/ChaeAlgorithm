#include <iostream>
#include <vector>

using namespace std;
int n;
int map[300001];
int parent[300001];

int find(int n){ // 파인드
    if(parent[n] == n) return n;
    else return parent[n] = find(parent[n]);
}

void Union(int a, int b){ // 유니온
    a = find(a);
    b = find(b);
    if(a == b) return;
    else parent[a] = b;
}

int main(){
    cin >> n;

    for(int i=1; i<=n; i++){ // 부모 초기화
        parent[i] = i;
    }

    for(int i=0; i<n-2; i++){ // 노드 연결
        int a, b;
        cin >> a >> b;
        Union(a, b);
    }

    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            if(find(i) != find(j)){ // 부모가 다르면 연결해야 하는 다리
                cout << i << " " << j;
                return 0;
            }
        }
    }
}