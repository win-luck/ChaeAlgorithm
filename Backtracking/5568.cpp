#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
int n, k;
int ans = 0;
string arr[11];
bool visited[11];
map<string, bool> m;
vector<string> v;

void backtrack(int cnt){
    if(cnt == k){
        string str;
        for(int i=0; i<v.size(); i++){
            str += v[i];
        }
        m[str] = true;
        return;
    }
    
    for(int i=0; i<n; i++){
        if(visited[i]) continue;
        visited[i] = true;
        v.push_back(arr[i]);
        backtrack(cnt + 1);
        v.pop_back();
        visited[i] = false;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    backtrack(0);
    cout << m.size() << '\n';
    return 0;
}