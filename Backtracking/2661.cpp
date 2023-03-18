#include <iostream>
#include <string>

using namespace std;
int n;
string res;

bool validcheck(string v){
   // 인접한 두 부분 수열이 동일한 것이 있다면 실패
    for(int i = 1; i <= v.size() / 2; i++){
        if(v.substr(v.size() - i * 2, i) == v.substr(v.size() - i, i))
            return false;
    }
    return true;
}

void DFS(string v, int depth){
    if(res != "") return;
    if(!validcheck(v)) return;

    if(depth == n){ // 유효성 검사 최초 통과한 수열이 정답
        res = v;
    }
    
    for(int i=0; i<n; i++){ // n번 반복
        DFS(v + "1", depth + 1);
        DFS(v + "2", depth + 1);
        DFS(v + "3", depth + 1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    DFS("", 0);
    cout << res;
    return 0;
}