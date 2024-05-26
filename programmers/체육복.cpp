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
        if(arr[i] == 1){
            if(arr[i-1] == -1){
                arr[i-1]++;
                arr[i]--;
                answer += 2;
            } else if(arr[i+1] == -1){
                arr[i+1]++;
                arr[i]--;
                answer++;
            } else {
                answer++;
            }
        } else if(arr[i] == 0){
            answer++;   
        }
    }
    return answer;
}
