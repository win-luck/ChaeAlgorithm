#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
int n;
int parent[1000001];
int cnt[1000001];

int find(int num){
    if(num == parent[num]) return num;
    return parent[num] = find(parent[num]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);
    parent[b] = a;
    cnt[a] += cnt[b];
    cnt[b] = 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=1; i<=1000000; i++){
        parent[i] = i;
        cnt[i] = 1;
    }
    for(int i=0; i<n; i++){
        char c;
        int a, b;
        cin >> c;
        if(c == 'I'){
            cin >> a >> b;
            if(a > b) swap(a, b);
            if(find(a) != find(b)){
                merge(a, b);
            }
        } else {
            cin >> a;
            cout << cnt[find(a)] << '\n';
        }
    }
    return 0;
}