#include <iostream>

using namespace std;
int n, m, k;
int v, w;
int parent[10001];
int cost[10001];

int find(int x){
    if(x == parent[x]) return x;
    else return parent[x] = find(parent[x]);
}

void merge(int x, int y){
    x = find(x);
    y = find(y);
    if(x != y) {
        if(cost[x] < cost[y]) parent[y] = x; // 가격이 가장 작은 사람이 부모
        else parent[x] = y;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;
    for(int i=1; i<=n; i++){ // 부모 초기화
        cin >> cost[i];
        parent[i] = i;
    }

    for(int i=0; i<m; i++){ // 친구 관계 설정
        cin >> v >> w;
        merge(v, w);
    }

    int sum = 0;
    int cnt = 0;

    cost[0] = 100000000; // 본인의 비용이 가장 커야 본인이 부모가 안 된다. (최솟값이 나올 수 있다)
    for(int i=1; i<=n; i++){
        int p = find(i);
        if(p != find(0)){ // 이 그룹에 친구가 한 명이라도 필요한 상황
            sum += cost[p]; // 비용 추가
            merge(0, p); // 연결 (이제 이 그룹과는 모두 친구)
        }
    }

    if(sum <= k) // 친구 비용이 k보다 작거나 같으면 가능
        cout << sum << '\n';
    else
        cout << "Oh no" << '\n';
    return 0;
}