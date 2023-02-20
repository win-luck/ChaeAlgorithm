#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int arr[101][10001]; // [물품의 수][최대 허용 무게] 속에서의 최선의 "가치"

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, t;
    vector<pair<int, int> > vlist;
    cin >> n >> t;
    for(int i=0; i<n; i++){
        int k, s;
        cin >> k >> s;
        vlist.push_back(make_pair(k, s)); // 단원별 예상공부시간, 단원의 배점
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=t; j++){
            int curtime = vlist[i-1].first;
            int curvalue = vlist[i-1].second;
            // 짐을 담을 수 있는 경우
            if(curtime <= j){
                arr[i][j] = max(arr[i-1][j], arr[i-1][j-curtime] + curvalue); // (위칸의 가치) vs (이 무게의 물건을 담기 전 상황에서 이 무게를 담은 직후 가치)
            } else { // 짐을 담을 수 없는 경우 위칸 가치를 가져옴
                arr[i][j] = arr[i-1][j];
            }
        }
    }
    cout << arr[n][t];
    return 0;
}