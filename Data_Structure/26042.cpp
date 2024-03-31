#include <iostream>
#include <queue>

using namespace std;
int n, a, b, answer = 100001;
int maxval = 0;

int main(){
    cin >> n;
    queue<int> q;
    for(int i=1; i<=n; i++){
        cin >> a;
        if(a == 1){
            cin >> b;
            q.push(b);
            if(maxval < q.size()){
                maxval = q.size();
                answer = b;
            } else if(maxval == q.size()){
                if(answer > b){
                    answer = b;
                }
            }
        } else {
            q.pop();
        }
    }
    cout << maxval << " " << answer;
    return 0;
}
