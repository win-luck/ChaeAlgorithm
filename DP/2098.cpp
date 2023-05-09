#include <iostream>

#define INF 987654321
using namespace std;
int n, e;
int dist[16][16];
int dp[16][1 << 16];

int TSP(int now, int visited){
	// 모든 노드를 방문
	if(visited == e){
		if(dist[now][0] > 0){ // 0으로 돌아가는 경로가 존재한다면 반호나
			return dist[now][0];
		}

		return INF; // 불가능한 경우에는 INF 반환 
	}

	// 현재 상태를 이미 계산한 값이 dp 테이블에 있다면 그대로 사용
	if(dp[now][visited] != 0) return dp[now][visited];
	dp[now][visited] = INF; 
    
	for(int i = 0; i < n; i++){
		// 현재 i번 노드로 가는 경로가 없음
		if(dist[now][i] == 0) continue;
        
		// 이미 방문한 노드
		if(visited & (1 << i)) continue;

		// i번 노드 방문
		int temp = TSP(i, visited | 1 << i); 
		dp[now][visited] = min(dp[now][visited], dist[now][i] + temp); 
	}

	return dp[now][visited]; // 최소 비용 반환 
}

int main()
{ 
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	cin >> n;
	e = (1 << n) - 1;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> dist[i][j]; 
		}
	}
	
	cout << TSP(0, 1) << "\n"; 
	return 0;
}