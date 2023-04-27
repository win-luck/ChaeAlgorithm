#include <iostream>

using namespace std;
int n;
int sum = 0;
int arr[10003] = {0};

int main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }

    /*
    최대한 3개 연속으로 라면을 사게 만들어야 한다.
    arr[i+1] < arr[i+2] 이면
    arr[i] 혹은 arr[i+1]만큼 연속 3개 묶어서 라면을 사는 것이 이득이다.
    이후 남은 양은 arr[i]/arr[i+1] 둘을 비교하여 연속 2개 구매한다.

    arr[i+1] >= arr[i+2] 이면 
    2~3번째 공장의 차이, 혹은 1번째 공장 만큼 연속 2개 묶어서 
    라면을 사서 2~3번째 공장의 차이를 줄인 상태에서 연속 3개 구매한다.
    이렇게 하지 않으면 현재에서 7원으로 사는 게 이득이지만 다음 턴이 손해를 보는 반례를 방지할 수 있다.

    이후 남은 arr[i] 만큼 3을 곱해서 더해준다.
    */

    for(int i=1; i<=n; i++){
        if(arr[i+1] <= arr[i+2]){ // 3 5 7 9
            int cnt = min(arr[i], arr[i+1]); // 이 경우 3연속으로 산 뒤
            arr[i] -= cnt;
            arr[i+1] -= cnt;
            arr[i+2] -= cnt;
            sum += 7 * cnt;

            int cnt2 = min(arr[i], arr[i+1]); // 가능한 만큼 2연속으로 산다.
            arr[i] -= cnt2;
            arr[i+1] -= cnt2;
            sum += 5 * cnt2;
        } else { // 1 2 1 1
            int cnt = min(arr[i], abs(arr[i+1] - arr[i+2])); 
            // 위 조건문처럼 arr[i+1]과 arr[i]가 아니라, arr[i+1]-arr[i+2]와 arr[i]를 비교해준다.
            // 바로 3연속으로 사버리면 다음 인덱스에서 따로 사야 해서 비용이 늘어나버리는 반례 케이스가 있다.
            arr[i] -= cnt;
            arr[i+1] -= cnt;
            sum += 5 * cnt;

            int cnt2 = min(arr[i], arr[i+1]); // 가능한 만큼 3연속으로 산다.
            arr[i] -= cnt2;
            arr[i+1] -= cnt2;
            arr[i+2] -= cnt2;
            sum += 7 * cnt2;
        }
        sum += arr[i]*3;
        arr[i] = 0;
    }
    cout << sum << '\n';
    return 0;
}