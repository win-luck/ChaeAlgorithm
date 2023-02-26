#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;
int T, n, a, b;
double result;
int visited[21];
vector<pair<int, int> > pos;

void solve(){ // 벡터 매칭 : n/2개의 벡터들을 더하고 빼어 그 남은 거리가 정답이다.
    double x = 0;
    double y = 0;
    for(int i=0; i<n; i++){
        if(visited[i]){
            x -= pos[i].first;
            y -= pos[i].second;
        } else {
            x += pos[i].first;
            y += pos[i].second;
        }
    }
    result = min(result, sqrt(pow(x, 2) + pow(y, 2)));
}

void DFS(int nowpos, int cnt){
    if(cnt == n/2){ // n/2개의 벡터를 선택하였다면
        solve();
        return;
    }

    for(int i=nowpos; i<n; i++){
        visited[i] = 1;
        DFS(i + 1, cnt + 1);
        visited[i] = 0;
    }
}

int main(){
    cin >> T;
    while(T--){
        pos.clear(); // 초기화
        memset(visited, false, sizeof(visited));
        result = 100000000;

        cin >> n;
        for(int i=0; i<n; i++){
            cin >> a >> b;
            pos.push_back(make_pair(a, b));
        } // 입력

        DFS(0, 0);

        printf("%.7lf\n", result);
    }
    return 0;
}