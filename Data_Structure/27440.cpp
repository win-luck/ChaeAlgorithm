#include <iostream>
#include <map>
#include <queue>

using namespace std;

long long n;
map<long long, long long> m;
queue<long long> q;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    q.push(n);
    m[n] = 0;
    while(!q.empty()){
        long long x = q.front();
        q.pop();
        if(x == 1) break; // 종료조건

        if(x % 3 == 0){
            if(m.count(x/3) == 0){
                m[x/3] = m[x] + 1;
                q.push(x/3);
            }
        }
        if(x % 2 == 0){
            if(m.count(x/2) == 0){
                m[x/2] = m[x] + 1;
                q.push(x/2);
            }
        }
        if(x >= 2){
            if(m.count(x-1) == 0){
                m[x-1] = m[x] + 1;
                q.push(x-1);
            }
        }
    }
    cout << m[1];
    return 0;
}