#include <iostream>
#include <deque>
#include <vector>

using namespace std;
int n;
deque<int> dq;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    vector<int> v(n, 0);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    int card = 1;
    for(int i=n-1; i>=0; i--){
        int a = v[i];
        if(a == 1){
            dq.push_back(card);
        } else if(a == 2){
            int tmp = dq.back();
            dq.pop_back();
            dq.push_back(card);
            dq.push_back(tmp);
        } else {
            dq.push_front(card);
        }
        card++;
    }
    while(!dq.empty()){
        cout << dq.back() << " ";
        dq.pop_back();
    }
    return 0;
}
