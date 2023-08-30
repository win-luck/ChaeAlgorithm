#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
int visited[100001];
int a, b, n, m;

void BFS(int start, int end){
    queue<int> q;
    q.push(start);
    visited[start] = 1;

    while(!q.empty()){
        int x = q.front();
        q.pop();

        if(x == end){
            cout << visited[x]-1 << '\n';
            return;
        }

        if(x+1 <= 100000 && !visited[x+1]){
            q.push(x+1);
            visited[x+1] = visited[x] + 1;
        }

        if(x-1 >= 0 && !visited[x-1]){
            q.push(x-1);
            visited[x-1] = visited[x] + 1;
        }

        if(x+a <= 100000 && !visited[x+a]){
            q.push(x+a);
            visited[x+a] = visited[x] + 1;
        }

        if(x-a >= 0 && !visited[x-a]){
            q.push(x-a);
            visited[x-a] = visited[x] + 1;
        }

        if(x+b <= 100000 && !visited[x+b]){
            q.push(x+b);
            visited[x+b] = visited[x] + 1;
        }

        if(x-b >= 0 && !visited[x-b]){
            q.push(x-b);
            visited[x-b] = visited[x] + 1; 
        }

        if(x*a <= 100000 && !visited[x*a]){
            q.push(x*a);
            visited[x*a] = visited[x] + 1; 
        } 

        if(x*b <= 100000 && !visited[x*b]){
            q.push(x*b);
            visited[x*b] = visited[x] + 1; 
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    memset(visited, 0, sizeof(visited));
    cin >> a >> b >> n >> m;
    BFS(n, m);
    return 0;
}
