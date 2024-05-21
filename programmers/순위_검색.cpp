#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <map>

using namespace std;
map<string, vector<int>> target;
map<string, int> m;
string word[5];
bool visited[4];

void init(){
    m["cpp"] = 0;
    m["java"] = 1;
    m["python"] = 2;
    m["backend"] = 0;
    m["frontend"] = 1;
    m["junior"] = 0;
    m["senior"] = 1;
    m["chicken"] = 0;
    m["pizza"] = 1;
    
    vector<string> v1 = {"cpp", "java", "python", "-"};
    vector<string> v2 = {"backend", "frontend", "-"};
    vector<string> v3 = {"junior", "senior", "-"};
    vector<string> v4 = {"chicken", "pizza", "-"};
    vector<int> v;
    for(auto i: v1){
        for(auto j: v2){
            for(auto k: v3){
                for(auto l: v4){
                    target[i + j + k + l] = v;
                }
            }
        }
    }
}

void dfs(int totalcnt, int nowcnt, int idx, int num){
    if(nowcnt == totalcnt){
        string now = word[0] + word[1] + word[2] + word[3];
        target[now].push_back(num);
    }
    
    for(int i=idx; i<4; i++){
        if(visited[i]) continue;
        visited[i] = true;
        string tmp = word[i];
        word[i] = "-";
        dfs(totalcnt, nowcnt+1, i, num);
        word[i] = tmp;
        visited[i] = false;
    }
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    init();

    for(int i=0; i<info.size(); i++){
        stringstream ss(info[i]);
        string tmp;
        string now = "";
        int idx = 0;
        while(ss >> tmp){
            word[idx++] = tmp;
        }
        
        now = word[0] + word[1] + word[2] + word[3];
        int num = stoi(word[4]);
        target[now].push_back(num);
        // 와일드카드 -를 반영해야함
        dfs(1, 0, 0, num);
        dfs(2, 0, 0, num);
        dfs(3, 0, 0, num);
        target["----"].push_back(num);
    }
    for(int i=0; i<query.size(); i++){
        stringstream ss(query[i]);
        string tmp;
        string now = "";
        int idx = 0;
        string arr[5];
        while(ss >> tmp){
            if(tmp == "and") continue;
            arr[idx++] = tmp;
        }
        
        now = arr[0] + arr[1] + arr[2] + arr[3];
        int num = stoi(arr[4]);
        int cnt = 0;
        for(auto it: target[now]){
            if(it >= num) cnt++;
        }
        answer.push_back(cnt);
    }
    return answer;
}
