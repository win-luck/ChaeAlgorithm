#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;
int n;
string str;
map<vector<string>, int > m;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    cin.ignore();
    for(int i=0; i<n; i++){
        getline(cin, str);
        vector<string> v;
        stringstream ss(str);
        string tmp;

        while(ss >> tmp){
            v.push_back(tmp);
        }
        sort(v.begin(), v.end());
        m[v]++;
    }

    int answer = 0;
    for(auto it: m){
        answer = max(answer, it.second);
    }
    cout << answer;
    return 0;
}
