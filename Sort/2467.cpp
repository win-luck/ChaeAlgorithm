#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n, results, resulte;
    cin >> n;
    int water[n];

    for(int i=0; i<n; i++){
        cin >> water[i];
    } // 입력

    int start = 0;
    int end = n - 1;

    int v = 2000000001; // 초기값 설정
    results = water[start];
    resulte = water[end];

    while(start < end){
        int sum = water[start] + water[end];
        if(abs(sum) < v){ // 절댓값이 v보다 작으면 갱신
            v = abs(sum); 
            results = water[start];
            resulte = water[end];
        }
        if(sum < 0) { // 합이 음수라면 0에 가까워지기 위해서 start가 더 커지는 쪽으로 움직여야 함.
            start++;
        } else { // 합이 양수라면 0에 가까워지기 위해서 end가 더 작아지는 쪽으로 움직여야 함.
            end--;
        }
    }

    cout << results << " " << resulte << endl;
}