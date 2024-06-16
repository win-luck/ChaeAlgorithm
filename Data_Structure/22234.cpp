#include <iostream>
#include <queue>
#include <map>

using namespace std;
int n, m, t, w;
queue<pair<int, int> > q;
map<int, pair<int, int> > times;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> t >> w;
    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
        q.push(make_pair(a, b));
    }
    cin >> m;
    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        times[c] = make_pair(a, b); // c초에 id가 a인 고객이 진입
    }

    int now = 0;
    while(1){
        pair<int, int> p = q.front(); // id-잔여시간
        q.pop();

        bool flag = false;
        for(int i=0; i<min(p.second, t); i++){
            cout << p.first << '\n';
            now++;
            if(now == w){
                flag = true;
                break;
            }
            if(times.find(now) != times.end()){
                pair<int, int> next = times[now];
                q.push(next);
            }
        }
        if(p.second > t){
            q.push(make_pair(p.first, p.second-t));
        }
        if(flag) break;
    }
    return 0;
}
