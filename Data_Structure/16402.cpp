#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
int n, m;
string str;
int parent[501];
string nation[501];
map<string, int> maps;

int find(int num){
    if(num == parent[num]) return num;
    return parent[num] = find(parent[num]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    cin.ignore();
    for(int i=1; i<=n; i++){
        getline(cin, str);
        maps[str] = i;
        parent[i] = i;
        nation[i] = str;
    }

    for(int i=1; i<=m; i++){
        getline(cin, str);
        int type = str.back() - '0';
        string vs[2];
        int w = 0;

        string tmp = "";
        for(int j=0; j<str.size(); j++){
            if(str[j] != ','){
                tmp += str[j];
            } else {
                vs[w++] = tmp;
                tmp = "";
            }
        }

        int a = maps[vs[0]];
        int b = maps[vs[1]];

        /**
         * 종주국 vs 종주국
         * 종주국 vs 자기의 속국
        */

        if(type == 1){ // a가 승리
            if(find(a) != find(b)){
                parent[find(b)] = find(a);
            } else { // 속국이 종주국한테 재대결하는 경우
                if(find(a) == b){ // 속국이 승리하는 경우만 따지면 됨
                    parent[a] = a;
                    parent[b] = a;
                } 
            }
        } else if (type == 2){ // b가 승리
            if(find(a) != find(b)){
                parent[find(a)] = find(b);
            } else { // 속국이 재대결 신청
                if(find(b) == a){
                    parent[b] = b;
                    parent[a] = b;
                }
            }
        }
    }

    vector<string> answer;
    for(int i=1; i<=n; i++){
        if(parent[i] == i) answer.push_back(nation[i]);
    }
    cout << answer.size() << '\n';
    sort(answer.begin(), answer.end());
    for(int i=0; i<answer.size(); i++){
        cout << answer[i] << '\n';
    }
    return 0;
}
