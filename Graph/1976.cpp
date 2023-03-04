#include <iostream>
#include <vector>

using namespace std;
int parent[1001];
int map[1001][1001];
int n, m, citynum;
vector<int> v;

int find(int num){
    if(num == parent[num]){
        return num;
    }
    return parent[num] = find(parent[num]);
}

void Union(int a, int b){
    a = find(a);
    b = find(b);

    if(a == b) return;
    else parent[a] = b;
}

int main(){
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        parent[i] = i;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> map[i][j];
            if(map[i][j] == 1){
                Union(i, j);
            }
        }
    }

    for(int i=1; i<=m; i++){
        cin >> citynum;
        v.push_back(citynum);
    }

    for(int i=0; i<v.size()-1; i++){
        if(find(v[i]) != find(v[i+1])){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}