#include <string>
#include <vector>
#include <iostream>

using namespace std;
vector<int> rate;
vector<vector<int>> users;
vector<int> emoticons;
int maxcnt = 0;
int maxval = 0;
int n, m;

void calculate(){
    int cnt = 0;
    int total = 0;

    for(int i=0; i<m; i++){
        int lower = users[i][0];
        int price = users[i][1];
        int sum = 0;
        
        for(int j=0; j<n; j++){
            if(rate[j] >= lower){ // 비율 이상의 할인 시 구매함
                double val = emoticons[j]*(100-rate[j])/100;
                sum += val;
            }
        }
        if(sum >= price){ // 가격 이상의 돈을 사용하면 구매 취소하고 플러스서비스
            cnt++; 
            sum = 0;
        } 
        total += sum;
    }

    if(cnt > maxcnt){
        maxcnt = cnt;
        maxval = total;
    } else if(cnt == maxcnt){
        if(total > maxval){
            maxval = total;
        }
    }
}

void dfs(int cnt){
    if(cnt == n){ 
        calculate();
        return;
    }
    
    for(int i=10; i<=40; i+=10){
        rate.push_back(i);
        dfs(cnt+1);
        rate.pop_back();
    }
}

vector<int> solution(vector<vector<int>> u, vector<int> e) {
    users = u;
    emoticons = e;
    n = e.size();
    m = u.size();

    dfs(0);
    vector<int> answer = {maxcnt, maxval};
    return answer;
}
