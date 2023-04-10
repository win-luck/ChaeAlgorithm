#include <iostream>
#include <vector>

using namespace std;
int n;
bool visited[9];
vector<int> v;

void print(vector<int> v){
    for(int i=0; i<v.size(); i++){
        cout << v[i] << ' ';
    }
    cout << '\n';
}

void DFS(int cnt){
    if(cnt == n){
        print(v);
        return;
    }

    for(int i=0; i<n; i++){
        if(visited[i]) continue;
        
        visited[i] = true;
        v.push_back(i+1);
        DFS(cnt + 1);
        v.pop_back();
        visited[i] = false;
    }
}

int main(){
    cin >> n;
    DFS(0);
    return 0;
}