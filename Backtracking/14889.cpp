#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
int n;
int map[21][21];
bool visited[21];
int result = 987654321;

int score(){
    vector<int> start;
    vector<int> link;
    int ssum = 0;
    int lsum = 0;

    for(int i=0; i<n; i++){ // 팀 구성
            if(visited[i]){
                start.push_back(i);
            } else {
                link.push_back(i);
            }
    }

    for(int i=0; i<n/2; i++){ // 점수 계산
        for(int j=0; j<n/2; j++){
            ssum += map[start[i]][start[j]];
            lsum += map[link[i]][link[j]];
        }
    }

    return abs(ssum - lsum);
}

void DFS(int idx, int depth){
    if(depth == n / 2){ // 팀이 반으로 쪼개짐
        result = min(result, score());
        return;
    }

    for(int i=idx; i<n; i++){ // true, false로 팀 분할
        if(!visited[i]){
            visited[i] = true;
            DFS(i, depth + 1);
            visited[i] = false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> map[i][j];
        }
    }

    DFS(0, 0);
    cout << result << '\n';
    return 0;
}