#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<string> others;
vector<string> boj;
int n;

bool isNum(string s){ // s가 정수인가?
    for(int i=0; i<s.size(); i++){
        if(!(s[i] >= '0' && s[i] <= '9')) return false;
    }
    return true;
}

bool cmp(string s1, string s2){ // 길이가 같으면 사전순으로
    if(s1.length() == s2.length()){
        return s1 < s2;
    }
    return s1.length() < s2.length(); // 길이 오름차순
}

bool cmp2(string s1, string s2){
    int a = stoi(s1.substr(7));
    int b = stoi(s2.substr(7));
    return a < b; // 추출한 숫자의 오름차순
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cin.ignore();
    for(int i=0; i<n; i++){
        string str;
        getline(cin, str);
        if(str.substr(0, 7) == "boj.kr/" && isNum(str.substr(7))){ // 백준
            boj.push_back(str);
        } else {
            others.push_back(str);
        }
    }
    sort(others.begin(), others.end(), cmp);
    sort(boj.begin(), boj.end(), cmp2);
    for(int i=0; i<others.size(); i++){
        cout << others[i] << '\n';
    }
    for(int i=0; i<boj.size(); i++){
        cout << boj[i] << '\n';
    }
    return 0;
}