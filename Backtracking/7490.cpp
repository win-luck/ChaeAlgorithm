#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int t, n;
int arr[10];
vector<string> v;

void backtrack(int val, int cnt, string str, int before){
    if(val == 0 && cnt == n + 1){
        v.push_back(str);
        return;
    }

    if(cnt > n){
        return;
    }


    // 1. +
    str += '+';
    str += (cnt + '0'); // 현재 숫자 추가
    backtrack(val + cnt, cnt + 1, str, 1);
    str.pop_back();
    str.pop_back();


    // 2. -
    str += '-';
    str += (cnt + '0'); // 현재 숫자 추가
    backtrack(val - cnt, cnt + 1, str, 2);
    str.pop_back();
    str.pop_back();


    // 3. 공백 (직전 숫자에 10 곱한 뒤 더함)
    int tmp = (cnt-1) * 10 + (cnt);
    if(before == 1){ // 직전이 +인 상황 롤백
        val -= (cnt-1);
        tmp = val + tmp;
    } else if(before == 2){ // 직전이 -인 상황 롤백
        val += (cnt-1);
        tmp = val - tmp;
    } else if(before == 3){
        return; // 세자리부턴 따질 가치 없음
    } 
    str += ' ';
    str += (cnt + '0');
    backtrack(tmp, cnt + 1, str, 3);
    str.pop_back();
    str.pop_back();
}

// 숫자 - 기호 - 숫자 - 기호 - 숫자의 형태로 구성된다.

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    for(int i=0; i<t; i++){
        cin >> n;
        int val = 1;
        string str = "1";
        backtrack(val, 2, str, 0);

        sort(v.begin(), v.end());
        for(int i=0; i<v.size(); i++){
            cout << v[i] << '\n';
        }
        v.clear();
        cout << '\n';
    }
}