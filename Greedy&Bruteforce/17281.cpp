#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n;
int answer = 0;
int arr[51][10];
vector<int> order;

int baseball(){
    int total = 0;
    int next = 0; // 다음 이닝의 첫 타자 저장
    for(int i=0; i<n; i++){ // 이닝
        int base[4] = {0, 0, 0, 0};
        int out = 0;
        for(int j=next; j<9; j++){
            int now = arr[i][order[j]-1]; // 현재 타자의 결과
            if(now == 0) {
                out++;
                if(out >= 3) { // 3아웃 이닝 종료
                    next = j+1;
                    if(next >= 9) next = 0;
                    break;
                }
                if(j == 8){
                    j = -1; // 타석 초기화
                }
                continue;
            }

            base[0] = 1;
            if(now == 1){ // 안타
                if(base[3]){
                    total++;
                    base[3] = 0;
                }
                for(int k=2; k>=0; k--){
                    if(base[k]){
                        base[k+1] = 1;
                        base[k] = 0;
                    }
                }
            } else if(now == 2){ // 2루타
                for(int k=2; k<4; k++){
                    total += base[k];
                    base[k] = 0;
                }
                for(int k=1; k>=0; k--){
                    if(base[k]){
                        base[k+2] = 1;
                        base[k] = 0;
                    }
                }
            } else if(now == 3){ // 3루타
                for(int k=1; k<4; k++){
                    total += base[k];
                    base[k] = 0;
                }
                base[3] = 1;
                base[0] = 0;
            } else { // 홈런
                for(int k=0; k<4; k++){
                    total += base[k];
                    base[k] = 0;
                }
            }
            if(j == 8){
                j = -1; // 타석 초기화
            }
        }
    }
    return total;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for(int i=2; i<=9; i++){
        order.push_back(i);
    }

    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<9; j++){
            cin >> arr[i][j];
        }
    }

    do{ // 2~9의 순열에 1 삽입
        order.insert(order.begin()+3, 1);
        int score = baseball();
        order.erase(order.begin()+3);
        answer = max(answer, score);
    } while(next_permutation(order.begin(), order.end()));

    cout << answer;
    return 0;
}
