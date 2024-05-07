#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
int l, n;
string str;
vector<string> map;
vector<string> v;
bool visited[21] = {false,};
bool flag = false;

bool validcheck(){
    for(int i=0; i<l; i++){
        for(int j=0; j<l; j++){
            if(map[i][j] != map[j][i]) return false;
        }
    }
    return true;
}

void dfs(int cnt){
    if(cnt == l){
        if(validcheck()){
            for(int i=0; i<l; i++){
                cout << map[i] << '\n';
            }
            exit(0);
        }
        return;
    }

    for(int i=0; i<n; i++){
        if(visited[i]) continue;
        visited[i] = true;
        map[cnt] = v[i];
        dfs(cnt+1);
        visited[i] = false;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> l >> n;
    map.resize(l);
    v.resize(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    dfs(0);
    if(!flag) cout << "NONE";
    return 0;
}
