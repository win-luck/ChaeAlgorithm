#include <iostream>
#include <algorithm>
#include <vector>

#define INF 9876543
using namespace std;
int n, t, m, x, y, s;
int check[1001]; // 특별한 도시 여부 저장
int dist[1001][1001];
vector<pair<int, int> > pos;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    pos.push_back(make_pair(0, 0)); // 인덱스 1~N번으로 맞추기 위함

    cin >> n >> t;
    for(int i=1; i<=n; i++){
        cin >> s >> x >> y;
        check[i] = s;
        pos.push_back(make_pair(x, y));
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i == j) dist[i][j] = 0;
            else dist[i][j] = abs(pos[i].first - pos[j].first) + abs(pos[i].second - pos[j].second);
            if(check[i] && check[j]){
                dist[i][j] = min(dist[i][j], t);
            }
        }
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

    cin >> m; // A에서 B로 가는 최소이동시간 출력
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        cout << dist[a][b] << '\n';
    }
    return 0;
}
