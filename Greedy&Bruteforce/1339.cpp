#include <iostream>
#include <algorithm>

using namespace std;
int n;
// 자릿수 계산을 위한 배열
int num[10] = {1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
int alpha[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0}; // A부터 G까지
long long sum = 0;
int alpha_cnt[27] = {0, };

bool cmp(int a, int b){ // 내림차순 정렬
    return a > b;
}

int main(){
    cin >> n;
    string word[11];
    for(int i=0; i<n; i++){
        int cnt = 0;
        cin >> word[i];
        for(int j=word[i].size()-1; j>=0; j--){
            string str = word[i];
            int a = str[j] - 'A'; // A부터 Z까지에 해당하는 0~26이 저장될 것이다.
            alpha_cnt[a] += num[cnt]; // 특정 자릿수에 해당하는 값을 더해준다.(예: b가 2번째 자리에 있으면 b의 cnt에 10을 더해줌))
            cnt++;
        }
    }

    sort(alpha_cnt, alpha_cnt + 27, cmp); // 내림차순 정렬
    // 이렇게 하면 가장 큰 자릿수를 차지하는대로 정렬된다. (내림차순이므로)

    for(int i=0; i<10; i++){
        sum += alpha_cnt[i] * alpha[i]; // 가장 큰 자릿수를 차지하는 숫자부터 차례대로 9~1을 곱해주는 것이 optimal하다.
    }

    cout << sum << '\n';
    return 0;
}