#include <iostream>
#include <queue>

using namespace std;
long long a, b;
int result;

bool range(long long n){ // 범위 내에서 있는 관찰
    if(n<=b) return true;
    return false;
}

int main(){
    result = 1;
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    cin >> a >> b;

    queue<pair<long long, long long> > q; // 숫자, 연산 수
    q.push(make_pair(a, 1));

    while(!q.empty()){
        pair<long long, long long> now = q.front();
        q.pop();

        if(now.first == b){
            cout << now.second << '\n';
            return 0;
        }

        if(range(now.first*10+1)) q.push(make_pair(now.first*10+1, now.second+1));
        if(range(now.first*2)) q.push(make_pair(now.first*2, now.second+1));
    }
    cout << -1 << '\n';
    return 0;
}

