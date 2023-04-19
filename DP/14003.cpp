#include <iostream>
#include <vector>

#define MAX 1000001
using namespace std;

int arr[MAX];
int result[MAX];
int pos[MAX] = {0, };
vector<int> v;

int binarySearch(int start, int end, int target) { // target이 어디 위치에 가야하는지 이분탐색으로 위치를 반환
    int mid;
    int pos = end;

    while(start <= end) {
        mid = (start + end) / 2;

        if(result[mid] < target){
            start = mid + 1;
        } else {
            pos = mid;
            end = mid - 1;
        }
    }
    return pos;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

    result[0] = arr[0];
    int idx = 0;
    for(int i=1; i<n; i++) {
        if(arr[i] > result[idx]) { // 수열의 i번째 수가 LIS의 idx번째 수보다 크다면 조건 충족
            result[++idx] = arr[i]; // LIS에 끝에 추가, LIS의 인덱스 증가
            pos[i] = idx; // LIS 배열 내에서 arr[i]가 idx 위치에 저장되어있음을 의미한다.
        } else { // 작거나 같으면 조건을 충족하지 않으므로 이분 탐색으로 수열의 i번째 수가 끼어들 자리를 찾아냄
            int binaryidx = binarySearch(0, idx, arr[i]);
            result[binaryidx] = arr[i];
            pos[i] = binaryidx;
        }
    }

    cout << idx + 1 << endl;
    for(int i = n-1; i>=0; i--){
        if(idx < 0) break; // LIS 완성되었음을 의미
        if(pos[i] == idx){ // LIS 배열의 원소임을 감지
            v.push_back(arr[i]);
            idx--;
        }
    }

    for(int i=v.size()-1; i>=0; i--){ // 역출력
        cout << v[i] << ' ';
    }
    return 0;
}