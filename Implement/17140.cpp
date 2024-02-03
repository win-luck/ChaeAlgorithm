#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>

using namespace std;
int tr, tc, k;
int r, c;
int arr[101][101];

bool cmp(pair<int, int> p1, pair<int, int> p2){
    if(p1.second == p2.second) return p1.first < p2.first;
    return p1.second < p2.second;
}

void R(){ // 행 연산
    for(int i=1; i<=r; i++){
        map<int, int> m; // 숫자-등장횟수
        for(int j=1; j<=c; j++){
            if(arr[i][j] != 0)
                m[arr[i][j]]++;
        }
        vector<pair<int, int> > tmp(m.begin(), m.end());
        sort(tmp.begin(), tmp.end(), cmp);

        int s = 2 * tmp.size(); // 행의 길이 갱신 시도
        c = max(c, s);

        for(int j=1; j<=100; j++) // 0 채우기
            arr[i][j] = 0;
        
        for(int j=0; j<tmp.size(); j++){ // 결과 반영
            arr[i][j*2 + 1] = tmp[j].first;
            arr[i][(j+1)*2] = tmp[j].second;
        }
    }
}

void C(){ // 열 연산
    for(int i=1; i<=c; i++){
        map<int, int> m;
        for(int j=1; j<=r; j++){
            if(arr[j][i] != 0)
                m[arr[j][i]]++;
        }
        vector<pair<int, int> > tmp(m.begin(), m.end());
        sort(tmp.begin(), tmp.end(), cmp);

        int s = 2 * tmp.size();
        r = max(r, s);
        
        for(int j=1; j<=100; j++)
            arr[j][i] = 0;
        
        for(int j=0; j<tmp.size(); j++){
            arr[j*2 + 1][i] = tmp[j].first;
            arr[(j+1) * 2][i] = tmp[j].second;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0); 
    memset(arr, 0, sizeof(arr));
    cin >> tr >> tc >> k;
    r = 3;
    c = 3;
    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            cin >> arr[i][j];
        }
    }

    if(arr[tr][tc] == k){ // 연산 진행할 필요없음
        cout << 0;
        return 0;
    }

    int t = 0;
    while(1){
        t++;
        if(r >= c){
            R();
        } else {
            C();
        }
        if(arr[tr][tc] == k) break; // 성공
        if(t >= 100){ // 100초가 지남
            cout << -1;
            return 0;
        }
    }
    cout << t;
    return 0;
}
