#include <iostream>
#include <vector>

using namespace std;
int n, m, q;
int a, b;
int p[1001];

int find(int num){
    if(num == p[num]) return num;
    return p[num] = find(p[num]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b){
        if(a > b) swap(a, b);
        p[a] = b;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> q;
    for(int i=1; i<=n; i++){
        p[i] = i;
    }
    for(int i=0; i<m; i++){
        cin >> a >> b;
        merge(a, b);
    }
    for(int i=0; i<q; i++){
        cin >> a >> b;
        cout << (find(a) == find(b) ? "Y\n" : "N\n");
    }
    return 0;
}
