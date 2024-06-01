#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <iostream>

using namespace std;
int arr[51][51] = {0, };
map<string, int> m;
int idx = 0;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    for(auto it: friends){
        m[it] = ++idx;
    }
    for(auto it: gifts){
        stringstream ss(it);
        string s1, s2;
        ss >> s1 >> s2;
        arr[m[s1]][m[s2]]++;
    }
    
    map<int, int> table;
    for(int i=1; i<=idx; i++){
        int give = 0;
        int take = 0;
        for(int j=1; j<=idx; j++){
            give += arr[i][j];
            take += arr[j][i];
        }
        table[i] = give-take; // 선물 지수
    }
    
    map<int, int> nextgift; // 다음달에 받을 선물
    for(int i=1; i<=idx; i++){
        for(int j=i+1; j<=idx; j++){
            if(arr[i][j] == arr[j][i]){
                if(table[i] == table[j]) continue;
                else if(table[i] > table[j]){
                    nextgift[i]++;
                } else {
                    nextgift[j]++;
                }
            } else if(arr[i][j] > arr[j][i]){
                nextgift[i]++;
            } else {
                nextgift[j]++;
            }
        }
    }
    for(int i=1; i<=idx; i++){
        answer = max(answer, nextgift[i]);
    }
    return answer;
}
