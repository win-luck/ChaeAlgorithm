#include <iostream>

using namespace std;
int d[101][101];
int INF=100000000;

int main(){
    int N, M;
    cin >> N >> M;

    for(int i=1; i <= N; i++) {
        for(int j=1; j <= N; j++){
            d[i][j] = INF;
        }
    }
    
    for(int a=1; a<=M; a++) {
        int x, y, input;
        cin >> x >> y >> input;
        
        if(input < d[x][y]) {
            // 버스가 여러개면 가장 작은 것만 입력되도록
            d[x][y] = input;
        }
    }
    
    for(int k=1; k<=N; k++) {
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++) {
                if(d[i][j] > d[i][k] + d[k][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    } // 플로이드 워셜 알고리즘
    
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            if(i == j || d[i][j] == INF) {
                // 만약 출발/도착도시가 같거나, 연결되어 있지 않으면 0
                cout << "0 ";
            } else { 
                // 그렇지 않으면 보통 출력
                cout << d[i][j] << " ";
            }
        }
        cout << '\n';
    }      
}
