#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(pair<int, double> p1, pair<int, double> p2){
    if(p1.second == p2.second){ // 실패율이 같은 경우
        return p1.first < p2.first; // 인덱스 작은 순서대로 정렬
    }
    return p1.second > p2.second; // 실패율이 높은 순으로 정렬
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int, double> > v;
    double totaluser[N+1];
    double notclearuser[N+1];
    
    for(int i=0; i<=N; i++){
        totaluser[i] = notclearuser[i] = 0;
    } // 배열 초기화
    
    // stages는 1부터 n+1까지 존재
    // 실패율: 스테이지에 도달했으나 클리어 못한 수 / 스테이지에 도달한 전체 수
    for(int i=1; i<=N; i++){
        for(int j=0; j<stages.size(); j++){
            if(stages[j] >= i){
                totaluser[i]++; // 스테이지에 도달한 전체 수
                if(stages[j] == i){
                    notclearuser[i]++; // 스테이지에 도달했으나 클리어 못한 수
                }
            }
        }
    }
    for(int i=1; i<=N; i++){
        double a;
        if(totaluser[i] == 0) a = 0; // 스테이지에 도달한 유저가 없는경우 실패율 0
        else a = (notclearuser[i] / totaluser[i]); // 실패율 계산
        v.push_back(make_pair(i, a)); // "스테이지별 실패율" 삽입
    }
    
    sort(v.begin(), v.end(), cmp); // 규칙대로 정렬
    for(int i=0; i<v.size(); i++){
        answer.push_back(v[i].first);
    }    
    return answer;
}