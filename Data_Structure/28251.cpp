#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
int q, n;
int parent[200001];
long long power[200001];
long long cnt[200001];

int find(int num){
    if(num == parent[num]) return num;
    return parent[num] = find(parent[num]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b){
        parent[b] = a;
        power[a] += cnt[a] * cnt[b] + power[b];
        cnt[a] += cnt[b];
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    for(int i=1; i<=n; i++){
        cin >> cnt[i];
        parent[i] = i;
    }
    for(int i=1; i<=q; i++){
        int a, b;
        cin >> a >> b;
        if(a > b) swap(a, b);
        merge(a, b);
        cout << power[find(a)] << '\n';
    }
    return 0;
}
