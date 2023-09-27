#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <algorithm>

using namespace std;
int n, m;
bool visited[10];
vector<int> v;
set<int> s;

void DFS(vector<int> tmp, int idx){
    if(tmp.size() == m){
        int sum = 0;
        for(int i=0; i<tmp.size(); i++){
            sum += tmp[i];
        }
        for(int i=2; i<=sqrt(sum); i++){
            if(sum % i == 0){
                return;
            }
        }
        s.insert(sum);
        return;
    }

    for(int i=0; i<n; i++){
        if(visited[i]) continue;
        tmp.push_back(v[i]);
        visited[i] = true;
        DFS(tmp, idx+1);
        visited[i] = false;
        tmp.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        v.push_back(a);
    }

    vector<int> tmp;
    DFS(tmp, 0);
    if(s.empty()){
        cout << -1;
    } else {
        for(auto it: s){
            cout << it << " ";
        }
    }
    return 0;
}
