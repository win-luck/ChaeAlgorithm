#include <iostream>
#include <map>

using namespace std;
int n, m;
int parent[10001];
int money[10001];

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

    cin >> n >> m;
    for(int i=0; i<n; i++){
        parent[i] = i;
        cin >> money[i];
    }
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        merge(a, b);
    }

    map<int, int> group;
    for(int i=0; i<n; i++){
        group[find(i)] += money[i];
    }

    bool flag = true;
    for(auto it: group){
        if(it.second < 0){
            flag = false;
            break;
        }
    }
    cout << (flag == true ? "POSSIBLE" : "IMPOSSIBLE");
    return 0;
}
