#include <iostream>

using namespace std;
int n, m, a, b, k;
int parent[1000001];

int find(int n){
    if(n == parent[n]){
        return n;
    }
    return parent[n] = find(parent[n]);
}

bool merge(int a, int b){
    a = find(a);
    b = find(b);

    if(a == b) return false;
    else {
        parent[a] = b;
        return true;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i=0; i<=n; i++){ // 부모 초기화
        parent[i] = i;
    }

    for(int i=0; i<m; i++){
        cin >> k >> a >> b;
        if(k == 0){ // 0이면 같은 집합으로 병합
            merge(a, b);
        } else { // 1이면 검증
            if(find(a) == find(b)){ // 부모가 같음
                cout << "YES" << '\n';
            } else {
                cout << "NO" << '\n';
            }
        }
    }
    return 0;
}