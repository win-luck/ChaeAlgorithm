#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

#define INF 987654321
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t, n;

    cin >> t;
    for(int a=0; a<t; a++){
        long long answer = 0;
        bool flag = false;
        long long dist[201][201];
        vector<int> v;

        cin >> n;
        for(int i=0; i<n; i++){
            int p;
            cin >> p;
            v.push_back(p);
        } // 이동할 순서 계산 (마지막엔 출발 도시로 돌아온다.)
        v.push_back(v[0]);

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin >> dist[i][j];
                if(dist[i][j] == -1) dist[i][j] = INF;
            }
        }

        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(dist[i][j] > dist[i][k] + dist[k][j]){
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        for(int i=0; i<v.size()-1; i++){
            if(dist[v[i]][v[i+1]] >= INF){
                flag = true;
                break;
            }

            answer += dist[v[i]][v[i+1]];
        }

        if(flag) cout << "impossible" << '\n';
        else cout << answer << '\n';
    }
    return 0;
}