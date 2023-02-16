#include <iostream>
#include <vector>

using namespace std;
int d[101][101];
int way[101][101];
int INF=100000000;

int main(){
    int N, M;
    cin >> N >> M;

    for(int i=1; i <= N; i++) {
        for(int j=1; j <= N; j++){
            if(i == j) {
                d[i][j] = 0;
            }
            else {
                d[i][j] = INF;
            }
        }
    }
    
    for(int a=1; a<=M; a++) {
        int x, y, input;
        cin >> x >> y >> input;
        
        d[x][y] = min(d[x][y], input); // 버스가 여러개면 가장 작은 것만 입력되도록
        way[x][y] = y;
        
    }
    
    for(int k=1; k<=N; k++) {
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++) {
                if(d[i][j] > d[i][k] + d[k][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                    way[i][j] = way[i][k]; // i에서 j로 갈 때 거치는 노드는 i에서 k로 갈 때 거치는 노드와 같다.
                }
            }
        }
    } // 플로이드 워셜 알고리즘
    
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            if(d[i][j] == INF || d[i][j] == 0) { // 만약 출발/도착도시가 같거나, 연결되어 있지 않으면 0
                cout << "0 ";
            } else { 
                // 그렇지 않으면 보통 출력
                cout << d[i][j] << " ";
            }
        }
        cout << '\n';
    }      

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(d[i][j] == INF || d[i][j] == 0){ // 만약 출발/도착도시가 같거나, 연결되어 있지 않으면 0
                cout << "0" << '\n';
                continue;
            }

            vector<int> route; // i부터 j까지 최단으로 움직이는 경로를 저장하자
            int nowpos = i; // 시작은 i
            while(nowpos != j){ // j 도착 전까지
                route.push_back(nowpos); // 움직이고 있는 위치를 저장한다.
                nowpos = way[nowpos][j]; 
                // 만약 경로가 1 -> 2 -> 4 -> 7 이라면, way[1][7] = way[1][4] = way[1][2] = 2이므로 nowpos에 2가 저장되고,
                // 그 다음 2 -> 4 -> 7 에서 way[2][7] = way[2][4] = 4이므로 nowpos에 4가 저장된다.
            }
            route.push_back(j);

            cout << route.size() << " "; // 형식에 맞게 경로의 길이와 실제 경로를 출력
            for(int i=0; i<route.size(); i++){
                cout << route[i] << " ";
            }
            cout << '\n';
        }
    }


}
