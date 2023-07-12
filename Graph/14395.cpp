#include <iostream>
#include <queue>
#include <vector>
#include <map>

using namespace std;

long long s, t;
map<long long, bool> m;
queue<pair<string, long long> > q;
string d[4] = {"*", "+", "-", "/"};

long long cal(long long a, int idx){
    if(idx == 0) return a * a;
    else if(idx == 1) return 2*a;
    else if(idx == 2) return 0;
    else return 1;
}

void BFS(){
    q.push(make_pair("", s));

    while(!q.empty()){
        string seq = q.front().first;
        long long x = q.front().second;
        q.pop();

        if(x == t){ // 도착
            cout << seq << '\n';
            return;
        }

        for(int i=0; i<4; i++){
            long long nx = cal(x, i);
            if(nx < 1) continue; // 0은 의미가 없음
            if(m[nx]) continue; // 이미 시도한 연산
            m[nx] = true;
            q.push(make_pair(seq + d[i], nx));
        }
    }
    cout << -1 << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> s >> t;
    if(s == t) {
        cout << 0 << '\n';
    }
    else {
        BFS();
    }
    return 0;
}

