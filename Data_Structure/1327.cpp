#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <string>

using namespace std;
int n, k;
queue<pair<string, int> > q;
map<string, bool> visited;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    string str = "";
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        str += to_string(a);
    }
    string last = str;
    sort(last.begin(), last.end()); // 목적지

    q.push(make_pair(str, 0));
    visited[str] = true;
    while(!q.empty()){
        string x = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if(x == last){
            cout << cnt;
            return 0;
        }

        for(int i=0; i<=n-k; i++){
            string nx = x;
            reverse(nx.begin()+i, nx.begin()+i+k);
            if(visited.count(nx) == 0){
                visited[nx] = true;
                q.push(make_pair(nx, cnt + 1));
            }
        }
    }
    cout << -1;
    return 0;
}
