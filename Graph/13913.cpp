#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n, k;
int parent[100001] = { 0, };
bool visited[100001];
vector<int> result;
queue<int> q;

void BFS(){
    q.push(n);
    visited[n] = true;

    while(!q.empty()){
        int x = q.front();
        q.pop();

        if(x == k){
            result.push_back(x);
            while(x != n){
                x = parent[x];
                result.push_back(x);
            }
            return;
        }

        if(x-1 >= 0 && !visited[x-1]){
            q.push(x-1);
            visited[x-1] = true;
            parent[x-1] = x;
        }

        if(x+1 <= 100000 && !visited[x+1]){
            q.push(x+1);
            visited[x+1] = true;
            parent[x+1] = x;
        }

        if(x*2 <= 100000 && !visited[x*2]){
            q.push(x*2);
            visited[x*2] = true;
            parent[x*2] = x;
        }
    }
}

int main(){
    cin >> n >> k;
    BFS();
    cout << result.size()-1 << '\n';
    for(int i=result.size()-1; i>=0; i--){
        cout << result[i] << " ";
    }
    return 0;
}