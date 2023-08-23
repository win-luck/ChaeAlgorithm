#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int parent[21];
int n, m, k;

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
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    for(int i=1; i<=n; i++){
        parent[i] = i;
    }

    for(int i=1; i<=m; i++){
        int a, b;
        cin >> a >> b;
        if(find(a) != find(b)){
            merge(a, b);
        }
    }
    
    vector<int> groupSizes(n+1, 0);
    for(int i=1; i<=n; i++){
        groupSizes[find(i)]++;
    }

    bool isSafe = false;
    for(int i=1; i<=n; i++){
        if(groupSizes[i] == k || groupSizes[i] == n-k){
            isSafe = true;
            break;
        }
    }

    if(isSafe){
        cout << "SAFE" << '\n';
    } else {
        cout << "DOOMED" << '\n';
    }
    return 0;
}
