#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
int n;
int like[401][4]; // 학생이 좋아하는 사람
int pos[401][401]; // 학생 번호
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
vector<int> v;

void input(){ // 입력
    cin >> n;
    for(int i=1; i<=n*n; i++){
        int a;
        cin >> a;
        for(int j=0; j<4; j++){
            cin >> like[a][j];
        }
        v.push_back(a);
    }
    memset(pos, 0, sizeof(pos));
}

int satisfy(int cnt){ // 학생별 만족도 계산
    if(cnt == 1) return 1;
    else if(cnt == 2) return 10;
    else if(cnt == 3) return 100;
    else if(cnt == 4) return 1000;
    else return 0;
}

void getscore(){ // 총점수 계산
    int answer = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int cnt = 0;
            for(int a=0; a<4; a++){
                int nx = i + dx[a];
                int ny = j + dy[a];
                int num = pos[i][j]; // 특정 학생
                if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                for(int b=0; b<4; b++){ // 이 좋아하는 학생인지 판정
                    if(pos[nx][ny] == like[num][b]){
                        cnt++;
                        break;
                    }
                }
            }
            answer += satisfy(cnt);
        }
    }
    cout << answer;
}

bool cmp(pair<pair<int, int>, pair<int, int> > p1, pair<pair<int, int>, pair<int, int> > p2){ // 문제 요구에 따른 정렬
    if(p1.first.first == p2.first.first){
        if(p1.first.second == p2.first.second){
            if(p1.second.first == p2.second.first){
                return p1.second.second < p2.second.second;
            }
            return p1.second.first < p2.second.first;
        }
        return p1.first.second > p2.first.second;
    }
    return p1.first.first > p2.first.first;
}

void sit(int x, int y, int idx){
    pos[x][y] = v[idx];
    if(idx == n*n-1) return; // 종료조건

    vector<pair<pair<int, int>, pair<int, int> > > tmp;
    int next = v[idx+1]; // 다음 학생
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!pos[i][j]){ // 비어있는 칸일 때
                int likecnt = 0; // 좋아하는 학생 수
                int blankcnt = 0; // 빈칸 수
                for(int a=0; a<4; a++){
                    int nx = i + dx[a];
                    int ny = j + dy[a];
                    if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                    if(!pos[nx][ny]){
                        blankcnt++;
                        continue;
                    }
                    for(int b=0; b<4; b++){
                        if(pos[nx][ny] == like[next][b]){
                            likecnt++;
                            break;
                        }
                    }
                }
                tmp.push_back(make_pair(make_pair(likecnt, blankcnt), make_pair(i, j))); // (좋아하는 학생 수, 빈칸 수, 행, 열)
            }
        }
    }
    sort(tmp.begin(), tmp.end(), cmp);
    sit(tmp.front().second.first, tmp.front().second.second, idx+1); // 다음 학생 진행
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    input();
    sit(1, 1, 0);  
    getscore();
    return 0;
}
