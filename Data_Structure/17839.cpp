#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
map<string, int> m;
int n;
int idx = 1;
bool visited[200001];
vector<int> v[200001];
vector<string> answer;
string tmp[200001];

void BFS(){
    queue<int> q;
    q.push(m["Baba"]);
    visited[m["Baba"]] = true;

    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i=0; i<v[x].size(); i++){
            if(visited[v[x][i]]) continue;
            visited[v[x][i]] = true;
            answer.push_back(tmp[v[x][i]]);
            q.push(v[x][i]);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++){
        string s1, s, s2;
        int x, y;

        cin >> s1 >> s >> s2;
        if(m.count(s1) == 0){
            x = idx;
            tmp[x] = s1;
            m[s1] = idx++;
        } else {
            x = m[s1];
        }
        if(m.count(s2) == 0){
            y = idx;
            tmp[y] = s2;
            m[s2] = idx++;
        } else {
            y = m[s2];
        }
        v[x].push_back(y);
    }

    if(m.count("Baba") == 0) return 0;
    BFS();
    sort(answer.begin(), answer.end());
    for(int i=0; i<answer.size(); i++){
        cout << answer[i] << '\n';
    }
    return 0;
}