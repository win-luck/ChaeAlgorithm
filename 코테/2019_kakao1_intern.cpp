#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int> > board, vector<int> moves) {
    int answer = 0;
    int n = moves.size();
    int m = board.size();
    stack<int> s;

    for(int i=0; i<n; i++){
        int now = (moves[i]-1); // 크레인이 어디서 작동할지 위치 확인
        for(int j=0; j<m; j++){
            if(board[j][now] != 0){
                if(!s.empty() && s.top() == board[j][now]){ // 스택 최상단과 동일하면 삭제
                    s.pop();
                    answer += 2;
                } else {
                    s.push(board[j][now]);
                }
                board[j][now] = 0;
                break; // 크레인은 하나만 들고 올라오므로
            }
        }
    }
    
    return answer;
}