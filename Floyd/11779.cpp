#include <iostream>
#include <vector>
#define INF 100000000

using namespace std;

int d[1001][1001];
int city[1001][1001];
int n, m, s, e, v;

int main(){
    cin >> n >> m;

    for(int i=1; i<=n; i++){ // 초기화
        for(int j=1; j<=n; j++){
            if(i == j) d[i][j] = 0;
            else d[i][j] = INF;
        }
    }

    for(int i=0; i<m; i++){
        cin >> s >> e >> v;
        if(d[s][e] > v){ // A에서 B로 가는 경로가 여러 개 존재할 수 있기에 가장 작은 것으로만 갱신한다.
            d[s][e] = v;
            city[s][e] = e;
        }
    }

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(d[i][j] > d[i][k] + d[k][j]){
                    d[i][j] = d[i][k] + d[k][j];
                    city[i][j] = city[i][k]; // 경로 저장
                }
            }
        }
    }

    int start, end;
    cin >> start >> end;

    vector<int> result;

    int temp = start; // 최단 거리로 이동할 때의 노드를 저장
    while(temp != end){
        result.push_back(temp);
        temp = city[temp][end];
    }
    result.push_back(temp);

    cout << d[start][end] << '\n';
    cout << result.size() << '\n';
    for(int i=0; i<result.size(); i++){
        cout << result[i] << " ";
    }
}