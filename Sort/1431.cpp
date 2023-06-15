#include <iostream>
#include <algorithm>

using namespace std;
int n;
vector<string> v;

int sumcheck(string s1){ // 한 문자열 내 모든 숫자의 합
    int sum = 0;
    for(int i=0; i<s1.length(); i++){
        if(s1[i] >= '0' && s1[i] <= '9') sum += (s1[i]-'0');
    }
    return sum;
}

bool cmp(string s1, string s2){
    if(s1.length() == s2.length()){
        if(sumcheck(s1) == sumcheck(s2)){
            return s1 < s2; // 3번 조건: 사전순 정렬
        }
        return sumcheck(s1) < sumcheck(s2); // 2번 조건: 문자열 내 숫자합이 적은 게 먼저
    }
    return s1.length() < s2.length(); // 1번 조건: 짧은 게 먼저
}


int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        string a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end(), cmp);
    for(int i=0; i<n; i++){
        cout << v[i] << '\n';
    }
    return 0;
}