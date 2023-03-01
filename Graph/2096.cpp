#include <iostream>

using namespace std;
int n, maxc, minc, x, y, z;
int dpmax[2][3];
int dpmin[2][3];

int main(){
    cin >> n;
    int flag = 0;
    // 일반적인 DP로는 무조건 시간초과,
    // 중요한 것은 "현재 값"과 "전 값"을 비교하는 것.

    for(int i=0; i<n; i++){
        cin >> x >> y >> z; // 한 줄 입력마다 갱신해주자.

        dpmin[flag][0] = x + min(dpmin[!flag][0], dpmin[!flag][1]);
        dpmin[flag][1] = y + min(dpmin[!flag][0], min(dpmin[!flag][1], dpmin[!flag][2]));
        dpmin[flag][2] = z + min(dpmin[!flag][1], dpmin[!flag][2]);
        
        dpmax[flag][0] = x + max(dpmax[!flag][0], dpmax[!flag][1]);
        dpmax[flag][1] = y + max(dpmax[!flag][0], max(dpmax[!flag][1], dpmax[!flag][2]));
        dpmax[flag][2] = z + max(dpmax[!flag][1], dpmax[!flag][2]);
        
        flag = !flag; // 이렇게 현재값과 전값으로 단순화하면 시간초과를 막을 수 있다. 메모리 관련 제한이 걸려 있을 때 이런 아이디어도 생각해보자.
    }
    
    maxc = max(dpmax[!flag][0], max(dpmax[!flag][1], dpmax[!flag][2]));
    minc = min(dpmin[!flag][0], min(dpmin[!flag][1], dpmin[!flag][2]));
    cout << maxc << " " << minc << '\n';
    return 0;
}