#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
int notPrime[10001];
int visited[10001];
int t, s, e;

void bfs(){
    queue<int> q;
    q.push(s);
    visited[s] = 1;

    while(!q.empty()){
        int x = q.front();
        q.pop();

        if(x == e){
            cout << visited[x]-1 << '\n';
            return;
        }

        int num[4];
        int tmp = x;
        for(int i=0; i<4; i++){
            num[i] = x % 10;
            x /= 10;
        }

        // 원래 수 -> num[3]*1000 + num[2]*100 + num[1]*10 + num[0]
        for(int i=0; i<4; i++){
            int now = num[i]; // 원상복구를 위한 자릿수의 최초값 저장
            for(int j=0; j<=9; j++){
                if(i == 3 && j == 0) continue;
                num[i] = j;
                int next = num[3]*1000 + num[2]*100 + num[1]*10 + num[0];
                if(!notPrime[next] && !visited[next]){
                    visited[next] = visited[tmp] + 1;
                    q.push(next);
                }
            }
            num[i] = now;
        }
    }
    cout << "Impossible\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    notPrime[1] = true; // 에라스토테네스의 체
    for(int i=2; i*i<=10000; i++){
        if(!notPrime[i]){
            for(int j=2; i*j<=10000; j++){
                notPrime[i*j] = true;
            }
        }
    }

    cin >> t;
    while(t--){
        memset(visited, 0, sizeof(visited));
        cin >> s >> e;
        if(s == e){
            cout << 0 << '\n';
            continue;
        }
        bfs();
    }
    return 0;
}
