#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
int n, m;
string str;
vector<string> voca;
map<string, int> w;

bool cmp(string a, string b){
    if(a.length() == b.length() && w[a] == w[b]) return a < b; // 알파벳 오름차순
    else if(w[a] == w[b]) return a.length() > b.length(); // 단어의 길이가 길수록 앞으로
    return w[a] > w[b]; // 단어의 빈도가 높은 게 앞으로
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> str;
        if(str.length() >= m){
            if(w.find(str) == w.end()){
                w[str] = 0;
                voca.push_back(str);
            }
            w[str]++;
        }
    }
    sort(voca.begin(), voca.end(), cmp);
    for(int i=0; i<voca.size(); i++){
        cout << voca[i] << "\n";
    }
    return 0;
}