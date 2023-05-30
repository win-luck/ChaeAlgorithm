#include <iostream>
#include <algorithm>
#include <vector>

#define INF 10000000
using namespace std;
int n, m;
int dist[101][101];
vector<int> v;

int main(){
    cin >> n >> m;

    for(int i=0; i<m; i++){
        int a;
        cin >> a;
        v.push_back(a);
    } // 경로

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> dist[i][j];
        }
    } // i에서 j로 가는 데 걸리는 비용

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    int sum = 0;
    int a = v.front();
    for(int i=1; i<v.size(); i++){
        int b = v[i];
        sum += dist[a][b];
        a = v[i];
    }
    cout << sum;
    return 0;
}