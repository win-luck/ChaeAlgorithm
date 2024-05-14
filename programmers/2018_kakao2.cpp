#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<string> map1;
    vector<string> map2;
    
    string s = "";
    for(int i=0; i<n; i++){ // arr1 10진수 2진수로 변환
        int tmp = arr1[i];
        while(tmp != 0){
            s += (tmp % 2 + '0');
            tmp /= 2;
        }

        for(int t=s.size(); t<n; t++) s += '0'; // 자릿수 부족할 경우 0으로 채워줘야 함
        reverse(s.begin(), s.end()); // 뒤집으면 2진수
        map1.push_back(s);
        s = "";
    }
    
    for(int i=0; i<n; i++){ // arr2 10진수 2진수로 변환
        int tmp = arr2[i];
        while(tmp != 0){
            s += (tmp % 2 + '0');
            tmp /= 2;
        }

        for(int t=s.size(); t<n; t++) s += '0'; // 자릿수 부족할 경우 0으로 채워줘야 함
        reverse(s.begin(), s.end()); // 뒤집으면 2진수
        map2.push_back(s);
        s = "";
    }

    for(int i=0; i<n; i++){ // map1와 map2를 비교하며 #와 공백을 채워나간다.
        string s = "";
        string a = map1[i];
        string b = map2[i];   
        for(int j=0; j<n; j++){
            if(a[j] == '1' || b[j] == '1') s += '#';
            else s += ' ';
        }
        answer.push_back(s);
    }
    return answer;
}