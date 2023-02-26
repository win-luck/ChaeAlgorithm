#include <iostream>
#include <vector>
#include <cstring>

#define INF 987654321
using namespace std;
int d[101][101];
int friends[101];
int T, n, m, a, b, c, k;
int result;

void init(){
    result = INF;
    cin >> n >> m;
    for(int i=1; i<=n; i++){ // 간선 초기화
        for(int j=1; j<=n; j++){
            if(i == j) d[i][j] = 0;
            else d[i][j] = INF;
        }
    }
    
    for(int i=0; i<m; i++){
        cin >> a >> b >> c;
        d[a][b] = c;
        d[b][a] = c; // 양방향
    }

    cin >> k;
    for(int i=0; i<k; i++){ // 친구들의 노드 저장
        cin >> friends[i];
    }
}

int main(){
    cin >> T;

    while(T--){
        init();

        for(int k=1; k<=n; k++){ // 플로이드-워셜
            for(int i=1; i<=n; i++){
                for(int j=1; j<=n; j++){
                    if(d[i][j] > d[i][k] + d[k][j]){
                        d[i][j] = d[i][k] + d[k][j];
                    }
                }
            }
        }

        int pos = 1;
        for(int i=1; i<=n; i++){
            int sum = 0;
            for(int j=0; j<k; j++){
                sum += d[i][friends[j]]; // 친구들을 연결짓는 거리를 계산하여 최소로 갱신함
            }
            if(result > sum){
                pos = i;
                result = sum;
            }
        }

        cout << pos << '\n'; // 최소가 되는 노드를 출력
    }

    return 0;
}