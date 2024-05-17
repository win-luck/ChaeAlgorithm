#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int n = number.size();
    int cnt = n-k;
    int idx = 0;
    for(int i=0; i<cnt; i++){
        char now = number[idx];     
        for(int j=idx+1; j<=i+k; j++){
            if(now < number[j]){
                idx = j;
                now = number[j];
            }
        }
        answer += number[idx++];
    }
    return answer;
}
