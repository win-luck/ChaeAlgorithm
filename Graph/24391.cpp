#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int n, m;
int parent[100001];
vector<int> v;

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
    
    cin >> n >> m;
    for(int i=0; i<=100000; i++){
        parent[i] = i;
    }

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        merge(a, b);
    }

    for(int i=1; i<=n; i++){
        int a;
        cin >> a;
        v.push_back(a);
    }

    int cnt = 0;
    for(int i=0; i<v.size()-1; i++){
        if(find(v[i]) != find(v[i+1]))
            cnt++;
    }
    cout << cnt << '\n';
    return 0;
}