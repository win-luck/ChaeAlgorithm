#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int t, n;
bool visited[100001];
string arr[100001];
int result = 100;

int makesum(vector<string> v){
    string a = v[0];
    string b = v[1];
    string c = v[2];

    int sum = 0;
    for(int i=0; i<4; i++) sum += (a[i] != b[i]) ? 1 : 0;
    for(int i=0; i<4; i++) sum += (b[i] != c[i]) ? 1 : 0;
    for(int i=0; i<4; i++) sum += (a[i] != c[i]) ? 1 : 0;
    return sum;
}

void DFS(int cnt, vector<string> v){
    if(v.size() == 3){
        result = min(result, makesum(v));
        return;
    }

    for(int i=cnt; i<n; i++){
        if(visited[i]) continue;
        visited[i] = true;
        v.push_back(arr[i]);
        DFS(cnt + 1, v);
        v.pop_back();
        visited[i] = false;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    fill(visited, visited+100001, false);
    fill(arr, arr+100001, "");

    cin >> t;
    for(int a=0; a<t; a++){        
        result = 100;
        fill(visited, visited+100001, false);
        fill(arr, arr+100001, "");
        vector<string> v;

        cin >> n;
        for(int i=0; i<n; i++) cin >> arr[i];
        if(n > 32){ // 32개 초과면 무조건 0이 답
            cout << 0 << '\n';
            continue;
        }
        DFS(0, v);
        cout << result << '\n';
    }
    return 0;
}
