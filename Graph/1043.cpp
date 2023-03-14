#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
int n, m, tru, temp;
int res = 0;
int parent[51];
vector<int> truth;
vector<vector<int> > total(50);

int Find(int num){
    if(num == parent[num]) return num;
    return parent[num] = Find(parent[num]);
}

void Union(int a, int b){
    a = Find(a);
    b = Find(b);
    parent[a] = b;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    cin >> tru;

    for(int i=1; i<=n; i++){ // 부모 초기화
        parent[i] = i;
    }

    for(int i=0; i<tru; i++){ // 진실자의 명단
        cin >> temp;
        truth.push_back(temp);
    }

    for(int i=0; i<m; i++){
        int k;
        cin >> k;
        int now;
        int pre;
        for(int j=0; j<k; j++){ // 파티 입력
            if(j == 0){
                cin >> now;
            } else {
                pre = now;
                cin >> now;
                Union(pre, now); // 파티별로 그룹화
            }
            total[i].push_back(now);
        }
    }
    
    for(int i=0; i<total.size(); i++){
        bool flag = false;
        for(int j=0; j<total[i].size(); j++){
            if(flag) break;
            for(int k=0; k<truth.size(); k++){
                if(Find(truth[k]) == Find(total[i][j])){ // 같은 그룹에 속한다 -> 진실을 아는 자가 있다
                    flag = true;
                    break;
                }
            }
        }
        if(flag) res++; // 발각되면 참여 파티가 하나 깎인다
    }

    cout << m - res;
    return 0;
}