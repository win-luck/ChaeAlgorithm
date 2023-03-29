#include <iostream>
#include <algorithm>

using namespace std;
int t, n;
pair<int, int> arr[100001];

int main(){
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> arr[i].first >> arr[i].second;
        }
        
        sort(arr, arr + n); // 서류 오름차순
        int cnt = 1; // 서류 1등은 일단 선발
        int interview = arr[0].second;

        for(int i=1; i<n; i++){
            if(arr[i].second < interview){ // 서류 i등이 서류 i-1등보다 면접등수가 높은 경우 채용 가능
                cnt++;
                interview = arr[i].second;
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}