#include <iostream>
#include <cstring>

using namespace std;
int d, k, a, b;
int A[31];
int B[31];


int main(){
    cin >> d >> k;

    A[1] = 1;
    A[2] = 0;
    B[1] = 0;
    B[2] = 1;

    for(int i=3; i<=d; i++){
        A[i] = A[i-2] + A[i-1];
        B[i] = B[i-2] + B[i-1];
    } // day가 진행될 때마다 초항을 더하는 형식이므로 A와 B 앞에 붙는 계수를 계산한다.
    // 무턱대고 dp배열을 사용하려 하니 시행착오가 꽤 컸다. 반드시 dp배열을 쓰는 것은 아니다.

    // d번째 날에 k개를 먹는 경우의 수를 이제 추적해야 한다.
    int Bnum = 0;
    int Anum = 0;

    for(int i=1; i<=k; i++){
        if((k - i * A[d]) % B[d] == 0){ // ax + by = c에서, c - ax가 b에 의해 나누어떨어진다면 y를 구할 수 있다.
            Bnum = (k - i * A[d]) / B[d];
            Anum = i;
            break;
        }
    }
    cout << Anum << '\n';
    cout << Bnum << '\n';
    return 0;
}

/**
 * 점화식의 특정 인덱스 항으로 초항 두개를 역추적
 * 1항 - A
 * 2항 - B
 * 3항 - A+B
 * 4항 - A+2B
 * 5항 - 2A+3B
 * 6항 - 3A+5B
*/