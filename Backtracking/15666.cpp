#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
int n, m;
int arr[8];
vector<int> v;
set<vector<int> > s;
bool visited[8];

void Backtrack(int cnt, int idx){
    if(cnt == m){
        s.insert(v);
        return;
    }
    for(int i=idx; i<n; i++){
        if(visited[i]) continue;

        if(v.empty() || arr[i] >= v.back()){
        visited[i] = true;
        v.push_back(arr[i]);
        Backtrack(cnt + 1, idx + 1);
        v.pop_back();
        visited[i] = false;
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr, arr + n);
    Backtrack(0, 0);
    for(auto vec: s){
        for(auto it: vec){
            cout << it << " ";
        }
        cout << '\n';
    }
    return 0;
}