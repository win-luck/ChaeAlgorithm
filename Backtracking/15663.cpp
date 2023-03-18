#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m;
vector<int> seq;
vector<int> tempseq;
bool visited[9];

void print(vector<int> v){
    if(tempseq == v) return;
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << '\n';
    tempseq = v;
}

void DFS(vector<int> v, int depth){
    if(depth == m){
        print(v);
    }

    for(int i=0; i<n; i++){
        if(visited[i]) continue;
        if(seq[i] == seq[i-1] && !visited[i-1]) continue; // 중복 제거

        visited[i] = true;
        v.push_back(seq[i]);
        DFS(v, depth + 1);
        v.pop_back();
        visited[i] = false;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> v;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        seq.push_back(tmp);
    }
    sort(seq.begin(), seq.end());
    
    DFS(v, 0);
    return 0;
}