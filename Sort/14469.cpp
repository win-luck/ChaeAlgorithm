#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n;
vector<pair<int, int> > v;

int main(){
    cin >> n;
    v.resize(n);
    for(int i=0; i<n; i++){
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());

    int answer = v[0].first + v[0].second;
    for(int i=1; i<v.size(); i++){
        if(answer <= v[i].first){
            answer = v[i].first + v[i].second;
        } else {
            answer += v[i].second;
        }
    }
    cout << answer;
    return 0;
}
