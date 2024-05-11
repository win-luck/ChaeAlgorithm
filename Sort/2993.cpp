#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
string str;
vector<string> answer;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> str;
    int n = str.size();
    for(int i=1; i<n; i++){
        for(int j=i+1; j<n; j++){
            string str1 = str.substr(0, i);
            string str2 = str.substr(i, j-i);
            string str3 = str.substr(j);
            reverse(str1.begin(), str1.end());
            reverse(str2.begin(), str2.end());
            reverse(str3.begin(), str3.end());
            string tmp = str1 + str2 + str3;
            answer.push_back(tmp);
        }
    }
    sort(answer.begin(), answer.end());
    cout << answer[0];
    return 0;
}
