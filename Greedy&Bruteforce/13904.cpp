#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
int answer = 0;
int arr[1001];
vector<pair<int, int> > v;

bool cmp(pair<int ,int> p1, pair<int ,int> p2){
    return p1.second > p2.second;
} // 점수 내림차순으로 정렬

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0; i<=1000; i++){
        arr[i] = 0;
    }
    for(int i=0; i<n; i++){
        int d, w;
        cin >> d >> w;
        v.push_back(make_pair(d, w));
    }
    sort(v.begin(), v.end(), cmp);
    
    for(int i=0; i<n; i++){
        for(int j=v[i].first; j>0; j--){
            if(arr[j] == 0){
                arr[j] = v[i].second;
                break;
            }
        }
    }

    for(int i=0; i<=1000; i++){
        answer += arr[i];
    }
    cout << answer;
    return 0;
}