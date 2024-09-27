#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int n, m, d, p;
int answer = 0;
int arr[16][16];
int exist[16][16] = {0, };
vector<pair<int, int> > pos;

// 특수 영양제를 이동 규칙에 따라 이동시킵니다.
void func1(){
    d--;
    vector<pair<int, int> > tmp;
    for(int i=0; i<pos.size(); i++){
        int x = pos[i].first;
        int y = pos[i].second;
        exist[x][y]--;

        int nx = x + (dx[d] * p);
        int ny = y + (dy[d] * p);
        if(nx < 0){
            nx += n;
        }
        if(nx >= n){
            nx -= n;
        }
        if(ny < 0){
            ny += n;
        }
        if(ny >= n){
            ny -= n;
        }
        tmp.push_back(make_pair(nx, ny));
        exist[nx][ny]++;
    }
    pos.clear();
    pos = tmp;
}

void func2(){
    // 특수 영양제가 있는 땅의 리브로수는 높이가 1만큼 증가
    for(int i=0; i<pos.size(); i++){
        arr[pos[i].first][pos[i].second]++;
    }

    int add[pos.size()] = {0, };
    for(int i=0; i<pos.size(); i++){
        int x = pos[i].first;
        int y = pos[i].second;

        int cnt = 0;
        // 대각선으로 인접한 높이 1 이상의 리브로수의 개수 만큼 높이가 증가
        for(int j=1; j<8; j+=2){
            int nx = x + dx[j];
            int ny = y + dy[j];
            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if(arr[nx][ny] >= 1) cnt++;
        }
        add[i] += cnt;
    }

    for(int i=0; i<pos.size(); i++){
        arr[pos[i].first][pos[i].second] += add[i];
    }

    // 해당 년도에 특수 영양제를 맞은 땅을 제외하고 
    // 높이가 2 이상인 리브로수를 높이 2만큼 잘라내고 해당 땅 위에 특수 영양제
    vector<pair<int, int> > tmp;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j] >= 2 && !exist[i][j]){
                arr[i][j] -= 2;
                tmp.push_back(make_pair(i, j));
                exist[i][j] = true;
            }
        }
    }

    for(auto it: pos){
        exist[it.first][it.second] = false;
    }
    pos.clear();
    pos = tmp;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }
    // 특수 영양제의 초기 위치
    pos.push_back(make_pair(n-2, 0));
    exist[n-2][0]++;
    pos.push_back(make_pair(n-2, 1));
    exist[n-2][1]++;
    pos.push_back(make_pair(n-1, 0));
    exist[n-1][0]++;
    pos.push_back(make_pair(n-1, 1));
    exist[n-1][1]++;

    while(m--){
        cin >> d >> p;
        func1();
        func2();
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            answer += arr[i][j];
        }
    }
    cout << answer;
    return 0;
}
