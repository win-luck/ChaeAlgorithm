#include <iostream>
#include <set>

using namespace std;
int n, m;
int parent[50001];

int find(int num){
    if(num == parent[num]) return num;
    return parent[num] = find(parent[num]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return;
    parent[b] = a;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int idx = 1;
    while(1){
        cin >> n >> m;
        if(n == 0 && m == 0) break;
        for(int i=1; i<=n; i++){
            parent[i] = i;
        }
        for(int i=0; i<m; i++){
            int a, b;
            cin >> a >> b;
            merge(a, b);
        }
        set<int> s;
        for(int i=1; i<=n; i++){
            s.insert(find(i));
        }
        cout << "Case " << idx++ << ": " << s.size() << '\n';
    }
    return 0;
}
