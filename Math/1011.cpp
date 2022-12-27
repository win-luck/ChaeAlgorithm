#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

double solve(double start, double end){
    double result = 0;
    double lengths = end - start;
    /*
    마지막은 1로 끝난다. 보편적으로 12321의 데칼코마니 형태를 띤다고 생각해볼 수 있다.
    1 -> 1, 1번 [1]
    2 -> 11, 2번 [2]
    3 -> 111, 3번
    4 -> 121, 3번 [4]
    5 -> 1211, 4번
    6 -> 1221, 4번 [6]
    7 -> 12211, 5번
    8 -> 12221, 5번
    9 -> 12321, 5번 [9]
    10 -> 123211, 6번
    11 -> 123221, 6번
    12 -> 123321, 6번 [12]
    13 -> 1123321, 7번
    14 -> 1223321, 7번
    15 -> 1233321, 7번
    16 -> 1234321, 7번 [16]
    17 -> 12343211, 8번
    18 -> 12343221, 8번 
    1. 제곱수의 다음부터 +1, 2. 특정 제곱수+ 그 제곱수+제곱수의 루트값 다음부터 +1
    */

    double i = 1;
    while(lengths > i * i){
        i++;
    }
    // 반복문을 이탈한 시점에서 lengths는 (i-1)의 제곱보다는 클 것이며, i의 제곱보다는 작거나 같을 것이다.
    // (i-1)*(i-1) < lengths <= i*i

    if(lengths > (i-1)*(i-1) && lengths <= (i-1)*(i-1) + i-1){
        result = 2 * (i-1);
    } else {
        result = 2 * i - 1;
    }

    return result;
}


int main(){

    double n, start, end;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> start;
        cin >> end;
        cout << solve(start, end) << endl;
    }
}
