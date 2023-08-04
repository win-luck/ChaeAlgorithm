#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
int arr[10001];
vector<pair<int, int> > v;

bool cmp(pair<int ,int> p1, pair<int ,int> p2){
    return p1.first > p2.first;
} // 점수 내림차순으로 정렬

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0; i<=10000; i++){
        arr[i] = 0;
    }

    for(int i=0; i<n; i++){
        int p, d;
        cin >> p >> d;
        v.push_back(make_pair(p, d));
    }

    sort(v.begin(), v.end(), cmp);
    for(int i=0; i<n; i++){
        for(int j=v[i].second; j>0; j--){
            if(arr[j] == 0){
                arr[j] = v[i].first;
                break;
            }
        }
    }
    int answer = 0;
    for(int i=0; i<=10000; i++){
        answer += arr[i];
    }
    cout << answer;
    return 0;
}