#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;
int n;
map<string, vector<int> > m;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long ans = 0;
    cin >> n;
    for(int a=0; a<n; a++){
        int t, cnt;
        string str;

        cin >> t;
        cin >> str;
        cin >> cnt;
        if(t == 1){
            for(int i=0; i<cnt; i++){
                int val;
                cin >> val;
                m[str].push_back(val); // 정보 담기
            }
        } else {
            if(m[str].empty()) continue; // 애초에 비어있으면 꺼내지를 못함
            sort(m[str].begin(), m[str].end()); // 오름차순 정렬하여 뒤부터 꺼냄
            for(int i=0; i<cnt; i++){
                ans += m[str].back();
                m[str].pop_back();

                if(m[str].empty()) break; // 비었으면 이탈
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
