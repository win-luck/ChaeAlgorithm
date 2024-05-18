#include <string>
#include <iostream>
#include <vector>

using namespace std;
int map[101][101];
int n, m;

int rotate(int x1, int y1, int x2, int y2){
    // x1행 y1열부터 x2행 y2열까지 테두리를 시계방향으로 회전
    // 테두리 부분만 회전하며 내부는 회전하지 않는다.
    // 회전한 모든 숫자 중 최솟값을 구하면 된다.
    
    // 오른쪽
    int tmp = map[x2][y2];
    int val = tmp;
    for(int i=x2; i>=x1+1; i--){
        map[i][y2] = map[i-1][y2];
        val = min(val, map[i-1][y2]);
    }
    
    // 위쪽
    for(int i=y2; i>=y1+1; i--){
        map[x1][i] = map[x1][i-1];
        val = min(val, map[x1][i-1]);
    }
    
    // 왼쪽
    for(int i=x1; i<=x2-1; i++){
        map[i][y1] = map[i+1][y1];
        val = min(val, map[i+1][y1]);
    }
    
    // 아래
    for(int i=y1; i<y2-1; i++){
        map[x2][i] = map[x2][i+1];
        val = min(val, map[x2][i+1]);
    }
    
    map[x2][y2-1] = tmp;
    return val;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    n = rows;
    m = columns;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            map[i][j] = (i-1)*m + j;
        }
    }
    for(int i=0; i<queries.size(); i++){
        int minval = rotate(queries[i][0], queries[i][1], queries[i][2], queries[i][3]);
        answer.push_back(minval);
    }
    return answer;
}
