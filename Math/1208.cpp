#include <iostream>
#include <map>

using namespace std;
map<int, int> sumtable;
int n, s;
int arr[41];
long long answer = 0;

// 이분 탐색에 map을 활용한다는 발상이 굉장히 어려웠던 문제. 항상 모든 자료구조에 대해 열린 마음을 갖자.

void sumLeft(int cnt, int sum){
    if(cnt == n/2){ // 백트래킹을 활용해 절반의 구간에 벌어지는 덧셈을 모두 실행했다면
        sumtable[sum]++; // 그 합에 해당하는 모든 sum의 등장 횟수를 각각 더해준다.
        return;
    }
    sumLeft(cnt + 1, sum); // 현재 숫자를 더하지 않음
    sumLeft(cnt + 1, sum + arr[cnt]); // 현재 숫자를 더해줌
}

void sumRight(int cnt, int sum){
    if(cnt == n){
        answer += sumtable[s - sum]; // 현재 sum을 더하여 s가 되는 모든 경우의 수를 map을 활용해 구함
        return;
    }
    sumRight(cnt + 1, sum);
    sumRight(cnt + 1, sum + arr[cnt]);
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> s;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    sumLeft(0, 0);
    sumRight(n/2, 0);
    if(s == 0) // s가 0이면 양쪽이 다 공집합인 경우를 배제
        answer--;
    cout << answer << '\n';
    return 0;
}