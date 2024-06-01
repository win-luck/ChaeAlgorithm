#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;
int n, m;
int parent[100001];
set<int> s;

int find(int num){
    if(num == parent[num]) return num;
    return parent[num] = find(parent[num]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);
    parent[b] = a;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=1; i<=n; i++){
        parent[i] = i;
    }
    int cnt = 0;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        if(find(a) == find(b)) cnt++; // 연결 끊기 연산
        merge(a, b);
    }
    for(int i=1; i<=n; i++){
        if(s.find(find(i)) == s.end()) s.insert(find(i)); // 연결 연산
    }
    cout << cnt + s.size()-1;
    return 0;
}
