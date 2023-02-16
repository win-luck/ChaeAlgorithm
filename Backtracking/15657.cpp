#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, M;
vector<int> arr;
vector<int> list;
int temp = 0;

void printLine(){ // 한 줄 출력
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
        if(temp > arr[i]){ // 비내림차순 정렬
            continue;
        }

        temp = arr[i]; // 현재 리스트의 마지막 수 갱신
        list.push_back(arr[i]);
        makeList(num + 1); // 채워진 상태에서 다음 탐색으로 이동
        list.pop_back();
        temp = list.back(); // 마지막 수 빼낸 이후 수로 갱신
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