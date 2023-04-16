#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;
int n, m;
string str;
map<string, int> dict;
string arr[100001];
vector<string> result;

int main(){
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> str;
        dict[str] = i;
        arr[i] = str; // value를 역추적하는 건 시간초과 위험성이 있기에 따로 배열로 빼서 표현
    }

    for(int i=1; i<=m; i++){
        cin >> str;
        if(str[0] >= 'A' && str[0] <= 'Z'){ // key가 들어옴
            result.push_back(to_string(dict[str]));
        } else { // value가 들어옴
            result.push_back(arr[stoi(str)]);
        }
    }
    for(int i=0; i<result.size(); i++){
        cout << result[i] << '\n';
    }
    return 0;
}