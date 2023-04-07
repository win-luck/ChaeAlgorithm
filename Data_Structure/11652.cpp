#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
int n;
long long maxcnt = 0; // 정수 범위 넘어서므로 long long
long long maxkey = 0;
map<long long, int> m;

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        long long a;
        cin >> a;
        m[a]++;
    }
    
    for(auto i: m){ // 기본적으로 key 오름차순인 map을 순회하면서
        if(i.second > maxcnt){ // value가 이전보다 더 클 때 관련 정보 갱신
            maxcnt = i.second;
            maxkey = i.first;
        }
    }
    cout << maxkey << '\n';
    return 0;
}