#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int water[100001];
int clean[100001] = {0, };
int dirty[100001] = {0, };
int parent[100001];
int n, m, q;

int find(int a){
    if(parent[a] == a){
        return a;
    }
    return parent[a] = find(parent[a]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);
    water[a] += water[b];
    parent[b] = a;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> q;
    for(int i=1; i<=n; i++){
        cin >> water[i];
        if(water[i] == 0){
            water[i]--;
        }
        parent[i] = i;
    }
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        if(find(a) != find(b)){
            merge(a, b);
        }
    }
    for(int i=0; i<q; i++){
        int a;
        cin >> a;
        cout << (water[find(a)] > 0 ? 1 : 0) << '\n';
    }
    return 0;
}
