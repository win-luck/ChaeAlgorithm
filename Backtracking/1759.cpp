#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int l, c;
char ch;
int visited[16];
vector<char> input;
vector<char> result;

bool isMo(char chr){ // 모음인지 검증
    if(chr == 'a' || chr == 'e' || chr == 'i' || chr == 'o' || chr == 'u') return true;
    return false;
}

bool validcheck(){  // 최소 한 개의 모음과 최소 두 개의 자음으로 구성되었는지 검증한다.
    int Mocount = 0;
    int Jacount = 0;
    for(int i=0; i<result.size(); i++){
        if(isMo(result[i])) Mocount++;
        else Jacount++;
    }

    if(Mocount >= 1 && Jacount >= 2) return true;
    else return false;
}

void printstr(){ // 한 줄 출력
    for(int i=0; i<result.size(); i++){
        cout << result[i];
    }
    cout << '\n';
}

void DFS(int depth){
    if(result.size() == l){ // 출력 조건이 갖춰진다면
        if(validcheck()) printstr(); // 유효성 검사 통과하면 출력
        return;
    }

    for(int i=depth; i<c; i++){ // DFS를 벡터로 다룰 줄도 알아야 한다.
        result.push_back(input[i]);
        DFS(i + 1);
        result.pop_back();
    }
}

int main(){
    cin >> l >> c;
    for(int i=0; i<c; i++){ // 입력
        cin >> ch;
        input.push_back(ch);
    }
    sort(input.begin(), input.end()); // 알파벳 오름차순 정렬

    DFS(0);
    return 0;
}