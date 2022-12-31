#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long solve(int a, int b, int c){
    if(b == 0) return 1;
    long long half = solve(a, b/2, c);
    long long answer = half * half % c;
    if(b % 2 == 0) return answer; // 짝수일 때
    else return answer * a % c; // 홀수일 때 분할정복 시 2의 a승 / 2의 a+1승으로 나뉘기 때문에 필요한 조건문
}


int main(){
    int A,B,C;
    cin >> A >> B >> C;
    cout << solve(A, B, C);
    return 0;
}