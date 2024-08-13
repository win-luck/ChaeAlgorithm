#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n;
bool visited[5];
string str;
vector<string> v;

void dfs(int idx, int cnt, int totalsize, string value){
    if(cnt == totalsize){
        v.push_back(value);
        return;
    }

    for(int i=0; i<totalsize; i++){
        if(visited[i]) continue;
        visited[i] = true;
        dfs(i, cnt+1, totalsize, value + str[i]);
        visited[i] = false;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++){
        fill(visited, visited+5, false);
        v.clear();
        cin >> str;

        cout << "Case # " << i << ":\n";
        dfs(0, 0, str.size(), "");
        for(auto it: v){
            cout << it << '\n';
        }
    }
    return 0;
}
