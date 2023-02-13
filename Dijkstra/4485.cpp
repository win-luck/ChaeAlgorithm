#include <iostream>
#include <queue>

#define INF 100000000
#define MAX 126
using namespace std;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int map[MAX][MAX]; // map[a].push_back({b, c}) -> a도시에서 b도시까지의 거리는 c
int dist[MAX][MAX];
int n;
bool endflag;

int dijkstra(){
    priority_queue<pair<int, pair<int, int> > > pq; // 맵의 비용, x좌표, y좌표
    pq.push(make_pair(-map[0][0], make_pair(0, 0))); // 우선순위 큐 활용을 위한 음수처리
    dist[0][0] = map[0][0]; // dist[a][b] -> 시작점으로부터 (a,b) 좌표까지의 비용

    while(!pq.empty()){
        int cost = -pq.top().first; // 현재 좌표까지의 비용
        int nowx = pq.top().second.first; // 현재 x,y좌표
        int nowy = pq.top().second.second;
        pq.pop();

        for(int i=0; i<4; i++){
            int newx = nowx + dx[i];
            int newy = nowy + dy[i];

            if(newx >= 0 && newx < n && newy >= 0 && newy < n){ // 맵의 범위 내에서
                int newcost = cost + map[newx][newy]; // 새롭게 계산한 비용이
                if(dist[newx][newy] > newcost){ // 기존의 거리값보다 작으면 갱신한다.
                    dist[newx][newy] = newcost;
                    pq.push(make_pair(-newcost, make_pair(newx, newy)));
                }
            }
        }
    }

    return dist[n-1][n-1];
}

void init(){ // 거리 초기화
    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            dist[i][j] = INF;
        }
    }
}

void input() { // 관련 값 입력 및 종료 감지
    cin >> n;
    if(n == 0) {
        endflag = true;
        return;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> map[i][j];
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int num = 0;

    while(1){
        init();
        input();
        if(endflag) break; // 0 입력시 프로그램 종료
        cout << "Problem " << ++num << ": " << dijkstra() << endl;
    }

    return 0;
}