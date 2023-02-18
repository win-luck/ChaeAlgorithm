#include <iostream>

using namespace std;
#define INF 10000000
int d[501][501];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc, n, m, w, s, e, t;
    cin >> tc;

    for(int i=0; i<tc; i++){ // 음수 가중치는 벨만포드 혹은 플로이드-워셜
        cin >> n >> m >> w;

        for(int i=1; i<=n; i++){ // 초기화
            for(int j=1; j<=n; j++){
                if(i == j) d[i][j] = 0; 
                else d[i][j] = INF;
            }
        }

        for(int j=0; j<m; j++){
            cin >> s >> e >> t;
            if(d[s][e] > t) { // 같은 구간을 중복 삽입하는 경우 최소로 갱신해야 함.
                d[s][e] = t;
                d[e][s] = t;
            }
        }
        for(int j=0; j<w; j++){
            cin >> s >> e >> t;
            if(d[s][e] > -t){
                d[s][e] = -t;
            }
        }

        // 플로이드-워셜 알고리즘
        for(int k=1; k<=n; k++){ // 경유점에 해당하는 노드가 제일 위에 있어야 하고
            for(int i=1; i<=n; i++){ // 그 다음 출발점
                for(int j=1; j<=n; j++){ // 그 다음 도착점이 된다.
                    if(d[i][k] + d[k][j] < d[i][j]){
                        d[i][j] = d[i][k] + d[k][j];
                    }
                }
            }
        }

        bool flag = false;
        for(int i=1; i<=n; i++){
            if(d[i][i] < 0){ // 음수가 가능한 경우가 존재하면 yes
                flag = true;
                break;
            }
        }
        if(flag){
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }

    return 0;
}