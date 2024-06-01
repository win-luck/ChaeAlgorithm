#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int next = -1;
    for(int i=0; i<section.size(); i++){
        if(section[i] <= next) continue;
        next = section[i] + m - 1;
        answer++;
    }
    return answer;
}
