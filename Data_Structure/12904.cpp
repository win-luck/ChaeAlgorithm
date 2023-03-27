#include <iostream>
#include <algorithm>

using namespace std;
string s1, s2;


int main(){
    int res = 0;
    cin >> s1;
    cin >> s2; // s2를 s1로 만드는 역발상

    while(1){
        if(s1.size() == s2.size()){ // 길이가 같을 때
            if(s1 == s2) { // 같은 문자열이면 성공
                res = 1;
            }
            break;
        }

        if(s2[s2.size()-1] == 'A'){ // 끝이 A일 때
            s2.pop_back(); // 빼기
        } else { // B일 때
            s2.pop_back(); // 빼고
            reverse(s2.begin(), s2.end()); // 역행
        }
    }
    cout << res;
    return 0;
}