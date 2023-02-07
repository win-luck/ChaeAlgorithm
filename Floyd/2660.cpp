#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int d[51][51];
#define INF 10000

int main(){
    int N;
    cin >> N;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(i == j) continue;
            else d[i][j] = INF;
        }
    }

    int a, b;
    while(1){
        cin >> a >> b;
        if(a == -1 && b == -1) 
            break;
        d[a][b] = 1;
        d[b][a] = 1;
    }

    for(int k=1; k<=N; k++){ // 경유하는 노드가 제일 위에 있어야 하고
        for(int i=1; i<=N; i++){ // 그 다음 출발점
            for(int j=1; j<=N; j++){ // 그 다음 도착점이 된다.
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }    

    int result = INF;
    int val[51] = { 0, };
    vector<int> answer;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(i == j) continue;
            val[i] = max(val[i], d[i][j]); // i번째 친구의 점수를 계산하는 과정, 가장 긴 d[i][j]가 점수가 된다.
        }
        result = min(result, val[i]);
    }

    for(int i=1; i<=N; i++){
        if(val[i] == result){
            answer.push_back(i);
        }
    }

    sort(answer.begin(), answer.end());

    cout << result << " " << answer.size() << endl;
    for(int i=0; i<answer.size(); i++){
        cout << answer[i] << " ";
    }

    return 0;
}