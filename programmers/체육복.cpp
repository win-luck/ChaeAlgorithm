#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int arr[31] = {0, };
    for(int i=0; i<reserve.size(); i++){
        arr[reserve[i]]++;
    }
    for(int i=0; i<lost.size(); i++){
        arr[lost[i]]--;
    }
    for(int i=1; i<=n; i++){
        if(arr[i] == 1){ // 현재 여벌
            if(arr[i-1] == -1){ // 왼쪽이 여벌 필요
                arr[i-1]++;
                arr[i]--;
                answer += 2; // 다시 왼쪽 친구 순회할 일 없기에 +2
            } else if(arr[i+1] == -1){ // 오른쪽이 여벌 필요
                arr[i+1]++;
                arr[i]--;
                answer++; // 오른쪽은 다음 인덱스에서 반영
            } else {
                answer++;
            }
        } else if(arr[i] == 0){ // 자기만 입음
            answer++;   
        }
    }
    return answer;
}
