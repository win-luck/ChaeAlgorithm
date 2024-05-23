#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#define INF 987654321

using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    int dist[201][201];
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }
    for(int i=0; i<fares.size(); i++){
        dist[fares[i][0]][fares[i][1]] = fares[i][2];
        dist[fares[i][1]][fares[i][0]] = fares[i][2];       
    }
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    for(int i=1; i<=n; i++){
        if(dist[s][i] != INF && dist[i][a] != INF && dist[i][b] != INF){
            answer = min(answer, dist[s][i] + dist[i][a] + dist[i][b]);
        }
    }
    return answer;
}
