#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
map<string, int> m;
int n;

bool cmp(pair<string, int> p1, pair<string, int> p2){
    if(p1.second == p2.second){ // 학생 이름 오름차순
        return p1.first < p2.first;
    }
    return p1.second > p2.second; // 인기도 내림차순
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++){
        string str;
        cin >> str;
        m[str] = 0;
    }

    for(int i=0; i<n+1; i++){
        string str;
        getline(cin, str);
        string tmp = "";
        for(int j=0; j<str.size(); j++){
            if(str[j] == ' '){
                m[tmp]++;
                tmp = "";
            } else {
                tmp += str[j];
            }
        }
        if(tmp != ""){
            m[tmp]++;
        }
    }

    vector<pair<string, int> > v(m.begin(), m.end());
    sort(v.begin(), v.end(), cmp);
    for(int i=0; i<v.size(); i++){
        cout << v[i].first << " " << v[i].second << '\n';
    }
    return 0;
}
