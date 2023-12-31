#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
int n, m;
map<int, string> dic;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        string str;
        int a;
        cin >> str >> a;
        if(dic.find(a) == dic.end()){ // 같은 전투력에 대해서는 최초 입력만 유효
            dic[a] = str;
        }
    }

    map<int, string>::iterator iter;
    for(int i=1; i<=m; i++){
        int a;
        cin >> a;
        iter = dic.lower_bound(a);
        cout << iter->second << '\n';
    }
    return 0;
}
