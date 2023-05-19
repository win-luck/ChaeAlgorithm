#include <iostream>

#define INF 10000
using namespace std;
int n, d;
int res = 0;
string str;
char fr[51][51];
int dist[51][51];

int main(){
    cin >> n;
    cin >> d;

    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            if(i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }

    for(int i=1; i<=n; i++){ // 두 친구의 최초 거리는 d
        cin >> str;
        for(int j=1; j<=n; j++){
            fr[i][j] = str[j-1];
            if(fr[i][j] == 'Y'){
                dist[i][j] = d;
            }
        }
    }

    for(int k=1; k<=n; k++){ // 플로이드-워셜로 노드 간 최단거리 계산
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for(int i=1; i<=n; i++){ // 만들어진 경로 중 가장 긴 것을 찾아 출력
        for(int j=1; j<=n; j++){
            if(i == j) continue;
            if(res < dist[i][j]){
                res = dist[i][j];
            }
        }
    }
    if(res >= INF) cout << -1 << '\n'; // 단 INF보다 크거나 같으면 -1 출력
    else cout << res << '\n';
    return 0;
}