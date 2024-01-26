#include <iostream>
#include <vector>
#include <cstring>
#include <map>

using namespace std;
struct fireball{
    int r, c, m, d, s;
    fireball(int ar, int ac, int am, int as, int ad){
        r=ar;
        c=ac;
        m=am;
        d=ad;
        s=as;
    }
};
int n, m, k;
vector<fireball> v;
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    for(int i=0; i<m; i++){
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        v.push_back(fireball(a, b, c, d, e));
    }

    while(k--){
        map<pair<int, int>, vector<int> > dict;
        for(int i=0; i<v.size(); i++){
            fireball f = v[i];
            int nx = f.r + dx[f.d] * f.s; // 방향 d로 속력 s만큼 이동
            int ny = f.c + dy[f.d] * f.s;
            while(nx < 0)
                nx += n;
            while(nx >= n)
                nx -= n;
            while(ny < 0)
                ny += n;
            while(ny >= n)
                ny -= n;
            v[i].r = nx;
            v[i].c = ny;
            dict[make_pair(v[i].r, v[i].c)].push_back(i);
        }

        vector<fireball> tmp;
        // 2개 이상의 파이어볼이 있는 칸을 탐지
        for(auto it: dict){
            int sr = it.first.first;
            int sc = it.first.second;
            vector<int> now = it.second;
            if(now.size() == 0) continue;
            else if(now.size() == 1){
                tmp.push_back(fireball(sr, sc, v[now[0]].m, v[now[0]].s, v[now[0]].d));
            } else {
                int totalm = 0;
                int totals = 0;
                int cnt = now.size();
                int flaga = 0;
                int flagb = 0;

                for(int i=0; i<cnt; i++){
                    totalm += v[now[i]].m;
                    totals += v[now[i]].s;
                    if(v[now[i]].d % 2 == 1){
                        flaga++;
                    } else {
                        flagb++;
                    }
                }

                int newm = totalm / 5;
                int news = totals / cnt;
                if(newm == 0) continue; // 질량이 0이면 소멸
                if(flaga == cnt || flagb == cnt){ // 모두 홀수거나 모두 짝수거나
                    for(int i=0; i<=6; i+=2){
                        tmp.push_back(fireball(sr, sc, newm, news, i));
                    }
                } else {
                    for(int i=1; i<=7; i+=2){
                        tmp.push_back(fireball(sr, sc, newm, news, i));
                    }
                }
            }
        }
        v = tmp;
    }
    int answer = 0;
    for(int i=0; i<v.size(); i++){
        answer += v[i].m;
    }
    cout << answer;
    return 0;
}
