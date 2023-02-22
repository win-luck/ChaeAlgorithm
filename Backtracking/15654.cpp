#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, M;
bool visited[8];
vector<int> arr;
vector<int> list;

void printLine(){ // 한 줄 출력하는 로직
    for(int i=0; i<list.size(); i++){
        cout << list[i] << " ";
    }
    cout << '\n';
}

void makeList(int num){
    if(num == M){ // 백트래킹: 자릿수가 다 채워지면 출력한다.
        printLine();
        return;
    }
    for(int i=0; i<N; i++){
        if(visited[i]) continue; // 이미 방문한 숫자 제외

        visited[i] = true; // 방문처리 후
        list.push_back(arr[i]); // 삽입
        makeList(num + 1); // 채워진 상태에서 다음 탐색으로 이동
        list.pop_back(); // 빼내기
        visited[i] = false; // 방문하지 않은 것으로 처리
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        arr.push_back(num);
    }

    sort(arr.begin(), arr.end()); // 오름차순으로 정렬 후
    makeList(0); // 탐색 개시
    return 0;
}