#include <iostream>
#include <algorithm>

using namespace std;
int parent[100001];
int planet[100001];
int n, m;

int find(int num){
    if(num == parent[num]) return num;
    return parent[num] = find(parent[num]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=1; i<=n; i++){
        parent[i] = i;
        cin >> planet[i];
    }

    for(int i=1; i<=m; i++){
        int a, b;
        cin >> a >> b;
        if(a > b) swap(a, b);

        a = find(a);
        b = find(b);
        if(a != b){
            if(a > b) {
                parent[a] = b;
                planet[b] += planet[a];
            } else {
                parent[b] = a;
                planet[a] += planet[b];
            }
        }
        cout << ((a > b) ? planet[b] : planet[a]) << '\n';
    }
    return 0;
}
