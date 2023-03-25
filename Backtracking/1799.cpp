#include <iostream>
#include <vector>

using namespace std;
int t, s, n;
char map[7][7];
vector<pair<int, int> > tpos;
bool result;

bool validcheck(){
    for(int i=0; i<tpos.size(); i++){
        int x = tpos[i].first; // 행
        int y = tpos[i].second; // 열

        for(int i=y+1; i<n; i++){ // 선생 기준으로 상하좌우를 쭉 뻗어나가며 학생 감지
            if(map[x][i] == 'O') break; // 장애물 확인 시 더 이상 그쪽 방향으로 진행하지 않음
            if(map[x][i] == 'S') return false;
        }

        for(int i=y-1; i>=0; i--){
            if(map[x][i] == 'O') break;
            if(map[x][i] == 'S') return false;
        }

        for(int i=x-1; i>=0; i--){
            if(map[i][y] == 'O') break;
            if(map[i][y] == 'S') return false;
        }

        for(int i=x+1; i<n; i++){
            if(map[i][y] == 'O') break;
            if(map[i][y] == 'S') return false;
        }
    }
    return true;
}

void DFS(int depth){
    if(result) return; // 하나라도 가능하면 더 이상 진행할 필요 없음
    if(depth == 3){ // 장애물 3개 배치 완료
        result = validcheck();
        return;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(map[i][j] == 'O') continue; // 장애물 배치
            if(map[i][j] == 'X'){
                map[i][j] = 'O';
                DFS(depth + 1);
                map[i][j] = 'X';
            }
        }
    }

}

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> map[i][j];
            if(map[i][j] == 'T'){ // 선생님 좌표 저장 
                tpos.push_back(make_pair(i, j));
            }
        }
    }

    DFS(0);

    if(result) cout << "YES";
    else cout << "NO";
    return 0;
}