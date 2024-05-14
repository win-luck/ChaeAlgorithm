#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<string> map;
int N, M;

vector<pair<int, int>> search(){
    vector<pair<int, int>> v;
    for(int i=0; i<N-1; i++){
        for(int j=0; j<M-1; j++){
            if(map[i][j] != '0' && map[i][j] == map[i][j+1] && map[i+1][j] == map[i+1][j+1] && map[i][j] == map[i+1][j+1]){
                v.push_back({i, j});
                v.push_back({i+1, j});
                v.push_back({i, j+1});
                v.push_back({i+1, j+1});
            }
        }
    }
    return v;
}

void remove(vector<pair<int, int>> target){
    for(int i=0; i<target.size(); i++){
        map[target[i].first][target[i].second] = '0';
    }
    
    for(int i=0; i<M; i++){
        int bidx = -1;
        int tidx = -1;
        for(int j=N-1; j>=0; j--){
            if(map[j][i] == '0'){
                if(bidx == -1) bidx = j;
            }
            
            if(bidx != -1 && map[j][i] != '0'){
                if(tidx == -1) tidx = j;
            }
            
            if(bidx != -1 && tidx != -1){
                while(tidx >= 0 && map[tidx][i] != '0'){
                    swap(map[bidx--][i], map[tidx--][i]);
                }
                j = tidx+1;
                tidx = -1;
            }
        }
    }
}

int solution(int m, int n, vector<string> board) {
    map = board;
    N = m;
    M = n;
    while(1){
        vector<pair<int, int>> target = search();
        if(target.empty()) break;
        remove(target);
    }

    int answer = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(map[i][j] == '0') answer++;
        }
    }
    return answer;
}
