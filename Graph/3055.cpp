#include <iostream>
#include <queue>

using namespace std;
int r, c;
char map[51][51];
int endr, endc;
int res = 0;
queue<pair<int, int> > gosm_q;
queue<pair<int, int> > water_q;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void BFS(){ // 물 확장 이후 고슴도치가 움직인다.

    while(!gosm_q.empty()){
        int watercnt = water_q.size(); // 확장하는 물의 좌표 개수

        for(int i=0; i<watercnt; i++){
            int wx = water_q.front().first;
            int wy = water_q.front().second;

            water_q.pop();
            for(int j=0; j<4; j++){
                int wnx = wx + dx[j];
                int wny = wy + dy[j];

                if(wnx < 0 || wny < 0 || wnx >= r || wny >= c) continue;
                if(map[wnx][wny] == '.'){ // 물의 확장
                    map[wnx][wny] = '*';
                    water_q.push(make_pair(wnx, wny));
                }
            }
        }

        int gosmcnt = gosm_q.size(); // 고슴도치의 이동
        for(int i=0; i<gosmcnt; i++){
            int gx = gosm_q.front().first;
            int gy = gosm_q.front().second;

            gosm_q.pop();

            for(int j=0; j<4; j++){
                int gnx = gx + dx[j];
                int gny = gy + dy[j];

                if(gnx == endr && gny == endc){ // 도착
                    cout << ++res << '\n';
                    return;
                }

                if(gnx < 0 || gny < 0 || gnx >= r || gny >= c) continue;
                if(map[gnx][gny] == '.'){ // 고슴도치 이동
                    map[gnx][gny] = 'S';
                    gosm_q.push(make_pair(gnx, gny));
                }
            }
        }
        res++;
    }
    cout << "KAKTUS"; // 큐 이탈 -> 실패
}

void input(){
    string str;
    cin >> r >> c;
    for(int i=0; i<r; i++){
        cin >> str;
        for(int j=0; j<c; j++){
            map[i][j] = str[j];
            if(map[i][j] == 'D'){ // 도착점
                endr = i;
                endc = j;
            } else if(map[i][j] == 'S'){ // 고슴도치
                gosm_q.push(make_pair(i, j));
            } else if(map[i][j] == '*'){ // 물
                water_q.push(make_pair(i, j));
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    BFS();
    return 0;
}