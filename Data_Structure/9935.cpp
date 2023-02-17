#include <iostream>
#include <string.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string a, b;
    string tmp = ""; // 임시 문자열
    cin >> a >> b;

    for(int i = 0; i < a.length(); i++){
        tmp += a[i]; // 문자 하나씩 담다가

        if(tmp.length() >= b.length()){ // 폭발시킬 문자열 b의 길이보다 크거나 같은 상황부터는 이제 터뜨릴지 말지 검증해야 한다.
            bool isBomb = true;
            for(int j=0; j<b.length(); j++){
                if(tmp[tmp.length() - b.length() + j] != b[j]){ 
                    // "helloit" 에서 폭탄이 "it"이라면 이를 감지하기 위해서는, 맨 뒤부터 폭탄의 길이만큼을 순회하며 폭탄이 맞는지 확인한다.
                    isBomb = false;
                    break;
                }
            }

            if(isBomb){ // 폭탄이 맞으면
                tmp.erase(tmp.end() - b.length(), tmp.end()); // 맨 뒤 폭탄 제거
            }
        }
    }

    if(tmp.empty()){
        cout << "FRULA" << '\n';
    } else {
        cout << tmp << '\n';
    }
    return 0;
}