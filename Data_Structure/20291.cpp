#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sstream>

using namespace std;
string str;
int n;
map<string, int> m;

string split(string str, char Delimiter) {
    istringstream iss(str);             // istringstream에 str을 담는다.
    string buffer;                      // 구분자를 기준으로 절삭된 문자열이 담겨지는 버퍼
 
    vector<string> result;
 
    // istringstream은 istream을 상속받으므로 getline을 사용할 수 있다.
    while (getline(iss, buffer, Delimiter)) {
        result.push_back(buffer);               // 절삭된 문자열을 vector에 저장
    }
 
    return result[1];
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> str;
        str = split(str, '.'); // . 기준으로 잘라낸 우측 문자열
        m[str]++; // 에 해당하는 파일 개수 증가
    }

    for(auto it: m){
        cout << it.first << " " << it.second << '\n';
    }
    return 0;
}