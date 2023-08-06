#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int t, n, k, m;
int parent[1000001];

int find(int num){
    if(num == parent[num]) return num;
    return parent[num] = find(parent[num]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);
    parent[a] = b;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    for(int a=0; a<t; a++){
        cin >> n;
        for(int i=0; i<=n; i++){
            parent[i] = i;
        }
        cin >> k;
        for(int i=0; i<k; i++){
            int a, b;
            cin >> a >> b;
            if(find(a) != find(b)){
                merge(a, b);
            }
        }
        cin >> m;
        vector<int> v;
        for(int i=0; i<m; i++){
            int a, b;
            cin >> a >> b;
            v.push_back(find(a) == find(b) ? 1 : 0);
        }
        cout << "Scenario " << a+1 << ":\n";
        for(int i=0; i<v.size(); i++){
            cout << v[i] << '\n';
        }
        cout << '\n';
    }
    return 0;
}