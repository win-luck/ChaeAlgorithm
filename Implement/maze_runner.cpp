#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
int n, m, t, ex, ey;
vector<pair<int, int> > v;
int arr[11][11]; // 좌표별 벽 정보
int answer = 0;
map<int, pair<int, int> > dict;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// 사각형 크기 오름차순, 행/열 번호 오름차순 정렬
bool cmp(pair<int, pair<int, int> > p1, pair<int, pair<int, int> > p2){
    if(p1.first == p2.first){
        if(p1.second.first == p2.second.first){
            return p1.second.second < p2.second.second;
        }
        return p1.second.first < p2.second.first;
    }
    return p1.first < p2.first;
}

// 좌표 오름차순 정렬
bool cmp2(pair<int, int> p1, pair<int, int> p2){
    if(p1.second == p2.second){
        return p1.second < p2.second;
    }
    return p1.first < p2.first;
}

// 디버깅용
void print(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
}

// 참가자들이 이동
void move(){
    for(int i=v.size()-1; i>=0; i--){
        if(v[i].first == ex && v[i].second == ey) {
            v.erase(v.begin() + i);
            continue;
        }
        pair<int, int> now = v[i];
        if(now.first == ex && now.second == ey) continue;
        int nowdis = abs(ex - now.first) + abs(ey - now.second); // 현재 출구까지의 거리

        for(int a=0; a<4; a++){
            int nx = now.first + dx[a];
            int ny = now.second + dy[a];

            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue; // 이탈
            if(arr[nx][ny] > 0) {
                continue; // 벽
            }
            int nextdis = abs(ex - nx) + abs(ey - ny); // 다음 좌표 기준 출구까지의 거리
            if(nowdis > nextdis){ // 이동 가능
                answer++;
                v[i] = make_pair(nx, ny);
                break;
            }
        }
    }
    if(!v.empty())
        sort(v.begin(), v.end(), cmp2);
}

// 특정 영역 회전
void rotate(int r, int c, int size){
    int tmp[11][11]; // 임시 arr
    vector<pair<int, int> > tmpvec; // 임시 v

    // 영역에 들어있는 사람 추적
    for(int i=v.size()-1; i>=0; i--){
        if(v[i].first >= r && v[i].first < r+size && v[i].second >= c && v[i].second < c+size){
            if(!(v[i].first == ex && v[i].second == ey)){
                tmpvec.push_back(v[i]);
            }
            v.erase(v.begin() + i);
        }
    }

    for(int i=r; i<r+size; i++){
        for(int j=c; j<c+size; j++){
            tmp[i][j] = arr[i][j];
        }
    }

    // 시계방향 90도 회전
    for(int i=r; i<r+size; i++){
        for(int j=c; j<c+size; j++){
            tmp[j - c + r][r + c + size - 1 - i] = arr[i][j];
        }
    }

    for(int i=r; i<r+size; i++){
        for(int j=c; j<c+size; j++){
            arr[i][j] = tmp[i][j];
            if(arr[i][j] == -1){ // 출구 조정
                ex = i;
                ey = j;
            }
        }
    }

    // 사람 좌표 갱신
    for(auto& it: tmpvec){
        int x = it.first;
        int y = it.second;
        int nx = y - c + r; // 회전된 x 좌표
        int ny = r + c + size - 1 - x; // 회전된 y 좌표
        v.push_back(make_pair(nx, ny));
    }
    sort(v.begin(), v.end(), cmp2);

    // 회전 후 내구도 감소
    for(int i=r; i<r+size; i++){
        for(int j=c; j<c+size; j++){
            if(arr[i][j] > 0) arr[i][j]--; 
        }
    }
}

// 회전시킬 영역을 결정
void rotateFunc(){
    vector<pair<int, pair<int, int> > > info;
    for(int k=2; k<=n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i+k > n || j+k > n) continue;
                bool exit = false; // 출구 존재 여부
                bool user = false; // 참가자 존재 여부
                for(int a=i; a<i+k; a++){
                    for(int b=j; b<j+k; b++){
                        int sx = 0;
                        int sy = 0;
                        if(a < 0 || b < 0 || a >= n || b >= n) continue;
                        if(a == ex && b == ey) exit = true;

                        for(auto &it: v){
                            if(it.first >= i && it.first < i+k && it.second >= j && it.second < j+k){
                                if(it.first == ex && it.second == ey) continue;
                                sx = it.first;
                                sy = it.second;
                                user = true;
                                break;
                            }
                        }
                        if(exit == true && user == true){ // 둘 다 존재함 -> 현재 k, i, j 등록
                            rotate(i, j, k);
                            return;
                        }
                    }
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> t;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }
    for(int i=1; i<=m; i++){
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(a-1, b-1));
    }
    cin >> ex >> ey;
    arr[--ex][--ey] = -1;

    for(int i=1; i<=t; i++){
        move();
        rotateFunc();
    }
    cout << answer << '\n';
    cout << ex+1 << " " << ey+1;
    return 0;
}
