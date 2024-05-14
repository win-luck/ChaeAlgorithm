#include <string>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;
int answer = 0;
int n, m;
vector<int> v;
bool visited[21];
vector<vector<string>> map;
set<vector<int>> c;

bool unique(){
    bool selected[21];
    set<string> s;
    for(int i=0; i<map.size(); i++){
        string now = "";
        for(int j=0; j<v.size(); j++){
            now += map[i][v[j]];
        }
        if(s.find(now) == s.end()) s.insert(now);
        else return false;
    }
    c.insert(v);
    return true;
}

bool minimal(){
    for(auto it: c){
        vector<int> tmp = it;
        int len = 0;
        if(tmp.size() < v.size()){
            for(int j=0; j<tmp.size(); j++){
                if(find(v.begin(), v.end(), tmp[j]) != v.end()){
                    len++;
                }
            }
            if(len == tmp.size()) return false;
        }
    }
    return true;
}

void dfs(int idx, int cnt, int size){
    if(cnt == size){
        if(unique() && minimal()) answer++;
        return;
    }
    
    for(int i=idx; i<m; i++){
        if(visited[i]) continue;
        visited[i] = true;
        v.push_back(i);
        dfs(i, cnt+1, size);
        v.pop_back();
        visited[i] = false;
    }
}

int solution(vector<vector<string>> relation) {
    map = relation;
    n = map.size();
    m = map[0].size();
    for(int i=1; i<=n; i++){
        dfs(0, 0, i);
    }
    return answer;
}
