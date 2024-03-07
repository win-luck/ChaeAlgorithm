#include <iostream>
#include <algorithm>
#include <queue>

#define MAX 1000001
using namespace std;

bool not_prime[MAX];
bool visited[MAX];
int t, n, a, b;
int answer = -1;

bool find(int a, int b){
    for(int i=a; i<=b; i++){
        if(!not_prime[i]) return true;
    }
    return true;
}

void bfs(int x){
    fill(visited, visited + MAX, false);
    queue<pair<int, int> > q;
    q.push(make_pair(x, 0));
    visited[x] = true;

    while(!q.empty()){
        int now = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if(!not_prime[now] && a <= now && now <= b){
            answer = cnt;
            return;
        }

        if(!visited[now/2]){
            visited[now/2] = true;
            q.push(make_pair(now/2, cnt+1));
        }

        if(!visited[now/3]){
            visited[now/3] = true;
            q.push(make_pair(now/3, cnt+1));
        }

        if(now+1 < MAX && !visited[now+1]){
            visited[now+1] = true;
            q.push(make_pair(now+1, cnt+1));
        }

        if(now >= 1 && !visited[now-1]){
            visited[now-1] = true;
            q.push(make_pair(now-1, cnt+1));
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    not_prime[1] = true;
    for(int i=2; i*i<=MAX; i++){
        if(!not_prime[i]){
            for(int j=2; i*j<=MAX; j++){
                not_prime[i*j] = true;
            }
        }
    }

    cin >> t;
    while(t--){
        answer = -1;
        cin >> n >> a >> b;
        if(!find(a, b)){
            cout << -1 << '\n';
            continue;
        }
        bfs(n);
        cout << answer << '\n';
    }
    return 0;
}
