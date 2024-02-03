#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
int n, m, k;
int arr[51][51];
int tmp[51][51];
bool visited[51][51];
int answer = 100001;
vector<pair<int, pair<int, int> > > v;
vector<int> idx;

void init(){ // 배열 초기상태로 설정
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            arr[i][j] = tmp[i][j];
        }
    }
}

void rotate(int sx, int sy, int len){
    if(visited[sx][sy] || len < 2) {
        return;
    }

    // 위쪽 (->)
    int ex = sx + len - 1; // 격자 아래 끝부분
    int ey = sy + len - 1; // 격자 오른쪽 끝부분
    
    int tmp = arr[sx][ey];
    for(int i=ey; i>sy; i--){
        arr[sx][i] = arr[sx][i-1];
        visited[sx][i] = true;
    }

    // 왼쪽 (업)
    for(int i=sx; i<ex; i++){
        arr[i][sy] = arr[i+1][sy];
        visited[i][sy] = true;
    }

    // 아래쪽 (<-)
    for(int i=sy; i<ey; i++){
        arr[ex][i] = arr[ex][i+1];
        visited[ex][i] = true;
    }

    // 오른쪽 (다운)
    for(int i=ex; i>sx+1; i--){
        arr[i][ey] = arr[i-1][ey];
        visited[i][ey] = true;
    }
    arr[sx+1][ey] = tmp;
    visited[sx+1][ey] = true;
    
    rotate(sx+1, sy+1, len-2);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
            tmp[i][j] = arr[i][j];
        }
    }
    for(int i=0; i<k; i++){
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back(make_pair(c, make_pair(a-1, b-1)));
        idx.push_back(i);
    }

    do {
        init();
        for(int i=0; i<idx.size(); i++){
            memset(visited, false, sizeof(visited));
            int r = v[idx[i]].second.first;
            int c = v[idx[i]].second.second;
            int s = v[idx[i]].first;
            rotate(r-s, c-s, s*2 + 1);
        }
        for(int i=0; i<n; i++){
            int val = 0;
            for(int j=0; j<m; j++){
                val += arr[i][j];
            }
            answer = min(answer, val);
        }
    } while(next_permutation(idx.begin(), idx.end()));
    cout << answer;
    return 0;
}
