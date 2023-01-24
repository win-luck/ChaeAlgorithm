#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;

    long long water[n];
    long long result[3];

    for(int i=0; i<n; i++){
        cin >> water[i];
    } // 입력
    sort(water, water + n);

    long long v = 3000000001; // 초기값 설정

    for(int i = 0; i < n; i++){ // i번째 값을 고정시킨 상태에서 오른쪽 집단을 투 포인터로 탐색하여 마치 브루트포스처럼 값을 갱신
        int l = i + 1;
        int r = n - 1;

        while(l < r){
            long long total = water[i] + water[l] + water[r];
            if(llabs(total) < v){ // 절댓값이 v보다 작으면 갱신
                v = llabs(total); 
                result[0] = water[i];
                result[1] = water[l];
                result[2] = water[r];
            }

            if(total < 0) { // 합이 음수라면 0에 가까워지기 위해서 start가 더 커지는 쪽으로 움직여야 함.
                l++;
            } else { // 합이 양수라면 0에 가까워지기 위해서 end가 더 작아지는 쪽으로 움직여야 함.
                r--;
            }
        }
    }

    cout << result[0] << " " << result[1] << " " << result[2] << endl;
    return 0;
}